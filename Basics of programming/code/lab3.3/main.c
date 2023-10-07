#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <complex.h>

void result(float a, float y1, float complex y2, float complex y3);

int main() {
    int exit;
    float a, b, c;
    char validation;
    do {

        printf("enter coefficients of the equation\n");

        printf("a=");
        if (scanf("%f%c", &a, &validation) != 2 || validation != '\n') {
            printf("enter number without symbol\n");
            fflush(stdin);
            continue;
        }


        printf("b=");
        if (scanf("%f%c", &b, &validation) != 2 || validation != '\n') {
            printf("enter number without symbol\n");
            fflush(stdin);
            continue;
        }
        printf("c=");
        if (scanf("%f%c", &c, &validation) != 2 || validation != '\n') {
            printf("enter number without symbol\n");
            fflush(stdin);
            continue;
        }

            float p, q, d, y, y1, u, v;
            float complex y2, y3;
            p=b-(a*a/3);
            q=(2*a*a*a/27)-(a*b/3)+c;
            d=(p*p*p/27)+(q*q/4);

            if(d>0){

                y=(-q/2.0) + sqrt(d);

                u = (y>0) ? ( pow(y,1/3.) ) : ( pow(fabs(y),1/3.)*(-1) );
                v=(-1)* p/(3*u);


                y2=((-(u+v))/2)+ I *(sqrt(3)*(u-v))/2;
                y3=((-(u+v))/2)- I *(sqrt(3)*(u-v))/2;
                printf("%fi\n", cimag(y2));

                if(u==0){
                    printf("wrong coefficients\n");
                    continue;
                }else{

                    y1=u+v;

                    result(a, y1, y2, y3);
                }

            } else if(d==0){

                if(p==0){
                    printf("wrong coefficients\n");
                    continue;
                } else {
                    y1 = 3 * q / p;
                    y2 = y3 = -3 * q /( 2 * p);

                    result(a, y1, y2, y3);
                }

            }else{
                float f, r;

                if((-pow(p, 3)/27)<=0){
                    printf("wrong coefficients\n");
                    continue;
                }else{
                    r=sqrt(-pow(p, 3)/27);
                    f=acos(-q/(2*r));

                    y1=2*fabs(pow(r,1/3.))*cos(f/3);
                    y2=2*fabs(pow(r,1/3.))*cos((f+2*M_PI)/3);
                    y3=2*fabs(pow(r,1/3.))*cos((f+4*M_PI)/3);


                    result(a, y1, y2, y3);
                }
            }






        printf("Press n or N if you don't want to continue\n");

        exit = getch();
    }while(exit != 78 && exit != 110);

    return 0;
}

void result(float a, float y1, float complex y2, float complex y3){
    printf("x1= %.4f\n", y1-(a/3));
    printf("x2= %.4f + %.5fi\n", creal(y2-(a/3)), cimag(y2));
    printf("x2= %.4f - %.5fi\n", creal(y3-(a/3)), cimag(y3));
}