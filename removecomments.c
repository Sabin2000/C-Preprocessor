#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <conio.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILESIZE 512

/*
@Author Sabin Constantin Lungu
Matriculation Number: 40397517
Last Modified: 18/02/2019 @ 11:41
Purpose: To remove the comments from the given program by using the -i command line argument.
Parameters: *filename - A file pointer used to manipulate the given file ie read & write to. & a pointer to an output file to write to.
*/

void removeComments(FILE *fileName, FILE *outputFile) { // A void method that is used to remove the comments from the given file.
	char fileBuffer[FILESIZE]; // Create a file buffer with the constant passed in to store the files.
	char slashBuffer[FILESIZE];
	fseek(fileName, 0, SEEK_SET); // Sets the file position to the start.

	if(fileName !=NULL) { // If the file is not equal to null.
		int startIndex = 0;

		 while(fgets(fileBuffer, FILESIZE, fileName)) { // Loop through the file line by line

		 	if(fileBuffer[0] != '/' || fileBuffer[0] == '#') { 
		 		
		 		for(int charIndex = 0; charIndex < strlen(fileBuffer)-1; ++charIndex) { // Loop through the length of the file buffer.

		 			if((fileBuffer[charIndex] == '/' && fileBuffer[charIndex+1] == '/') || (fileBuffer[charIndex] == '#')) { // If the char index is equal to the first slash and the one next to it
		 				fileBuffer[charIndex] = '\n'; 
		 				fileBuffer[charIndex+1] = '\0'; // Set the file buffer array to null terminator so no garbage is printed to the screen.
		 				break; 
		 			}
		 			slashBuffer[charIndex] = fileBuffer[charIndex]; // Swaps the characters to the new file buffer.
		 		}

		 		fprintf(outputFile, "%s", fileBuffer); // Write the contents to the output file.
		 	}
		 	startIndex++;
		 }
		 
	} else {
		
		printf("\n File not opened ok", fileName);
	}
}