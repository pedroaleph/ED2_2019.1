#include "arv_rb.h"
#include <stdio.h>

Nodo* RightRot(Arv_rb* T, Nodo* x) {
	Nodo* y = x->esq;
	x->esq = y->dir;
	if (y->dir != T->nil) y->dir->p = x;
	y->p = x->p;
	if (x->p == T->nil) T->raiz = y;
	else if (x->p->esq == x) x->p->esq = y;
	else x->p->dir = y;
	y->dir = x;
	x->p = y;
	return y;
}
Nodo* LeftRot(Arv_rb* T, Nodo* x) {
	Nodo* y = x->dir;
	x->dir = y->esq;
	if (y->esq != T->nil) y->esq->p = x;
	y->p = x->p;
	if (x->p == T->nil) T->raiz = y;
	else if (x->p->dir == x) x->p->dir = y;
	else x->p->esq = y;
	y->esq = x;
	x->p = y;
	return y;
}
Nodo* insert(Arv_rb* T, Nodo* z) {
	Nodo* y = T->nil;
	Nodo* x = T->raiz;
	while (x != T->nil) {
		y = x;
		if (z->info < x->info) x = x->esq;
		else x = x->dir;
	}
	z->p = y;
	if (y == T->nil) T->raiz = z;
	else if (z->info < y->info) y->esq = z;
	else y->dir = z;
	z->esq = z->dir = T->nil;
	z->color = RED;
	return insert_Fixup(T, z);
}
Nodo* insert_Fixup(Arv_rb* T, Nodo* z) {
	while (z->p->color == RED) {
		if (z->p->p->esq = z->p) {
			Nodo* y = z->p->p->dir;
			if (y->color == RED) { // caso 1
				z->p->color = BLACK;
				y->color = BLACK;
				z->p->p->color = RED;
				z = z->p->p;
			}
			else{
				if (z == z->p->dir) { //caso 2
					z = z->p;
					return LeftRot(T, z);
				}
				//caso 3
				z->p->p->color = RED;
				z->p->color = BLACK;
				return RightRot(T, z->p->p);
			}
		else {
			//espelho
		}
	}
		T->raiz->color = BLACK;
		return T->raiz;
}