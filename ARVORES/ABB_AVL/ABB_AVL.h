typedef struct nodo {
	int info;
	int alt;
	struct nodo* esq;
	struct nodo* dir;
}Nodo;
typedef struct arv_bin {
	Nodo* raiz;
}Arv_bin;
Arv_bin* abb_cria();
Nodo* abb_busca_iterativa(Nodo* raiz, int k);
void abb_insere(Arv_bin* arv, int k);
Nodo* insere_no(Nodo* raiz, int k);
void arv_imprime_formatado(Arv_bin* arv);
void arv_imprime_formatado_no(Nodo* raiz);
void arv_libera(Arv_bin* arv);
void arv_libera_no(Nodo* raiz);
Nodo* abb_busca_no(Nodo* raiz, int k);
void abb_remove(Arv_bin* arv, int k);
Nodo* abb_remove_no(Nodo* arv, int k);
int altura(Nodo* arv);
Nodo* new_nodo(int k);
int fb_nodo(Nodo* raiz);
Nodo* rotRight(Nodo* z);
int Max(int alt_sae, int alt_sad);
Nodo* rotLeft(Nodo* z);