#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <assert.h>
#include <string.h>

#define FILESIZE 512 // Defines the file size. Defines the number of bytes to be allocated in memory.

/*
@Author Sabin Constantin Lungu
Matriculation Number: 40397517
Last Modified: 18/02/2019 @ 11:40
Purpose: To count the number of non-empty lines in the file given by using the -i command line argument.
Parameters: *filename - A file pointer used to manipulate the given file ie read & write to.
*/

void countLines(FILE *fileName) { // A void method that counts the lines in the given file.
 char fileBuffer[FILESIZE]; // Create a char array buffer to store the max size of the string file.
 int lineCounter = 0; // Set the line counter to 0
  
  fseek(fileName, 0, SEEK_SET); // Set the file position to the start

   if(fileName !=NULL) { // If the file is not empty
    
      while(!feof(fileName)) { // Loop over the contents of the file.
      	char theComments = fgetc(fileName); // Get the characters from the file

         if(theComments == '\n') { // If a there is a new line in the file
          lineCounter++; // Increment the counter
          
          if(fgetc(fileName) == '\n'); // If the string file is equal to a new line
          
         }
      }
      printf("\n Total non-empty lines for the Given file: %d", lineCounter);
   }
}
