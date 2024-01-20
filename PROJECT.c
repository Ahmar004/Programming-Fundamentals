//name of this plagiarism detection software: Brute
//this name is used in comments...

//A quick note: wherever single quotes i.e. ' ' are used in comments, they are representing either the name of a variable, array or a function etc.

//----------------------functionality of project-----------------------
//----1----

//including library files
#include<stdio.h>
#include<string.h>
//defining easy words to use in place of print-formatting attributes...
// "[1m" is used for making text bold
// "[m" resets the formatting attributes...
// hover to printf() statements to see usage...
#define font_bold                   "\e[1m"
#define reset_format                "\e[m"
#define font_bold_slow_blink        "\e[1;5m"
#define font_bold_slow_blink_red    "\e[1;5;31m"
#define font_bold_slow_blink_blue   "\e[1;5;34m"
#define font_bold_red               "\e[1;31m"
#define font_bold_blue              "\e[1;34m"

//User-defined function prototypes:

char lowIt(char letter);//481
int validateFile(FILE *ptr);//469
int welcomeUser(void); //419
char *getcwd(char *buf, size_t size); //used for showing CWD, see welcomeUser( ) function

void nullTheArray(char *ptr, int rows, int columns);//502
float bruteApproach(char File1[][750], int line1, char File2[][1000], int line2); //514
 
int main()
{

//welcomeUser function returns 1 if user has placed files in the appropriate directory (CWD) and wants to continue.
//Brute should execute (stop) its process if user wants to exit...
//welcomeUser returns 0 if user wants to exit...

//welcomeUser gets called
    int fromUser = welcomeUser();
   
//if return-value is zero:
   
    if (fromUser == 0)
    {
        printf( font_bold_slow_blink_red "\n\t\t\t\tExiting Brute...\n\n\n\n" reset_format );
        return 0;
    }

    FILE *ptr1;
   
    //taking name from the user for file-1...(files must be placed within the same folder...)
   
    char array1[15];
   
    nullTheArray(array1, 15, 1);   //it's a void function so therefore stand-alone
   
    //taking file name for file-1
   
    printf( font_bold_blue "\n\t\t\t\tPlease enter file name for file#1 (along with its extension):" reset_format );
    scanf("%s",array1);
   
   
   
    int lineCount1=0;
    char character;
    ptr1= fopen(array1, "r");
   
   //show error if file was unable to open...
   
   int fileCheck = validateFile(ptr1);
    if (fileCheck == 0)  
    {
        printf( font_bold_red "\n\t\t\t\tUnable to open the file.\n\t\t\t\tPlease try again! (it looks like the file you mentioned is not in the CWD-Current Working Directory.)\n\n"reset_format);
        printf( font_bold_red "\n\t\t\t\tYou may visit the CWD please...\n" reset_format );
        return 0;
    }
           

    //determining total number of lines for updated array:

    character = fgetc(ptr1);
   int inBrackets=0;
   
    while (character != EOF)
     {
        if ( ( character == '(')  )    //ignoring curly braces
          {
              inBrackets=1;   
          } 
          else if( character == ')')
           {
            inBrackets=0;
           }
        if ( (character=='\n')|| (character==';'&& inBrackets==0))
        {
            lineCount1++;
        }
       
        character = fgetc(ptr1);
     }
     
     //for tracing with future
    fseek(ptr1,0, SEEK_SET);
 
       /*------------------------------------------------------------------------*/
     
       
       /*------------------------------------------------------------------------*/

   char file1[lineCount1][750];  //array for storing content in a tokenized manner...
   
   
   nullTheArray(&file1[0][0], lineCount1, 750);  //storing null at all indexes of the array.
   
   //initialization of some variables
   
   //
   
    int linelength1 = 0;  //for storing length of characters in one line to appropriately populate the 2-d array...
    int lines1 = 0;     //
    char character1;  //variable for storing the character fetched by ptr1
    int determinant = 0;    //for dealing with
    inBrackets=0;
   
    while (character1 != EOF)
    {  
        character1 = fgetc(ptr1);    //get character
   
          if ( ( character1 == '{') || ( character1 == '}') )    //ignoring curly braces
          {
              continue;    
          }
          
          // Dealing with comments

    // If two consecutive slashes '//', ignore the rest of the line
    if ( ( (character1 == '/') && (determinant == 1) ) || (character1 == '#') )
    {
        if (linelength1 > 2)
        {
            file1[lines1][linelength1 - 1] = '\0';
        }
    
        while ( character1 != '\n' && character1 != EOF)
        {
            character1 = fgetc(ptr1);
        }
        
        if (linelength1 > 2)
        {
            lines1++;
        }
        
        linelength1 = 0; // Reset column index for the next line
        determinant = 0;
    }

    // If a single slash '/', set determinant to 1
    if (character1 == '/')
    {
        determinant = 1;
    }
    else
    {
        determinant = 0;  // Reset determinant if not a slash
    }
          
          if ( ( character1 == '(')  )    //ignoring curly braces
          {
              inBrackets=1;   
          } 
          else if( character1 == ')')
           {
            inBrackets=0;
           }   
          //with the help of next conditional statement we are ignoring consecutive new-line characters...
         
          if (character1 == '\n' || (character1==';'&& inBrackets==0))    //dealing with new-line characters and specifically (consecutive new-line characters...)
          {
                if (linelength1 > 0) 
                {
                      // Increment only if the current line has characters other than new-line-character
                      if(character1==';'&& inBrackets==0)
                      file1[lines1][linelength1] =  lowIt(character1);
                      
                      lines1++;
                      linelength1 = 0;   // Reset column index for the next line
                }
          }
   
          //we have used else if for dealing with characters  so that whenever there's a new-line character, then the compiler deals with it and does not enter the next conditional.
         //i.e. compiler will only enter this conditional when there's neither a newline character nor a space in the character1...
   
          else if (character1 != ' ')  //ignoring spaces as well...  (Adding characters into array here...)
          {
                file1[lines1][linelength1] =  lowIt(character1);  
                linelength1++;
          }
   
    }  //while ends here...  

     
    fclose(ptr1);
   
   

  /*------------------------------------------------------------------------*/
 
 
 
         /*-------------------------------------file2---------------*/  
 FILE *ptr2;
   
    //for opening file by taking name from the user...
    char array2[15];
    nullTheArray(&array2[0], 15, 1);
    printf( font_bold_blue "\n\t\t\t\tPlease enter file name for file#2 (along with its extension):" reset_format );
    scanf("%s",array2);
    int linecount2=0;
    int Character2;
     
    ptr2= fopen(array2, "r");
   
   //show error if file was unable to open..
    int v = validateFile(ptr2);
    if (v== 0)
    {
        printf( font_bold_red "\n\t\t\t\tUnable to open the file.\n\t\t\t\tPlease try again! (it looks like the file you mentioned is not in the CWD-Current Working Directory.)\n\n"reset_format);
        printf( font_bold_red "\n\t\t\t\tYou may visit the CWD please...\n" reset_format );
        return 0;
    }
    
    int inBracket;

    while (Character2 != EOF)
     {
        if ( ( Character2 == '(')  )    //ignoring curly braces
          {
              inBracket=1;   
          } 
          else if( Character2 == ')')
           {
            inBracket=0;
           }
        if ( (Character2 =='\n') || ( Character2 ==';' && inBracket == 0 ))
        {
            linecount2++;
        }
       
        Character2 = fgetc(ptr2);
     }
   fseek(ptr2,0, SEEK_SET);
     
   
    /*------------------------------------------------------------------------*/
   char file2[linecount2][1000];
   
   nullTheArray(&file2[0][0], linecount2, 1000);
   
   //initialization of some variables...
   
   int linelength2 = 0;  //for storing length of characters in one line to appropriately populate the 2-d array...
    int lines2 = 0;     //
    char character2;  //variable for storing the character fetched by ptr1
    int determinant2 = 0;    //for dealing with
    inBrackets=0;
   
    while (character2 != EOF)
    {  
        character2 = fgetc(ptr2);    //get character
   
          if ( ( character2 == '{') || ( character2 == '}') )    //ignoring curly braces
          {
              continue;    
          }
          
              // Dealing with comments

    // If two consecutive slashes '//', ignore the rest of the line
    if ( ( (character2 == '/') && (determinant2 == 1) ) || ( character2 == '#' ) )
    {
        if (linelength2 > 2)
        {
            file2[lines2][linelength2 - 1] = '\0';
        }
    
        while ( character2 != '\n' && character2 != EOF)  
        {
            character2 = fgetc(ptr2);
        }
        
        if (linelength2 > 2)
        {
            lines2++;
        }
        
        linelength2 = 0; // Reset column index for the next line
        determinant2 = 0;
    }

    // If a single slash '/', set determinant to 1
    if (character2 == '/')
    {
        determinant2 = 1;
    }
    else
    {
        determinant2 = 0;  // Reset determinant if not a slash
    }


          
          if ( ( character2 == '(')  )    //ignoring brackets
          {
              inBrackets=1;   
          } 
          else if( character2 == ')')
           {
            inBrackets=0;
           }   
          //with the help of next conditional statement we are ignoring consecutive new-line characters...
         
          if (character2 == '\n' || (character2==';'&& inBrackets==0))    //dealing with new-line characters and specifically (consecutive new-line characters...)
          {
                if (linelength2 > 0) 
                {
                      // Increment only if the current line has characters other than new-line-character
                      if(character2==';'&& inBrackets==0)
                      file2[lines2][linelength2] =  lowIt(character2);
                      lines2++;
                      linelength2 = 0;   // Reset column index for the next line
                }
          }
   
          //we have used else if for dealing with characters  so that whenever there's a new-line character, then the compiler deals with it and does not enter the next conditional.
         //i.e. compiler will only enter this conditional when there's neither a newline character nor a space in the character1...
   
          else if (character2 != ' ')  //ignoring spaces as well...  (Adding characters into array here...)
          {
                file2[lines2][linelength2] =  lowIt(character2);  
                linelength2++;
          }
   
    }  //while ends here...  
       
         
     fclose(ptr2);
     
     
 /*----------------------------------------------------------------------------*/


     printf( font_bold_red "\n\t\t\t\tNumber of similar lines:%d\n" reset_format , (int) bruteApproach(file1, lines1, file2,lines2));

    float rate = ( ( bruteApproach(file1, lines1, file2,lines2) ) / ( (float) lines2 ) ) * 100;
    
     printf( font_bold_red "\n\t\t\t\tRate of plagiarism between 2 files: %.2f\n\n" reset_format , rate);

//asking user whether to show concatenated files:
printf( font_bold_blue "\n\t\t\t\tDo you want to see the concatenated files or not\n\n\t\t\t\tpress y for yes or n for no\t" reset_format );

char c;
scanf(" %c",&c);
switch (c) {
    case 'y':
    case 'Y': {
        // Code for 'yes' case
        
        printf( font_bold_blue "\n\n\n\t\t\t\tFile-1 is as follows:\n\n" reset_format );
        
        for (int i = 0; i < lines1; i++)
        {  
            printf("\t\t\t\t");
        
            int j = 0;
            while ( (j < 750) && (file1[i][j] != '\0') )
            {
                printf("%c", file1[i][j]);
                j++;
            }
           printf("---index: %d\n", i);
        }
        
        printf( font_bold_blue "\n\n\n\t\t\t\tFile-2 is as follows:\n\n" reset_format );
        
        
  for (int i = 0; i < lines2; i++)
    {
        printf("\t\t\t\t");
    
        for (int j = 0; file2[i][j]!='\0'; j++)
        {
            printf("%c", file2[i][j]);
        }
        printf("---index: %d\n", i);
    }
    
        printf( font_bold_red "\n\t\t\t\tSystem exiting...\n\n\n\n" reset_format );
        
        break;
    }
    case 'n':
    case 'N':
        // User chose 'no' - exit the system
        printf( font_bold_red  "\n\t\t\t\tSystem exiting...\n\n\n\n" reset_format );
        return 0;
    default:
        // Handle unexpected input
        printf( font_bold_red "\n\t\t\t\tInvalid choice. Exiting...\n\n\n\n" reset_format );
        return -1;  // Indicate an error
}
}



int welcomeUser()
{
    char check;

    printf( font_bold_blue "\n\n\n----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n"  reset_format  );
   
        printf( font_bold_red "----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n"  reset_format  );
       
            printf( font_bold_red "----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n"  reset_format  );
   
    printf( font_bold_blue "----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n"  reset_format  );
   
    printf( font_bold_slow_blink_red "\t\t\t\t\t\t\t\t\t\tWelcome to Brute Plagiarism Detector\n" reset_format );
   
    printf( font_bold_blue "\n\n\t\t\t\tDear user, it is to inform you that the files to compare must be placed in the current-working directory (CWD) before running Brute.\n" reset_format );
    printf( font_bold_blue "\n\t\t\t\tPlease ensure that you have placed the two files to compare in the following directory (CWD): \n\n\t" reset_format );
   
    char cwd[256];
   
    if (getcwd(cwd, sizeof(cwd)) == NULL)
    {
      printf("\n\t\t\t\tError while fetching CWD via getcwd() function\n");
    }
    else
    {
      printf( font_bold_blue "\t\t\t%s\n" reset_format , cwd);
    }
   
    printf( font_bold_blue "\n\t\t\t\tPress 'c' to continue with Brute" reset_format font_bold_red " or 'e' to exit" reset_format font_bold_blue "(if you have not placed the two files in the CWD):  ");
    scanf(" %c", &check);
    fflush(stdin);
   
    while ( ( check != 'c') && (check != 'C') && (check != 'e') && (check != 'E') )    //preventing wrong input...
    {
        printf( font_bold_blue "\n\t\t\t\tPress 'c' to continue with Brute" reset_format font_bold_red " or 'e' to exit" reset_format font_bold_blue "(if you have not placed the two files in the CWD):  ");
        scanf(" %c", &check);
        fflush(stdin);
    }
   
    if (check == 'c' || check == 'C')
    {
        return 1;
    }
    else
    {
        return 0;
    }

}

int validateFile(FILE *ptr)
{
    if (ptr== NULL)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

char lowIt(char letter)
{
 return ( ( (int)letter >= 65) && ( (int)letter <= 90 ) )? letter + 32 : letter;
}

int alphabetValidate(char alphabet)     //the function alphabetValidate returns 2 if there's a capital alphabet...and 1 if small... and 0 if not an alphabet
{
    if ( ((int)alphabet >= 65) && ((int)alphabet <= 90) )
    {
        return 2;
    }
    else if ( ((int)alphabet >= 97) && ((int)alphabet <= 122) )
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
 
void nullTheArray(char *ptr, int rows, int columns)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
              *ptr = '\0';
              ptr++;  
        }
    }
}

float bruteApproach(char File1[][750], int line1, char File2[][1000], int line2)
{
     int similarity = 0;
  for(int i=0;i<line1;i++)
    {
            for(int j=0;j<line2;j++)
                {
                  if(strcmp(File1[i],File2[j])==0)
                   {
                     similarity++;
                   }
                } 
    }   // float similarityPercentage = (similarity / ((float)line1+line2)/2.0) * 100;

  return similarity;
}
