#include <stdio.h>
#include <conio.h>
#include <math.h>

float delta(float n, float del, float x);

int main() {
    int exit;
    char validation;
    float del, n, my_sin,  x_rad,  x1, x2, dx, eps;

    do {
        printf("x1 =");
        if (scanf("%f%c", &x1, &validation) != 2 || validation != '\n' || x1 > 360 || x1 < 0) {
            printf("invalid entered\n");
            fflush(stdin);
            continue;
        }

        printf("x2 = ");
        if (scanf("%f%c", &x2, &validation) != 2 || validation != '\n' || x2 > 360 || x2 < 0) {
            printf("invalid entered\n");
            fflush(stdin);
            continue;
        }

        printf("dx = ");
        if (scanf("%f%c", &dx, &validation) != 2 || validation != '\n') {
            printf("enter number without symbol\n");
            fflush(stdin);
            continue;
        }

        if (x1 < x2 && dx < 0) {
            printf("enter dx>0\n");
            continue;
        } else if (x1 > x2 && dx > 0) {
            printf("enter dx<0\n");
            continue;
        } else if (dx == 0) {
            printf("dx!=0\n");
            continue;
        }


        printf("Epsilon =");
        if (scanf("%f%c", &eps, &validation) != 2 || validation != '\n') {
            printf("enter number without symbol\n");
            fflush(stdin);
            continue;
        }


        printf("---x---      ---sin(x)---  ---sin(taylor)---  ---sin(x)-sin(taylor)---\n");

            for (float x = x1; (x1<=x2)?(x <= x2):(x>=x2); x += dx) {
                x_rad = x * M_PI / 180;
                del = my_sin = x_rad;
                n = 1;

                while (fabs(del) >= eps) {
                    del = delta(n, del, x_rad);
                    my_sin = my_sin + del;
                    n = n + 2;
                }

                printf("%.3f   \t%.6f\t%.6f\t   %.6f\n", x, sin(x_rad), my_sin, (sin(x_rad) - my_sin));
                if (x + dx > x2 && x != x2 && x1<=x2) {
                    x_rad = x2 * M_PI / 180;
                    del = my_sin = x_rad;
                    n = 1;

                    while (fabs(del) >= eps) {
                        del = delta(n, del, x_rad);
                        my_sin = my_sin + del;
                        n = n + 2;
                    }
                    printf("%.3f   \t%.6f\t%.6f\t   %.6f\n", x2, sin(x_rad), my_sin, (sin(x_rad) - my_sin));
                }else if(x + dx<x2 && x != x2 && x1>x2){
                    x_rad = x2 * M_PI / 180;
                    del = my_sin = x_rad;
                    n = 1;

                    while (fabs(del) >= eps) {
                        del = delta(n, del, x_rad);
                        my_sin = my_sin + del;
                        n = n + 2;
                    }
                    printf("%.3f   \t%.6f\t%.6f\t   %.6f\n", x2, sin(x_rad), my_sin, (sin(x_rad) - my_sin));
                }
            }



                printf("Press n or N if you don't want to continue\n");


                exit = getch();
            }while(exit != 78 && exit != 110);

    return 0;
}

float delta(float n, float del, float x) {
    del = del * ((-x * x) / ((n+1)*(n+2)));
    return del;

}
