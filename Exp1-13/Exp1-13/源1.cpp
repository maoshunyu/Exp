#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)
int main() {
    enum week { Mon = 1, Tues, Wed, Thurs, Fri, Sat, Sun } day;
    scanf("%d", &day);
    switch (day) {
    case Mon: puts("Monday"); break;
    case Tues: puts("Tuesday"); break;
    case Wed: puts("Wednesday"); break;
    case Thurs: puts("Thursday"); break;
    case Fri: puts("Friday"); break;
    case Sat: puts("Saturday"); break;
    case Sun: puts("Sunday"); break;
    default: puts("Error!");
    }
    return 0;

}
