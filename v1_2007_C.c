#include <stdio.h>

int resh(int number){
    if (((number + 2) % 4) == 0){
        return 0;
    }
    else{
        if ((number == 4)||(number == 1)){
            return 1;
        }
        else{
            if (((number - 1) % 4) == 0){
                return resh((number - 1) / 4);
            }
            else{
                if ((number % 4) == 0){
                    return resh((number) / 4);
                }
                else{
                    return resh((number + 1) / 4);
                }
            }
        }
    }
}

void printAnswer(int boolean){
    if (boolean){
        printf("YES\n");
    }
    else{
        printf("NO\n");
    }
}

int scanNumber(void){
    int number = 0;
    scanf("%d", &number);
    return number;
}

int main(){
    int num = 0, boolean;
    printf("Waiting for number...\n");

    num = scanNumber();
    boolean = func_Unnamed(num);
    printAnswer(boolean);

    system("pause");
    return 0;
}