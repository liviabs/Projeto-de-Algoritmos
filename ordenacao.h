#ifndef ORDENACAO_H
#define ORDENACAO_H

// Funções de ordenação
void insertionSort(int *a, int n);
void bubbleSort(int *a, int n);
void selectionSort(int *a, int n);
void shellSort(int *a, int n);
void mergeSort(int *a, int inicio, int fim);

void quickSortInicio(int *vet, int inicio, int fim);
int particionaInicio(int *vet, int inicio, int fim);

void quickSortMedio(int *vet, int inicio, int fim);
int particionaMedio(int *vet, int inicio, int fim);

void quickSortAleatorio(int *vet, int inicio, int fim);
int particionaAleatorio(int *vet, int inicio, int fim);

void troca(int *a, int *b);
void minHeapify(int A[], int n, int i);
void buildMinHeap(int A[], int n);
void heapSortMin(int A[], int n); // heapSort clássico


int heap_minimum(int A[], int n);
int heap_extract_min(int A[], int *n);
void heap_increase_key(int A[], int n, int i, int novoValor);
void min_heap_insert(int A[], int *n, int valor);


// Função para gerar vetor conforme tipo
void gerarVetor(int *a, int n, char tipo);

#endif
