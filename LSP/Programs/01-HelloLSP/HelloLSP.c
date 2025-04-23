#include <stdio.h>
#include <unistd.h>

int main(void)
{
    printf("%s : Hello LSP !!!\n", __func__);
    printf("%s : pid : %d\n", __func__, getpid());
    return 0;
}
