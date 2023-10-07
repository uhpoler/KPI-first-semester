#include <stdio.h>
#include <math.h>

typedef  struct { //дозволяє користувачам надавати альтернативні імена для простих  і визначених користувачем типів даних.
    float re, im;
} complex;
char entered(float *, char[]);
void contour_1 ( float l, float ce, float r0, float w);
void contour_2 ( float l, float ce, float r0, float w);
void contour_3 ( float l, float ce, float r1, float r2, float w);
void contour_4 ( float l, float ce, float r1, float r2, float w);
float res_freq(float l, float ce);
void print1(complex resultat);
void print2(complex resultat);
complex reim(complex zm1, complex zm2);




int main() {
    int exit, choose;
    char validation;
    float  l, r0, ce, r1, r2, step, f_max, f_min;


    do{

        printf("Select the circuit {1, 2, 3, 4}\n");
        if (scanf("%d%c", &choose, &validation) != 2 || validation != '\n') {
            printf("invalid entered\n");
            fflush(stdin);
            continue;
        }

        if(choose == 1){
            fflush(stdin);

            entered(&l, "L == ");
            entered(&ce, "C == ");
            entered(&r0, "R == ");
            entered(&f_min, "F min == ");
            entered(&f_max, "F max == ");

            while(f_min>f_max){
                printf("\n\nError. F min have to be < than F max. try again\n\n");
                fflush(stdin);
                entered(&l, "L == ");
                entered(&ce, "C == ");
                entered(&r0, "R == ");
                entered(&f_min, "F min == ");
                entered(&f_max, "F max == ");
                entered(&step, "step == ");
            }
            entered(&step, "step == ");

            int plus=1;
            float w, i;
            printf("resonant frequency %f\n\n", res_freq( l, ce));

            for (i = f_min; i <= f_max; i += step){

                w=2*M_PI*i;

                printf("f%d = %f   ", plus, i);
                printf("z%d = ", plus);
                contour_1 ( l,  ce,  r0, w);
                plus++;
            }

        } else if(choose == 2){
            fflush(stdin);

            entered(&l, "L == ");
            entered(&ce, "C == ");
            entered(&r0, "R == ");
            entered(&f_min, "F min == ");
            entered(&f_max, "F max == ");

            while(f_min>f_max) {
                printf("\n\nError. F min have to be < than F max. try again\n\n");
                fflush(stdin);

                entered(&l, "L == ");
                entered(&ce, "C == ");
                entered(&r0, "R == ");
                entered(&f_min, "F min == ");
                entered(&f_max, "F max == ");
                entered(&step, "step == ");
            }
            entered(&step, "step == ");

            int plus=1;
            float w, i;
            printf("resonant frequency %f\n\n", res_freq( l, ce));

            for (i = f_min; i <= f_max; i += step){

                w=2*M_PI*i;

                printf("f%d = %f   ", plus, i);
                printf("z%d = ", plus);
                contour_2 ( l,  ce,  r0, w);
                plus++;
            }
        } else if(choose == 3){
            fflush(stdin);

            entered(&l, "L == ");
            entered(&ce, "C == ");
            entered(&r1, "R1 == ");
            entered(&r2, "R2 == ");
            entered(&f_max, "F max == ");
            entered(&f_min, "F min == ");

            while(f_min>f_max) {
                printf("\n\nError. F min have to be < than F max. try again\n\n");
                fflush(stdin);
                entered(&l, "L == ");
                entered(&ce, "C == ");
                entered(&r1, "R1 == ");
                entered(&r2, "R2 == ");
                entered(&f_max, "F max == ");
                entered(&f_min, "F min == ");
                entered(&step, "step == ");
            }
            entered(&step, "step == ");

            int plus=1;
            float w, i;
            printf("resonant frequency %f\n\n", res_freq( l, ce));

            for (i = f_min; i <= f_max; i += step){

                w=2*M_PI*i;

                printf("f%d = %f   ", plus, i);
                printf("z%d = ", plus);
                contour_3 ( l,  ce,  r1, r2, w);
                plus++;
            }

        }else if(choose == 4){
            fflush(stdin);

            entered(&l, "L == ");
            entered(&ce, "C == ");
            entered(&r1, "R1 == ");
            entered(&r2, "R2 == ");
            entered(&f_min, "F min == ");
            entered(&f_max, "F max == ");

            while(f_min>f_max) {
                printf("\n\nError. F min have to be < than F max. try again\n\n");
                fflush(stdin);
                entered(&l, "L == ");
                entered(&ce, "C == ");
                entered(&r1, "R1 == ");
                entered(&r2, "R2 == ");
                entered(&f_min, "F min == ");
                entered(&f_max, "F max == ");
                entered(&step, "step == ");
            }
            entered(&step, "step == ");
            int plus=1;
            float w, i;
            printf("resonant frequency %f\n\n", res_freq( l, ce));

            for (i = f_min; i <= f_max; i += step){

                w=2*M_PI*i;

                printf("f%d = %f   ", plus, i);
                printf("z%d = ", plus);
                contour_4 ( l,  ce,  r1, r2, w);
                plus++;
            }

        }else{
            fflush(stdin);
            printf("invalid input. try again enter 1, 2, 3 or 4\n");
        }



    }while(exit != 78 && exit != 110);

    return 0;

}

char entered(float *var, char var_name[]){
    char validation;
    printf("enter %s", var_name );
    while (scanf("%f%c", &*var, &validation) != 2 || validation != '\n' || *var>1000000 || *var<0) {
        printf("invalid input. enter %s from 1 to 1000000 \n\n", var_name);
        fflush(stdin);
        printf("enter %s:", var_name);
    }
}

float res_freq(float l, float ce){
    return 1/(2*M_PI*sqrtf(l*ce));
}

void print1(complex resultat){
    printf("%.6g - i * %.6gi\n", resultat.re, fabs(resultat.im));

}

void print2(complex resultat){
    printf("%.6g + i * %.6gi\n", resultat.re, fabs(resultat.im));

}

void contour_1 ( float l, float ce, float r0, float w){
    complex a1, a2, resultat;

        a1.re=l/ce;
        a1.im=r0/(w*ce);
        a2.re=r0;
        a2.im=(w*l)-1/(w*ce);

        resultat = reim(a1, a2);
        print1(resultat);
}

void contour_2 ( float l, float ce, float r0, float w){
    complex b1, b2, resultat;

    b1.re=l/ce;
    b1.im=r0/(w*ce);
    b2.re=r0;
    b2.im=(w*l)-1/(w*ce);

    resultat = reim(b1, b2);
    print1(resultat);
}

void contour_3 ( float l, float ce, float r1, float r2, float w){
    complex c1, c2, resultat;

    c1.re=(r1*r2) + r1*(l/ce);
    c1.im=w*l*r1 - (r2/(w*ce));
    c2.re=r1+r2;
    c2.im=(w*l)-1/(w*ce);

    resultat = reim(c1, c2);
    print2(resultat);
}

void contour_4 ( float l, float ce, float r1, float r2, float w){
    complex d1, d2, resultat;

    d1.re=(r1*r2) + (l/ce);
    d1.im=w*l*r1 - (r2/(w*ce));
    d2.re=r1+r2;
    d2.im=(w*l)-1/(w*ce);

    resultat = reim(d1, d2);
    print2(resultat);
}

complex reim(complex zm1, complex zm2) {
    complex resultat;
    resultat.re = (zm1.re * zm2.re + zm1.im * zm2.im) / (zm2.re * zm2.re + zm2.im * zm2.im);
    resultat.im = (zm1.im * zm2.re - zm1.re * zm2.im) / (zm2.re * zm2.re + zm2.im * zm2.im);
    return resultat;
}

