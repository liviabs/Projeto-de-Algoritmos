#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#ifdef _WIN32
    #include <direct.h>
    #define MKDIR(x) _mkdir(x)
#else
    #define MKDIR(x) mkdir(x, 0777)
#endif

#include "salvar.h"

// Salvar vetor em arquivo
void salvarEmArquivo(const char *nomeArquivo, int *a, int n) {
    FILE *f = fopen(nomeArquivo, "w");
    if (!f) {
        printf("Erro ao criar arquivo %s\n", nomeArquivo);
        exit(1);
    }

    fprintf(f, "%d\n\n", n);
    for (int i = 0; i < n; i++) {
        fprintf(f, "%d\n", a[i]);
    }
    fprintf(f, "\n");
    fclose(f);
}

// Salvar tempo em arquivo
void salvarTempo(const char *nomeArquivo, double tempo) {
    FILE *f = fopen(nomeArquivo, "w");
    if (!f) {
        printf("Erro ao criar arquivo %s\n", nomeArquivo);
        exit(1);
    }
    fprintf(f, "Tempo de execução: %.6f segundos\n", tempo);
    fclose(f);
}

// Criar pastas
void criarPastas(const char *algoritmo) {
    char caminho[200];

    // Pasta principal
    MKDIR(algoritmo);

    // Pastas principais
    sprintf(caminho, "%s/entrada", algoritmo);
    MKDIR(caminho);
    sprintf(caminho, "%s/saida", algoritmo);
    MKDIR(caminho);
    sprintf(caminho, "%s/tempo", algoritmo);
    MKDIR(caminho);

    // Subpastas
    sprintf(caminho, "%s/entrada/crescente", algoritmo);
    MKDIR(caminho);
    sprintf(caminho, "%s/entrada/decrescente", algoritmo);
    MKDIR(caminho);
    sprintf(caminho, "%s/entrada/random", algoritmo);
    MKDIR(caminho);

    sprintf(caminho, "%s/saida/crescente", algoritmo);
    MKDIR(caminho);
    sprintf(caminho, "%s/saida/decrescente", algoritmo);
    MKDIR(caminho);
    sprintf(caminho, "%s/saida/random", algoritmo);
    MKDIR(caminho);

    sprintf(caminho, "%s/tempo/crescente", algoritmo);
    MKDIR(caminho);
    sprintf(caminho, "%s/tempo/decrescente", algoritmo);
    MKDIR(caminho);
    sprintf(caminho, "%s/tempo/random", algoritmo);
    MKDIR(caminho);
}
