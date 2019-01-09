#include <cs50.h>
#include <stdio.h>

void hashtag_matrix2(int num_row){
    
    int num_col = 2*num_row+2;
    char Hashtags[num_col];
    
    for(int line=0; line<num_row; line++){
        //left matrix
        for(int col=0; col<num_row; col++){
            int linepluscol =line+col;
            if( linepluscol<num_row-1 ){
                Hashtags[col]=' ';
            }else{
                Hashtags[col]='#';
            }
        }
        //middle of matrix
        for(int col=num_row; col<num_row+2; col++){
            Hashtags[col]=' ';
        }
        //right matrix
        for(int col=num_row+2; col<num_col; col++){
            if( (col-num_row-2) <=line ){
                Hashtags[col]='#';
            }else{
                Hashtags[col]=' ';
            }
        }
       
        printf("%s\n", Hashtags);
    }
}

int main(void){
    int height = get_int("Height: ");
    if (height>0){
        hashtag_matrix2(height);
    }
}