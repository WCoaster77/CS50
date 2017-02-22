#include <cs50.h>
#include <stdio.h>
#include <math.h>

// Declare Global Variables
long long int cardNo = 0;
long long cardLn = 0;
int count = 0, num1 = 0, num2 = 0;

// Declare prototypes
long long getNumber();
// void getCount();


int main(void)
{
    getNumber();
    // getCount(cardNo);

    // Run Hash Check
    cardLn = cardNo;
    do
    {
        num1 += cardLn % 10;
        cardLn /= 10;
        if((cardLn % 10) > 4)
        {
            num2 += (((cardLn % 10) * 2) % 10) + (((cardLn % 10) * 2) / 10);
        }
        else
        {
            num2 += (cardLn % 10) * 2;
        };
        cardLn /= 10;
    } while(cardLn != 0);

    // Find length of card number   
    cardLn = cardNo;
    while(cardLn != 0)
    {
        cardLn /= 10;
        ++count;
    }
    
    cardLn = cardNo;
    int i = 0;
    while(i < count - 2)
    {
        cardLn /= 10;
        ++i;
    }
    
    // check if visa, mc, or amex
    if((num1 + num2) % 10 == 0) // Check if valid card number
    {
        switch(cardLn) // if valid check card type
        {
            case 34:
            case 37:
                printf("AMEX\n");
                break;
            case 50 ... 56:
                printf("MASTERCARD\n");
                break;
            case 40 ... 49:
                printf("VISA\n");
                break;
            default:
                printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
    
    // printf("num1: %i\nnum2: %i\nPrefix: %lld\nTotal: %i\nCount: %i\n", num1, num2, cardLn, num1 + num2, count);
}

// Get card number
long long getNumber()
{
    printf("Please enter number to test: ");
    cardNo = get_long_long();
    return cardNo;
}