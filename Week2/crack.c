#define _XOPEN_SOURCE
#include <unistd.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

/*
 * brian:51.xJagtPnb6s--->TF
 * bjbrown:50GApilQSG3E2--->UPenn
 * emc:502sDZxA/ybHs--->puppy
 * greg:50C6B0oz0HWzo--->FTW
 * jana:50WUNAFdX/yjA--->Yale
 * lloyd:50n0AAUD.pL8g--->lloyd
 * malan:50CcfIk1QrPr6--->maybe
 * natmelo:50JIIyhDORqMU--->nope
 * rob:51v3Nh6ZWGHOQ--->ROFL
 * veronica:61v1CDwwP95bY--->hola
 * walker:508ny6Rw0aRio--->sean
 * zamyla:50cI2vYkF0YU2--->LOL
 * */

int main(int argc, string argv[]){
    
    if ( argc != 2 ){
        
        printf("Usage: ./crack HashedPassword\n");
        return 1; //with main returning 1 (thereby signifying an error).       
    } else {
        
        //password is no longer than five: a\0\0\0\0\0-ZZZZZ\0
        //string letters = "\0abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
        //letter frequency
        string letters = "\0eEtTaAoOiInNsShHrRdDlLcCuUmMwWfFgGyYpPbBvVkKjJxXqQzZ";//e\0\0\0\0\0-ZZZZZ\0
        int let_length = 53;//1+26+26 '\0'+letters
        char salt[3] = {argv[1][0], argv[1][1], '\0'};
        // a\0\0\0\0\0-ZZZZZ\0->6
        char key[6] = "\0\0\0\0\0\0";
        
        for ( int pos5 = 0 ; pos5 < let_length ; pos5++ ){//from \0
            for ( int pos4 = 0 ; pos4 < let_length ; pos4++ ){//from \0
                for ( int pos3 = 0 ; pos3 < let_length ; pos3++ ){//from \0
                    for ( int pos2 = 0 ; pos2 < let_length ; pos2++ ){//from \0
                        for ( int pos1 = 1 ; pos1 < let_length ; pos1++ ){//from a
                            
                            //password is no longer than five (5) characters
                            key[0] = letters[pos1];
                            key[1] = letters[pos2];
                            key[2] = letters[pos3];
                            key[3] = letters[pos4];
                            key[4] = letters[pos5];
                            
                            //Compare created encryption with encryption of command line
                            if ( strcmp(crypt(key,salt), argv[1]) == 0 ){
                                
                                printf("%s\n", key);
                                return 0;
                            }
                        }
                    }
                }
            }
        }
        
        printf("Not found!\n");
        return 2;
    }
}
 
