#include <cs50.h>
#include <stdio.h>

void hashtag_matrix(int Col){//Col = number of columns
    
    char Hashtags[Col][Col];
    for(int i=0; i<Col; i++){
        
        for(int j=0; j<Col; j++){
            if( (i+j)>=Col-1 ){
                Hashtags[i][j]='#';
            }else{
                Hashtags[i][j]=' ';
            }
        }
       
        printf("%s\n", Hashtags[i]);
    }
}

int main(void){
    
    int height = get_int("Height: ");
    if(height>0){
        hashtag_matrix(height);   
    }else{
        printf("Mario: Enter a number greater than 0!\n");
    }
}