#include "arv_bin.h"
#include <iostream>
#include <stdlib.h>
#include <queue>
#include <stack>
#include <math.h>

using namespace std;
//questao 1
Arv_bin* arv_cria(Nodo* raiz) {
	Arv_bin* arv = (Arv_bin*)malloc(sizeof(Arv_bin));
	arv->raiz = raiz;
	return arv;
}

Nodo* arv_cria_no(char c, Nodo* esq, Nodo* dir) {
	Nodo* nodo = (Nodo*)malloc(sizeof(Nodo));
	nodo->esq = esq;
	nodo->dir = dir;
	nodo->info = c;
	return nodo;
}

void arv_imprime_escolhendo_ordem(Arv_bin * arv, int ordem) {
	if (ordem == 1) arv_imprime_pre_ordem(arv->raiz);
	else if (ordem == 2) arv_imprime_in_ordem(arv->raiz);
	else if (ordem == 3) arv_imprime_pos_ordem(arv->raiz);
	else {
		printf("escolha de 1 a 3\n");
		arv_imprime_escolhendo_ordem(arv, ordem);
	}
	printf("\n");
}
void arv_imprime_pre_ordem(Nodo* raiz) {
	if (raiz != NULL) {
		printf("%c", raiz->info);
		arv_imprime_pre_ordem(raiz->esq);
		arv_imprime_pre_ordem(raiz->dir);
	}
}
void arv_imprime_in_ordem(Nodo* raiz){
	if (raiz != NULL) {
		arv_imprime_in_ordem(raiz->esq);
		printf("%c", raiz->info);
		arv_imprime_in_ordem(raiz->dir);
	}

}
void arv_imprime_pos_ordem(Nodo* raiz) {
	if (raiz != NULL) {
		arv_imprime_pos_ordem(raiz->esq);
		arv_imprime_pos_ordem(raiz->dir);
		printf("%c", raiz->info);
	}

}

void arv_imprime_formatado(Arv_bin* arv) {
	arv_imprime_formatado_no(arv->raiz);
	printf("\n");
}

void arv_imprime_formatado_no(Nodo* raiz) {
	printf("<");
	if (raiz != NULL) {
		printf("%c", raiz->info);
		arv_imprime_formatado_no(raiz->esq);
		arv_imprime_formatado_no(raiz->dir);
	}
	printf(">");
}

void arv_libera(Arv_bin* arv) {
	if (arv != NULL) {
		arv_libera_no(arv->raiz);
		free(arv);
	}
}
void arv_libera_no(Nodo* raiz) {
	if (raiz->esq != NULL)  arv_libera_no(raiz->esq);
	if (raiz->dir != NULL)  arv_libera_no(raiz->dir);
	free(raiz);
}
int arv_pertence(Arv_bin* arv, char a) {
	return arv_pertence_no(arv->raiz, a);
}
int arv_pertence_no(Nodo* raiz, char a) {
	if (raiz == NULL) return 0;
	if (raiz->info == a) return 1;
	if(arv_pertence_no(raiz->esq, a)) return 1;
	return arv_pertence_no(raiz->dir, a);
}
Nodo* arv_busca(Arv_bin* arv, char a) {
	return arv_busca_no(arv->raiz,a);
}
Nodo* arv_busca_no(Nodo* raiz, char a) {
	if (raiz==NULL) return NULL;
	else if (raiz->info == a) return raiz;
	else {
		Nodo* no = arv_busca_no(raiz->esq, a);
		if (no != NULL) return no;
		else return arv_busca_no(raiz->dir, a);
	}
}
int arv_altura(Arv_bin* arv) {
	return arv_altura_no(arv->raiz);
}
int arv_altura_no(Nodo* raiz) {
	if (raiz == NULL) return -1;
	int alt_sae = 1 + arv_altura_no(raiz->esq);
	int alt_sad = 1 + arv_altura_no(raiz->dir);
	return Max(alt_sae, alt_sad);
}
int Max(int alt_sae, int alt_sad) {
	return alt_sae > alt_sad ? alt_sae: alt_sad;
}
//questao 3
int tamanho(Arv_bin* arv) {
	if(arv!=NULL){
		return tamanho_no(arv->raiz);
	}
	return 0;
}
int tamanho_no(Nodo* raiz) {
	if (raiz != NULL) {
		return tamanho_no(raiz->esq) + tamanho_no(raiz->dir) + 1;
	}
	return 0;
}
//questao 2
void largura(Arv_bin* arv) {
	Nodo* no;
	queue<Nodo*> fila;
	fila.push(arv->raiz);
	while (!fila.empty()) {
		no = fila.front();
		fila.pop();
		if (no->esq != NULL) fila.push(no->esq);
		if (no->dir != NULL) fila.push(no->dir);
	}
}
//questao 4, sem testar
void arv_espelho(Arv_bin* arv,Arv_bin* esp) {
	arv_espelho_no(arv->raiz,esp->raiz);
}
void arv_espelho_no(Nodo* raiz, Nodo* esp) {
	if (raiz != NULL) {
		Nodo* no = arv_cria_no(raiz->info,NULL,NULL);
		esp = no;
		arv_espelho_no(raiz->esq, esp->dir);
		arv_espelho_no(raiz->dir, esp->esq);
	}
}
//questao 5, tentei fazer sozinho mas não consegui, então tentei entender o codigo do victor
void arv_imprime_iterativo_in_ordem(Arv_bin* arv) {
	stack<Nodo*> pilha;
	Nodo* no = arv->raiz;
	while (no || !pilha.empty()) {
		if (no != NULL) {
			pilha.push(no);
			no = no->esq;
		}
		else {
			no = pilha.top();
			printf("%c", no->info);
			pilha.pop();
			no = no->dir;
		}

	}
	printf("\n");

}
//questao 6
void arv_imprime_iterativo_pos_ordem(Arv_bin* arv) {
	Nodo *p = NULL;
	Nodo *r = NULL;
	stack<Nodo*> pilha;
	stack<Nodo*> pilha_aux;
	pilha.push(arv->raiz);
	while (!pilha.empty()){
		p = pilha.top();
		pilha_aux.push(p);
		pilha.pop();
		if (p->esq != NULL)
			pilha.push(p->esq);
		if (p->dir != NULL)
			pilha.push(p->dir);

	}
	if (pilha.empty()){
		while (!pilha_aux.empty())
		{
			r = pilha_aux.top();
			printf("%c", r->info);
			pilha_aux.pop();
		}
	}
	printf("\n");
}
//questao 7
int arv_folhas(Arv_bin* arv) {
	if (arv == NULL) return 0;
	return arv_folhas_no(arv->raiz);
}
int arv_folhas_no(Nodo* raiz) {
	if (raiz->esq == NULL && raiz->dir == NULL) return 1;
	return arv_folhas_no(raiz->esq) + arv_folhas_no(raiz->dir);
}
//questao 8
void arv_estrita(Arv_bin* arv) {
	if ((tamanho(arv) - 1) % 2 == 0)
		printf("eh estritamente binaria\n");
	else printf("nao eh estritamento binaria");
}
//questao 9
void arv_completa(Arv_bin* arv) {
	if (2 * (pow(2, arv_altura(arv))) == tamanho(arv) + 1)
		printf("eh completa\n");
	else printf("nao eh completa\n");
}