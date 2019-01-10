#include <cs50.h>
#include <stdio.h>

void cashback();

int main(void){
    float owe = get_float("Change owed: ");
    int penny = (int)(owe*100);
    if (penny>0){
        cashback(penny);
    }else{
        printf("foo\n");
    }
}

void cashback(int p){
    int numberOfCointyp = 4;
    int cointyp[4] = {25, 10, 5, 1};
    int numberOfCoints = 0;
    for (int i=0; i<numberOfCointyp && p>0; i++){
        numberOfCoints = numberOfCoints + p / cointyp[i];
        p = p%cointyp[i];
    }
    printf("%i\n", numberOfCoints);
}