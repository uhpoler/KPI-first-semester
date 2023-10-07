#include <stdio.h> //містить функції вводу-виводу.
#include <conio.h> //містить описи функцій керування екраном в текстовому режимі.

int roman(int,int,char);

int main()
{
    int a;
    printf("ENTER NUMBER\n");
    scanf("%i",&a);

    if(a > 0){
        printf("You entered: %d\n", a);
        printf("Your number in roman is: ");

    } else {
        printf("ENTER NUMBER which is > 0");
    }

    a=roman(a,1000,'M');
    a=roman(a,500,'D');
    a=roman(a,100,'C');
    a=roman(a,50,'L');
    a=roman(a,10,'X');
    a=roman(a,5,'V');
    a=roman(a,1,'I');

    getch();
    return 0;
}

int roman(int i,int j,char c)
{ while (i>=j)
    { putchar(c);
        i=i-j;
    }
    return(i);
}