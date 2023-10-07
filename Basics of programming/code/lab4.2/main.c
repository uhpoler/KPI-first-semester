#include <stdio.h>
#include <conio.h>

void increase(float *elements, int n);

int main() {
    int n, exit;
    float numbers[n];
    char validation;

    do {
        printf("enter the number of elements\n");

        while (scanf("%d%c", &n, &validation) != 2 || validation != '\n') {
            printf("enter number without symbol\n");
            fflush(stdin);
        }

        if (n<=0) {
            printf("enter n correctly\n");
            fflush(stdin);
            continue;
        }


        printf("enter the elements of the array[%d]:\n", n);

        for (int i=0; i<n; i++) {

            if (scanf("%f%c", &numbers[i], &validation) != 2 || validation != '\n') {
                printf("enter number without symbol\n");
                fflush(stdin);
                i=i-1;
                continue;
            }else if(i > 1e8 || i < -1e8) {
                printf("element must be from -1e8 to 1e8\n");
                fflush(stdin);
                i=i-1;
                continue;

            }
        }


        increase(numbers,n);

        printf("\nsorted array in decreasing order\n");
        for (int i=n-1; i>-1; i--) {
            printf("%.3f  ", numbers[i]);
        }

        increase(numbers,n);

        printf("\n\nsorted array in increasing order\n");
        for (int i=0; i<n; i++) {
            printf("%.3f  ", numbers[i]);
        }

        printf("\nPress n or N if you don't want to continue\n");

        exit = getch();
    }while(exit != 78 && exit != 110);

    return 0;
}

void increase(float *elements, int n) {
    int i, j;
    float t;

    for (i = 0; i<n-1; i++)
        for (j = i+1; j<n; j++)
            if (elements[j] < elements[i]) {
                t = elements[i];
                elements[i] = elements[j];
                elements[j] = t;
            }
}
