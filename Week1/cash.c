#include <cs50.h>
#include <stdio.h>

void cashback(int);

int main(void){
    
    float oweChange;
    float scaling_factor = 100.0;
    do {
        oweChange = get_float("Change owed: ");
    } while ( oweChange <= 0 );
    
    int returnPenny = (int) (oweChange * scaling_factor);
    cashback(returnPenny);
}

void cashback(int returnPenny){

    int numberOfCoinTyp = 4;
    int quarters = 25;
    int dimes = 10;
    int nickels = 5;
    int pennies = 1;
    int coinTyp[] = { quarters, dimes, nickels, pennies };
    int amountOfReturnCoins = 0;
    for ( int coinTypeIndex = 0 ; coinTypeIndex < numberOfCoinTyp && returnPenny > 0 ; coinTypeIndex++ ){

        amountOfReturnCoins +=  returnPenny / coinTyp[coinTypeIndex];
        returnPenny %= coinTyp[coinTypeIndex];
    }

    printf("%i\n", amountOfReturnCoins);
}
 
