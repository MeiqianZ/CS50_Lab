#include <cs50.h>
#include <stdio.h>

void hashtag_matrix(int matrixSize){
    
    char Hashtags[matrixSize+1];
    for ( int row = 0 ; row < matrixSize ; row++ ){

        int column;
        for ( column = 0 ; column < matrixSize ; column++ ){

            if ( (row+column) >= matrixSize-1 ){

                Hashtags[column] = '#';
            } else {
                
                Hashtags[column] = ' ';
            }
        }
        Hashtags[column] = '\0';
        printf("%s\n", Hashtags);
    }
}

int main(void){
    
    int height = get_int("Height: ");
    if ( height > 0 ){

        hashtag_matrix(height);   
    } else {

        printf("Mario: Enter a number greater than 0!\n");
    }
}
 
