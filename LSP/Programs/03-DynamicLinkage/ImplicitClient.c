#include <stdio.h>
#include <unistd.h>

int main(void)
{
    // Code
    int num = 3;

    printf("\n%s() => Start\n\n", __func__);
    printf("PID : %d\n", getpid());

    // Load-Time Linkage (Implicit Linking)
    printf("Square of %d = %d\n", num, square(num));
    printf("Cube of %d = %d\n", num, cube(num));

    printf("\n%s() => End\n", __func__);

    return 0;
}
