#include <stdio.h>  //library files
#include <math.h>   //library files

int function(int num)  //function
{
    return floor(log10(fabs(num))) + 1;  //returning number of digits
}

int main()   //main function
{
    long int num = 4; 


    while (num < 5)   // condition
    {   
    printf("Enter an unsigned number greater than five: ");   //getting user-input
    scanf(" %ld", &num);  //storing
    }
    
  printf("Number of digits in the entered number: %d", floor(log10(fabs(num))) + 1);//good
}
