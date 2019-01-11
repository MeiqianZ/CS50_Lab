#include <cs50.h>
#include <stdio.h>
#include <math.h>

void whichCard();
void Print(char);
int numberLength();
bool LuhnsAlg();

int main(void){
    
    long number = get_long("Number: ");
    int length = numberLength(number);
    whichCard(number, length);
    
}
void whichCard(long number, int len){
    int numOfAmerican = 15;
    int numOfMasterOrVisa = 16;
    int numOfVisa = 13;
    if (len==numOfAmerican || len==numOfMasterOrVisa || len==numOfVisa){
        
        //long to string
        char cache[len];
        sprintf(cache,"%ld",number);
        bool strToInt = false;
        char Textbegin;
        
        //All American Express numbers start with 34 or 37
        if (len==numOfAmerican && cache[0]=='3'&& (cache[1]=='4' || cache[1]=='7')){
            strToInt = true;
            Textbegin = 'A';
        }else if (len==numOfMasterOrVisa){
            strToInt = true;
            if (cache[0]=='4'){
                Textbegin = 'V';
            }else{
                Textbegin = 'M';
            }
        }else if (len==numOfVisa && cache[0]=='4'){
            strToInt = true;
            Textbegin = 'V';
        }else{
            Print('I');
        }
        
        //string to int array and check Luhn's Algorithm
        if (strToInt){
            int numeral[len];
            for (int i=0; i<len; i++){
                numeral[i] = (int)cache[i]-48; //char 0..9 = int 48..57
            }
            if (LuhnsAlg(numeral, len)){
                Print(Textbegin);
            }else{
                Print('I');
            }
        }
        
    }else{
            Print('I');
    }
}

void Print(char textbegin){
    if (textbegin=='A'){
        printf("AMEX\n");
    }else if (textbegin=='M'){
        printf("MASTERCARD\n");
    }else if (textbegin=='V'){
        printf("VISA\n");
    }else if (textbegin=='I'){
        printf("INVALID\n");
    }
}

int numberLength(long num){
    double x;
    int length = 0;
    for (int i=12; i<=16; i++){
        x  = pow(10, i);
        if (num < x){
            length = i;
            break;
        }
    }
    return length;
}

bool LuhnsAlg(int Numeral[], int len){
    int sum = 0;
    int endsum = 0;
    int prod;
    //  example
    //  | | | | | | | | | | |  |  |  | len=13
    //   0 1 2 3 4 5 6 7 8 9 10 11 12
    //   | |                    |  |
    //   | len-i_max1-1=13-12   |  len-i_min2=13-1 
    //   len-i_max2=13-13       len-i_min1-1=13-2
    //1.
    for (int i = 2; i<=len; i+=2){
        prod = 2 * Numeral[len-i];//starting with the number’s second-to-last digit
        //6->2*6->12->1+2+sum instead of 12+sum
        if (prod<10){
            sum = prod + sum;
        }else{
            sum = prod%10 + 1 + sum;
        }
    }

    //2.
    for (int i = 1; i<=len; i+=2){
        endsum = Numeral[len-i] + endsum;
    }
    endsum = sum + endsum;

    //3. End of endsum is 0?
    endsum = endsum%10;
    if (endsum==0){
        return 1;
    }else{
        return 0;
    }
}
