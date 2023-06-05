#include <stdio.h>
#include <stdlib.h>
typedef struct arvore{
    int n;
    struct *esq;
    struct *dir;
}
typedef struct cel no;
struct *arvore;


void inicializa(arvore r){
    no *ptr = (no)*malloc(sizeof(no));
    ptr->r == 0;
}
void preenche_arvore(arvore r){
    scanf("%d", &k);
    no *ptr = (no)*malloc(sizeof(no));
    if(k > ptr->r){
        ptr->esq == k;
    }
    else{
        ptr->dir == k;
    }
}

void buscabinaria(arvore r){
    no *ptr = (no)*malloc(sizeof(no));
    while(ptr!=NULL){
    }
        
}

int main() {
    arvore Arvore;
    int test, qtdnum;
    scanf("%d %d", &c, &qtdnum);
    int i = 0, j = 0;
    
    while(i <= c){
        while(j <= qtdnum){ 
            preenche_arvore(arvore Arvore);
            j++;
        }    
    i++;
    }
    
    return 0;
}
