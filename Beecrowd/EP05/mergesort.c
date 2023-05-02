#include <stdio.h>
#include <stdlib.h>

#define MAX 20000

// Função para mesclar duas submatrizes ordenadas em um array
void merge(int arr[], int left[], int right[], int leftSize, int rightSize)
{
    int i = 0, j = 0, k = 0;

    // Mescla os elementos em ordem crescente
    while (i < leftSize && j < rightSize)
    {
        if (left[i] <= right[j])
        {
            arr[k++] = left[i++];
        }
        else
        {
            arr[k++] = right[j++];
        }
    }

    // Copia os elementos restantes da submatriz esquerda (se houver algum)
    while (i < leftSize)
    {
        arr[k++] = left[i++];
    }

    // Copia os elementos restantes da submatriz direita (se houver algum)
    while (j < rightSize)
    {
        arr[k++] = right[j++];
    }
}

// Função principal do MergeSort
void mergeSort(int arr[], int size)
{
    if (size < 2)
    {
        return; // Caso base: o array está vazio ou contém apenas um elemento
    }

    int mid = size / 2;
    int left[mid];
    int right[size - mid];

    // Preenche as submatrizes esquerda e direita
    for (int i = 0; i < mid; i++)
    {
        left[i] = arr[i];
    }
    for (int i = mid; i < size; i++)
    {
        right[i - mid] = arr[i];
    }

    // Chamadas recursivas para ordenar as submatrizes esquerda e direita
    mergeSort(left, mid);
    mergeSort(right, size - mid);

    // Mescla as submatrizes ordenadas em um único array
    merge(arr, left, right, mid, size - mid);
}

// Função para imprimir um array
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{

    int i;
    int arr[MAX];

    for (i = 0; i < MAX; i++)
    {
        arr[i] = rand();
    }
    int size = sizeof(arr) / sizeof(arr[0]);

    mergeSort(arr, size);

    return 0;
}
