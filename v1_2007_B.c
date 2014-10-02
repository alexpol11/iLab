#include <stdio.h>

int findDelit(int number){
    int i = 2, boolSqr = -1;
    while (i != (number / 2 + 1)){
        if ((number % i) == 0){
            number /= i;
            boolSqr++;
            if (boolSqr == 1){
                return 1;
            }
        } else{
            boolSqr = -1;
            i++;
        }
    }
    return 0;
}

int scanNumber(){
    int number = 0;

    printf("Waiting for number...\n");
    scanf("%d", &number);
    return number;
}

void printAnswer(int boolSqr){
    if (boolSqr){
        printf("YES\n");
    }
    else{
        printf("NO\n");
    }
}

int main(){
    
    int number = 0, boolSqr;

    number = scanNumber();
    boolSqr = findDelit(number);
    printAnswer(boolSqr);

    system("pause");
    return 0;
}