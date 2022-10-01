#include <stdio.h>
#include <stdlib.h>

// A ideia da pilha é que os elementos sejam inseridos e retirados do topo, asssim como uma pilha de pratos onde pegamos o prato no topo e para adicionar um prato na pilha colocamos no topo. É possível implentá-la com o uso de vetores e listas, neste arquivo será usado listas. Para tal, há cinco funções fundamentais para manipularmos pilhas;
/*
- Criar uma pilha vazia;
- Inserir um elemento no topo (push);
- Remover o elemento do topo (pop);
- Verificar se a pilha está vazia;
- Liberar a estrutura da pilha.
*/

typedef struct lista{
    float info;
    struct lista* prox;
} Lista;    

typedef struct pilha{
    Lista* prim;
} Pilha;

// Função para criar pilha. Essa função aloca a estrutura da pilha e inicializa como sendo vazia.
Pilha* pilha_cria(){
    Pilha* p = (Pilha*) malloc(sizeof(Pilha));
    p->prim = NULL;
    return p;
}

// O primeiro elemento da lista representa o topo da pilha. Cada novo elemento é inserido no início da lista e, consequentemente, sempre que solicitado, retiramos o elemento também do início da lista. A implementação dessas funções é ilustrada a seguir:

void pilha_push(Pilha* p, float v){
    Lista* n = malloc(sizeof(Lista));
    n->info = v;
    n->prox = p->prim;
    p->prim = n;
}

float pilha_pop(Pilha* p){
    Lista* t;
    float v;
    if(pilha_vazia(p)){
        printf("Pilha vazia!\n");
        exit(1);
    }
    t = p->prim;
    v = t->info;
    p->prim = t->prox;
    free(t);
    return v;    
}

int pilha_vazia(Pilha* p){
    return (p->prim == NULL);
}

void pilha_libera(Pilha* p){
    Lista* q = p->prim;
    while(q != NULL){
        Lista* t = q->prox;
        free(q);
        q = t;
        free(p);
}
}

void pilha_imprime(Pilha* p){
    Lista* q;
    for(q=p; q != NULL; q = q->prox){
        print("%f\n", q->info);
    }
}