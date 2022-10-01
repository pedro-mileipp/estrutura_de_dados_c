#include <stdio.h>
#include <stdlib.h>

// A ideia da pilha é que os elementos sejam inseridos e retirados do topo, asssim como uma pilha de pratos onde pegamos o prato no topo e para adicionar um prato na pilha colocamos no topo. É possível implentá-la com o uso de vetores e listas, neste arquivo será usado vetores. Para tal, há cinco funções fundamentais para manipularmos pilhas;
/*
- Criar uma pilha vazia;
- Inserir um elemento no topo (push);
- Remover o elemento do topo (pop);
- Verificar se a pilha está vazia;
- Liberar a estrutura da pilha.
*/

#define N 50 /* número máximo de elementos */

// A pilha é composta pelo vetor e número de elementos armazenados
typedef struct pilha{
    int n;
    float vet[N];
} Pilha;

// Função para criar pilha. A função para criar pilha aloca dinamicamente essa estrutura e inicializa a pilha como sendo vazia, isto é, com o número de elementos igual a zero.
Pilha* pilha_cria(){
    Pilha* p = (Pilha*) malloc(sizeof(Pilha));
    p->n = 0; /* inicializa a pilha com zero elementos */
    return p;
}

// Função que verifica se a pilha está vazia
int pilha_vazia(Pilha* p){
    return(p->n == 0);
}

// Função para inserir elemento. Para tal, usamos a próxima posição livre do vetor. Devemos ainda assegurar que há espaço para inserção de um novo elemento, tendo em vista que usamos um vetor de tamanho fixo.
void pilha_push(Pilha* p, float v){
    if(p->n == N){ /* verifica se a pilha atingiu o limite definido */
        printf("Capacidade da pilha estorou!\n");
        exit(1); /* aborta o programa */
    }
    /* insere  elemento próxima posição livre */
    p->vet[p->n] = v; /* no primeiro elemento inserido o valor de n é 0, o que significa que será a base e também o topo, porém nas adições posterioresm sempre irá adicionar no topo, pois logo após o n é incrementado*/
    p->n++;
}

//Função para remover elemento da pilha. A função pop retira o elemento do topo.
float pilha_pop(Pilha* p){
    float v;
    if(pilha_vazia(p)){
        printf("Pilha vazia!\n");
        exit(1);
    }
    /* retira elemento do topo */
    v = p->vet[p->n-1];
    p->n--;
    return v;
}


void pilha_imprime(Pilha* p){
    int i;
    for(i=p->n-1; i >=0; i--){
        printf("%f\n", p->vet[i]);
    }
}

void libera_pilha(Pilha* p){
    free(p);        
}

int main()
{
    Pilha *pilha_exemplo = pilha_cria();
    pilha_push(pilha_exemplo, 5);
    pilha_push(pilha_exemplo, 10);
    pilha_push(pilha_exemplo, 15);
    pilha_push(pilha_exemplo, 20);
    pilha_imprime(pilha_exemplo);
    pilha_pop(pilha_exemplo);
    printf("\n");
    pilha_imprime(pilha_exemplo);
    return 0;
}


