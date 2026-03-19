# PassImg

Library to ask for passwords. Instead of using a input box that hides what you
are typing, this library opens a image picker and extracts the password from the
selected image.

## Example
```c
#include "passfile.h"
#include <stdio.h>

int
main()
{
        const char *password = pf_get();
        printf("password: %s\n", password);
        return 0;
}
```

## Pros

- If you are a streamer and you dont have to leak your passwords, this library
  is the solution as you don't have to hide anything. They need the exact same
  picture to get the same password, a screencapture doesn't work.

## Cons

- If you lose the picture, it's impossible to get the password.
- It's harder to share the password between devices

## About security

A lot of people ask me what happens if someone get into my computer and stole my
images. I ask them why they don't stole my passwords too.

## Notes about current implementation

I develop this in about an hour; it has bugs, security issues and stability
concerns. I don't find them yet.

## Deps

You need stb_image and tinyfiledialogs. I may provide you a statically linked
library in the future. Check `./deps`.


