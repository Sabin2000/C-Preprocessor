#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define FILESIZE 512

/*
@Author Sabin Constantin Lungu
Matriculation Number: 40397517
Last Modified: 18/02/2019 @ 11:49
Purpose: To remove the "#include" from the start of the file and replace it with the method contents in the header file that will be used.
Parameters: *filename - A file pointer used to manipulate the given file ie read & write to, also a pointer to an output file where the contents will be written to.
*/

void removeInclude(FILE *fileName, FILE *outputFile) { // A void method to remove the "#include" from the file and replace it with the methods in the appropriate header file
    char charactersBuffer[FILESIZE]; // A character buffer to store the characters.
    char fileBuffer[FILESIZE];
    fseek(fileName, 0, SEEK_SET); // fseek used to start at the beginning of the file.

    int foundHashtag =0; // A found hashtag flag.
    int foundQuote = 0;
    int fileIndex = 0; // The file index that is read from.
    int newFile = 0;

 if(fileName != NULL) {
 
      while(fgets(charactersBuffer, FILESIZE, fileName)) { // Gets each character line by line
  
      	if(charactersBuffer[0] == '#') { // If the first index of the characters buffer is equal to the hashtag
      		foundHashtag = 1;  // Set the flag to true.
      	
      		for(int charIndex = 0; charIndex <=strlen(charactersBuffer)-1; charIndex++) {

      			if(charactersBuffer[charIndex] == '"') {
      		
      				if(foundQuote == 1) {
      					foundQuote =0;
      				 	fileBuffer[fileIndex] = '\0'; // Set the file buffer and its index to the null terminator.
      				}

      			else {
                  	foundQuote = 1; 
                 		charIndex++;
      				}         
      			}

      			if(foundQuote == 1) { // If the found quote flag is true 
      				fileBuffer[fileIndex] = charactersBuffer[charIndex]; // Swap the buffers around and increment the file index.
      				fileIndex++;
      				newFile = 1;
      			}
      		}
      	}

      	if(newFile == 1) { // If the new file is equal to true

	      	FILE *headerFile = fopen(fileBuffer, "r"); // Read in the contents of the header file that is stored in the file buffer.

	      		if(headerFile !=NULL) {

					    printf("Header open successful\n");
	      			newFile = 0;

	      			char theCharacters = fgetc(headerFile); // Get the characters from the file.

	      			while(!feof(headerFile)) { // While the file has not reached the end of its contents

					   	fprintf(outputFile, "%c", theCharacters); // Print the characters to the output file.
					  	theCharacters = fgetc(headerFile);
	      		} 

	      		fclose(headerFile);	
	      	}
      	} 
   } 
  } else {

  	printf("File not opened\n", fileName);
  }
}