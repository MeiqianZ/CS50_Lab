#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 512

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }

    // open memory card file
    char *infile = argv[1];
    //printf("%s\n",infile);

    FILE *input = fopen(infile, "r");
    if (input == NULL)
    {
        printf("Could not open card.raw.\n");
        return 2;
    }

    // create buffer
    unsigned char buffer[BUFFER_SIZE];

    // filename counter
    int filecount = 0;

    FILE *picture = NULL;

    // check if we've found a jpeg yet or not
    int jpg_found = 0; //false

    // go through cardfile until there aren't any blocks left
    while (fread(buffer, BUFFER_SIZE, 1, input) == 1)
    {
        // read first 4 bytes of buffer and see if jpg signature using bitwise on last byte
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && buffer[3] >= 0xe0 && buffer[3] <= 0xef)
        {
            if (jpg_found == 1)
            {
                // We found the start of a new pic so close out current picture
                fclose(picture);
            }
            else
            {
                // jpg discovered and now we have the green light to write
                jpg_found = 1;
            }

            char filename[8];
            sprintf(filename, "%03d.jpg", filecount); //%03d is three-digit decimal number
            picture = fopen(filename, "a");
            filecount++;
        }

        if (jpg_found == 1)
        {
            // write 512 bytes to file once we start finding jpgs
            fwrite(&buffer, BUFFER_SIZE, 1, picture);
        }

    }

    // close files
    fclose(input);
    fclose(picture);

    return 0;
}

