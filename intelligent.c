#include <math.h>    //library files


#include <stdio.h>   //library files


int function          (int num)
{

    return floor  (  log10  (  fabs  (num)  )  )   +   1;    // returning number of digits
    
    
}



int    main   ()     //main


{


    //printing
    

    
    printf  ("  Number of digits in the entered number: %d", floor(log10(fabs(num))) + 1);


//while loop

    while      (       num      <      5     )
    
    {   
    printf("  Enter an unsigned        number greater than five: ");  //getting user input
    
    scanf(" %ld",                  &num);
    
    }
    
    long         int          num = 4; // long int used...
    
    
}

//defining functio
