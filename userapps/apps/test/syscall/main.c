#include <stdio.h>

int main(int argc, char **argv)
{
    syscall(200, 1, 2, 3, 4, 5, 6);

    return 0;
}
