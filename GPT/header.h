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

typedef int (*function)(const Person*, const Person*); // ����� �� �-��

PersonArray* personArray(void); // �������� �������

void personAdd(PersonArray* array); // ���������� �������� (� ������)

void arrayAdd(PersonArray* array, char* name, char* surname); // ����������

void arrayPrint(PersonArray* array); // �����

void arrayFree(PersonArray* array); // ������������ ������


int sortingForName(Person* a, Person* b); // �� �����

int sortingForSurname(Person* a, Person* b); // �� ��������

void bubbleSorting(PersonArray* array, function sort); // ���������� 