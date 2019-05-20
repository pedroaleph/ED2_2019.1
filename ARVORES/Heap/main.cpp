#include "Heap.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
	int n = 11;
	Heap* H = new_Heap(n);
	H->A[1] = 16;
	H->A[2] = 14;
	H->A[3] = 10;
	H->A[4] = 8;
	H->A[5] = 7;
	H->A[6] = 9;
	H->A[7] = 3;
	H->A[8] = 2;
	H->A[9] = 4;
	H->A[10] = 1;
	print_heap(H);
	heap_sort(H);
	print_heap(H);
	system("pause");
	return 0;
}