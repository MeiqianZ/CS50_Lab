#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int key(int Input[], int length);
void caesarsCipher(int Key);

int main(int argc, string argv[]){
    
    if ( argc != 2 ){
        
        printf("Usage: ./caesar key\n");
    } else {
        
        bool numeral = true;
        int Input[strlen(argv[1])];
        int length = strlen(argv[1]);
        
        for ( int inputIndex = 0 ; inputIndex < length ; inputIndex++ ){
            
            Input[inputIndex] = (int) argv[1][inputIndex];
            
            if ( 48 <= Input[inputIndex]  &&  Input[inputIndex] <= 57 ){
                
                Input[inputIndex] = Input[inputIndex] - 48;
            } else {
                
                numeral = false;
                printf("Usage: ./caesar key\n");
                break;
            }
        }
        
        if ( numeral ){
            
            caesarsCipher(key(Input, length)); 
        }
    } 
}

int key(int Input[], int length){
    
    int Key = 0;
    for ( int i = 1 ; i <= length ; i++ ){
        
        Key = Input[length-i] * pow(10,i-1) + Key;
    }
    return Key;
}

void caesarsCipher(int Key){
    
    string plaintext = get_string("plaintext: ");
    int pLength = strlen(plaintext);
    int plain[pLength];
    char ciphertext[pLength];
    
    for ( int i = 0 ; i < pLength ; i++ ){
        
        plain[i] = (int) plaintext[i];
        
        //wrapping around alphabetically
        if ( 65 <= plain[i]  &&  plain[i] <= 90 ){
            
            plain[i] = (plain[i] - 65 + Key) % 26 + 65;
        } else if ( 97 <= plain[i]  &&  plain[i] <= 122 ){
            
            plain[i] = (plain[i] - 97 + Key) % 26 + 97;
        }
        
        ciphertext[i] = (char)(plain[i]); 
    }
    printf("ciphertext: %s\n", ciphertext);
}
 
