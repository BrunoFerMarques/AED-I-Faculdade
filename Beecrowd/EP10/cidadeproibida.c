#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_CIDADES 1000

typedef struct {
    int cidades[MAX_CIDADES];
    int frente, tras;
}Fila;

void inicializarfila(Fila *fila){
    fila->frente = NULL;
    fila->tras = NULL;
}

bool filavazia(Fila *fila){
    return fila->frente == -1;
}

void enfileirar(Fila *fila, int cidade){
    if (filavazia(fila))
    {
        fila->frente = 0;
        fila-> tras = 0;
    }
    else {
        fila->tras = (fila->tras + 1) % MAX_CIDADES;
    }
    fila->cidades[fila->tras] = cidade;
}

int desenfileirar(Fila *fila){
    int cidade = fila->cidades[fila->frente];
    if (fila->frente == fila->tras)
    {
        fila->frente = -1;
        fila->tras = -1;
    }
    else{
        fila->frente = (fila->frente+1) % MAX_CIDADES;
    }
    return cidade;
}

int busca_minimo(int grafo[MAX_CIDADES][MAX_CIDADES], int numCidades, int inicio, int fim, int evitar)
{
    bool visitadas[MAX_CIDADES] = {false};
    int distancia[MAX_CIDADES];
    Fila fila;
    inicializarfila(&fila);

    visitadas[inicio] = true;
    distancia[inicio] = 0;
    enfileirar(&fila, inicio);

        while (!filavazia(&fila))
        {
            int cidadeatual = desenfileirar(&fila);
            for (int i = 1; i <= numCidades; i++)
            {
                if (grafo[cidadeatual][i] && !visitadas[i] && i != evitar)
                {
                    visitadas[i] = true;
                    distancia[i] = distancia[cidadeatual] + 1;
                    enfileirar(&fila, i);
                    if (i = fim)
                    {
                        return distancia[i];
                    }
                }
            }
        }
    return -1;
}


int main (){

    int numcid, numrotas;
    while (scanf("%d %d", &numcid, &numrotas) == 2)
    {
        int grafo[MAX_CIDADES][MAX_CIDADES] = {{0}};
        int cidadeA, cidadeB;
        for (int i = 0; i < numrotas; i++)
        {
        scanf("%d %d", &cidadeA, &cidadeB);
            grafo[cidadeA][cidadeB] = 1;
            grafo[cidadeB][cidadeA] = 1;
        }

        int curitiba, riachoDeJaneiro, estadunido;
        scanf("%d %d %d", &curitiba, &riachoDeJaneiro, &estadunido);

        int minimoHoras = busca_minimo(grafo, numcid, curitiba, riachoDeJaneiro, estadunido);
        printf("%d\n", minimoHoras);

    }


}
