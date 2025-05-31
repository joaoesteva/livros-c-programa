#include <stdio.h>
#include <string.h>

#define MAX 100

typedef struct {
    char titulo[100], autor[100], editora[100];
    int ano, paginas;
} Livro;

void preencher(Livro v[], int *n) {
    printf("Qtd de livros: "); scanf("%d", n); getchar();
    for (int i = 0; i < *n; i++) {
        printf("\nLivro %d\n", i+1);
        printf("Titulo: "); fgets(v[i].titulo, 100, stdin);
        printf("Autor: "); fgets(v[i].autor, 100, stdin);
        printf("Editora: "); fgets(v[i].editora, 100, stdin);
        printf("Ano: "); scanf("%d", &v[i].ano);
        printf("Páginas: "); scanf("%d", &v[i].paginas); getchar();
        v[i].titulo[strcspn(v[i].titulo, "\n")] = 0;
    }
}

void imprimir(Livro v[], int n) {
    for (int i = 0; i < n; i++)
        printf("[%d] %s - %s - %s - %d - %d págs\n", i,
            v[i].titulo, v[i].autor, v[i].editora, v[i].ano, v[i].paginas);
}

int buscaLinear(Livro v[], int n, char *t) {
    for (int i = 0; i < n; i++)
        if (strcmp(v[i].titulo, t) == 0) return i;
    return -1;
}

void ordenar(Livro v[], int n) {
    for (int i = 0; i < n-1; i++)
        for (int j = 0; j < n-i-1; j++)
            if (strcmp(v[j].titulo, v[j+1].titulo) > 0) {
                Livro tmp = v[j]; v[j] = v[j+1]; v[j+1] = tmp;
            }
}

int buscaBinaria(Livro v[], int n, char *t) {
    int ini = 0, fim = n - 1;
    while (ini <= fim) {
        int m = (ini + fim) / 2;
        int cmp = strcmp(v[m].titulo, t);
        if (cmp == 0) return m;
        else if (cmp < 0) ini = m + 1;
        else fim = m - 1;
    }
    return -1;
}

int main() {
    Livro livros[MAX];
    int n; char busca[100];

    preencher(livros, &n);
    imprimir(livros, n);

    printf("\nBusca linear - Titulo: ");
    fgets(busca, 100, stdin); busca[strcspn(busca, "\n")] = 0;
    int pos = buscaLinear(livros, n, busca);
    printf("Posição: %d\n", pos);

    ordenar(livros, n);
    printf("\nOrdenado:\n"); imprimir(livros, n);

    printf("\nBusca binária - Titulo: ");
    fgets(busca, 100, stdin); busca[strcspn(busca, "\n")] = 0;
    pos = buscaBinaria(livros, n, busca);
    printf("Posição: %d\n", pos);

    return 0;
}
