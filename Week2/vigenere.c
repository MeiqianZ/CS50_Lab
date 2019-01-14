 #include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int key();
void vigeneresCipher();

int main(int argc, string argv[])
{
    if (argc==2){
        
        bool alphabet = true;
        int Input[strlen(argv[1])];
        int length = strlen(argv[1]);
        
        for (int j=0; j<length; j++){
            
            Input[j] = (int)argv[1][j];
            
            if (65<=Input[j] && Input[j]<=90){
                Input[j] = Input[j]-65;
            }else if(97<=Input[j] && Input[j]<=122){
                Input[j] = Input[j]-97;
            }else{
                alphabet = false;
                printf("Usage: ./vigenere keyword\n");
                break;
            }
        }
        
        if (alphabet){
            vigeneresCipher(Input, length); 
        }
        
    }else{
        printf("Usage: ./vigenere keyword\n");
    }
}

void vigeneresCipher(int Key[], int Len){
    
    string plaintext = get_string("plaintext: ");
    int pLength = strlen(plaintext);
    int plain[pLength];
    char ciphertext[pLength];
    
    for(int i=0; i<pLength; i++){
        
        //to ASCII Code
        plain[i] = (int)plaintext[i];
        
        //wrapping around alphabetically with reuse of keys
        if (65<=plain[i] && plain[i]<=90){
            plain[i] = (plain[i]-65+Key[i%Len])%26+65;
        }else if (97<=plain[i] && plain[i]<= 122){
            plain[i] = (plain[i]-97+Key[i%Len])%26+97;
        }
        
        ciphertext[i] = (char)(plain[i]); 
    }
    printf("ciphertext: %s\n", ciphertext);
}
