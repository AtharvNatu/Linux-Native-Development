#include <stdio.h>
#include <stdlib.h>

void _init(void)
{
    printf("\n%s() => Library init() Invoked\n", __func__);
}

int square(int num)
{
    return num * num;
}

int cube(int num)
{
    return num * num * num;
}

void _fini(void)
{
    printf("\n%s() => Library fini() Invoked\n", __func__);
}

