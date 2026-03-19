#include <assert.h>
#include <openssl/evp.h>
#include <stdlib.h>
#include <string.h>

#include "./tinyfiledialogs/tinyfiledialogs.h"
#include "passfile.h"
#include "stb_image.h"

#define len(x) (sizeof((x)) / sizeof(*(x)))

const char *internal_buffer[45];

typedef struct File {
        unsigned char *data;
        unsigned int data_len;
        int x;
        int y;
        int channels;
} File;

static File *
load_file(const char *filename)
{
        File *file = calloc(1, sizeof(File));
        file->data = stbi_load(filename, &file->x, &file->y, &file->channels, 0);
        file->data_len = file->x * file->y * file->channels;
        return file;
}

static void
free_file(File *file)
{
        stbi_image_free(file->data);
        free(file);
}

static const char *
pick_files()
{
        char const *lFilterPatterns[] = { "*.png", "*.jpg", "*.jpeg" };
        return tinyfd_openFileDialog(
        "Pick a file",        // title
        "",                   // default path
        len(lFilterPatterns), // patterns-len
        lFilterPatterns,      // patterns
        "Images",             // filter description
        0                     // 0 single, 1 multiple selection
        );
}

static void
file_hash(File *file, void **digest, unsigned int *digest_size)
{
        EVP_MD_CTX *ctx;

        ctx = EVP_MD_CTX_new();
        *digest = malloc(EVP_MAX_MD_SIZE);

        EVP_DigestInit_ex(ctx, EVP_sha256(), NULL);
        EVP_DigestUpdate(ctx, file->data, file->data_len);
        EVP_DigestFinal_ex(ctx, *digest, digest_size);
        EVP_MD_CTX_free(ctx);
}

static const char *
b64(void *data, unsigned int size)
{
        internal_buffer[EVP_EncodeBlock((unsigned char *) internal_buffer, data, size)] = 0;
        return (const char *) internal_buffer;
}

const char *
pf_get()
{
        void *digest;
        unsigned int digest_size;
        File *file;
        const char *b64_digest_str;

        char *stream = strdup(pick_files());

        file = load_file(stream);
        file_hash(file, &digest, &digest_size);
        free_file(file);
        b64_digest_str = b64(digest, digest_size);

        free(digest);
        free(stream);

        return b64_digest_str;
}

#undef len

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
