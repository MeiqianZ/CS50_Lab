#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "bmp.h"

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        printf("Usage: ./resize 0<n<=100 input.bmp output.bmp\n");
        return 1;
    }

    //check expansion
    /* wird durch atoi() Funktion ersetzt.
    int length = strlen(argv[1]);
    int Input[length];
    int expansion = 0;
    for (int inputIndex = 0 ; inputIndex < length ; inputIndex++)
    {
        Input[inputIndex] = (int) argv[1][inputIndex];

        if ( 48 <= Input[inputIndex]  &&  Input[inputIndex] <= 57 ){

            expansion += (Input[inputIndex] - 48) * pow(10,length-inputIndex-1);
        } else {

            printf("Usage: ./resize 0<n<=100 input.bmp output.bmp\n");
            return 2;
        }
    }
    */
    int expansion = atoi(argv[1]);
    if (expansion > 100)
    {
        printf("Usage: ./resize 0<n<=100 input.bmp output.bmp\n");
        return 2;
    }

    // remember filenames
    char *infile = argv[2];
    char *outfile = argv[3];

    // open input file
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        printf("Could not open %s.\n", infile);
        return 3;
    }

    // open output file
    FILE *outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        printf("Could not create %s.\n", outfile);
        return 4;
    }


    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf, bf_new;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);
    bf_new = bf;

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi, bi_new;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);
    bi_new = bi;

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 ||
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        printf("Unsupported file format.\n");
        return 5;
    }

    // determine padding for scanlines. HERE!
    int padding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

    //new dimensions
    bi_new.biWidth *= expansion;
    bi_new.biHeight *= expansion;
    int padding_new = (4 - (bi_new.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

    bi_new.biSizeImage = (bi_new.biWidth * abs(bi_new.biHeight) * 3) + padding_new * abs(bi_new.biHeight);
    bf_new.bfSize = bf_new.bfOffBits + bi_new.biSizeImage;


    // write outfile's BITMAPFILEHEADER with bf_new
    fwrite(&bf_new, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER with bi_new
    fwrite(&bi_new, sizeof(BITMAPINFOHEADER), 1, outptr);



    // iterate over infile's scanlines
    for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++)
    {
        //with expansion
        for (int row = 0; row < expansion; row++)
        {
            // iterate over pixels in scanline
            for (int j = 0; j < bi.biWidth; j++)
            {
                // temporary storage
                RGBTRIPLE triple;

                // read RGB triple from infile
                fread(&triple, sizeof(RGBTRIPLE), 1, inptr);

                // write RGB triple to outfile, with expansion
                for (int column = 0; column < expansion; column++)
                {
                    fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
                }
            }

            // add a padding_new
            for (int k = 0; k < padding_new; k++)
            {
                fputc(0x00, outptr);
            }

            // Return to the beginning of a scanline
            if (row < expansion - 1)
            {
                fseek(inptr, -bi.biWidth * sizeof(RGBTRIPLE), SEEK_CUR);
            }

        }

        // skip over padding, if any
        fseek(inptr, padding, SEEK_CUR);
    }

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // success*/
    return 0;
}
 
