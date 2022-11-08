//
// Created by rob on 11/6/22.
//

#include <stdio.h>
#include <malloc.h>

// allocate memory for string of size n characters
char *stringAlloc(int n)
{
    char* pString = (char *) malloc(n * sizeof(char));
    if (pString == NULL)
        printf("Error: stringAlloc() failed to allocate memory for string.");
    return pString;
}

// free memory allocated for string
void stringFree(char* pString)
{
    free(pString);
}

// method to fill string with characters from user input
void stringFill(char* pString, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("Enter character %d: ", i + 1);
        scanf(" %c", &pString[i]);
    }
}

// method to edit the string by index and then the length of other characters to be changed
void stringEdit(char* pString, int index, int length)
{
    int i;
    for (i = 0; i < length; i++)
    {
        printf("Enter character %d: ", i + 1);
        scanf(" %c", &pString[index + i]);
    }
}

// method to print the string
void stringPrint(char* pString)
{
    int n;
    for(n = 0; *pString != '\0'; pString++)
    {
        n++;
    }

    int i;
    for (i = 0; i < n; i++)
    {
        printf("%c", pString[i]);
    }
    printf("\n");
}


