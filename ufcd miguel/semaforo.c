#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

volatile sig_atomic_t parar = 0; // Variável para controlar a paragem

// Função de tratamento de sinal
void tratar_sinal(int sinal) {
    parar = 1; // Define a variável para parar o semáforo
}

void semaforo() {
    while (!parar) {
        printf("Semaforo VERMELHO\n");
        sleep(10);
        
        printf("Semaforo VERDE\n");
        sleep(5);
        
        printf("Semaforo AMARELO\n");
        sleep(3);
    }
}

int main() {
    signal(SIGINT, tratar_sinal); // Captura o sinal de interrupção (Ctrl+C)

    printf("Semaforo iniciado. Pressione Ctrl+C para parar.\n");
    semaforo();
    printf("Semaforo parado.\n");
    
    return 0;
}

