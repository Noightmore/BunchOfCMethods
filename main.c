#include <stdio.h>
#include <malloc.h>
#include "stringTools.c"
#include "stringBackupTool.c"

int main()
{
    Node* pStack = stackCreate();
    char* pString = stringAlloc(10);
    stringFill(pString, 10);
    stackPush(pStack, pString);
    stringEdit(pString, 0, 10);
    stackPush(pStack, pString);
    stackPrint(pStack);
    stringFree(stackPop(pStack));
    stackPrint(pStack);
    stringFree(stackPop(pStack));
    stackFree(pStack);

    char *pString2 = stringAlloc(10);
    stringFill(pString2, 10);

    char string3[] = "Hello World";
    stringFill(string3, 10);


    return 0;
}