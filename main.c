
#include <stdio.h>

#include "A.h"
#include "C.h"

int main()
{
    int result = add_number(1, 2);
    printf("ADD Result: %d\n", result);
    result = mul_number(1, 2);
    printf("MUL Result: %d\n", result);
    result = sub_number(3, 1);
    printf("SUB Result: %d\n", result);
    return 0;
}

