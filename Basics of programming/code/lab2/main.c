#include <stdio.h>
#include <math.h>
#include <conio.h>


int main() {
    float a, b, c;
    printf("enter the sides of the triangle \n");


    printf("\na = ");
    while(!scanf("%f", &a)) {
        printf("this is not a number\n");
        return 0;
    }
    printf("\nb = ");
    while(!scanf("%f", &b)) {
        printf("this is not a number\n");
        return 0;
    }

    printf("\nc = ");
    while(!scanf("%f", &c)) {
        printf("this is not a number\n");
        return 0;
    }

    while ((a + b) <= c || (a + c) <= b || (b + c) <= a || a <= 0 || b <= 0 || c <= 0) {

        printf("incorrect  try again");


        printf("\na = ");
        while(!scanf("%f", &a)) {
            printf("this is not a number\n");
            return 0;
        }
        printf("\nb = ");
        while(!scanf("%f", &b)) {
            printf("this is not a number\n");
            return 0;
        }
        printf("\nc = ");
        while(!scanf("%f", &c)) {
            printf("this is not a number\n");
            return 0;
        }

            return 0;

    }



        float per, p, va, vb, vc, ba, bb, bc, s;
        double ma, mb, mc;
        p = (a + b + c)/2;
        s = sqrtf(p*(p-a)*(p-b)*(p-c));
        printf("Square of triangle: %.3f\n", s);
        per = a+b+c;
        printf("perimeter of triangle: %.3f\n", per);

        va = 2*s/a;
        vb = 2*s/b;
        vc = 2*s/c;
        printf("height to a: %.3f\n", va);
        printf("height to b: %.3f\n", vb);
        printf("height to c: %.3f\n", vc);

        ma = 0.5*sqrtf(2*b*b + 2*c*c - a*a);
        mb = 0.5*sqrtf(2*a*a + 2*c*c - b*b);
        mc = 0.5*sqrtf(2*b*b + 2*a*a - c*c);
        printf("median to a: %.3f\n", ma);
        printf("median to b: %.3f\n", mb);
        printf("median to c: %.3f\n", mc);

        ba = 2*sqrtf(b*c*p*(p-a))/(b+c);
        bb = 2*sqrtf(a*c*p*(p-b))/(a+c);
        bc = 2*sqrtf(b*a*p*(p-c))/(b+a);
        printf("bisector to a %.3f\n", ba);
        printf("bisector to b %.3f\n", bb);
        printf("bisector to c %.3f\n", bc);


        getch();
        return 0;

    }

