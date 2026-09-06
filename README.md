# 📊 Projeto de Algoritmos — Ordenação e Fila de Prioridade

Projeto de faculdade em **C** feito para estudar e comparar o desempenho de diferentes **algoritmos de ordenação**, além de implementar as operações básicas de uma **fila de prioridade (min-heap)**.

O programa gera vetores de teste, ordena com o algoritmo escolhido, mede o tempo de execução e salva tudo em arquivos, permitindo comparar como cada algoritmo se comporta conforme o tamanho e o tipo do vetor de entrada.

<br>

## 🧩 O que o programa faz

Ao rodar, é exibido um menu no terminal onde você escolhe:

1. **O algoritmo de ordenação** (ou a fila de prioridade)
2. **O tipo do vetor de entrada** — crescente, decrescente ou aleatório
3. **O tamanho do vetor** — 10, 100, 1.000, 10.000, 100.000 ou 1.000.000 elementos

A partir daí, o programa:

1. Gera um vetor com o tamanho e tipo escolhidos (`gerarVetor`)
2. Salva esse vetor em um arquivo de **entrada**
3. Ordena o vetor com o algoritmo escolhido, cronometrando o tempo com `clock()`
4. Salva o vetor já ordenado em um arquivo de **saída**
5. Salva o tempo de execução (em segundos) em um arquivo de **tempo**

Esse ciclo se repete até o usuário escolher a opção `0 - Sair`. As pastas de saída são criadas automaticamente pelo próprio programa (`criarPastas`), então não é preciso criá-las manualmente.

<br>

## 🧩 Algoritmos implementados

### Algoritmos de ordenação (`ordenacao.c` / `ordenacao.h`)

| Opção | Algoritmo | 
|---|---|
| 1 | Insertion Sort | 
| 2 | Bubble Sort | 
| 3 | Selection Sort | 
| 4 | Shell Sort | 
| 5 | Merge Sort | 
| 6 | QuickSort (pivô no início) | 
| 7 | QuickSort (pivô no meio) | 
| 8 | QuickSort (pivô aleatório) | 
| 9 | Heap Sort (min-heap) | 

### Fila de prioridade — min-heap (opção 10 do menu)

Implementação das operações clássicas de heap, testáveis isoladamente pelo menu:

- `HEAP_MINIMUM` — retorna o menor elemento sem removê-lo
- `HEAP_EXTRACT_MIN` — remove e retorna o menor elemento
- `HEAP_INCREASE_KEY` — aumenta o valor de uma posição do heap e restaura a propriedade de heap
- `MIN_HEAP_INSERT` — insere um novo valor no heap

<br>

## 🧩 Tipos de vetor de entrada

A função `gerarVetor` cria o vetor de três formas diferentes, usadas para avaliar o algoritmo em diferentes cenários:

- **Crescente (`c`)** — vetor já ordenado (`1, 2, 3, ..., n`), o melhor caso para a maioria dos algoritmos
- **Decrescente (`d`)** — vetor ordenado ao contrário (`n, n-1, ..., 1`), geralmente o pior caso
- **Aleatório (`r`)** — valores aleatórios entre `0` e `n*10`, caso médio

<br>

## 🧩 Estrutura do projeto

```bash
Projeto de Algoritmos/
├── main.c              # menu interativo e fluxo principal do programa
├── ordenacao.c / .h     # implementação dos algoritmos de ordenação e do min-heap
├── salvar.c / .h        # gravação de arquivos (entrada/saída/tempo) e criação de pastas
├── pa.cbp               # projeto do Code::Blocks
├── pa.depend / pa.layout
├── obj/Debug/           # arquivos objeto gerados na compilação
├── bin/Debug/pa.exe     # executável compilado (Windows)
│
└── <Nome_do_Algoritmo>/       # uma pasta para cada algoritmo testado
    ├── entrada/
    │   ├── crescente/entrada_<N>_c.txt
    │   ├── decrescente/entrada_<N>_d.txt
    │   └── random/entrada_<N>_r.txt
    ├── saida/
    │   ├── crescente/saida_<N>_c.txt
    │   ├── decrescente/saida_<N>_d.txt
    │   └── random/saida_<N>_r.txt
    └── tempo/
        ├── crescente/tempo_<N>_c.txt
        ├── decrescente/tempo_<N>_d.txt
        └── random/tempo_<N>_r.txt
```

Cada algoritmo (`Insertion_Sort`, `Bubble_Sort`, `Selection_Sort`, `Shell_Sort`, `Merge_Sort`, `QuickSort_Inicio`, `QuickSort_Medio`, `QuickSort_Aleatorio`, `HeapSort_Min`) já vem com resultados salvos para os 6 tamanhos de vetor × 3 tipos de entrada, prontos para consulta ou para servir de base em uma análise comparativa.

<br>

## 🧩 Formato dos arquivos gerados

**Arquivo de entrada/saída** (`entrada_<N>_<tipo>.txt` / `saida_<N>_<tipo>.txt`):
```
<tamanho do vetor N>

<elemento 1>
<elemento 2>
...
<elemento N>
```

**Arquivo de tempo** (`tempo_<N>_<tipo>.txt`):
```
Tempo de execução: <segundos> segundos
```

<br>

## 🧩 Como compilar e executar

O projeto foi desenvolvido no **Code::Blocks** com o compilador **GCC (MinGW)**, mas pode ser compilado por linha de comando em qualquer sistema com GCC instalado.

### Pelo Code::Blocks
Abra o arquivo `pa.cbp` no Code::Blocks e use **Build and Run** (F9).

### Pela linha de comando
Na pasta do projeto:

```bash
gcc main.c ordenacao.c salvar.c -o pa
./pa
```

No Windows, o executável já compilado está em `bin/Debug/pa.exe`.

Ao rodar, siga o menu exibido no terminal para escolher o algoritmo, o tipo de vetor e o tamanho desejado.

<br>

## 🧩 Objetivo do projeto

Trabalho da disciplina de Algoritmos, com foco em:

- Implementar na prática os principais algoritmos de ordenação estudados em aula
- Comparar o tempo de execução de cada algoritmo conforme o tamanho da entrada cresce
- Observar o impacto do tipo de entrada (já ordenada, invertida ou aleatória) na performance de cada algoritmo
- Implementar e manipular uma estrutura de fila de prioridade baseada em min-heap
