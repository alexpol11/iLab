#include <stdio.h>
#include <math.h>

struct Cisla {
    double a;
    double b;
    double c;
};

struct Korni
{
    double x1;
    double x2;
    short numAnswers;
};

void printKorni(struct Korni otv){
    switch (otv.numAnswers){
    case 0: printf("NO\n");
        break;
    case 1: printf("x = %lg\n", otv.x1);
        break;
    case 2: printf("x1 = %lg x2 = %lg\n", otv.x1, otv.x2);
        break;
    case 3: printf("R\n");
        break;
    default:break;
    }
}



struct Cisla scanKoeff(struct Cisla koeff){
    printf("Ax^2 + Bx + C = 0\nWaiting for A, B, C...\n");
    scanf("%lg %lg %lg", &koeff.a, &koeff.b, &koeff.c);
    return koeff;
}

struct Korni resh(struct Cisla koeff){
    struct Korni temp;
    temp.numAnswers = 0;
    temp.x1 = 0;
    temp.x2 = 0;

    if (koeff.a == 0){
        if (koeff.b == 0){
            if (koeff.c == 0){
                temp.numAnswers = 3;
            }
            else{
                temp.numAnswers = 0;
            }
        }
        else{
            temp.x1 = -koeff.c / koeff.b;
            temp.numAnswers = 1;
        }
    }
    else{
        double d = koeff.b*koeff.b - 4 * koeff.a*koeff.c;
        if (d < 0){
            temp.numAnswers = 0;
        }
        if (d == 0){
            temp.x1 = -koeff.b / (2 * koeff.a);
            temp.numAnswers = 1;
        }
        if (d > 0){
            temp.x1 = (-koeff.b + sqrt(d)) / (2 * koeff.a);
            temp.x2 = (-koeff.b - sqrt(d)) / (2 * koeff.a);
            temp.numAnswers = 2;
        }
    }

    return temp;
}

int main(){
    struct Cisla koeff;
    koeff.a = 0;
    koeff.b = 0;
    koeff.c = 0;

    struct Korni otv;
    otv.x1 = 0;
    otv.x2 = 0;
    otv.numAnswers = 0;

    koeff = scanKoeff(koeff);
    otv = resh(koeff);

    printKorni(otv);
    return 0;
}