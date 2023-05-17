#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int encontrarIndice(char *str, int inicio, int fim, char caractere)
{
    for (int i = inicio; i <= fim; i++)
    {
        if (str[i] == caractere)
        {
            return i;
        }
    }
    return -1;
}

void construirPosfixo(char *prefixo, char *infixo, int inicio, int fim, int *indice)
{
    if (inicio > fim)
    {
        return;
    }

    char raiz = prefixo[*indice];
    (*indice)++;

    if (inicio == fim)
    {
        printf("%c", raiz);
        return;
    }

    int indiceRaiz = encontrarIndice(infixo, inicio, fim, raiz);

    construirPosfixo(prefixo, infixo, inicio, indiceRaiz - 1, indice);
    construirPosfixo(prefixo, infixo, indiceRaiz + 1, fim, indice);

    printf("%c", raiz);
}

int main()
{
    int C;
    scanf("%d", &C);

    while (C--)
    {
        int N;
        scanf("%d", &N);

        char prefixo[N + 1];
        char infixo[N + 1];
        scanf("%s %s", prefixo, infixo);

        int indice = 0;
        construirPosfixo(prefixo, infixo, 0, N - 1, &indice);
        printf("\n");
    }

    return 0;
}
