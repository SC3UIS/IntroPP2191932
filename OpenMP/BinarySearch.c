#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h> // Incluir la biblioteca de OpenMP

#define SIZE 5000  // Define el tamaño "SIZE" en 5000
void binary_search(int [], int, int, int);
void bubble_sort(int [], int);

int main()
{
    int key, i;
    int list[SIZE];

    // Generar números aleatorios y llenar la lista
    srand(time(NULL));
    printf("Generated list:\n");
    for(i = 0; i < SIZE; i++)
    {
        list[i] = rand() % 5000; // Números aleatorios entre 0 y 5000
        printf("%d ", list[i]);
    }

    double start_time = omp_get_wtime(); // Obtener el tiempo de inicio

    bubble_sort(list, SIZE);
    printf("\n\nSorted list:\n");
    for(i = 0; i < SIZE; i++)
    {
        printf("%d ", list[i]);
    }
    
    key = list[rand() % SIZE]; // Escoger aleatoriamente una clave de la lista ordenada
    printf("\n\nAutomatically chosen key: %d\n", key);
    binary_search(list, 0, SIZE - 1, key);

    double end_time = omp_get_wtime(); // Obtener el tiempo de finalización
    printf("\nTime taken: %f seconds\n", end_time - start_time); // Imprimir el tiempo de ejecución

    return 0;
}

void bubble_sort(int list[], int size)
{
    int temp, i, j;
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size - 1; j++)
        {
            if (list[j] > list[j + 1])
            {
                temp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = temp;
            }
        }
    }
}

void binary_search(int list[], int lo, int hi, int key)
{
    int mid;

    if (lo > hi)
    {
        printf("Key not found\n");
        return;
    }
    mid = (lo + hi) / 2;
    if (list[mid] == key)
    {
        printf("Key found at index %d\n", mid);
    }
    else if (list[mid] > key)
    {
        binary_search(list, lo, mid - 1, key);
    }
    else if (list[mid] < key)
    {
        binary_search(list, mid + 1, hi, key);
    }
}
