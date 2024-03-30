#include "header.h"

int main() 
{
    PersonArray* Array = personArray();
   
    personAdd(Array);
    printf(" \n -- > Before sorting:\n");
    arrayPrint(Array);

    bubbleSorting(Array, sortingForName);
    printf("\n -- > After sorting NAME:\n");
    arrayPrint(Array);

    bubbleSorting(Array, sortingForSurname);
    printf("\n -- > After sorting by SURNAME:\n");
    arrayPrint(Array);

    arrayFree(Array);
    return 0;
}