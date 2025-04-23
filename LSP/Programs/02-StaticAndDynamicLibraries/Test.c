#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    printf("%s() : Start : %d\n", __func__, getpid());
    f1();
    printf("%s() : End\n", __func__);
    return 0;
}
