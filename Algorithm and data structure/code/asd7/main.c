#include <stdio.h>

void Arr1(char *array1);
void Arr2(char *array2);
void printArr(char *array1, int number);
int fillArr3(char *array1, char *array2, char *array3);

int main(){
    char array1[10]={}, array2[10]={}, array3[10]={};
    int numberArr3, sum=0;

    Arr1(array1);
    Arr2(array2);
    numberArr3=fillArr3(array1, array2, array3);

    for(int i=0; i<=numberArr3; i++){
        if(array3[i]>101){
            sum+=array3[i];
        }
    }

    printf("Array1: ");
    printArr(array1, 10);
    printf("\nArray2: ");
    printArr(array2, 10);
    printf("\nArray3: ");
    printArr(array3, numberArr3);
    printf("\nResult: %d", sum);

    return 0;
}

void Arr1(char *array1){
    for(int i=0; i<10; i++){
        array1[i]=95 + i;
    }
}

void Arr2(char *array2){
    for(int i=0; i<10; i++){
        array2[i]=105 - i;
    }
}

int fillArr3(char *array1, char *array2, char *array3){
    int num=0;
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            if(array1[i]==array2[j]){
                array3[num]=array1[i];
                num++;
            }
        }
    }
    return num;
}

void printArr(char *array1, int number){
    for(int i=0; i<number; i++){
        printf("%d  ", array1[i]);
    }
}

