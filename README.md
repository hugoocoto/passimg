# PassImg

Library to ask for passwords. Instead of using an input box that hides what you
are typing, this library opens an image picker and extracts the password from
the selected image.

## Example
```c
#include "passimg.h"
#include <stdio.h>

int
main()
{
        const char *password = passimg();
        printf("password: %s\n", password);
        return 0;
}
```

## Pros

- If you are a streamer and you don't want to leak your passwords, this library
  is the solution as you don't have to hide anything. They need the exact same
  picture to get the same password, a screencapture doesn't work.

## Cons

- If you lose the picture, it's impossible to get the password.
- It's harder to share the password between devices.

## About security

A lot of people ask me what happens if someone gets into my computer and stole
my images. I ask them why they don't stole my passwords too.

## Notes about current implementation

I develop this in about an hour and 100 C lines; it has bugs, security issues
and stability concerns. I don't find them yet. If someone want to use this
library, let me know and I will spend a little more time on this.

## Deps

You need stb_image and tinyfiledialogs. I may provide you a statically linked
library in the future. Check `./deps`.


