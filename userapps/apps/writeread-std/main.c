#include <string.h>
#include <stdio.h>

int main(int argc, char **argv)
{
    FILE *fd;
    char buf[9] = {0};
    char *text = "w-r--std";

    if (argc < 2)
        return 1;

    printf("---write read std---\n\n");

    fd = fopen(argv[1], "w+");
    if (fd == NULL)
    {
        printf("open fail\n");
        return 1;
    }

    printf("write: %s\n", text);

    if (fwrite(text, 8, 1, fd) != 1)
    {
        printf("write fail\n");
        goto _out;
    }
    printf("do seek\n\n");
    fseek(fd, 0, SEEK_SET);
    printf("do read\n\n");
    if (fread(buf, 8, 1, fd) == 1)
    {
        printf("read: %s\n", buf);
    }
    else
    {
        printf("read fail\n");
    }

_out:
    fclose(fd);

    return 0;
}
