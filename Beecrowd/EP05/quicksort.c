#include <stdio.h>
#include <stdlib.h>

#define MAX 20000 // valor do max deve ser alterado caso deseje um teste com um vetor de N diferentes posições;

int Separa(int p, int n, int vet[])
{
    int c, j, k, t;
    c = vet[n];
    j = p;
    for (k = p; k < n; k++)
        if (vet[k] <= c)
        {
            t = vet[j];
            vet[j] = vet[k];
            vet[k] = t;
            j++;
        }
    vet[n] = vet[j];
    vet[j] = c;

    return j;
}

void QuickSort(int p, int n, int vet[])
{
    int j;
    if (p < n)
    {
        j = Separa(p, n, vet);
        QuickSort(p, j - 1, vet);
        QuickSort(j + 1, n, vet);
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

    QuickSort(0, MAX - 1, vet);

    return 0;
}
