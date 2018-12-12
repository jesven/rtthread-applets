#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char **argv)
{
    int fd;

    fd = open("/wftst", O_CREAT | O_WRONLY | O_TRUNC, 0);
    if (fd < 0)
    {
        printf("open fail\n");
        return 1;
    }

    if (write(fd, "writetst", 8) != 8)
    {
        printf("write fail\n");
    }
    close(fd);
    printf("write success\n");

    return 0;
}
