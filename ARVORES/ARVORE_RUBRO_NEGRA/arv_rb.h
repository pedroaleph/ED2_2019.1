#define RED 1;
#define BLACK 0;

typedef struct arv_rb {
	Nodo* nil;
	Nodo* raiz;
}Arv_rb;

typedef struct nodo {
	int alt;
	int info;
	struct nodo* p;
	struct nodo* esq;
	struct nodo* dir;
	int color;
}Nodo;
