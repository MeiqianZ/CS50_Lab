#include <cs50.h>
#include <stdio.h>

bool leftLowerTriangularOfRightMatrix(int, int, int);

void hashtag_matrix2(int num_row){
    
    int num_col = 2 * num_row + 2;
    char Hashtags[num_col+1];   
    for ( int row = 0 ; row < num_row ; row++ ){
        
        int leftMatrixStart = 0;
        int midMatrixStart = num_row;
        int rightMatrixStart = num_row + 2;
        int col;
        
        //left matrix
        for ( col = leftMatrixStart ; col < midMatrixStart ; col++ ){
            
            int rowPlusCol = row + col;
            if ( rowPlusCol  <  num_row - 1 ){
                
                Hashtags[col] = ' ';
            } else {
                
                Hashtags[col] = '#';
            }
        }
        
        //middle of matrix
        for ( col = midMatrixStart ; col < rightMatrixStart ; col++ ){
            
            Hashtags[col] = ' ';
        }
        
        //right matrix
        for ( col = rightMatrixStart ; col < num_col ; col++ ){
            
            if ( leftLowerTriangularOfRightMatrix(col, num_row, row) ){
                
                Hashtags[col] = '#';
            } else {
                
                Hashtags[col] = ' ';
            }
        }
        Hashtags[col] = '\0';
        printf("%s\n", Hashtags);
    }
}

bool leftLowerTriangularOfRightMatrix(int col, int num_row, int row){
    
    int colRightMatrix = col - num_row - 2;
    if ( colRightMatrix <= row ){
        
        return 1;
    } else {
        
        return 0;
    }
}

int main(void){
    
    int height;
    do {
        
        height = get_int("Height: ");
    } while ( height <= 0  ||  height > 8 ); //only from 1 to 8
        
    hashtag_matrix2(height);
}
