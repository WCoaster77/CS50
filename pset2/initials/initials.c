#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    //printf("Please enter your full name: ");
    string s = get_string();
    
    int i = 0;
    int spcChk = 1; // Flag to see if last char was a space. Flag set to on incase first char
                    // is not a space.
    do
    {
        if (isspace(s[i]))
        {
            spcChk = 1; // set flag to if char is a space
        }
        else
        {
            if (spcChk == 1)  // if flag was set then this is first letter after space
                                // so make upper case
            {
                if (isalpha(s[i])) // checks for alpha charachter
                {
                    printf("%c", toupper(s[i])); // if all is good make char upper case
                    spcChk = 0; // Reset flag to 0 so next non space char does not get printed
                }
            }
        }
        i++; // go tot next char
    }
    while ( i <= strlen(s));  // check to see if there are more letters
    printf("\n");
    
    return 0;
}
