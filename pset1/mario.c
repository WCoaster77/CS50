#include <cs50.h>
#include <stdio.h>

// Declare prototypes
void prtSpace();
void prtBlock();

// Declare Global Variables
int height = 0; // Height of pyramid
int width = 1; // Width of pyramid
char symbol = '#'; // The block


int main(void)
{
    do // Check if height is in range
    {
        printf("How high should we go? (1 - 23): ");
        height = get_int();
    }
    while(height < 0 || height > 23);
    
    int space = height - width; // To align left side of pyaramid

    for(int i = 0; i < height; i++)
    {
        prtSpace(space);
        prtBlock();
        printf("  ");
        prtBlock();
        width++;
        space--;
        printf("\n");
    }
}

void prtSpace(space)
{
    for(int count = space; count > 0; count--)
    {
        printf(" ");   
    } 
}

void prtBlock()
{
    for(int count = 0; count < width; count++)
    {
        printf("%c", symbol);   
    }
}