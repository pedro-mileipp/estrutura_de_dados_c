#include <stdio.h>
#include <stdlib.h>

// Numa lista encadeada, para cada novo elemento inserido na estrutura, alocamos um espaço de memória para armazená-lo. Dessa forma, o espaço total de memória gasto pela estrutura é proporcional ao número de elementos armazenado. No entanto, não podemos garantir que os elementos armazenados na lista ocuparão um espaço de memória contíguo; portanto, não temos acesso direto aos elementos da lista. Para percorrer todos os elementos da lista devemos explicitamente guardar seu encadeamento, o que é feito armazenando-se, junto com a informação de cada elemento, um ponteiro para o próximo elemento da lista.

// A estrutura consiste em uma estrutura encadeada de elementos, em geral chamados de nós da lista.

// estrutura do nó da lista
struct lista
{
    int info; // informação do nó
    struct lista* prox; // ponteiro com valor nulo para o próximo nó, estrutura auto-referenciada
}; 
typedef struct lista Lista;

// Função de criação. A função que cria uma lista vazia deve ter como valor de retorno uma lista sem nenhum elemento.
Lista* lst_cria(void){
    return NULL; // retorna null porque a lista inicialmente não possui nenhum elemento, pois ela está vazia.
}

// Função de inserção. Uma vez criada a lista vazia, podemos inserir nela novos elementos. Para cada elemento inserido, devemos alocar dinamicamente a memória necessária para armazenar o elemento e encadeá-lo na lista existente. A função de inserção mais simples insere o novo elemento no início da lista.
Lista* lst_insere(Lista* paramLista, int paramNum){
    Lista* novo = (Lista*) malloc(sizeof(Lista));
    novo->info = paramNum; // informação do nó
    novo->prox = paramLista; // estrutura para o próximo nó
    paramLista = novo;
    return novo; // retorna o novo elemento criado e inserido na lista encadeada
}

// Função que percorre a lista para imprimir os termos.
void lst_imprime(Lista* paramLista){
    Lista* aux_lista; /* variável auxiliar para percorrer a lista */
    for (aux_lista = paramLista; aux_lista != NULL; aux_lista = aux_lista->prox){
        printf("info = %d\n", aux_lista->info);
    }
}

// Função que verifica se a lista está vazia
void lst_vazia(Lista* paramLista){
    if(paramLista == NULL)
        printf("Lista vazia!\n");
    else
        printf("Lista com elementos!\n");
}

// Função que busca um elemento na lista
Lista* lst_busca(Lista* paramLista, int num){
    Lista* aux_lista;
    for (aux_lista = paramLista; aux_lista != NULL; aux_lista= aux_lista->prox){
        if(aux_lista->info == num){
            printf("Elemento encontrado!\n");
            return aux_lista;
        }
    }
    return NULL;
}

// Função para retirar um elemento da lista
Lista* lst_retira(Lista* paramLista, int num){
    Lista* ant = NULL; /* ponteiro para o elemento anterior */
    Lista* p = paramLista; /* ponteiro para percorrer a lista */

    /* procura elemento na lista, guardando o elemento anterior */
    while (p != NULL && p->info != num){
        ant = p;
        p = p->prox;
    }

    /* verifica se achou o elemento */
    if(p == NULL){
        return paramLista; /* não achou, retorna a lista original */
    }

    /* retira elemento */
    if (ant == NULL){
        /* retira elemento do início */
        paramLista = p->prox;
    }
    else{
        /* retira elemento do meio da lista */
        ant->prox = p->prox;
    }

    free(p);
    return paramLista;        
}

// Função para liberar a lista
void lst_libera(Lista* paramLista){
    Lista* aux_lista = paramLista;
    while(aux_lista != NULL){
        Lista* t = aux_lista->prox; /* guarda referencia para o próximo elemento */
        free(aux_lista); /* libera a memória apontada por aux_lista */
        aux_lista = t; /* faz aux_lista apontar para o próximo elemento */
    }
}
void *achaMenor(Lista *l){
    Lista *aux_lista = l;
	int qtdVoltas = 0;
    int menor = 0;
	while(aux_lista != NULL){
		if(qtdVoltas == 0){
            menor = aux_lista->info;
        }
        if(aux_lista->info < menor){
            menor = aux_lista->info;
        }
        aux_lista = aux_lista->prox;
        qtdVoltas++;
	}
    printf("Menor elemento: %d", menor);
}


int main(){
    // uso das funções no escopo main
    Lista* lista_exemplo; /* declara uma lista não inicializada */
    lista_exemplo = lst_cria(); /* cria e inicializa a lista como vazia */
    lista_exemplo = lst_insere(lista_exemplo, 23); 
    lista_exemplo = lst_insere(lista_exemplo, 45); 
    lista_exemplo = lst_insere(lista_exemplo, 78); 
    lista_exemplo = lst_insere(lista_exemplo, 31);
    lista_exemplo = lst_insere(lista_exemplo, 10);

   lst_imprime(lista_exemplo); /* imprime 23, 45, 78 e 31 */
    printf("\n");
    lista_exemplo = lst_retira(lista_exemplo, 45); /* retira o elemento 45 da lista */
    lst_imprime(lista_exemplo);
    achaMenor(lista_exemplo);
    lst_libera(lista_exemplo);
    return 0;
}
