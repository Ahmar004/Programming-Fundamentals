#include <stdio.h>
#include <math.h>

int function(int num);

int main()  
{
    long int num = 4; //variable

//while loop
    while (num < 5)
    {   
    printf("Enter an unsigned number greater than five: ");
    scanf(" %ld", &num);
    }
    
    printf("Number of digits in the entered number: %d", floor(log10(fabs(num))) + 1);
}

int function(int num)
{
    return floor(log10(fabs(num))) + 1;
}
