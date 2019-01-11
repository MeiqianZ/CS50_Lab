#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int key();
void caesarsCipher();

int main(int argc, string argv[])
{
    if (argc==2){
        
        bool numeral = true;
        int Input[strlen(argv[1])];
        int length = strlen(argv[1]);
        
        for (int j=0; j<length; j++){
            
            Input[j] = (int)argv[1][j];
            
            if (48<=Input[j] && Input[j]<=57){
                Input[j] = Input[j]-48;
            }else{
                numeral =false;
                printf("Usage: ./caesar key\n");
                break;
            }
        }
        
        if (numeral){
            caesarsCipher(key(Input, length)); 
        }
        
    }else{
        printf("Usage: ./caesar key\n");
    }
}

int key(int inp[], int len){
    int k=0;
    for (int i=1; i<=len; i++){
        k = inp[len-i]*pow(10,i-1)+k;
    }
    return k;
}

void caesarsCipher(int Key){
    
    string plaintext = get_string("plaintext: ");
    int pLength = strlen(plaintext);
    int plain[pLength];
    char ciphertext[pLength];
    
    for(int i=0; i<pLength; i++){
        
        plain[i] = (int)plaintext[i];
        
        //wrapping around alphabetically
        if (65<=plain[i] && plain[i]<=90){
            plain[i] = (plain[i]-65+Key)%26+65;
        }else if (97<=plain[i] && plain[i]<= 122){
            plain[i] = (plain[i]-97+Key)%26+97;
        }
        
        ciphertext[i] = (char)(plain[i]); 
    }
    printf("ciphertext: %s\n", ciphertext);
}
