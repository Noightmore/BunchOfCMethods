//
// Created by rob on 11/7/22.
//

#include <malloc.h>

// allocation of 2D array of pointers of any type
void** array2DCreate(int nRows, int nCols, int nBytes)
{
    void** pArray = (void **) malloc(nRows * sizeof(void *));
    for (int i = 0; i < nRows; i++)
        pArray[i] = (void *) malloc(nCols * nBytes);
    return pArray;
}

// free memory allocated for 2D array of pointers of any type
void array2DFree(void** pArray, int nRows)
{
    for (int i = 0; i < nRows; i++)
        free(pArray[i]);
    free(pArray);
}

// allocation of 3D array of pointers of any type
void*** array3DCreate(int nRows, int nCols, int nHeights, int nBytes)
{
    void*** pArray = (void ***) malloc(nRows * sizeof(void **));
    for (int i = 0; i < nRows; i++)
    {
        pArray[i] = (void **) malloc(nCols * sizeof(void *));
        for (int j = 0; j < nCols; j++)
            pArray[i][j] = (void *) malloc(nHeights * nBytes);
    }
    return pArray;
}

// free memory allocated for 3D array of pointers of any type
void array3DFree(void*** pArray, int nRows, int nCols)
{
    for (int i = 0; i < nRows; i++)
    {
        for (int j = 0; j < nCols; j++)
            free(pArray[i][j]);
        free(pArray[i]);
    }
    free(pArray);
}

