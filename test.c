#include <openssl/evp.h>
#include <stdio.h>
#include <string.h>

#include "./tinyfiledialogs/tinyfiledialogs.h"
#include "stb_image.h"

#define len(x) (sizeof((x)) / sizeof(*(x)))

typedef struct File {
        unsigned char *data;
        int x;
        int y;
        int channels;
} File;

File *
load_file(const char *filename)
{
        File *file = calloc(1, sizeof(File));
        file->data = stbi_load(filename, &file->x, &file->y, &file->channels, 0);
        return file;
}

void
free_file(File *file)
{
        stbi_image_free(file->data);
        free(file);
}

// '|' separated absolute paths
const char *
pick_files()
{
        char const *lFilterPatterns[] = { "*.png", "*.jpg", "*.jpeg" };
        char const *selection;

        selection = tinyfd_openFileDialog(
        "Pick a file",        // title
        "",                   // default path
        len(lFilterPatterns), // patterns-len
        lFilterPatterns,      // patterns
        "Images",             // filter description
        1                     // 0 single, 1 multiple selection
        );

        return selection;
}

/* Función para calcular y formatear el hash SHA-256 -- gemini */
void
calcular_sha256_cadena(const char *cadena, char *salida_hexadecimal)
{
        EVP_MD_CTX *contexto;
        unsigned char hash_binario[EVP_MAX_MD_SIZE];
        unsigned int longitud_hash;
        int i;

        /* Asignación del contexto criptográfico */
        contexto = EVP_MD_CTX_new();
        if (contexto == NULL) {
                return; /* Fallo en la asignación de memoria */
        }

        /* Inicialización, actualización y finalización del algoritmo */
        EVP_DigestInit_ex(contexto, EVP_sha256(), NULL);
        EVP_DigestUpdate(contexto, cadena, strlen(cadena));
        EVP_DigestFinal_ex(contexto, hash_binario, &longitud_hash);

        /* Liberación del contexto */
        EVP_MD_CTX_free(contexto);

        /* Conversión de la representación binaria a una cadena hexadecimal */
        for (i = 0; i < longitud_hash; i++) {
                sprintf(salida_hexadecimal + (i * 2), "%02x", hash_binario[i]);
        }
        salida_hexadecimal[64] = '\0';
}

int
main(void)
{
        const char *datos = "Texto de prueba para validacion SHA-256";
        char resultado_hexadecimal[65];

        calcular_sha256_cadena(datos, resultado_hexadecimal);
        printf("SHA-256: %s\n", resultado_hexadecimal);

        return 0;
}

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
