#include <stdio.h>
#include <stdlib.h>
#define MAX 5000
// Função para ajustar o heap máximo
void maxHeapify(int arr[], int size, int root)
{
    int largest = root;       // Inicializa o maior elemento como raiz
    int left = 2 * root + 1;  // Índice do filho esquerdo
    int right = 2 * root + 2; // Índice do filho direito

    // Verifica se o filho esquerdo é maior que a raiz
    if (left < size && arr[left] > arr[largest])
    {
        largest = left;
    }

    // Verifica se o filho direito é maior que a raiz ou o filho esquerdo
    if (right < size && arr[right] > arr[largest])
    {
        largest = right;
    }

    // Se o maior elemento não for a raiz, troca-os
    if (largest != root)
    {
        int temp = arr[root];
        arr[root] = arr[largest];
        arr[largest] = temp;

        // Chama recursivamente para ajustar o sub-heap afetado
        maxHeapify(arr, size, largest);
    }
}

// Função principal do HeapSort
void heapSort(int arr[], int size)
{
    // Constrói um heap máximo a partir do array
    for (int i = size / 2 - 1; i >= 0; i--)
    {
        maxHeapify(arr, size, i);
    }

    // Extrai os elementos um por um do heap e os coloca em ordem crescente
    for (int i = size - 1; i > 0; i--)
    {
        // Move a raiz (maior elemento) para o final do array
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        // Chama a função maxHeapify na submatriz reduzida
        maxHeapify(arr, i, 0);
    }
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

    heapSort(arr, size);

    return 0;
}
