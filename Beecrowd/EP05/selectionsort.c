#include <stdio.h>
#include <stdlib.h>

#define MAX 20000 // valor do max deve ser alterado caso deseje um teste com um vetor de N diferentes posições;

void SelectionSort(int vet[], int n)
{
    int i, j, min, temp;
    for (i = 0; i < n - 1; i++)
    {
        min = i; // assume que o menor elemento restante é o atual (i)
        for (j = i + 1; j < n; j++)
        { // itera sobre os elementos restantes do array
            if (vet[j] < vet[min])
            {            // verifica se o elemento atual é menor do que o menor elemento restante
                min = j; // atualiza o índice do menor elemento
            }
        }
        temp = vet[min];   // guarda o valor do menor elemento em uma variável temporária
        vet[min] = vet[i]; // substitui o menor elemento pelo elemento atual
        vet[i] = temp;     // substitui o elemento atual pelo menor elemento
    }
}

int main()
{
    int i;
    int vet[MAX];
    // preencher o vetor, caso deseje fazer diferente testes com numeros aleatorios, ative a linha abaixo:
    // srand(time(NULL)

    for (i = 0; i < MAX; i++)
    {
        vet[i] = rand();
    }

    SelectionSort(vet, MAX);

    return 0;
}
