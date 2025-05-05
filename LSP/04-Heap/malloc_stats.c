#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

int main(int argc, char** argv)
{
    // Variable Declarations
    void* ptr = NULL;

    // Code
    if (argc != 2)
    {
        printf("\nBad Usage : Format : App <Size in Kb>\n");
        exit(EXIT_FAILURE);
    }

    int size = atoi(argv[1]);

    //* Allocate Heap Block
    ptr = malloc(size * 1024);
    if (ptr == NULL)
    {
        printf("Failed to allocate memory to ptr ... Exiting !!!");
        exit(EXIT_FAILURE);
    }

    printf("Invoked malloc() : @%p\n", ptr);
    getchar();
    printf("-------------------------------------------------------\n");
    malloc_stats();
    printf("-------------------------------------------------------\n");

    free(ptr);
    ptr = NULL;
    getchar();
    printf("Invoked free()\n");
    printf("-------------------------------------------------------\n");
    malloc_stats();
    printf("-------------------------------------------------------\n");

    return 0;
}

