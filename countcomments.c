#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#define FILESIZE 512

/*
@Author Sabin Constantin Lungu
Matriculation Number: 40397517
Last Modified: 18/02/2019 @ 11:59
Purpose: To count the number of comments in the given file using the -i command line argument.
Parameters: *filename used to read in the given file.
*/

void countComments(FILE *fileName) { // A void method to count the comments in the files
  char stringFileBuffer[FILESIZE];
  int stringCommentCounter = 0;
  
  fseek(fileName, 0, SEEK_SET); // Set the starting position of the file at the beginning.

   if(fileName !=NULL) {

      while(!feof(fileName)) { // A while loop to go through to the end of the file.
         char stringComments = fgetc(fileName);

         if(stringComments == '/') {

         	if(fgetc(fileName) == '/')
         		stringCommentCounter++;
         }
      }
      printf("\n Total Number Of Comments In The Given File : %d", stringCommentCounter);
   }
}
