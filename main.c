#include <stdio.h>
#include <stdbool.h>
#include <conio.h>
#include <stdlib.h>

int days[] = {31,28,31,30,31,30,31,31,30,31,30,31};
char* months[] = {"January","February","March","April","May","June","July",
        "August","September","October","November","December"};
char * week[] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};

bool isLeapYear (int year) {
    if (year%4 == 0 && year%400 == 0 || year%100!=0) return true;
    return false;
}

// formula from:
// https://faculty.cs.niu.edu/~hutchins/csci297p2/webpages/zeller.htm
int zellerAlgo (int day, int month, int year) {
    int A, B, C, D, W, X, Y, Z, R, NewYear;
    if (month < 3) {
        A = month + 10;
        NewYear = year - 1;
    }
    else {
        A = month - 2;
        NewYear = year;
    }
    B = day;
    C = NewYear % 100; // century
    D = NewYear / 100;
    W = (13 * A - 1) / 5;
    X = C / 4;
    Y = D / 4;
    Z = W + X + Y + B + C - 2 * D;
    R = Z % 7;
    if (R < 0) R += 7;
    return R;
}

int printCalendar(int month, int year) {
    int start = zellerAlgo(1, month, year);
    printf("\n\nSun   Mon  Tue  Wed  Thu  Fri  Sat\n");
    for (int i = 0; i <= start * 5; i++) {
        printf(" ");
    }
    for (int day = 1; day <= days[month-1]; day++) {
        printf("%2d", day);
        if ((day + start) % 7 > 0) {
            printf("   ");
        }
        else {
            printf("\n ");
        }
    }
    return 0;
}

int main() {
    int month, year;
    printf("\n\nEnter the month: ");
    scanf("%d", &month);
    printf("\nEnter the year: ");
    scanf("%d", &year);
    
    top:
    printf("Year: %d Mont: %d", year, month);
    printCalendar(month, year);
    printf("\n\nNext month [Type 2]\nPrevious Month [Type 1]\nExit [Type 0]\n");
    int next;
    scanf("%d", &next);
    if (next == 2) {
        if (month == 12) {
            month = 1;
            year++;
        }
        else {
            month++;
        }
        goto top;
    }
    if (next == 1) {
        if (month == 1) {
            month = 12;
            year--;
        }
        else {
            month--;
        }
        goto top;
    }
    if (next == 0) {
        exit(0);
    }

    return 0;
}