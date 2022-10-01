#include <stdio.h>
#include <stdlib.h>

// O conceito de fila é análogo ao que usa-se no mundo real (FIFO: first in, first out), o primeiro na fila será atendido e sairá da fila. Portanto, as inserções são feitos no final e as remoções no início. Também é possível usar listas e vetores, neste arquivo utilizaremos a implementações com filas. Para tal há 5 funções fundamentais para manejar filas.
/*
- Criar uma fila vazia;
- Inserir um elemento no fim;
- Retirar o elemento do início;
- Verificar se a fila está vazia;
- Liberar a fila.
*/      

typedef struct no{
    int dado;
    struct no* prox;
} No;

typedef struct fila{
    No* ini;
    No* fim;
} Fila;

void insere(Fila* f, int paramDado){
    No* ptr = (No*) malloc(sizeof(No));
    if(ptr == NULL){
        printf("Erro de alocação!\n");
        exit(1);
    } else{
        ptr->dado = paramDado; // atribuindo o dado ao nó atual
        ptr->prox = NULL; // o proximo no não teve nenhuma inserção, então para não haver lixo de memória, ele será nulo
    }

    if(f->ini == NULL){ // para o caso da primeira inserção, onde o início será nulo, o nó será adicionado no início
        f->ini = ptr;
    } else{
        f->fim->prox = ptr;
    }

    f->fim = ptr; // na primeira inserção o fim e o início sempre apontarão para o mesmo nó, porém posteriormente em uma fila todo nó será adicionado no fim
}

int remove(Fila* f){
    No* ptr = f->ini;
    int info;
    if(ptr != NULL){
        f->ini = ptr->prox;
        ptr->prox = NULL;
        info = ptr->dado;
        free(ptr);
        return info;
    } else{
        printf("Fila vazia!\n");
        exit(1);
    }
}

void imprime(Fila *f){
    No* ptr = f->ini;
    if(ptr != NULL){
        while(ptr != NULL){
            printf("%d ", ptr->dado);
            ptr = ptr->prox;
        }
    }else{
        printf("Fila vazia!\n");
        exit(1);       
    }
}