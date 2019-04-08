#include <iostream>
#include  "Arv_bin_busca.h"

using namespace std;

int main() {
	//questao 1
	Arv_bin* arv = abb_cria();
	abb_insere(arv, 50);
	abb_insere(arv, 30);
	abb_insere(arv, 70);
	abb_insere(arv, 20);
	abb_insere(arv, 40);
	abb_insere(arv, 60);
	abb_insere(arv, 80);
	abb_insere(arv, 15);
	abb_insere(arv, 25);
	abb_insere(arv, 35);
	abb_insere(arv, 45);
	abb_insere(arv, 36);
	abb_remove(arv, 30);
	arv_imprime_formatado(arv);
	system("PAUSE");
	return 0;
}