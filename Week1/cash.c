#include <cs50.h>
#include <stdio.h>

void cashback(int);

int main(void){
    
    float oweChange;
    do {
        oweChange = get_float("Change owed: ");
    } while ( oweChange <= 0 );
    
    int returnPenny = (int) (oweChange * 100);
    cashback(returnPenny);
}

void cashback(int returnPenny){

    int numberOfCoinTyp = 4;
    int coinTyp[4] = {25, 10, 5, 1};
    int amountOfReturnCoints = 0;
    for ( int i=0; i<numberOfCoinTyp && returnPenny>0; i++ ){

        amountOfReturnCoints +=  returnPenny / coinTyp[i];
        returnPenny %= coinTyp[i];
    }

    printf("%i\n", amountOfReturnCoints);
}
