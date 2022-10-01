#include <stdio.h>
#include <stdlib.h>

// O conceito de fila é análogo ao que usa-se no mundo real (FIFO: first in, first out), o primeiro na fila será atendido e sairá da fila. Portanto, as inserções são feitos no final e as remoções no início. Também é possível usar listas e vetores, neste arquivo utilizaremos a implementações com vetores. Para tal há 5 funções fundamentais para manejar filas.
/*
- Criar uma fila vazia;
- Inserir um elemento no fim;
- Retirar o elemento do início;
- Verificar se a fila está vazia;
- Liberar a fila.
*/      

#define N 10 /* tamanho máximo do vetor */

typedef struct fila{
    int dados[N];
    int fim; /* os dados são inseridos no fim da fila */
} T_Fila;

void fila_inicializa(T_Fila* f){
    int i;
    for(i=0; i<N; i++){
        f->dados[i] = 0;
    }
    f->fim = 0;
    /* os elementos são zerados em todos os índices da fila, pois a fila inicializa vazia */
}

void insere(T_Fila* f, int dado){
    if(f->fim == N){
        printf("Fila cheia!\n");
        exit(1);
    }else{
        f->dados[f->fim] = dado;
        f->fim++;
    }
}

int retira(T_Fila* f){
    int dado, i;
    if(f->fim == 0){
        printf("Fila vazia!\n");
        exit(1);   
    } else{
        dado = f->dados[0];
        for(i=0; i < f->fim; i++){
            f->dados[i] = f->dados[i+1];
        }
        f->fim--;
        return dado;    
    }   
}

void imprime(T_Fila* f){
    int i;
    for(i=0; i < f->fim; i++){
        printf("%d ", f->dados[i]);
    }
}

int main()
{
    T_Fila f1;
    fila_inicializa(&f1);
    insere(&f1, 10);
    insere(&f1, 40);
    retira(&f1);
    imprime(&f1);
    
    return 0;
}
