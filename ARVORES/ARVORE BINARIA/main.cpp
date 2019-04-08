#include "arv_bin.h"
#include <iostream>

using namespace std;

int main() {
	printf("TAD de uma arvore binaria\n");
	Arv_bin* arv = arv_cria(
					arv_cria_no('a',
									arv_cria_no('b',
										arv_cria_no('d',
												arv_cria_no('h', NULL, NULL),
												NULL),
										arv_cria_no('e', NULL, NULL)
										),
									arv_cria_no('c',
										arv_cria_no('f', NULL, NULL),
										arv_cria_no('g', NULL, NULL)
										)
					)
	);
	printf("impressao em pre ordem: ");
	arv_imprime_escolhendo_ordem(arv, 1);
	printf("impressao em in ordem: ");
	arv_imprime_escolhendo_ordem(arv, 2);
	printf("impressao em pos ordem: ");
	arv_imprime_escolhendo_ordem(arv, 3);
	printf("impressao formatada: ");
	arv_imprime_formatado(arv);
	printf("'h' pertence a arvore? ");
	arv_pertence(arv, 'h') ? printf("sim\n"): printf("nao\n");
	printf("'k' pertence a arvore? ");
	arv_pertence(arv, 'k') ? printf("sim\n"): printf("nao\n");
	printf("existe um nodo com 'g'?");
	Nodo* n = arv_busca(arv, 'g');
	if(n!=NULL)printf("sim\n"); else printf("nao\n");
	printf("altura da arvore : %d\n",arv_altura(arv));
	printf("tamanho da arvore : %d\n", tamanho(arv));
	//arv_imprime_iterativo_in_ordem(arv);
	arv_libera(arv);
	system("PAUSE");

	return 0;
}