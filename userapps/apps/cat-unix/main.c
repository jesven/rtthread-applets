#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char **argv)
{
    int length;
    char buffer[81];
    int fd;

    if (argc < 2)
        return 1;

    if ((fd = open(argv[1], O_RDONLY)) < 0)
    {
        printf("Open %s failed\n", argv[1]);

        return 1;
    }

    do
    {
        memset(buffer, 0, sizeof(buffer));
        length = read(fd, buffer, sizeof(buffer)-1);
        if (length > 0)
        {
            printf("%s\r\n", buffer);
        }
    }while (length > 0);

    close(fd);

    return 0;
}
