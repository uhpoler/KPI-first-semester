
#include <stdio.h>

int main()
{
    long int binary, hexadecimal, var, i;

    i = 1;
    hexadecimal = 0;

    printf("\nenter the binary number: ");
    scanf("%ld", &binary);
    while (binary != 0)
    {
        var = binary % 10;
        hexadecimal = hexadecimal + var * i;
        i = i * 2;
        binary = binary / 10;
    }
    printf("number in hexadecimal: %lX", hexadecimal);
    return 0;
}