#include "string_functions.h"
#define TERMINATOR 0
// Removes a newline from the end of a string.
// Parameters: string, an array of characters.
void chomp(char *string)
{
    int len = my_strlen(string);
    if(len > 1 && string[len -1] == '\n')
    {
        string[len -1] = TERMINATOR ;
    }
}
// Calculates the length of a string.
// Parameters: string, an array of characters.
int my_strlen(char *string)
{
    int i=0;
    while(string[i] != TERMINATOR )
    {
        i++;
    }
    return i;
}
// Determines whether one string comes before another alphabetically.
// Parameters: string2, the first string to compare; string2, the second
// string to compare.
// Returns: 0 if the two strings are the same, otherwise the difference
// between them.
int my_strcmp(char *string1, char *string2)
{
    int i = 0;
    while(string1[i] == string2[i])
    {
        if(string1[i] == TERMINATOR )
        {
            break;
        }
        i++;
    }
    return string1[i] - string2[i];
}
