#include <stdio.h>
#include <conio.h>
#include <math.h>

char entered(float *, char[]);
float function1(float x, float  y);
float function2(float x, float y);
float halving(float (*function)(float, float), float a1, float a2, float y, float eps);
float nuton (float (*function)(float, float), float a2, float eps, float y);
float result_validation(float x, float a1, float eps, float a2);

int main() {
    int exit;
    char validation;
    float y, x, a1, a2, eps, choose;

    do {
        printf("Select the equation\n 1) cos(y/x)-2sin(1/x)+1/x   or \n 2) sin(lnx)-cos(lnx)+y*lnx\n");
        if (scanf("%f%c", &choose, &validation) != 2 || validation != '\n') {
            printf("invalid entered\n");
            fflush(stdin);
            continue;
        }

        //косинус---------------------------------------------
        if (choose ==  1) {
            fflush(stdin);

            entered(&a1, "a1 == ");
            entered(&a2, "a2 == ");
            entered(&y, "y == ");
            entered(&eps, "eps == ");


            printf("choose a calculation method:\n1)method of halving\n2)Newton's method\npress 1 or 2\n");
            if (scanf("%f%c", &choose, &validation) != 2 || validation != '\n') {
                printf("invalid entered\n");
                fflush(stdin);
                continue;
            }

            //метод половинок з косинусом----------------------------------------
            if (choose ==  1) {
                fflush(stdin);

                x=halving(function1, a1, a2, y, eps);
                result_validation(x, a1, eps, a2);


            //метод ньютона з косинусом-------------------------------------------
            }else if(choose ==  2){
                fflush(stdin);

                x=nuton(function1, a2, eps, y);
                result_validation(x, a1, eps, a2);

            }else{
                printf("invalid input. try again enter 1 or 2\n");
            }

        //синус-------------------
        }else if (choose ==  2){
            fflush(stdin);

            entered(&a1, "a1 == ");
            entered(&a2, "a2 == ");
            entered(&y, "y == ");
            entered(&eps, "eps == ");

            printf("choose a calculation method:\n1)method of halving\n2)Newton's method\npress 1 or 2\n");
            if (scanf("%f%c", &choose, &validation) != 2 || validation != '\n') {
                printf("invalid entered\n");
                fflush(stdin);
                continue;
            }

            //метод половинок з синусом----------------------------------------
            if (choose ==  1) {
                fflush(stdin);

                x=halving(function2, a1, a2, y, eps);
                result_validation(x, a1, eps, a2);


            //метод ньютона з синусом-------------------------------------------
            }else if(choose ==  2){
                fflush(stdin);

                x=nuton(function2, a2, eps, y);
                result_validation(x, a1, eps, a2);
            }else{
                printf("invalid input. try again enter 1 or 2\n");
            }

        }else{
            printf("invalid input. try again enter 1 or 2\n");
        }



        printf("Press n or N if you don't want to continue\n");


        exit = getch();
    }while(exit != 78 && exit != 110);

    return 0;
}

char entered(float *var, char var_name[]){
    char validation;
    printf("enter %s", var_name );
    while (scanf("%f%c", &*var, &validation) != 2 || validation != '\n' || *var>1000 || *var<-1000) {
        printf("invalid input\n\n");
        fflush(stdin);
        printf("enter %s:", var_name);
    }
}


float function1(float x, float y){
    return (cos(y/x)-2*sin(1.0/x)+1.0/x);
}

float function2(float x, float y){
    return (sin(log(x))-cos(log(x))+y*log(x));
}

float halving(float (*function)(float, float), float a1, float a2, float y, float eps){
    float x;
    while(fabs(a2-a1)>eps){
        x=(a1+a2)/2.0;
        if((*function)(x,y)*(*function)(a1,y)>0){
            a1=x;
        }else{
            a2=x;
        }
    }
    return x;
}

float nuton (float (*function)(float, float), float a2, float eps, float y){
    float x, pohidna, delta;

    x = a2;
    pohidna = ((function(x+eps, y) - function(x, y))/eps);
    delta = function(x, y)/pohidna;
    x = x - delta;
    do{
        delta =  function(x, y)/pohidna;
        x = x - delta;
    }while (fabs(delta)>eps);

    return x;
}

float result_validation(float x, float a1, float eps, float a2){

    if (x >= (a1+eps) && x <= (a2-eps)){
        printf("x==%f\n", x);
    }
    else{
        printf("invalid entered. try again. x has to be >= (a1+eps) and <= (a2-eps)\n");
    }
}
