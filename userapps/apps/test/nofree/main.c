#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{

    printf("malloc but not free\n");
    malloc(1);

    return 0;
}
