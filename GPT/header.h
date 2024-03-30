#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <malloc.h>

typedef struct
{
    char* name;
    char* surname;
} Person;

typedef struct
{
    Person** array;
    size_t size;
} PersonArray;

typedef int (*function)(const Person*, const Person*); // адрес на ф-ию

PersonArray* personArray(void); // создание массива

void personAdd(PersonArray* array); // добавление учеников (в ручную)

void arrayAdd(PersonArray* array, char* name, char* surname); // заполнение

void arrayPrint(PersonArray* array); // вывод

void arrayFree(PersonArray* array); // освобождение памяти


int sortingForName(Person* a, Person* b); // по имени

int sortingForSurname(Person* a, Person* b); // по фамиллии

void bubbleSorting(PersonArray* array, function sort); // сортировка 