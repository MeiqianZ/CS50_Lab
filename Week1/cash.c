#include <cs50.h>
#include <stdio.h>

void cashback(int);

int main(void){

    float owe = get_float("Change owed: ");
    int returnPenny = (int)(owe*100);
    if (returnPenny>0){

        cashback(returnPenny);
    }else{

        printf("foo\n");//requires
    }
}

void cashback(int returnPenny){

    int numberOfCoinTyp = 4;
    int coinTyp[numberOfCoinTyp] = {25, 10, 5, 1};
    int amountOfReturnCoints = 0;
    for (int i=0; i<numberOfCoinTyp && returnPenny>0; i++){

        amountOfReturnCoints +=  returnPenny / coinTyp[i];
        returnPenny %= cointyp[i];
    }

    printf("%i\n", amountOfReturnCoints);
}
