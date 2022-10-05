#include <stdio.h>
#include <stdlib.h>


typedef struct pessoa{
    int senha;
    struct pessoa *prox;
} Pessoa;

Pessoa *fila;

void add(int senha){
	Pessoa *p = (Pessoa*) malloc(sizeof(Pessoa));
	p->senha = senha;
	p->prox = NULL;

	if(fila==NULL){
		fila = p;
	}else{
		Pessoa *filaAux = fila;
		while(filaAux->prox!=NULL){
			filaAux = filaAux->prox;
		}
		filaAux->prox = p;
	}
}

void removeFirst(){
	if(fila == NULL){
		printf("Fila vazia!");
	} else{
		fila = fila->prox;
	}
}

void alteraTop(int novo){
	if(fila==NULL){
		printf("Fila vazia!");
	}else{
		Pessoa *filaAux = fila;
		while(filaAux->prox!=NULL){
			filaAux = filaAux->prox;
		}
		filaAux->senha = novo;
	}
}
void alteraIni(int novo){
	fila->senha = novo;
}

void imprime(){ /* para a recursão precisa de um parâmetro Pessoa (exemplo: Pessoa *f) */
//  MÉTODO COM RECURSÃO
// 	if(f!=NULL){
// 		printf("Senha da Pessoa: %d\n",f->senha);
// 		imprime(f->prox);
// }
	Pessoa *aux = fila;
	while(aux != NULL){
		printf("Senha da Pessoa: %d\n",aux->senha);
		aux = aux->prox;
	}
}

int main(void) {
  	add(5);
	add(8);
	add(10);
	add(22);
	alteraTop(3000);
	alteraIni(8000);
	imprime();

	printf("\n");
	add(15);
	// removeFirst();
	imprime();
	printf("\n");

	alteraIni(5000);
	alteraTop(10000);
	imprime();

    return 0;
}