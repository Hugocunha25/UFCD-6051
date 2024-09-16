#include <stdio.h>


// Função para exibir o menu
void mostrarMenu() {
    printf("********** Menu **********\n");
    printf("1. Visualizar Cronograma\n");
    printf("2. Marcar Ocupação\n");
    printf("3. Atividade de Monitorização\n");
    printf("4. Mediação\n");
    printf("5. Sair\n");
    printf("Escolha uma opção: ");
}

// Função para visualizar o cronograma
void visualizarCronograma() {
    printf("Visualizando o cronograma...\n");
    // Aqui você pode adicionar o código para visualizar o cronograma.
}

// Função para marcar a ocupação
void marcarOcupacao() {
    printf("Marcar ocupação...\n");
    // Aqui você pode adicionar o código para marcar a ocupação.
}

// Função para realizar a atividade de monitorização
void atividadeMonitorizacao() {
    printf("Realizando atividade de monitorização...\n");
    // Aqui você pode adicionar o código para a atividade de monitorização.
}

// Função para realizar a mediação
void mediacao() {
    printf("Realizando mediação...\n");
    // Aqui você pode adicionar o código para a mediação.
}

int main() {
    int opcao;

    while (1) {
        mostrarMenu();
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                visualizarCronograma();
                break;
            case 2:
                marcarOcupacao();
                break;
            case 3:
                atividadeMonitorizacao();
                break;
            case 4:
                mediacao();
                break;
            case 5:
                printf("Saindo...\n");
                return 0;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    }

    return 0;
}

}
