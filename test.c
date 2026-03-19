#include "passfile.h"
#include <stdio.h>

int
main()
{
        const char *password = pf_get();
        printf("password: %s\n", password);
        return 0;
}
