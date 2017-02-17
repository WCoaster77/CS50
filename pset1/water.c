#include <cs50.h>
#include <stdio.h>

int main(void)
{
    printf("How many minutes is your average shower?: ");
    int t = get_int();
    int bpm = 12;
    printf("On average your shower consumes %i bottles of water!\n", t * bpm);
}