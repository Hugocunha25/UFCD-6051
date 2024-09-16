#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PALAVRA 50
#define MAX_TENTATIVAS 6

void limpar_tela() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void desenhar_forca(int erros) {
    printf("  _____\n");
    printf("  |     |\n");
    printf("  |     %c\n", (erros >= 1 ? 'O' : ' '));
    printf("  |    %c%c%c\n", (erros >= 3 ? '/' : ' '), (erros >= 2 ? '|' : ' '), (erros >= 4 ? '\\' : ' '));
    printf("  |    %c %c\n", (erros >= 5 ? '/' : ' '), (erros >= 6 ? '\\' : ' '));
    printf("  |\n");
    printf("_|_\n\n");
}

void limpar_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void remover_acentos(char *str) {
    const char *acentos = "áàãâéêíóôõúüç";
    const char *sem_acentos = "aaaaeeiooouuc";
    char *p = str;
    while (*p) {
        const char *a = acentos;
        const char *s = sem_acentos;
        while (*a) {
            if (*p == *a) {
                *p = *s;
                break;
            }
            a++;
            s++;
        }
        p++;
    }
}

int jogar_forca() {
    char palavra_secreta[MAX_PALAVRA];
    char palavra_revelada[MAX_PALAVRA];
    char letras_tentadas[26] = {0};
    int tentativas_restantes = MAX_TENTATIVAS;
    int tamanho_palavra;
    
    printf("Jogador 1, digite a palavra secreta: ");
    fgets(palavra_secreta, MAX_PALAVRA, stdin);
    palavra_secreta[strcspn(palavra_secreta, "\n")] = 0; // Remove o \n do final
    remover_acentos(palavra_secreta);
    tamanho_palavra = strlen(palavra_secreta);
    
    for (int i = 0; i < tamanho_palavra; i++) {
        palavra_revelada[i] = '_';
    }
    palavra_revelada[tamanho_palavra] = '\0';
    
    limpar_tela();
    
    while (tentativas_restantes > 0 && strcmp(palavra_revelada, palavra_secreta) != 0) {
        desenhar_forca(MAX_TENTATIVAS - tentativas_restantes);
        printf("Palavra: %s\n", palavra_revelada);
        printf("Letras tentadas: ");
        for (int i = 0; i < 26; i++) {
            if (letras_tentadas[i]) printf("%c ", 'a' + i);
        }
        printf("\n");
        
        char tentativa;
        printf("\nTente uma letra: ");
        scanf(" %c", &tentativa);
        limpar_buffer();
        tentativa = tolower(tentativa);
        
        if (letras_tentadas[tentativa - 'a']) {
            printf("Voce ja tentou essa letra! Pressione Enter para continuar...");
            getchar();
            limpar_tela();
            continue;
        }
        
        letras_tentadas[tentativa - 'a'] = 1;
        
        int acertou = 0;
        for (int i = 0; i < tamanho_palavra; i++) {
            if (tolower(palavra_secreta[i]) == tentativa) {
                palavra_revelada[i] = palavra_secreta[i];
                acertou = 1;
            }
        }
        
        if (!acertou) {
            tentativas_restantes--;
            printf("Letra errada! Tentativas restantes: %d\n", tentativas_restantes);
            printf("Pressione Enter para continuar...");
            getchar();
        }
        
        limpar_tela();
    }
    
    desenhar_forca(MAX_TENTATIVAS - tentativas_restantes);
    if (strcmp(palavra_revelada, palavra_secreta) == 0) {
        printf("Parabens! Voce acertou a palavra: %s\n", palavra_secreta);
    } else {
        printf("Voce perdeu! A palavra era: %s\n", palavra_secreta);
    }
    
    return 0;
}

int main() {
    char jogar_novamente;
    
    do {
        jogar_forca();
        
        printf("\nDeseja jogar novamente? (S/N): ");
        scanf(" %c", &jogar_novamente);
        limpar_buffer();
        jogar_novamente = tolower(jogar_novamente);
        
        limpar_tela();
    } while (jogar_novamente == 's');
    
    printf("Obrigado por jogar! Ate a proxima!\n");
    printf("Pressione Enter para sair...");
    getchar();
    
    return 0;
}