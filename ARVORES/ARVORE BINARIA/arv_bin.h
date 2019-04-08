typedef struct no {
	char info;
	struct no* esq;
	struct no* dir;
}Nodo;
typedef struct arv_bin {
	Nodo* raiz;
} Arv_bin;

Arv_bin* arv_cria(Nodo* raiz);
Nodo* arv_cria_no(char c, Nodo* esq, Nodo* dir);
void arv_imprime_escolhendo_ordem(Arv_bin* arv, int ordem);
void arv_imprime_pre_ordem(Nodo* raiz);
void arv_imprime_in_ordem(Nodo* raiz);
void arv_imprime_pos_ordem(Nodo* raiz);
void arv_imprime_formatado(Arv_bin* arv);
void arv_imprime_formatado_no(Nodo* raiz);
void arv_libera(Arv_bin* arv);
void arv_libera_no(Nodo* raiz);
int arv_pertence(Arv_bin* arv, char a);
int arv_pertence_no(Nodo* raiz, char a);
Nodo* arv_busca(Arv_bin* arv, char a);
Nodo* arv_busca_no(Nodo* raiz, char a);
int arv_altura(Arv_bin* arv);
int arv_altura_no(Nodo* raiz);
int Max(int alt_sae, int alt_sad);
int tamanho(Arv_bin* arv);
int tamanho_no(Nodo* raiz);
void largura(Arv_bin* arv);
void arv_espelho(Arv_bin* arv, Arv_bin* esp);
void arv_espelho_no(Nodo* raiz, Nodo* esp);
void arv_imprime_iterativo_in_ordem(Arv_bin* arv);
void arv_imprime_iterativo_pos_ordem(Arv_bin* arv);
int arv_folhas(Arv_bin* arv);
int arv_folhas_no(Nodo* raiz);
void arv_estrita(Arv_bin* arv);
void arv_completa(Arv_bin* arv);