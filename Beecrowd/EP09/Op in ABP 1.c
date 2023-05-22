#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct No {
    char letra;
    struct No* esquerda;
    struct No* direita;
} No;

No* criarNo(char letra) {
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->letra = letra;
    novoNo->esquerda = NULL;
    novoNo->direita = NULL;
    return novoNo;
}

No* inserir(No* raiz, char letra) {
    if (raiz == NULL) {
        return criarNo(letra);
    }
    if (letra < raiz->letra) {
        raiz->esquerda = inserir(raiz->esquerda, letra);
    } else if (letra > raiz->letra) {
        raiz->direita = inserir(raiz->direita, letra);
    }
    return raiz;
}

bool buscar(No* raiz, char letra) {
    if (raiz == NULL) {
        return false;
    }
    if (letra == raiz->letra) {
        return true;
    }
    if (letra < raiz->letra) {
        return buscar(raiz->esquerda, letra);
    }
    return buscar(raiz->direita, letra);
}

void emOrdem(No* raiz, bool* primeiroElemento) {
    if (raiz != NULL) {
        emOrdem(raiz->esquerda, primeiroElemento);
        if (!*primeiroElemento) {
            printf(" ");
        }
        printf("%c", raiz->letra);
        *primeiroElemento = false;
        emOrdem(raiz->direita, primeiroElemento);
    }
}

void preOrdem(No* raiz, bool* primeiroElemento) {
    if (raiz != NULL) {
        if (!*primeiroElemento) {
            printf(" ");
        }
        printf("%c", raiz->letra);
        *primeiroElemento = false;
        preOrdem(raiz->esquerda, primeiroElemento);
        preOrdem(raiz->direita, primeiroElemento);
    }
}

void posOrdem(No* raiz, bool* primeiroElemento) {
    if (raiz != NULL) {
        posOrdem(raiz->esquerda, primeiroElemento);
        posOrdem(raiz->direita, primeiroElemento);
        if (!*primeiroElemento) {
            printf(" ");
        }
        printf("%c", raiz->letra);
        *primeiroElemento = false;
    }
}

int main() {
    No* raiz = NULL;
    char comando[10];
    char letra;

    while (scanf("%s", comando) != EOF) {
        if (strcmp(comando, "I") == 0) {
            scanf(" %c", &letra);
            raiz = inserir(raiz, letra);
        } else if (strcmp(comando, "INFIXA") == 0) {
            bool primeiroElemento = true;
            emOrdem(raiz, &primeiroElemento);
            printf("\n");
        } else if (strcmp(comando, "PREFIXA") == 0) {
            bool primeiroElemento = true;
            preOrdem(raiz, &primeiroElemento);
            printf("\n");
        } else if (strcmp(comando, "POSFIXA") == 0) {
            bool primeiroElemento = true;
            posOrdem(raiz, &primeiroElemento);
            printf("\n");
        } else if (strcmp(comando, "P") == 0) {
            scanf(" %c", &letra);
            if (buscar(raiz, letra)) {
                printf("%c existe\n", letra);
            } else {
                printf("%c nao existe\n", letra);
            }
        }
    }

    return 0;
}
