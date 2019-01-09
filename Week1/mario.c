#include <cs50.h>
#include <stdio.h>

void hashtag_matrix(int C){//C = number of columns
    
    char Hashtags[C][C];
    for(int i=0; i<C; i++){
        
        for(int j=0; j<C; j++){
            if( (i+j)>=C-1 ){
                Hashtags[i][j]='#';
            }else{
                Hashtags[i][j]=' ';
            }
        }
       
        printf("%s\n", Hashtags[i]);
    }
}

int main(void){
    
    int h = get_int("Height: ");
    if(h>0){
        hashtag_matrix(h);   
    }else{
        printf("Mario: Enter a number greater than 0!\n");
    }
}