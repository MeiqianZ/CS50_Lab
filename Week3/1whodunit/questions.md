# Questions

## What's `stdint.h`?

This is a header, it shall declare sets of integer types having specified widths, and shall define corresponding sets of macros.
In der Headerdatei <stdint.h> werden ganzzahlige Typen mit bestimmter Breite definiert. Mit »vorgegebener Breite« ist die Anzahl der Bits zur Darstellung des Werts gemeint, die dieser Typ verwenden darf. 
z.B. intN_t, uintN_t:
Ein int-Wert mit einer Breite von exakt N Bits. Dieser Typ ist optional und wird nicht vom C99-Standard gefordert. Damit wäre es beispielsweise möglich, eigene erweiterte Ganzzahltypen wie beispielsweise int22_t oder uint34_t zu definieren und verwenden.

## What's the point of using `uint8_t`, `uint32_t`, `int32_t`, and `uint16_t` in a program?
typedef uint8_t  BYTE; 8 Bit = 1 Byte, 0..255
typedef uint32_t DWORD; 32 Bit = 4 Bytes, 0..4292967295
typedef int32_t  LONG; 32 Bit = 4 Bytes, -2147483648..2147483647
typedef uint16_t WORD; 16 Bit = 2 Bytes, 0..65535
This define value range of BYTE, DWORD, LONG and WORD.
Es ist einfacher, Aliasnamen für explizite Ganzzahlen mit fester Breite zu verwenden. Gibt die Anzahl der Bytes an, da ein System, das ein Int sein kann, in einem anderen lang sein kann.

## How many bytes is a `BYTE`, a `DWORD`, a `LONG`, and a `WORD`, respectively?

BYTE = 1 byte, DWORD = 4 bytes, LONG = 4 bytes and WORD = 2 bytes.

## What (in ASCII, decimal, or hexadecimal) must the first two bytes of any BMP file be? Leading bytes used to identify file formats (with high probability) are generally called "magic numbers."

The header field used to identify the BMP and DIB file is 0x42 0x4D in hexadecimal, same as BM in ASCII.

## What's the difference between `bfSize` and `biSize`?

bfSize is in BITMAPFILEHEADER, it is the size of the whole bmp file. And biSize is the size of the BITMAPINFOHEADER header file, it is constant 40 bytes.

## What does it mean if `biHeight` is negative?

The RGBTRIPLE area will be empty, only 54 bytes are occupied and no picture will appear.
If biHeight is negative, the bitmap is a top-down DIB and its origin is the upper-left corner.
If biHeight is negative, indicating a top-down DIB, biCompression must be either BI_RGB or BI_BITFIELDS. Top-down DIBs cannot be compressed.

## What field in `BITMAPINFOHEADER` specifies the BMP's color depth (i.e., bits per pixel)?

biBitCount

## Why might `fopen` return `NULL` in lines 24 and 32 of `copy.c`?

If the file cannot be found.

## Why is the third argument to `fread` always `1` in our code? (For example, see lines 40, 44, and 75.)

In whodunit.c is the third argument to ` fread ` always ` 1 `, because the third argument is the number of elements, each one with a size of < size > bytes. Since we are looking through each struct one at a time we put the third argument as 1 every time.

## What value does line 63 of `copy.c` assign to `padding` if `bi.biWidth` is `3`?

int padding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4 = ( 4 - ( 3 * 3 ) % 4 ) % 4 = ( 4 - 1 ) % 4 = 3
RGBTRIPLE is 3 bytes (24 bits), 3 % 4 is 3,  Padding = 3

## What does `fseek` do?

Sets the file position indicator for the file stream to the value pointed to by offset.

## What is `SEEK_CUR`?

How you set the offset to be relative to the current position indicator instead of the start or end.
 
