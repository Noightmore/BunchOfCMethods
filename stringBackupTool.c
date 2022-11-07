//
// Created by rob on 11/6/22.
//

#include <stdio.h>
#include <malloc.h>
#include "stringTools.c"

typedef struct node
{
    char* pString;
    struct node* pNext;
} Node;

// create a linked list lifo stack
Node* stackCreate()
{
    Node* pStack = (Node *) malloc(sizeof(Node));
    pStack->pString = NULL;
    pStack->pNext = NULL;
    return pStack;
}

// push a string onto the stack
void stackPush(Node* pStack, char* pString)
{
    Node* pNewNode = (Node *) malloc(sizeof(Node));
    pNewNode->pString = pString;
    pNewNode->pNext = pStack->pNext;
    pStack->pNext = pNewNode;
}

// pop a string off the stack
char* stackPop(Node* pStack)
{
    Node* pTemp = pStack->pNext;
    char* pString = pTemp->pString;
    pStack->pNext = pTemp->pNext;
    free(pTemp);
    return pString;
}

// get the top value of the stack
char* stackTop(Node* pStack)
{
    return pStack->pString;
}

// print the stack
void stackPrint(Node* pStack)
{
    Node* pTemp = pStack->pNext;
    while (pTemp != NULL)
    {
        stringPrint(pTemp->pString);
        pTemp = pTemp->pNext;
    }
}

// free the stack
void stackFree(Node* pStack)
{
    Node* pTemp = pStack->pNext;
    while (pTemp != NULL)
    {
        Node* pTemp2 = pTemp->pNext;
        free(pTemp);
        pTemp = pTemp2;
    }
    free(pStack);
}

char* undo(Node* pStack)
{
    return stackPop(pStack);
}

// redo the last undo
char* redo(Node* pStack)
{
    return stackTop(pStack);
}




