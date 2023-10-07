#include <stdio.h>
#include <conio.h>
#include <math.h>


int check(float x, int k);
void positive_k(int k, float x, float e);
void negative_k(int k, float x, float e);

int main() {
    int k;
    float x, e, d;

    int exit;
    char validation;
    do {
        printf("x=");
        if (scanf("%f%c", &x, &validation) != 2 || validation != '\n') {
            printf("Invalid input");
            return 0;
        }

        printf("k=");
        if (scanf("%d%c", &k, &validation) != 2 || validation != '\n') {
            printf("Invalid input");
            return 0;
        }

        printf("e=");
        if (scanf("%e%c", &e, &validation) != 2 || validation != '\n') {
            printf("Invalid input");
            return 0;
        }

        if (check(x, k)) {
            printf("check_error");
            return 0;
        }

        if (k > 0) {
            positive_k(k, x, e);
        } else {
            negative_k(fabs(k), x, e);
        }

        printf("Press n or N if you don't want to continue\n");

        exit = getch();
    }while(exit != 78 && exit != 110);

    return 0;
}

int check(float x, int  k) {
    if (k == 0) return 0;

    if (k < 0) {
        if (abs(k) % 2 == 0) {
            if (x <= 0) return 1;
        }
        else {
            if (x == 0) return 1;
        }
    } else {
        if (abs(k) % 2 == 0) {
            if (x < 0) return 1;
        }
    }
    return 0;
}

void negative_k(int k, float x, float e) {
    float delta = 1, y = 1;

    while (1) {
        printf("delta: %f\n"
               "Y = %f\n\n", delta, 1 / y);

        delta = (1.0 / k) * (x / (pow(y, k - 1)) - y);

        if (fabs(delta) < e) break;

        y = y + delta;
    }
}

void positive_k(int k, float x, float e) {
    float delta = 1, y = 1;


    while (1) {
        printf("delta: %f\n"
               "Y = %f\n\n", delta, y);

        delta = (1.0 / k) * (x / (pow(y, k - 1)) - y);

        if (fabs(delta) < e) break;

        y = y + delta;
    }
}

