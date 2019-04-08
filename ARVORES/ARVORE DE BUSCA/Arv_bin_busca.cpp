#include "Arv_bin_busca.h"
#include <iostream>
#include <limits.h>

using namespace std;

Arv_bin * abb_cria() {
	Arv_bin* arv = (Arv_bin*)malloc(sizeof(Arv_bin));
	arv->raiz = NULL;
	return arv;
}

Nodo* abb_busca_iterativa(Nodo* raiz, int k) {
	while (raiz != NULL && raiz->info != k) {
		if (k < raiz->info) raiz = raiz->esq;
		else raiz = raiz->dir;
		return raiz;
	}
	return NULL;
}
void abb_insere(Arv_bin* arv, int k) {
	arv->raiz = insere_no(arv->raiz, k);
}
Nodo* insere_no(Nodo* raiz, int k) {
	if (raiz == NULL) {
		raiz = (Nodo*)malloc(sizeof(Nodo));
		raiz->info = k;
		raiz->esq = raiz->dir = NULL;
	}
	else if (k < raiz->info) raiz->esq = insere_no(raiz->esq, k);
	else raiz->dir = insere_no(raiz->dir, k);
	return raiz;
}

void arv_imprime_formatado(Arv_bin* arv) {
	arv_imprime_formatado_no(arv->raiz);
	printf("\n");
}

void arv_imprime_formatado_no(Nodo* raiz) {
	printf("<");
	if (raiz != NULL) {
		printf("%d", raiz->info);
		arv_imprime_formatado_no(raiz->esq);
		arv_imprime_formatado_no(raiz->dir);
	}
	printf(">");
}
void arv_libera(Arv_bin* arv) {
	arv_libera_no(arv->raiz);
	free(arv);
}
void arv_libera_no(Nodo* raiz) {
	if (raiz != NULL) {
		arv_libera_no(raiz->esq);
		arv_libera_no(raiz->dir);
		free(raiz);
	}
}
Nodo* abb_busca_no(Nodo* raiz, int k) {
	if (raiz == NULL || raiz->info == k) return raiz;
	if (k < raiz->info) return abb_busca_no(raiz->esq, k);
	else return abb_busca_no(raiz->dir, k);
	return NULL;
}
Nodo* abb_busca_no_iterativa(Nodo* raiz, int k) {
	Nodo* no = raiz;
	while (no != NULL && no->info != k) {
		if (k < no->info) no = no->esq;
		else no = no->dir;
	}
	return no;
}
void abb_remove(Arv_bin* arv, int k) {
	arv->raiz = abb_remove_no(arv->raiz, k);
}
Nodo* abb_remove_no(Nodo* raiz, int k) {
	if (raiz == NULL) return NULL;
	else if (k < raiz->info) raiz->esq = abb_remove_no(raiz->esq,k);
	else if (k > raiz->info) raiz->dir = abb_remove_no(raiz->dir,k);
	else {
		if (raiz->esq == NULL && raiz->dir == NULL) {
			free(raiz);
			return NULL;
		}
		else if (raiz->esq == NULL) {
			Nodo* aux = raiz;
			raiz = raiz->dir;
			free(aux);
		}
		else if (raiz->dir == NULL) {
			Nodo* aux = raiz;
			raiz = raiz->esq;
			free(aux);
		}
		else {
			/*Nodo* aux = raiz->esq;
			while (aux->dir != NULL) aux = aux->dir;
			raiz->info = aux->info;
			aux->info = k;
			raiz->esq = abb_remove_no(raiz->esq, k);
			*/
			//questao 2
			Nodo* aux = raiz->dir;
			while(aux->esq != NULL) aux = aux = aux->esq;
			raiz->info = aux->info;
			aux->info = k;
			raiz->dir = abb_remove_no(raiz->dir, k);
		
		}
	}
	return raiz;
}
//questao 3
bool vericidade(Nodo* raiz, int k) {
	if (raiz != NULL) {
		if (k < raiz->esq->info || k > raiz->dir->info) return false;
		else return vericidade(raiz->esq, raiz->esq->info) + vericidade(raiz->dir, raiz->dir->info);
	}
	return true;
}
// questao 4
int maximo(Arv_bin* arv) {
	Nodo* max = arv->raiz;
	while (max->dir != NULL) max = max->dir;
	return max->info;
}
//questao 5
int minimo(Arv_bin* arv) {
	Nodo* min = arv->raiz;
	while (min->esq != NULL) min = min->esq;
	return min->info;
}
//questao 7
bool abb_igualdade(Nodo* a, Nodo* b) {
	if (a != NULL && b != NULL) {
		if (a->info == b->info) {
			return abb_igualdade(a->esq, b->esq);
			return abb_igualdade(a->dir, b->dir);
		}
		else return false;
	}
	else if ((a == NULL && b != NULL) || (a != NULL && b == NULL))
		return false;
	return true;
}
//questao 8
int filho_unico(Nodo* raiz) {
	if (raiz == NULL) return 0;
	else {
		if (raiz->esq != NULL && raiz->dir == NULL)
			return filho_unico(raiz->esq)+ 1;
		else if (raiz->esq == NULL && raiz->dir != NULL)
			return filho_unico(raiz->dir) + 1;
		else return filho_unico(raiz->esq) + filho_unico(raiz->dir);
	}
}
// questao 9,nao entendi
void construcao(int vet[], Arv_bin* arv, int k) {
	int i = 0;
	while (k > i++) abb_insere(arv, vet[i]);
}
// questao 10, tambem nao entendi
void subsequencia(int seq[], int k, Arv_bin* arv) {
	Nodo*aux;
	int i = 0, n = 0;
	while (k > i++) {
		aux = abb_busca_no(arv->raiz, seq[i]);
		if (aux != NULL) n++;
	}
	if (i == n) printf("a subsequecia faz parte da arvore\n");
	else printf("a subsequencia nao faz parte da arvore\n");
}