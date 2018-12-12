#include <stdio.h>
#include <stdlib.h>

int gv = 5;
static int sgv;
int vgv[] = {1, 2};
const int cgv = 120;

int main(int argc, char **argv)
{
    int lv = 0x1782a5b3;

    printf("lv(0x1782a5b3) = %0x\n", lv);
    printf("gv(5) = %d\n", gv);
    printf("sgv(0) = %d\n", sgv);
    printf("vgv{1,2} = %d, %d\n", vgv[0], vgv[1]);
    printf("cgv(120) = %d\n", cgv);

    return 0;
}
