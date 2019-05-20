#include "ABB_AVL.h"
#include <iostream>
#include <limits.h>

using namespace std;

Arv_bin * abb_cria() {
	Arv_bin* arv = (Arv_bin*)malloc(sizeof(Arv_bin));
	arv->raiz = NULL;
	return arv;
}

Nodo* new_nodo(int k) {
	Nodo* no = (Nodo*)malloc(sizeof(Nodo));
	no->info = k;
	no->alt = 0;
	no->esq = no->dir = NULL;
	return no;
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
	if (raiz == NULL) return new_nodo(k);
	if(k < raiz->info) raiz->esq = insere_no(raiz->esq, k);
	else if (k > raiz->info) raiz->dir = insere_no(raiz->dir, k);
	else return raiz;
	raiz->alt = 1 + Max(altura(raiz->esq), altura(raiz->dir));
	int fb = fb_nodo(raiz);
	if (fb < -1 && k < raiz->esq->info) return rotRight(raiz);
	if (fb < -1 && k > raiz->esq->info) {
		raiz->esq = rotLeft(raiz->esq);
		return rotRight(raiz);
	}
	if (fb > 1 && k > raiz->esq->info) return rotLeft(raiz);
	if (fb > 1 && k < raiz->esq->info) {
		raiz->dir = rotRight(raiz->dir);
		return rotLeft(raiz);
	}
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
	else if (k < raiz->info) raiz->esq = abb_remove_no(raiz->esq, k);
	else if (k > raiz->info) raiz->dir = abb_remove_no(raiz->dir, k);
	else {
		if (raiz->esq == NULL && raiz->dir == NULL) {
			free(raiz);
			raiz = NULL;
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
			Nodo* aux = raiz->esq;
			while (aux->dir != NULL) aux = aux->dir;
			raiz->info = aux->info;
			aux->info = k;
			raiz->esq = abb_remove_no(raiz->esq, k);
		}
	}
	raiz->alt = 1 + Max(altura(raiz->esq), altura(raiz->dir));
	int fb = fb_nodo(raiz);
	// left left case
	if (fb < -1 && fb_nodo(raiz->esq) <= 0) return rotRight(raiz);
	//left right case
	if (fb < -1 && fb_nodo(raiz->esq) > 0) {
		raiz->esq = rotLeft(raiz->esq);
		return rotRight(raiz);
	}
	// right right case
	if (fb > 1 && fb_nodo(raiz->dir) <= 0) return rotLeft(raiz);
	//right left case
	if (fb > 1 && fb_nodo(raiz->dir) > 0) {
		raiz->dir = rotRight(raiz->dir);
		return rotLeft(raiz);
	}
	return raiz;
}
int altura(Nodo* raiz) {
	if (raiz == NULL) return -1;
	return raiz->alt;
}
int fb_nodo(Nodo* raiz) {
	if (raiz == NULL) return 0;
	return altura(raiz->dir) - altura(raiz->esq);
}
int Max(int alt_sae, int alt_sad) {
	return alt_sae > alt_sad ? alt_sae : alt_sad;
}
Nodo* rotRight(Nodo* z) {
	Nodo* y = z->esq;
	Nodo* w = y->dir;
	y->dir = z;
	z->esq = w;
	y->alt = 1 + Max(altura(y->esq), altura(y->dir));
	z->alt = 1 + Max(altura(z->esq), altura(z->dir));
	return y;
}
Nodo* rotLeft(Nodo* z) {
	Nodo* y = z->dir;
	Nodo* w = y->esq;
	y->esq = z;
	z->dir = w;
	y->alt = 1 + Max(altura(y->esq), altura(y->dir));
	z->alt = 1 + Max(altura(z->esq), altura(z->dir));
	return y;

}