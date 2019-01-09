#include <cs50.h>
#include <stdio.h>

void hashtag_matrix2(int num_row){
    
    int num_col = 2*num_row+2;
    char Hashtags[num_row][num_col];
    
    for(int line=0; line<num_row; line++){
        //left matrix
        for(int col=0; col<num_row; col++){
            if( (line+col)>=num_row-1 ){
                Hashtags[line][col]='#';
            }else{
                Hashtags[line][col]=' ';
            }
        }
        //middle of matrix
        for(int col=num_row; col<num_row+2; col++){
            Hashtags[line][col]=' ';
        }
        //right matrix
        for(int col=num_row+2; col<num_col; col++){
            if( (col-num_row-2) <=line ){
                Hashtags[line][col]='#';
            }else{
                Hashtags[line][col]=' ';
            }
        }
       
        printf("%s\n", Hashtags[line]);
    }
}

int main(void){
    printf("Height: ");
    int height = get_int();
    if (height>0){
        hashtag_matrix2(height);
    }
}
