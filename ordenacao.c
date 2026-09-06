#include <stdio.h>
#include <stdlib.h>
#include "ordenacao.h"

// Função de ordenação Insertion Sort
void insertionSort(int *a, int n) {
    for (int i = 1; i < n; i++) {
        int chave = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > chave) {
            a[j + 1] = a[j];
            j= j - 1;
        }
        a[j + 1] = chave;
    }
}

// Função de ordenação Bubble Sort
void bubbleSort(int *a, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

// Função de ordenação Selection Sort
void selectionSort(int *a, int n) {
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[min]) {
                min = j;
            }
        }
        if (min != i) {
            int tmp = a[i];
            a[i] = a[min];
            a[min] = tmp;
        }
    }
}

// Função de ordenação Shell Sort
void shellSort(int *a, int n) {
    for (int gap = n/2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = a[i];
            int j;
            for (j = i; j >= gap && a[j - gap] > temp; j -= gap) {
                a[j] = a[j - gap];
            }
            a[j] = temp;
        }
    }
}

// Função de ordenação Merge
void merge(int *v, int p, int q, int r) {
    int i = p;
    int j = q + 1;
    int k = 0;
    int m = r - p + 1;

    int *w = (int*) malloc(m * sizeof(int));

    while (i < q + 1 && j < r + 1) {
        if (v[i] <= v[j]) {
            w[k++] = v[i++];
        } else {
            w[k++] = v[j++];
        }
    }
    while (i < q + 1) {
        w[k++] = v[i++];
    }
    while (j < r + 1) {
        w[k++] = v[j++];
    }
    for (i = p, k = 0; i < r + 1; i++, k++) {
        v[i] = w[k];
    }

    free(w);
}
//Função principal do Merge Sort (recursiva)
void mergeSort(int *v, int p, int r) {
    if (p < r) {
        int q = (p + r) / 2;
        mergeSort(v, p, q);
        mergeSort(v, q + 1, r);
        merge(v, p, q, r);
    }
}

//------------------------------------------------------------------------------------------
/**Função de partição usando o primeiro elemento como pivô
int particionaInicio(int *vet, int inicio, int fim) {
    int pivo = vet[inicio];
    int i = inicio + 1;
    int j = fim;
    int temp;

    while (1) {
        // Move i até encontrar elemento maior que o pivô
        while (i <= fim && vet[i] <= pivo)
            i++;
        // Move j até encontrar elemento menor ou igual ao pivô
        while (vet[j] > pivo)
            j--;
        // Se os índices se cruzarem, para
        if (i >= j)
            break;
        // Troca elementos fora de ordem
        temp = vet[i];
        vet[i] = vet[j];
        vet[j] = temp;
    }

    // Coloca o pivô em sua posição final (índice j)
    vet[inicio] = vet[j];
    vet[j] = pivo;

    return j; // Retorna a posição final do pivô
}

// Função recursiva do QuickSort com pivô no início
void quickSortInicio(int *vet, int inicio, int fim) {
    if (inicio < fim) {
        int p = particionaInicio(vet, inicio, fim);
        quickSortInicio(vet, inicio, p - 1);
        quickSortInicio(vet, p + 1, fim);
    }
}**/
//-----------------------------------------------------------------------------

// quicksort (versão iterativa)
int particionaInicio(int *vet, int inicio, int fim) {
    int pivo = vet[inicio];
    int i = inicio + 1;
    int j = fim;
    int temp;

    while (1) {
        while (i <= fim && vet[i] <= pivo)
            i++;
        while (vet[j] > pivo)
            j--;
        if (i >= j)
            break;
        temp = vet[i];
        vet[i] = vet[j];
        vet[j] = temp;
    }
    vet[inicio] = vet[j];
    vet[j] = pivo;
    return j;
}
void quickSortInicio(int *vet, int inicio, int fim) {
    // Criar pilha manual
    int *pilha = (int*) malloc((fim - inicio + 1) * sizeof(int));
    int topo = -1;

    pilha[++topo] = inicio;
    pilha[++topo] = fim;

    while (topo >= 0) {
        fim = pilha[topo--];
        inicio = pilha[topo--];
        int p = particionaInicio(vet, inicio, fim);
        // Empilha subvetores maiores que 1 elemento
        if (p - 1 > inicio) {
            pilha[++topo] = inicio;
            pilha[++topo] = p - 1;
        }
        if (p + 1 < fim) {
            pilha[++topo] = p + 1;
            pilha[++topo] = fim;
        }
    }

    free(pilha);
}
//-----------------------------------------------

// quickSort pivo medio (versão 2)
int particionaMedio(int *vet, int inicio, int fim) {
    int meio = (inicio + fim) / 2;
    int pivo = vet[meio];
    int i = inicio;
    int j = fim;
    int temp;

    while (i <= j) {
        while (vet[i] < pivo)
            i++;
        while (vet[j] > pivo)
            j--;
        if (i <= j) {
            temp = vet[i];
            vet[i] = vet[j];
            vet[j] = temp;
            i++;
            j--;
        }
    }

    return i; // retorna o ponto de separação
}
// QuickSort com pivô no meio (versão iterativa para evitar estouro de pilha)
void quickSortMedio(int *vet, int inicio, int fim) {
    int *pilha = (int*) malloc((fim - inicio + 1) * sizeof(int));
    int topo = -1;

    pilha[++topo] = inicio;
    pilha[++topo] = fim;

    while (topo >= 0) {
        fim = pilha[topo--];
        inicio = pilha[topo--];
        int i = particionaMedio(vet, inicio, fim);
        // Empilha subvetores maiores que 1 elemento
        if (inicio < i - 1) {
            pilha[++topo] = inicio;
            pilha[++topo] = i - 1;
        }
        if (i < fim) {
            pilha[++topo] = i;
            pilha[++topo] = fim;
        }
    }

    free(pilha);
}
//---------------------------------------------------------------

//quickSort pivo aleatorio
int particionaAleatorio(int *vet, int inicio, int fim) {
    // Escolhe pivô aleatório e move para o início
    int indicePivo = inicio + rand() % (fim - inicio + 1);
    int temp = vet[inicio];

    vet[inicio] = vet[indicePivo];
    vet[indicePivo] = temp;

    int pivo = vet[inicio];
    int i = inicio + 1;
    int j = fim;
    int troca;

    while (1) {
        while (i <= fim && vet[i] <= pivo)
            i++;
        while (vet[j] > pivo)
            j--;
        if (i >= j)
            break;
        troca = vet[i];
        vet[i] = vet[j];
        vet[j] = troca;
    }

    vet[inicio] = vet[j];
    vet[j] = pivo;
    return j;
}
// QuickSort iterativo com pivô aleatório
void quickSortAleatorio(int *vet, int inicio, int fim) {
    int *pilha = (int*) malloc((fim - inicio + 1) * sizeof(int));
    int topo = -1;

    pilha[++topo] = inicio;
    pilha[++topo] = fim;

    while (topo >= 0) {
        fim = pilha[topo--];
        inicio = pilha[topo--];
        int p = particionaAleatorio(vet, inicio, fim);
        if (p - 1 > inicio) {
            pilha[++topo] = inicio;
            pilha[++topo] = p - 1;
        }
        if (p + 1 < fim) {
            pilha[++topo] = p + 1;
            pilha[++topo] = fim;
        }
    }

    free(pilha);
}


// heap
void troca(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Funções auxiliares
int parent(int i) { return (i - 1) / 2; }
int left(int i) { return 2 * i + 1; }
int right(int i) { return 2 * i + 2; }

void minHeapify(int A[], int n, int i) {
    int l = left(i);
    int r = right(i);
    int menor = i;

    if (l < n && A[l] < A[menor])
        menor = l;
    if (r < n && A[r] < A[menor])
        menor = r;

    if (menor != i) {
        troca(&A[i], &A[menor]);
        minHeapify(A, n, menor);
    }
}


void buildMinHeap(int A[], int n) {
    for (int i = n/2 - 1; i >= 0; i--)
        minHeapify(A, n, i);
}

void heapSortMin(int A[], int n) {
    buildMinHeap(A, n);

    for (int i = n - 1; i > 0; i--) {
        troca(&A[0], &A[i]);   // Menor vai para o final
        minHeapify(A, i, 0);
    }

    for (int i = 0; i < n / 2; i++)
        troca(&A[i], &A[n - 1 - i]);
}

//fila de prioridade

// Retorna o menor elemento
int heap_minimum(int A[], int n) {
    if (n == 0) return -1;
    return A[0];
}

// Remove o menor elemento
int heap_extract_min(int A[], int *n) {
    if (*n <= 0) return -1;

    int min = A[0];
    A[0] = A[*n - 1];
    (*n)--;

    minHeapify(A, *n, 0);
    return min;
}

// Aumenta valor e desce no heap
void heap_increase_key(int A[], int n, int i, int novoValor) {
    if (novoValor < A[i]) return;
    A[i] = novoValor;
    minHeapify(A, n, i);
}

// Insere um novo valor
void min_heap_insert(int A[], int *n, int valor) {
    int i = *n;
    A[i] = valor;
    (*n)++;

    while (i > 0 && A[parent(i)] > A[i]) {
        troca(&A[i], &A[parent(i)]);
        i = parent(i);
    }
}



// Função para gerar vetor conforme tipo
void gerarVetor(int *a, int n, char tipo) {
    if (tipo == 'c') {        // crescente
        for (int i = 0; i < n; i++)
            a[i] = i + 1;
    } else if (tipo == 'd') { // decrescente
        for (int i = 0; i < n; i++)
            a[i] = n - i;
    } else if (tipo == 'r') { // aleatório
        for (int i = 0; i < n; i++)
            a[i] = rand() % (n * 10);
    }
}



