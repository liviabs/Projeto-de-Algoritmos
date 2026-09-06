#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ordenacao.h"
#include "salvar.h"

int main() {
    int tamanhos[] = {10, 100, 1000, 10000, 100000, 1000000};
    char tiposEntrada[] = {'c', 'd', 'r'};

    int opcaoTamanho, opcaoTipo, opcaoAlgoritmo, opcFila;
    int N;
    char tipoEscolhido;
    const char *algoritmo;

    while (1) {
        // Escolha do algoritmo
        printf("\n==============================\n");
        printf("Escolha o algoritmo de ordenacao:\n");
        printf("1 - Insertion Sort\n");
        printf("2 - Bubble Sort\n");
        printf("3 - Selection Sort\n");
        printf("4 - Shell Sort\n");
        printf("5 - Merge Sort\n");
        printf("6 - QuickSort (pivo no inicio)\n");
        printf("7 - QuickSort (pivo medio)\n");
        printf("8 - QuickSort (pivo aleatorio)\n");
        printf("9 - Heap Sort (Min-Heap)\n");
        printf("10 - Fila de Prioridade \n");
        printf("0 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcaoAlgoritmo);

        if (opcaoAlgoritmo == 0) {
            printf("Encerrando o programa...\n");
            break;
        } else if (opcaoAlgoritmo == 1) {
            algoritmo = "Insertion_Sort";
        } else if (opcaoAlgoritmo == 2) {
            algoritmo = "Bubble_Sort";
        } else if (opcaoAlgoritmo == 3) {
            algoritmo = "Selection_Sort";
        } else if (opcaoAlgoritmo == 4) {
            algoritmo = "Shell_Sort";
        } else if (opcaoAlgoritmo == 5) {
            algoritmo = "Merge_Sort";
        }else if (opcaoAlgoritmo == 6) {
            algoritmo = "QuickSort_Inicio";
        }else if (opcaoAlgoritmo == 7) {
            algoritmo = "QuickSort_Medio";
        }else if (opcaoAlgoritmo == 8) {
            algoritmo = "QuickSort_Aleatorio";
        }else if (opcaoAlgoritmo == 9){
            algoritmo = "HeapSort_Min";
        }else if (opcaoAlgoritmo == 10) {
            opcFila = -1;
            while (opcFila != 0) {
                printf("\n========== FILA DE PRIORIDADE  ==========\n");
                printf("1 - HEAP_MINIMUM\n");
                printf("2 - HEAP_EXTRACT_MIN\n");
                printf("3 - HEAP_INCREASE_KEY\n");
                printf("4 - MIN_HEAP_INSERT\n");
                printf("0 - Voltar ao menu anterior\n");
                printf("Escolha: ");
                scanf("%d", &opcFila);

                if (opcFila == 1) {
                    printf("\n--- HEAP_MINIMUM ---\n");

                    printf("Escolha o tamanho do vetor: ");
                    scanf("%d", &N);

                    int *vet = (int*) malloc(N * sizeof(int));
                    gerarVetor(vet, N, 'r');

                    printf("\nVetor gerado:\n");
                    for (int i = 0; i < N; i++) printf("%d ", vet[i]);

                    buildMinHeap(vet, N);

                    printf("\n\nHeap construido:\n");
                    for (int i = 0; i < N; i++) printf("%d ", vet[i]);

                    int minimo = heap_minimum(vet, N);
                    printf("\n\nMenor elemento encontrado: %d\n", minimo);

                    free(vet);
                }else if (opcFila == 2) {
                    printf("\n--- HEAP_EXTRACT_MIN ---\n");

                    printf("Escolha o tamanho do vetor: ");
                    scanf("%d", &N);

                    int *vet = (int*) malloc(N * sizeof(int));
                    gerarVetor(vet, N, 'r');

                    buildMinHeap(vet, N);

                    printf("\nHeap antes da extracao:\n");
                    for (int i = 0; i < N; i++) printf("%d ", vet[i]);

                    int removido = heap_extract_min(vet, &N);

                    printf("\n\nMenor removido: %d\n", removido);

                    printf("\nHeap depois da extracao:\n");
                    for (int i = 0; i < N; i++) printf("%d ", vet[i]);
                    printf("\n");

                    free(vet);
                }

                else if (opcFila == 3) {
                    printf("\n--- HEAP_INCREASE_KEY ---\n");

                    printf("Escolha o tamanho do vetor: ");
                    scanf("%d", &N);

                    int *vet = (int*) malloc(N * sizeof(int));
                    gerarVetor(vet, N, 'r');

                    buildMinHeap(vet, N);

                    printf("\nHeap inicial:\n");
                    for (int i = 0; i < N; i++) printf("%d ", vet[i]);

                    int pos, valor;
                    printf("\nEscolha a POSICAO para aumentar (0 a %d): ", N-1);
                    scanf("%d", &pos);

                    printf("Digite o NOVO valor (maior que o atual): ");
                    scanf("%d", &valor);

                    heap_increase_key(vet, N, pos, valor);

                    printf("\nHeap depois do increase_key:\n");
                    for (int i = 0; i < N; i++) printf("%d ", vet[i]);
                    printf("\n");

                    free(vet);
                }

                else if (opcFila == 4) {
                    printf("\n--- MIN_HEAP_INSERT ---\n");

                    printf("Escolha o tamanho inicial do vetor: ");
                    scanf("%d", &N);

                    int *vet = (int*) malloc((N+1) * sizeof(int));
                    gerarVetor(vet, N, 'r');

                    buildMinHeap(vet, N);

                    printf("\nHeap inicial:\n");
                    for (int i = 0; i < N; i++) printf("%d ", vet[i]);

                    int valor;
                    printf("\nValor para inserir no heap: ");
                    scanf("%d", &valor);

                    min_heap_insert(vet, &N, valor);

                    printf("\nHeap depois da insercao:\n");
                    for (int i = 0; i < N; i++) printf("%d ", vet[i]);
                    printf("\n");

                    free(vet);
                }
            }
            continue;
        }else {
            printf("Opção inválida!\n");
            continue;
        }

        // Escolha do tipo de vetor
        printf("\nEscolha o tipo de vetor:\n");
        printf("1 - Crescente\n");
        printf("2 - Decrescente\n");
        printf("3 - Aleatorio\n");
        printf("Opcao: ");
        scanf("%d", &opcaoTipo);

        if (opcaoTipo < 1 || opcaoTipo > 3) {
            printf("Opção inválida!\n");
            continue;
        }
        tipoEscolhido = tiposEntrada[opcaoTipo - 1];

        // Escolha do tamanho do vetor
        printf("\nEscolha um tamanho para testar a ordenacao:\n");
        printf("1 - 10\n");
        printf("2 - 100\n");
        printf("3 - 1000\n");
        printf("4 - 10000\n");
        printf("5 - 100000\n");
        printf("6 - 1000000\n");
        printf("Opcao: ");
        scanf("%d", &opcaoTamanho);

        if (opcaoTamanho < 1 || opcaoTamanho > 6) {
            printf("Opção inválida!\n");
            continue;
        }

        int N = tamanhos[opcaoTamanho - 1];
        srand(time(NULL));
        criarPastas(algoritmo);
        int *vet = (int*) malloc(N * sizeof(int));
        if (vet == NULL) {
            printf("Erro: não foi possível alocar memória para o vetor!\n");
            continue;
        }
        gerarVetor(vet, N, tipoEscolhido);
        printf("\nProcessando vetor de tamanho %d (%c)...\n", N, tipoEscolhido);

        char nomeEntrada[200], pastaEntrada[120];
        char nomeSaida[200], pastaSaida[120];
        char nomeTempo[200], pastaTempo[120];

        // Pasta de ENTRADA
        if (tipoEscolhido == 'c')
            sprintf(pastaEntrada, "%s/entrada/crescente/", algoritmo);
        else if (tipoEscolhido == 'd')
            sprintf(pastaEntrada, "%s/entrada/decrescente/", algoritmo);
        else
            sprintf(pastaEntrada, "%s/entrada/random/", algoritmo);

        sprintf(nomeEntrada, "%sentrada_%d_%c.txt", pastaEntrada, N, tipoEscolhido);
        salvarEmArquivo(nomeEntrada, vet, N);

        // Ordenação e tempo
        clock_t inicio = clock();
        if (opcaoAlgoritmo == 1)
            insertionSort(vet, N);
        else if (opcaoAlgoritmo == 2)
            bubbleSort(vet, N);
        else if (opcaoAlgoritmo == 3)
            selectionSort(vet, N);
        else if (opcaoAlgoritmo == 4)
            shellSort(vet, N);
        else if (opcaoAlgoritmo == 5)
            mergeSort(vet, 0, N - 1);
        else if (opcaoAlgoritmo == 6)
            quickSortInicio(vet, 0, N - 1);
        else if (opcaoAlgoritmo == 7)
            quickSortMedio(vet, 0, N - 1);
        else if (opcaoAlgoritmo == 8)
            quickSortAleatorio(vet, 0, N - 1);
        else if (opcaoAlgoritmo == 9)
            heapSortMin(vet, N);

        clock_t fim = clock();
        double tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;

        // Pasta de SAÍDA
        if (tipoEscolhido == 'c')
            sprintf(pastaSaida, "%s/saida/crescente/", algoritmo);
        else if (tipoEscolhido == 'd')
            sprintf(pastaSaida, "%s/saida/decrescente/", algoritmo);
        else
            sprintf(pastaSaida, "%s/saida/random/", algoritmo);

        sprintf(nomeSaida, "%ssaida_%d_%c.txt", pastaSaida, N, tipoEscolhido);
        salvarEmArquivo(nomeSaida, vet, N);

        // Pasta de TEMPOS
        if (tipoEscolhido == 'c')
            sprintf(pastaTempo, "%s/tempo/crescente/", algoritmo);
        else if (tipoEscolhido == 'd')
            sprintf(pastaTempo, "%s/tempo/decrescente/", algoritmo);
        else
            sprintf(pastaTempo, "%s/tempo/random/", algoritmo);

        sprintf(nomeTempo, "%stempo_%d_%c.txt", pastaTempo, N, tipoEscolhido);
        salvarTempo(nomeTempo, tempo);

        free(vet);


        printf("FIM DA ORDENACAO!\n");
    }

    return 0;
}
