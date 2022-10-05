#include <stdio.h>
#include <stdlib.h>

struct nodo
{
    int valor;
	struct nodo *dir;
	struct nodo *esq;
}; typedef struct nodo Nodo;

Nodo *create(int value){
    Nodo *n = (Nodo*) malloc(sizeof(Nodo));
    n->valor = value;
    n->dir = NULL;
    n->esq = NULL;
    return n;
}

void add(Nodo *n, int value){
    if(value < n->valor){ // se o value for menor que o valor do nó será adicionado a esquerda
        if(n->esq == NULL){
            n->esq = create(value); // se a esquerda estiver fazia eu adiciono o nó lá
        } else{ // caso a esquerda não esteja vazia
            add(n->esq, value);
        }
    } else{ // se for maior vai adicionar a direita
        if(n->dir == NULL){ // se estiver adiciona direto
            n->dir = create(value);
        } else{ // se não faz a chamada recursiva
            add(n->dir, value);
        }
    }
}

void retira(Nodo *n, int valor){
	Nodo *filho = n;
	Nodo *pai;
	do{
		pai = filho;
		if(valor < filho->valor)
			filho = filho->esq;
		else if(valor > filho->valor)
			filho = filho->dir;	
	}while(filho!=NULL && filho->valor != valor);

	if(filho != NULL){ // nodo com o valor correspondente encontrado
		if(filho->esq == NULL && filho->dir == NULL){ // nodo folha
			printf("%d é nodo folha\n",valor);
			if(pai->esq == filho) pai->esq = NULL;
			if(pai->dir == filho) pai->dir = NULL;
		}
		if(filho->esq != NULL && filho->dir == NULL){ // nodo com 1 filho a esquerda
			printf("%d tem um filho a esquerda\n",valor);
			if(pai->esq == filho) pai->esq = filho->esq;
			if(pai->dir == filho) pai->dir = filho->esq;
		}
		if(filho->esq == NULL && filho->dir != NULL){ // nodo com 1 filho a direita
			printf("%d tem um filho a direita\n",valor);
			if(pai->esq == filho) pai->esq = filho->dir;
			if(pai->dir == filho) pai->dir = filho->dir;
		}
		if(filho->esq != NULL && filho->dir != NULL) // nodo com 2 filhos
		{
			printf("%d tem dois filhos\n",valor);
			if(filho->esq->dir==NULL){
				filho->valor = filho->esq->valor;
				filho->esq = NULL;
			}else{
				Nodo *p = filho->esq;
				Nodo *aux = p;
				while(p->dir != NULL){
					aux = p;
					p = p->dir;
				}
				aux->dir = NULL;
				filho->valor = p->valor;
			}
		}
	}
}

    


void imprimir1(Nodo *n){
    if(n == NULL)
        return;
    printf("%d ", n->valor);
    imprimir1(n->esq);
    imprimir1(n->dir);
}

void imprimir2(Nodo *nodo, int tab)
{
    for (int i = 0; i < tab; i++) {
        printf("-");
}
    if (nodo != NULL) {
        printf("%d\n", nodo->valor);
        imprimir2(nodo->esq, tab + 2);
        printf("\n");
        imprimir2(nodo->dir, tab + 2);
} else{ 
    printf("vazio");
    }
}

int main(int argc, char const *argv[])
{
    // forma de inserção manual
    Nodo *raiz = create(5);
    raiz->esq = create(2);
    raiz->esq->esq = create(1);
    raiz->dir = create(8);
    raiz->esq->dir = create(4);
    imprimir2(raiz, 0);
    printf("\n\n\n\n");
    /*
    FORMA ANALOGA

    Nodo *nodo5 = create(5);
	Nodo *nodo2 = create(2);
	Nodo *nodo1 = create(1);
	Nodo *nodo8 = create(8);
	Nodo *nodo4 = create(4);

	nodo5->esq = nodo2;
	nodo2->esq = nodo1;
	nodo5->dir = nodo8;
	nodo2->dir = nodo4;
    */

   // com a função de inserção
   Nodo *root = create(15);
   add(root, 8);
   add(root, 20);
   add(root, 4);
   add(root, 19);
   add(root, 12);
   add(root, 25);
   add(root, 13);
   imprimir2(root, 0);
   /*
   DESENHO DA ÁRVORE
        15
    8         20
  4   12   19    25
        13
   */

  /*
  Existem 3 casos para remoção de nós de uma árvore:
● Caso 1: nó a ser removido não tem filhos
    ○ Nesse caso o nó PAI aponta para NULL
● Caso 2: nó a ser removido só tem um filho.
    ○ Nesse caso o nó PAI aponta para esse filho.
● Caso 3: nó a ser removido tem 2 filhos
    ○ Nesse caso o nó é substituído pelo nodo mais à direita do seu nó esquerdo.
    ○ Ou pelo nó mais à esquerda do seu nó direito.
    ○ Substituir o Nodo 3 pelo nodo mais à esquerda de seu nodo direito.
    ○ Substituir o Nodo 3 pelo nodo mais à direita de seu nodo esquerdo.
  */


    return 0;
}
