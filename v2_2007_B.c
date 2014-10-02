#include <stdio.h>
#include <math.h>

int findB(int number){
    int i =  sqrt(number);
    while (i != 1){
        if ((number % (i*i)) == 0){
            return i;
        }
        i--;
    }
    return i;
}

int scanNumber(){
    int number = 0;

    printf("Waiting for number...\n");
    scanf("%d", &number);
    return number;
}

void printAnswer(int a, int b){
    printf("%d %d\n", a, b);
}

int findA(int number, int b){
    return (number / (b*b));
}

int main(){
    
    int number = 0, a = 0, b = 0;

    number = scanNumber();
    b = findB(number);
    a = findA(number, b);
    printAnswer(a, b);

    system("pause");
    return 0;
}