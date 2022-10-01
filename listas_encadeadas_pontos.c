#include <stdio.h>
#include <stdlib.h>

struct ponto
{
	float x;
	float y;
	struct ponto *prox;
}; typedef struct ponto Ponto;

Ponto *listaPontos; // ponteiro para a primeira estrutura
void addFirst(float x, float y){ // inserção no início.
	Ponto* p = (Ponto*) malloc(sizeof(Ponto));
	p->x = x;
	p->y = y;
	p->prox = listaPontos;
	listaPontos = p; 
}

void addLast(float x, float y){
	Ponto* p = (Ponto*) malloc(sizeof(Ponto));
	p->x = x;
	p->y = y;
	p->prox = NULL;
	if(listaPontos == NULL){
		listaPontos = p; // se a lista estiver vazia o último também será o primeiro
	} else{
		Ponto *listaAux = listaPontos;
		while(listaAux->prox != NULL){
			listaAux = listaAux->prox;		 
		}
		listaAux->prox = p;
		// o laço while vai percorrer até o último, quando chegar no último (listaAux->prox == NULL), fazemos listaAux->prox apontar para p.
	}
}

void addIndex(float x, float y, int index){
	Ponto *p = (Ponto*) malloc(sizeof(Ponto));
	p->x = x;
	p->y = y;
	if(index > calcula_tamanho()){
		printf("Posição inválida\n");
	} else{
		if(index == 0){
			p->prox = listaPontos;	
			listaPontos = p;
		} else{
			Ponto *listaAux = listaPontos;
			int i = 0;
			while(i != index-1){
				listaAux = listaAux->prox;
				i++;
			}
			p->prox = listaAux->prox;
			listaAux->prox = p;
		}
	}
}

void removeIndex(int index){
	if(index > calcula_tamanho() || index == 0){
		printf("Remoção inválida! Posição não existe, ou lista vazia\n");
	} else{
		if(index == 0){
			listaPontos = listaPontos->prox;
		} else{
			Ponto *listaAux = listaAux;
			int i = 0;
			while(i != index-1){
				listaAux = listaAux->prox;
				i++;
			}
			listaAux->prox = listaAux->prox->prox;
		}
	}
}

int calcula_tamanho(){
	Ponto *aux = listaPontos;
	int tam = 0;
	while (aux != NULL)
	{
		tam++;
		aux = aux->prox;
	}
	return tam;
}



void imprime(){
	Ponto *aux_lista = listaPontos;
	while(aux_lista != NULL){
		printf("Ponto (%.1f, %.1f) \n", aux_lista->x, aux_lista->y);
		aux_lista = aux_lista->prox;
	}
}


int main() {
	addFirst(1,1);
	addFirst(2,2);
	addFirst(3,3);
	addFirst(4,4);
	addFirst(5,5);
	addIndex(6, 6, 2);	
	removeIndex(1);
	imprime();
	// ordem: 5 4 6 3 2 1
	int tam = calcula_tamanho();
	printf("TAMANHO = %d", tam);

  	return 0;
}