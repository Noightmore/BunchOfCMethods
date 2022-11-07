//
// Created by rob on 11/7/22.
//

#include <stdio.h>
#include <malloc.h>

// method that writes anything to a binary file
void writeBinaryFile(char* pFileName, void* pData, int n)
{
    FILE* pFile = fopen(pFileName, "wb");
    if (pFile == NULL)
        printf("Error: writeBinaryFile() failed to open file.");
    fwrite(pData, n, 1, pFile);
    fclose(pFile);
}

// method that reads anything from a binary file
void readBinaryFile(char* pFileName, void* pData, int n)
{
    FILE* pFile = fopen(pFileName, "rb");
    if (pFile == NULL)
        printf("Error: readBinaryFile() failed to open file.");
    fread(pData, n, 1, pFile);
    fclose(pFile);
}

// method that writes a string to a text file
void writeTextFile(char* pFileName, char* pString)
{
    FILE* pFile = fopen(pFileName, "w");
    if (pFile == NULL)
        printf("Error: writeTextFile() failed to open file.");
    fprintf(pFile, "%s", pString);
    fclose(pFile);
}

// method that reads a string from a text file
void readTextFile(char* pFileName, char* pString)
{
    FILE* pFile = fopen(pFileName, "r");
    if (pFile == NULL)
        printf("Error: readTextFile() failed to open file.");
    fscanf(pFile, "%s", pString);
    fclose(pFile);
}

// method that appends a string to a text file
void appendTextFile(char* pFileName, char* pString)
{
    FILE* pFile = fopen(pFileName, "a");
    if (pFile == NULL)
        printf("Error: appendTextFile() failed to open file.");
    fprintf(pFile, "%s", pString);
    fclose(pFile);
}

