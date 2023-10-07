#include <stdio.h>


const char *days[] ={"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};

int main() {
    int date, month, year;
    char validation, n,  exit;
    do {

        printf("date=");
        if (scanf("%d%c", &date, &validation) != 2 || validation != '\n') {
            printf("enter number without symbol\n");
            continue;
        }
        if (date > 31){
            printf("enter a number less than 31\n");
            continue;
        }

        printf("month=");
        if (scanf("%d%c", &month, &validation) != 2 || validation != '\n') {
            printf("enter number without symbol\n");
            continue;
        }
        if (month > 12){
            printf("enter a number less than 12\n");
            continue;
        }
        if (month == 4 || month == 6 || month == 9 || month == 11){
            if (date > 30){
                printf("invalid day\n");
                continue;
            }
        } else if (month == 2){
            if ((year%100 !=0 && year % 4 ==0 || year % 100 == 0 && year % 400 ==0) && date > 29){
                printf("a leap year has fewer days\n");
                continue;
            } else if (date > 28){
                printf("a leap year has fewer days\n");
                continue;
            }
        }




        printf("year=");
        if (scanf("%d%c", &year, &validation) != 2 || validation != '\n') {
            printf("enter number without symbol\n");
            continue;
        }
        if (year > 9999 || year < 0000){
            printf("enter a year between 0000 and 9999\n");
            continue;
        }




        if (month > 2) {
            n=0;
        }
        if (month <= 2){
            if (year%100 !=0 && year % 4 ==0 || year % 100 == 0 && year % 400 ==0){
                n=1;
            } else {
                n = 2;
            }
        }


        char day= ((int)(365.25 * year) + (int)(30.56 * month) + date + n) % 7;

        printf("day of week %s\n", days[day]);


        printf("Press n or N if you don't want to continue\n");

        exit = getchar();

        fflush(stdin);
    }while(exit != 'n' && exit != 'N');

    return 0;
}

