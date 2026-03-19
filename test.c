#include "passimg.h"
#include <stdio.h>

int
main()
{
        const char *password = passimg();
        printf("password: %s\n", password);
        return 0;
}
