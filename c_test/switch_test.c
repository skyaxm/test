#include<stdio.h>
#include<stdlib.h>

enum day {
    Monday,
    Tuesday,
    Wednesday,
    Thusday,
    Friday,
    Saturday,
    Sunday
};

int main()
{
    enum day a;
    a = Friday;
    printf("%d\n", a);

    switch(a){
        case 0:
            printf("Monday\n");
            //break;
        case 1:
            printf("Tuesday\n");
            //break;
        case 2:
            printf("Wednesday\n");
            //break;
        case 3:
            printf("Thusday\n");
            //break;
        case 4:
            printf("Friday\n");
            //break;
        case 5:
            printf("Saturday\n");
            //break;
        case 6:
            printf("Sunday\n");
            //break;
        default:
            printf("Noday\n");
            //break;
    }

    return 0;
}
