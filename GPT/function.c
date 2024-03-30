#include "header.h"

PersonArray* personArray(void) // + +
{
    PersonArray* array = malloc(sizeof(PersonArray));
    array->array = NULL;
    array->size = 0;

    if (array == NULL)
        return -1;
    printf(" | Memory allocated |\n");
    return array;
}

void personAdd(PersonArray* array) // + +
{
    arrayAdd(array, "Joseph", "Goebbels");
    arrayAdd(array, "Vladimir", "Putin");
    arrayAdd(array, "Ernesto", "Huevara");
    arrayAdd(array, "Frida", "Kahlo");
    arrayAdd(array, "Stepan", "Bandera");
    arrayAdd(array, "Mohan", "Gandhi");
}

void arrayAdd(PersonArray* array, char* name, char* surname)
{
    array->size++;
    array->array = realloc(array->array, array->size * sizeof(Person*));

    Person* person = malloc(sizeof(Person));
    person->name = malloc((strlen(name) + 1) * sizeof(char));
    strcpy(person->name, name);
    person->surname = malloc((strlen(surname) + 1) * sizeof(char));
    strcpy(person->surname, surname);

    array->size--;
    array->array[array->size] = person;
    array->size++;
}

void arrayPrint(PersonArray* array) // + +
{
    for (size_t i = 0; i < array->size; i++)
        printf(" [%s %s]\n", array->array[i]->name, array->array[i]->surname);
}

void arrayFree(PersonArray* array)
{
    printf(" \n | Array clear |\n");
    for (size_t i = 0; i < array->size; i++)
    {
        free(array->array[i]->name);
        free(array->array[i]->surname);
        free(array->array[i]);
    }
    free(array->array);
    free(array);
}


int sortingForName(Person* a, Person* b)
{
    return strcmp(a->name, b->name);
}

int sortingForSurname(Person* a, Person* b)
{
    return strcmp(a->surname, b->surname);
}

void bubbleSorting(PersonArray* array, function sort) 
{
    for (size_t i = 0; i < array->size - 1; i++)
    {
        for (size_t j = 0; j < array->size - i - 1; j++)
        {
            int comparison = sort(array->array[j], array->array[j + 1]);
            if (comparison > 0)
            {
                Person* temp = array->array[j];
                array->array[j] = array->array[j + 1];
                array->array[j + 1] = temp;
            }
        }
    }
}