#define _GNU_SOURCE

#include <sys/types.h>
#include <sys/mman.h>
#include <dlfcn.h>
#include <stdio.h>

int add_number(int left, int right)
{
    const char *symbol = "add_number";
    int (*original)(int, int) = dlsym(RTLD_NEXT, symbol);
    // print left and right
    printf("From libB.so add_number(left: %d, right: %d)\n", left, right);
    return original(left, right);
}

int mul_number(int left, int right)
{
    printf("From libB.so mul_number(left: %d, right: %d)\n", left, right);
    return 69;
}

