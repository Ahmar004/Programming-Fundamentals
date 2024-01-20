#include <math.h>  
#include <stdio.h>

int function(int num)
{
    int a = 5;
    return floor(log10(fabs(num))) + 1;
}

int main()  
{
    long int num = 4; //variable

    printf("Number of digits in the entered number: %d", floor(log10(fabs(num))) + 1);

//while loop
    while (num < 5)
    {   
    printf("Enter an unsigned number greater than five: ");
    scanf(" %ld", &num);
    }
}
