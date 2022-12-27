#ifndef HEADER
#define HEADER

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

// int array

int** IInitArray(int rows, int columns)
{
    int** array = (int**) malloc(rows * sizeof(array));

    for (size_t i = 0; i < rows; i++)
        array[i] = (int*) calloc(columns, sizeof(*array));

    return array;
}

void IFillRandom(int** array, int rows, int columns)
{
    srand(time(NULL));

    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < columns; j++)
        {
            array[i][j] = rand() % 101 - 50;
        }
    }
}

void IFillFile(int** array, int rows, int columns)
{
    FILE* file = fopen("data.txt", "r");

    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < columns; j++)
        {
            fscanf(file, "%d", &array[i][j]);
        }
    }

    fclose(file);
}

void IFillConsole(int** array, int rows, int columns)
{
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < columns; j++)
        {
            printf("Введите элемент array[%lld][%lld] = ", i, j);
            scanf("%d", &array[i][j]);
        }
    }
}

void IPrintFile(int** array, int rows, int columns)
{
    FILE* file = fopen("output.txt", "w");

    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < columns; j++)
        {
            fprintf(file, "%4d ", array[i][j]);
        }
        fprintf(file, "\n");
    }
    
    fclose(file);
}

void IPrintConsole(int** array, int rows, int columns)
{
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < columns; j++)
        {
            printf("%4d ", array[i][j]);
        }
        printf("\n");
    }
}






// float array

float** FInitArray(int rows, int columns)
{
    float** array = (float**) malloc(rows * sizeof(array));

    for (size_t i = 0; i < rows; i++)
        array[i] = (float*) calloc(columns, sizeof(*array));

    return array;
}

void FFillRandom(float** array, int rows, int columns)
{
    srand(time(NULL));

    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < columns; j++)
        {
            array[i][j] = rand() % 101 - 50 + rand() % 101 * 0.01;
        }
    }
}

void FFillFile(float** array, int rows, int columns)
{
    FILE* file = fopen("data.txt", "r");

    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < columns; j++)
        {
            fscanf(file, "%f", &array[i][j]);
        }
    }
}

void FFillConsole(float** array, int rows, int columns)
{
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < columns; j++)
        {
            printf("Введите элемент array[%lld][%lld] = ", i, j);
            scanf("%f", &array[i][j]);
        }
    }
}

void FPrintFile(float** array, int rows, int columns)
{
    FILE* file = fopen("output.txt", "w");

    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < columns; j++)
        {
            fprintf(file, "%8.2f ", array[i][j]);
        }
        fprintf(file, "\n");
    }
    
    fclose(file);
}

void FPrintConsole(float** array, int rows, int columns)
{
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < columns; j++)
        {
            printf("%8.2f", array[i][j]);
        }
        printf("\n");
    }
}






#endif