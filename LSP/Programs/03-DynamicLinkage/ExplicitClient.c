#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dlfcn.h>

int main(void)
{
    void* handle = NULL;
    int (*fnptr)(int);
    int num = 3;
    int status;

    printf("\n%s() => Start\n\n", __func__);
    printf("PID : %d\n", getpid());

    //* Request Link-Loader to load specified library and attach it into our address space
    handle = dlopen("./libmymath.so", RTLD_NOW);
    if (handle == NULL)
    {
        printf("\nFailed To Load Dynamic Library ... Exiting !!!\n");
        exit(EXIT_FAILURE);
    }

    //* Lookup for the address of the required function - square
    fnptr = dlsym(handle, "square");

    //* Invoke Function Through Pointer
    int square = (fnptr)(3);
    printf("Square of %d = %d\n", num, square);

    //* Lookup for the address of the required function - cube
    fnptr = dlsym(handle, "cube");

    //* Invoke Function Through Pointer
    int cube = (fnptr)(3);
    printf("Cube of %d = %d\n", num, cube);
 
    //* Request Link-Loader To Unlink Library
    status = dlclose(handle);
    if (status == 0)
        printf("\nLibrary Unmapped ... \n");
    else
    {
        printf("\nFailed To Unlink Dynamic Library : %s ... Exiting !!!", dlerror());
        if (handle)
            handle = NULL;
        exit(EXIT_FAILURE);
    }

    if (handle)
        handle = NULL;

    printf("\n%s() => End\n\n", __func__);

    return 0;
}
