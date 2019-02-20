#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <conio.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "countlines.h"
#include "countcomments.h"
#include "removeinclude.h"
#include "removedefine.h"

#define FILESIZE 512 // A constant defined to store the file size with an appropriate size.
#define OUTPUTFILE 512

/*
@Author Sabin Constantin Lungu
Matriculation Number: 40397517
Last Modified: 18/02/2019 @ 11:44
Purpose: The main .c file to test the rest of the files.
Parameters: Number of command line arguments
*/

int main(int argc, char **argv) { // Main program with the main method to test the rest of the .c files

	FILE *inputFile = NULL; // Set the current input file pointer to NULL (empty)
	FILE *outputFile = NULL;

	int isFileGiven = 0; // A flag that is set to false.

	for(int startIndex = 0; startIndex < argc; startIndex++) { // Loop through the arguments.
		
		if(strcmp(argv[startIndex], "-i") == 0)  { // If the argument entered by the user is -i (strcmp function used to compare the input)

           inputFile = fopen(argv[startIndex+1], "r"); // Read in the file from the keyboard.

           int theLength = strlen(argv[startIndex+1]);
           char outputFileName[OUTPUTFILE];

           strcpy(outputFileName, argv[startIndex+1]); // Copy the output file name to the next command line argument.
           outputFileName[theLength-1] = 'o'; // Enables to write a new file to the disk.
           
           outputFile = fopen(outputFileName, "w");
           isFileGiven = 1; // Set the file flag to true.
	}
}
	  removeInclude(inputFile, outputFile); // Call the method to remove include
	  countComments(inputFile);

	  countLines(inputFile);
	  removeComments(inputFile, outputFile);

	  fclose(inputFile); // Close the input file.
	  fclose(outputFile); // Close the output file.

	return 0;
}