#include "Heap.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int Parent(int i)
{
	return i / 2;
}

int Left(int i)
{
	return 2*i;
}

int Right(int i)
{
	return 2*i + 1;
}

void exchange(int* a, int* b) 
{
	int aux = *a;
	*a = *b;
	*b = aux;
}
Heap* max_heapify(Heap* vet, int i)
{
	int largest;
	int left = Left(i);
	int right = Right(i);

	if (left <= vet->length && vet->A[left] > vet->A[i])
		largest = left;
	else largest = i;
	if (right <= vet->length && vet->A[right] > vet->A[largest])
		largest = right;
	if (largest != i) {
		exchange(&vet->A[largest], &vet->A[i]);
		vet = max_heapify(vet, largest);
	}
	return vet;
}
void build_max_heap(Heap* vet)
{
	vet->size = vet->length;
	int i;
	for (i = (vet->size) / 2; i > 0; i--)
		vet = max_heapify(vet,i);
}

void heap_sort(Heap * vet)
{
	build_max_heap(vet);
	int i;
	for (i = vet->length; i > 1; i--) {
		exchange(&vet->A[i], &vet->A[1]);
		vet->size--;
		vet = max_heapify(vet, 1);
	}
}

int heap_max(Heap * vet)
{
	return vet->A[1];
}

int extract_max(Heap * vet)
{
	if (vet->size < 1) return -1;
	int max = vet->A[1];
	vet->A[1] = vet->A[vet->size];
	vet->size--;
	vet = max_heapify(vet, 1);
	return max;
}

int heap_increase_key(Heap * vet, int x, int k)
{
	if (k < vet->A[x]) return -1;
	vet->A[x] = k;
	while (x > 1 && vet->A[Parent(x)]) {
		exchange(&vet->A[x], &vet->A[Parent(x)]);
		x = Parent(x);
	}
	return 1;
}

Heap* heap_max_insert(Heap * vet, int k)
{
	vet->size++;
	vet->A[vet->size] = INT_MIN;
	heap_increase_key(vet, vet->size, k);
	return vet;
}

Heap * new_Heap(int n)
{
	Heap* novo = (Heap*)malloc(sizeof(Heap));
	novo->length = n-1;
	novo->A = (int*)malloc((n + 1) * sizeof(int));
	return novo;
}

void print_heap(Heap * vet)
{
	int i;
	for (i = 1; i < vet->length; i++)
		printf("%d ", vet->A[i]);
	printf("\n");
}
