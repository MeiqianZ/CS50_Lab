#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

void vigeneresCipher(int Key[], int length);

int main(int argc, string argv[]){
    
    if ( argc != 2 ){
        
        printf("Usage: ./vigenere keyword\n");
    } else {
        
        bool keyword = true;
        int Input[strlen(argv[1])];
        int keywordLength = strlen(argv[1]);
        for ( int keywordIndex = 0 ; keywordIndex < keywordLength ; keywordIndex++ ){
            
            Input[keywordIndex] = (int) argv[1][keywordIndex];
            if ( 65 <= Input[keywordIndex]  &&  Input[keywordIndex] <= 90 ){
                
                Input[keywordIndex] = Input[keywordIndex] - 65;
            } else if ( 97 <= Input[keywordIndex]  &&  Input[keywordIndex] <= 122 ){
                
                Input[keywordIndex] -= 97;
            } else {
                
                keyword = false;
                printf("Usage: ./vigenere keyword\n");
                break;
            }
        }
        
        if ( keyword ){
            
            vigeneresCipher(Input, keywordLength); 
        }
    }
}

void vigeneresCipher(int Key[], int keywordLength){
    
    string plaintext = get_string("plaintext: ");
    int pLength = strlen(plaintext);
    printf("pLength: %i\n", pLength);
    int plain[pLength];
    char ciphertext[pLength+1];//end with '\0'
    int plainIndex;
    for ( plainIndex = 0 ; plaintext[plainIndex] != 0 ; plainIndex++ ){
        
        //to ASCII Code
        plain[plainIndex] = (int) plaintext[plainIndex];
        
        //wrapping around alphabetically with reuse of keys
        if ( 65 <= plain[plainIndex]  &&  plain[plainIndex] <= 90 ){
            
            plain[plainIndex] = (plain[plainIndex] - 65 + Key[plainIndex%keywordLength]) % 26 + 65;
        } else if ( 97 <= plain[plainIndex]  &&  plain[plainIndex] <= 122 ){
            
            plain[plainIndex] = (plain[plainIndex] - 97 + Key[plainIndex%keywordLength]) % 26 + 97;
        }
        
        ciphertext[plainIndex] = (char) (plain[plainIndex]); 
    }
    
    ciphertext[plainIndex] = '\0';
    printf("ciphertext: %s\n", ciphertext);
}
 
