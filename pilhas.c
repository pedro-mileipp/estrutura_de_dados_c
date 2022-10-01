#include <stdio.h>
#include <stdlib.h>


typedef struct prato{
    char cor;
    struct prato *prox;
} Prato;

Prato *pilha;

void add(char cor){
    Prato *p = (Prato*) malloc(sizeof(Prato));
    p->cor = cor;
    p->prox = pilha;
    pilha = p;
}

void retira(){
    if(pilha == NULL){
        printf("Pilha vazia!");
    } else{
        pilha = pilha->prox;
    }
}

void imprime(){ /* para a recursão precisa de um parâmetro Pessoa (exemplo: Prato *p) */
//  MÉTODO COM RECURSÃO
// 	if(p!=NULL){
// 		printf("Senha da Pessoa: %c\n",p->cor);
// 		imprime(p->prox);
// }
	Prato *aux = pilha;
	while(aux != NULL){
		printf("Senha da Pessoa: %c\n",aux->cor);
		aux = aux->prox;
	}
}

int main(void) {
    add('g');
    add('r');
    add('b');
    add('y');
    retira();
    imprime();
    return 0;
}