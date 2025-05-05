#include <stdio.h>
#include <unistd.h>

void* current_brk = NULL;
void* old_brk = NULL;
void* new_brk = NULL;

int main(void)
{
    int ret = 0;
    int *ptr = NULL;

    printf("[%d] : Retrieve Heap Start\n", getpid());
    getchar();

    //! Get Current Program Break Address
    current_brk = sbrk(0);
    old_brk = current_brk;
    printf("\nCurrent brk : %p\n", current_brk);

    //! Increase Program Break by 100 bytes

    return 0;
}

