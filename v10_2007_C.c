#include <stdio.h>
#include <math.h>

int findSlog(int number){
    int i =  sqrt(number);

    return i*i;
}

int scanNumber(){
    int number = 0;

    printf("Waiting for number...\n");
    scanf("%d", &number);
    return number;
}

void printAnswer(int a, int b, int c, int d){
    if (a == 0){
        printf("%d %d %d\n", b, c, d);
    }else printf("-1");
}

int findA(int number, int b){
    return (number / (b*b));
}

int main(){
    
    int number = 0, a = 0, b = 0, c = 0, d = 0;

    number = scanNumber();
    d = findSlog(number);
    c = findSlog(number - d);
    b = findSlog(number - c - d);
    a = findSlog(number - b - c - d);
    printAnswer(a, b, c , d);

    system("pause");
    return 0;
}