#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char **argv)
{
    int fd;
    char buf[9] = {0};

    fd = open("/wftst", O_RDONLY, 0);
    if (fd < 0)
    {
        printf("open fail\n");
        return 1;
    }

    if (read(fd, buf, 8) != 8)
    {
        printf("read fail\n");
    }
    else
    {
        printf("read: %s\n", buf);
    }
    close(fd);

    return 0;
}
