#include <cs50.h>
#include <stdio.h>
#include <math.h>

void whichCreditCard(long, int);
void printWhichCard(char);
int calculateLengthOfCreditCardNumber(long);
bool LuhnsAlg(int digit[], int lengthOfCreditCardNumber);


int main(void){
    
    long number = get_long("Number: ");
    int lengthOfCreditCardNumber = calculateLengthOfCreditCardNumber(number);
    whichCreditCard(number, lengthOfCreditCardNumber);
    
}

void whichCreditCard(long number, int lengthOfCreditCardNumber){
    
    int numOfAmerican = 15;
    int numOfMasterOrVisa = 16;
    int numOfVisa = 13;
    
    // for 1..12 digits is lengthOfCreditCardNumber=12 and for 0 or from 17 digits is lengthOfCreditCardNumber=0, so invalid
    if ( lengthOfCreditCardNumber == 0  ||  lengthOfCreditCardNumber == 12 || lengthOfCreditCardNumber == 14 ){
        
        printWhichCard('I');
    } else {
     
        //long to char array to int array 
        char numberInChar[lengthOfCreditCardNumber+1];
        sprintf(numberInChar,"%ld"+0,number);
        int digit[lengthOfCreditCardNumber];
        for ( int num_position = 0 ; num_position < lengthOfCreditCardNumber && numberInChar[num_position] != 0 ; num_position++ ){
            
            digit[num_position] = (int)numberInChar[num_position]-48;//char 0..9 = int 48..57;
        }
        
        //Check Step 1: first Character
        char firstCharacter = 0;
        //All American Express numbers start with 34 or 37
        if ( lengthOfCreditCardNumber == numOfAmerican  &&  digit[0] == 3  &&  ( digit[1] == 4  ||  digit[1] == 7 ) ){ 
            
            firstCharacter = 'A';
        } else if ( lengthOfCreditCardNumber == numOfMasterOrVisa ){
            
            //All Visa numbers start with 4
            if ( digit[0] == 4 ){
                
                firstCharacter = 'V';
            } else {
                
                firstCharacter = 'M';
            }
        } else if ( lengthOfCreditCardNumber == numOfVisa  &&  digit[0] == 4 ){ //All Visa numbers start with 4
            
            firstCharacter = 'V';
        } else {
            
            printWhichCard('I');
        }
        
        //check Luhn's Algorithm
        if ( firstCharacter != 0 ){
             if ( LuhnsAlg(digit, lengthOfCreditCardNumber) ){
                 
                printWhichCard(firstCharacter);
             } else {
                 
                printWhichCard('I');
            }
        }     
    }   
}

void printWhichCard(char firstCharacter){
    
    if ( firstCharacter == 'A' ){
        printf("AMEX\n");
    } else if ( firstCharacter == 'M' ){
        printf("MASTERCARD\n");
    } else if (firstCharacter == 'V' ){
        printf("VISA\n");
    } else if ( firstCharacter == 'I' ){
        printf("INVALID\n");
    }
}

int calculateLengthOfCreditCardNumber(long number){
    
    long digitToCompare;
    int length = 0;
    int startDigit = 12;
    int endDigit = 16;
    for ( int i = startDigit ; i <= endDigit ; i++ ){
        
        digitToCompare  = pow(10, i);
        //9999 9999 9999 9999 < 1 0000 0000 0000 0000 = 10^16 number is 16 digits 
        //or 9 < 1 0000 0000 0000 = 10^12 number is less than 12 digits
        //length = 0 from 17 digits
        if ( number < digitToCompare ){
            
            length = i;
            break;
        }
    }
    return length;
}

bool LuhnsAlg(int digit[], int lengthOfCreditCardNumber){
    
    int sum = 0;
    int endsum = 0;
    int prod;
    //  example
    //  | | | | | | | | | | |  |  |  | len=13
    //   0 1 2 3 4 5 6 7 8 9 10 11 12
    //   | |                    |  |
    //   | len-i_max1-1=13-12   |  len-i_min2=13-1 
    //   len-i_max2=13-13       len-i_min1-1=13-2
    //
    //step 1
    for ( int i = 2 ; i <= lengthOfCreditCardNumber ; i += 2 ){
        
        //starting with the number’s second-to-last digit
        prod = 2 * digit[lengthOfCreditCardNumber-i];
        //6->2*6->12->1+2+sum instead of 12+sum
        if ( prod < 10 ){
            
            //sum single digit result of prod 
            sum += prod;
        } else {
            
            //sum two digit of prod separated. max of prod is 2*9=18, so is 18%10 + 1
            sum += prod%10 + 1;
        }
    }

    //step 2
    for ( int i = 1 ; i <= lengthOfCreditCardNumber ; i += 2 ){
        
        endsum += digit[lengthOfCreditCardNumber-i];
    }
    endsum += sum;

    //step 3: End of endsum is 0?
    endsum %= 10;
    if ( endsum == 0 ){
        
        return 1;
    } else {
        
        return 0;
    }
}
 
