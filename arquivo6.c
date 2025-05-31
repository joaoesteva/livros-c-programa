#include <stdio.h>
#include <string.h>

#define MAX_LIVROS 100

typedef struct {
    char titulo[100];
    char autor[100];
    char editora[100];
    int anoPublicacao;
    int qtdPaginas;
} Livro;

void preencherVetor(Livro livros[], int *n) {
    printf("Quantos livros deseja cadastrar? ");
    scanf("%d", n);
    getchar(); // limpar buffer

    for (int i = 0; i < *n; i++) {
        printf("Livro %d:\n", i + 1);
        printf("Título: ");
        fgets(livros[i].titulo, 100, stdin);
        livros[i].titulo[strcspn(livros[i].titulo, "\n")] = 0;

        printf("Autor: ");
        fgets(livros[i].autor, 100, stdin);
        livros[i].autor[strcspn(livros[i].autor, "\n")] = 0;

        printf("Editora: ");
        fgets(livros[i].editora, 100, stdin);
        livros[i].editora[strcspn(livros[i].editora, "\n")] = 0;

        printf("Ano de publicação: ");
        scanf("%d", &livros[i].anoPublicacao);

        printf("Quantidade de páginas: ");
        scanf("%d", &livros[i].qtdPaginas);
        getchar(); // limpar buffer
    }
}

void imprimirVetor(Livro livros[], int n) {
    printf("\nLista de livros:\n");
    for (int i = 0; i < n; i++) {
        printf("[%d] %s - %s - %s - %d - %d páginas\n", i,
               livros[i].titulo,
               livros[i].autor,
               livros[i].editora,
               livros[i].anoPublicacao,
               livros[i].qtdPaginas);
    }
}

int buscarPorTitulo(Livro livros[], int n, char *tituloBuscado) {
    for (int i = 0; i < n; i++) {
        if (strcmp(livros[i].titulo, tituloBuscado) == 0) {
            return i;
        }
    }
    return -1;
}

void ordenarPorTitulo(Livro livros[], int n) {
    Livro temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (strcmp(livros[j].titulo, livros[j + 1].titulo) > 0) {
                temp = livros[j];
                livros[j] = livros[j + 1];
                livros[j + 1] = temp;
            }
        }
    }
}

int buscaBinariaPorTitulo(Livro livros[], int n, char *tituloBuscado) {
    int inicio = 0, fim = n - 1;
    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;
        int cmp = strcmp(livros[meio].titulo, tituloBuscado);
        if (cmp == 0) {
            return meio;
        } else if (cmp < 0) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }
    return -1;
}

int main() {
    Livro livros[MAX_LIVROS];
    int n;

    preencherVetor(livros, &n);
    imprimirVetor(livros, n);

    char tituloBusca[100];
    printf("\nDigite o título a ser buscado (linear): ");
    fgets(tituloBusca, 100, stdin);
    tituloBusca[strcspn(tituloBusca, "\n")] = 0;

    int pos = buscarPorTitulo(livros, n, tituloBusca);
    if (pos != -1)
        printf("Livro encontrado na posição: %d\n", pos);
    else
        printf("Livro não encontrado\n");

    ordenarPorTitulo(livros, n);
    printf("\nVetor ordenado por título:\n");
    imprimirVetor(livros, n);

    printf("\nDigite o título a ser buscado (binária): ");
    fgets(tituloBusca, 100, stdin);
    tituloBusca[strcspn(tituloBusca, "\n")] = 0;

    pos = buscaBinariaPorTitulo(livros, n, tituloBusca);
    if (pos != -1)
        printf("Livro encontrado na posição (binária): %d\n", pos);
    else
        printf("Livro não encontrado (binária)\n");

    return 0;
}
