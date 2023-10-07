#include <stdio.h>
#include <conio.h>
#include <string.h>

char input_check(int *, char[]);

int main() {
    int exit;
    char validation;
    char order;

    do{
        int amount_rows, row_length;

        input_check(&amount_rows, "amount of rows");
        input_check (&row_length, "row length");

        char array[amount_rows][row_length +1];

        for(int i=0; i < amount_rows; i++){
            printf("\n <--%d-->", i +1 );

            char elements[row_length + 1];

            while (scanf("%s%c", &elements, &validation) !=2 || validation !='\n' || elements[row_length] != '\0') {
                printf("invalid input\n");
                printf("\n <--%d-->", i + 1);
            }

            for(int j=0; j < row_length + 1; j++){
                array[i][j]=elements[j];
            }
        }

        char *result[amount_rows];

        for(int i=0; i < amount_rows; i++){
            result[i]=array[i];
        }

        for(int i=0; i < amount_rows - 1; i++){
            for(int j= i+1; j < amount_rows; j++){
                if(strcmp(result[i], result[j]) > 0){
                    char *temp= result[i];
                    result[i] = result[j];
                    result[j] = temp;
                }
            }
        }

        printf("In what order do you want to sort the array? [decreasing or increasing][press d/i]");
        scanf("%c", &order) ;
        if(order == 'd' || order == 'D'){
            printf("\n\n");
            for(int i = amount_rows-1; i > -1; i--){
                printf("-->%s\n", result[i]);
            }
        } else if(order == 'i' || order == 'I'){
            printf("\n\n");
            for(int i = 0; i < amount_rows; i++){
                printf("-->%s\n", result[i]);
            }
        }

        printf("\nPress n or N if you don't want to continue\n");

        exit = getch();
    }while(exit != 78 && exit != 110);

    return 0;
}


char input_check(int *var, char var_name[]) {

    char validation;

    printf("Enter %s:", var_name);
    while (scanf("%d%c", &*var, &validation) != 2 || validation != '\n' || *var < 1 || *var > 32767) {
        printf("invalid input\n\n");
        fflush(stdin);
        printf("Enter %s:", var_name);
    }
}
