#include <stdio.h>
#include <stdlib.h>

#define MAX 20000 // valor do max deve ser alterado caso deseje um teste com um vetor de N diferentes posições;50050

// funcao insertionSort, passo o vetor e o seu tamanho como parametro;
void InsertionSort(int vet[], int n)
{
    int i, aux, j;
    // crio uma variavel aux para segurar o valor antes da troca.
    for (i = 1; i < n; i++)
    {
        aux = vet[i];
        j = i - 1;
        while (j >= 0 && vet[j] > aux)
        {
            vet[j + 1] = vet[j];
            j = j - 1;
        }
        vet[j + 1] = aux;
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

    InsertionSort(vet, MAX);
}
