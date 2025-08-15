#include <stdio.h>  // Biblioteca padrão de entrada e saída (printf, scanf)
#include <stdlib.h> // Biblioteca para funções utilitárias (como system)

// Função principal do programa
int main() {
    int jogador1, jogador2; // Declara duas variáveis inteiras para armazenar as escolhas dos jogadores

    // Solicita a escolha do Jogador 1 e armazena na variável jogador1
    printf("Jogador 1 - Escolha (1=Pedra, 2=Papel, 3=Tesoura): ");
    scanf("%d", &jogador1);

    // Solicita a escolha do Jogador 2 e armazena na variável jogador2
    printf("Jogador 2 - Escolha (1=Pedra, 2=Papel, 3=Tesoura): ");
    scanf("%d", &jogador2);

    // Estrutura condicional para verificar o resultado do jogo
    if (jogador1 == jogador2) {
        // Caso ambos escolham a mesma opção, é empate
        printf("Empate!\n");
    } 
    else if ((jogador1 == 1 && jogador2 == 3) ||  // Pedra ganha de Tesoura
             (jogador1 == 2 && jogador2 == 1) ||  // Papel ganha de Pedra
             (jogador1 == 3 && jogador2 == 2)) {  // Tesoura ganha de Papel
        printf("Jogador 1 ganhou!\n");  // Jogador 1 vence
    } 
    else {
        // Se não for empate e o Jogador 1 não ganhou, então o Jogador 2 ganha
        printf("Jogador 2 ganhou!\n");
    }

    system("pause"); // Pausa o programa para o usuário ver o resultado (funciona no Windows)
    return 0;        // Finaliza o programa com código 0 (sucesso)
}
