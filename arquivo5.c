#include <stdio.h>
#include <string.h>
#include <ctype.h>

void contarVogais(char *frase) {
    int vogais = 0;
    for (int i = 0; frase[i] != '\0'; i++) {
        char c = tolower(frase[i]);
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            vogais++;
        }
    }
    printf("Quantidade de vogais: %d\n", vogais);
}

void capitalizarFrase(char *frase) {
    int novaPalavra = 1;
    for (int i = 0; frase[i] != '\0'; i++) {
        if (isspace(frase[i])) {
            novaPalavra = 1;
        } else if (novaPalavra && islower(frase[i])) {
            frase[i] = frase[i] - 32;
            novaPalavra = 0;
        } else {
            novaPalavra = 0;
        }
    }
    printf("Frase capitalizada: %s\n", frase);
}

int main() {
    char frase[200];

    printf("Digite uma frase: ");
    fgets(frase, sizeof(frase), stdin);
    frase[strcspn(frase, "\n")] = 0; 

    printf("Frase digitada: %s\n", frase);

    contarVogais(frase);
    capitalizarFrase(frase);

    return 0;
}
