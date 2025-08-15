#include <stdio.h>   // Biblioteca padrão de entrada e saída
#include <stdlib.h>  // Biblioteca padrão para funções utilitárias (ex: system, exit)

#define MAX_DISCOS 8      // Quantidade máxima de discos permitida no jogo
#define MAX_LARGURA 17    // Largura máxima para exibição dos discos na tela

// Estrutura das torres: cada torre é uma coluna e cada linha um disco
int torres[3][MAX_DISCOS]; 
int topo[3] = {0, 0, 0}; // Armazena a quantidade de discos em cada torre (índice do topo)

// ---------------------------------------------------------------
// Calcula a largura visual de um disco proporcional ao seu valor
// ---------------------------------------------------------------
int larguraDisco(int valor, int n) {
    return 1 + (valor - 1) * (MAX_LARGURA - 1) / (n - 1);
}

// ---------------------------------------------------------------
// Imprime visualmente um disco ou espaço vazio na tela
// ---------------------------------------------------------------
void imprimirDisco(int valor, int n) {
    if (valor == 0) {
        // Se não houver disco, imprime apenas espaços
        for (int i = 0; i < MAX_LARGURA; i++) printf(" ");
        return;
    }
    int largura = larguraDisco(valor, n);
    int espacos = (MAX_LARGURA - largura) / 2;

    // Espaços antes do disco
    for (int i = 0; i < espacos; i++) printf(" ");
    // Corpo do disco
    for (int i = 0; i < largura; i++) printf("=");
    // Espaços depois do disco
    for (int i = 0; i < espacos; i++) printf(" ");
}

// ---------------------------------------------------------------
// Imprime o estado atual das três torres com seus discos
// ---------------------------------------------------------------
void imprimirTorres(int n) {
    printf("\nESTADO ATUAL DAS TORRES:\n\n");
    // Imprime de cima para baixo
    for (int linha = n - 1; linha >= 0; linha--) {
        for (int t = 0; t < 3; t++) {
            if (linha < topo[t])
                imprimirDisco(torres[t][linha], n); // Imprime disco existente
            else
                imprimirDisco(0, n); // Espaço vazio
            printf("   "); // Espaço entre as torres
        }
        printf("\n");
    }

    // Base das torres
    for (int t = 0; t < 3; t++) {
        for (int i = 0; i < MAX_LARGURA; i++) printf("-");
        printf("   ");
    }
    printf("\n");

    // Nomes das torres
    printf("   T1");
    for (int i = 0; i < MAX_LARGURA - 2; i++) printf(" ");
    printf("T2");
    for (int i = 0; i < MAX_LARGURA - 2; i++) printf(" ");
    printf("T3\n");
}

// ---------------------------------------------------------------
// Inicializa a torre 1 com todos os discos em ordem decrescente
// ---------------------------------------------------------------
void inicializarTorres(int n) {
    for (int i = n; i >= 1; i--) {
        torres[0][topo[0]++] = i;
    }
}

// ---------------------------------------------------------------
// Move um disco de uma torre para outra, se o movimento for válido
// ---------------------------------------------------------------
int moverDisco(int origem, int destino) {
    if (topo[origem] == 0) return 0; // Origem vazia

    int disco = torres[origem][topo[origem] - 1];

    // Verifica se pode colocar sobre o disco do destino
    if (topo[destino] > 0) {
        int topoDestino = torres[destino][topo[destino] - 1];
        if (disco > topoDestino) return 0; // Movimento inválido
    }

    // Move o disco
    topo[origem]--;
    torres[destino][topo[destino]++] = disco;
    return 1;
}

// ---------------------------------------------------------------
// Verifica se o jogador venceu o jogo (todos discos na torre 3)
// ---------------------------------------------------------------
int venceu(int n) {
    if (topo[2] != n) return 0; // Torre 3 não tem todos os discos
    for (int i = 0; i < n - 1; i++) {
        if (torres[2][i] < torres[2][i + 1]) return 0; // Ordem incorreta
    }
    return 1; // Vitória
}

// ---------------------------------------------------------------
// Algoritmo recursivo para resolver a Torre de Hanoi automaticamente
// ---------------------------------------------------------------
void hanoi(int n, int origem, int destino, int auxiliar, int total) {
    if (n == 1) {
        printf("\nMovendo disco de T%d para T%d\n", origem + 1, destino + 1);
        moverDisco(origem, destino);
        imprimirTorres(total);
        return;
    }
    hanoi(n - 1, origem, auxiliar, destino, total);
    printf("\nMovendo disco de T%d para T%d\n", origem + 1, destino + 1);
    moverDisco(origem, destino);
    imprimirTorres(total);
    hanoi(n - 1, auxiliar, destino, origem, total);
}

// ---------------------------------------------------------------
// Pergunta ao jogador se deseja resolver o jogo automaticamente
// ---------------------------------------------------------------
void resolverAutomaticamente(int n) {
    char opcao;
    printf("\nDeseja resolver automaticamente? (s/n): ");
    scanf(" %c", &opcao);
    if (opcao == 's' || opcao == 'S') {
        printf("\nResolvendo Torre de Hanoi com %d discos...\n", n);
        hanoi(n, 0, 2, 1, n);
        printf("\nParabens! A torre foi resolvida automaticamente!\n");
        system("pause");
        exit(0);
    }
}

// ---------------------------------------------------------------
// Função principal
// ---------------------------------------------------------------
int main() {
    int n;

    // Pede quantidade de discos
    printf("Digite o numero de discos (3 a %d): ", MAX_DISCOS);
    scanf("%d", &n);

    // Verifica validade do número de discos
    if (n < 3 || n > MAX_DISCOS) {
        printf("Numero invalido. Escolha entre 3 e %d.\n", MAX_DISCOS);
        return 1;
    }

    // Inicializa o jogo
    inicializarTorres(n);

    // Pergunta se deseja resolução automática
    resolverAutomaticamente(n);

    // Loop de jogadas manuais
    while (1) {
        imprimirTorres(n);
        printf("\nDigite sua jogada (origem destino), ex: 1 3 ou 0 para sair: ");
        
        int origem, destino;
        scanf("%d", &origem);
        if (origem == 0) break; // Sair do jogo
        scanf("%d", &destino);

        // Valida torres
        if (origem < 1 || origem > 3 || destino < 1 || destino > 3) {
            printf("Torres devem estar entre 1 e 3.\n");
            continue;
        }

        // Tenta mover disco
        if (!moverDisco(origem - 1, destino - 1)) {
            printf("Movimento invalido!\n");
        }

        // Verifica vitória
        if (venceu(n)) {
            imprimirTorres(n);
            printf("\nParabens! Voce completou o jogo!\n");
            break;
        }
    }

    system("pause");
    return 0;
}
