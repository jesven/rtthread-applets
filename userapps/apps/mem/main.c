#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    char *buf;
    int i;

    printf("malloc test start\n");

    for (i = 1; i < 1024*1; i ++)
    {
        buf = malloc(i);
        if (buf)
        {
            memset(buf, 0xa5, i);
        }
        else
        {
            printf("malloc size %d fail\n", i);
            break;
        }
        free(buf);
    }
    printf("malloc test end\n");

    return 0;
}
