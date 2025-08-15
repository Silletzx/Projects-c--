#include <stdio.h>
#include <stdlib.h>

#define MAX_DISCOS 8
#define MAX_LARGURA 17

int torres[3][MAX_DISCOS];
int topo[3] = {0, 0, 0};


int larguraDisco(int valor, int n) {
    return 1 + (valor - 1) * (MAX_LARGURA - 1) / (n - 1);
}


void imprimirDisco(int valor, int n) {
    if (valor == 0) {
        for (int i = 0; i < MAX_LARGURA; i++) printf(" ");
        return;
    }
    int largura = larguraDisco(valor, n);
    int espacos = (MAX_LARGURA - largura) / 2;
    for (int i = 0; i < espacos; i++) printf(" ");
    for (int i = 0; i < largura; i++) printf("=");
    for (int i = 0; i < espacos; i++) printf(" ");
}


void imprimirTorres(int n) {
    printf("\nESTADO ATUAL DAS TORRES:\n\n");
    for (int linha = n - 1; linha >= 0; linha--) {
        for (int t = 0; t < 3; t++) {
            if (linha < topo[t])
                imprimirDisco(torres[t][linha], n);
            else
                imprimirDisco(0, n);
            printf("   ");
        }
        printf("\n");
    }
    for (int t = 0; t < 3; t++) {
        for (int i = 0; i < MAX_LARGURA; i++) printf("-");
        printf("   ");
    }
    printf("\n");
    printf("   T1");
    for (int i = 0; i < MAX_LARGURA - 2; i++) printf(" ");
    printf("T2");
    for (int i = 0; i < MAX_LARGURA - 2; i++) printf(" ");
    printf("T3\n");
}


void inicializarTorres(int n) {
    for (int i = n; i >= 1; i--) {
        torres[0][topo[0]++] = i;
    }
}


int moverDisco(int origem, int destino) {
    if (topo[origem] == 0) return 0;
    int disco = torres[origem][topo[origem] - 1];

    if (topo[destino] > 0) {
        int topoDestino = torres[destino][topo[destino] - 1];
        if (disco > topoDestino) return 0;
    }

    topo[origem]--;
    torres[destino][topo[destino]++] = disco;
    return 1;
}


int venceu(int n) {
    if (topo[2] != n) return 0;
    for (int i = 0; i < n - 1; i++) {
        if (torres[2][i] < torres[2][i + 1]) return 0;
    }
    return 1;
}


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


int main() {
    int n;

    printf("Digite o numero de discos (3 a %d): ", MAX_DISCOS);
    scanf("%d", &n);

    if (n < 3 || n > MAX_DISCOS) {
        printf("Numero invalido. Escolha entre 3 e %d.\n", MAX_DISCOS);
        return 1;
    }

    inicializarTorres(n);
    resolverAutomaticamente(n);

    while (1) {
        imprimirTorres(n);
        printf("\nDigite sua jogada (origem destino), ex: 1 3 ou 0 para sair: ");
        int origem, destino;
        scanf("%d", &origem);
        if (origem == 0) break;
        scanf("%d", &destino);

        if (origem < 1 || origem > 3 || destino < 1 || destino > 3) {
            printf("Torres devem estar entre 1 e 3.\n");
            continue;
        }

        if (!moverDisco(origem - 1, destino - 1)) {
            printf("Movimento invalido!\n");
        }

        if (venceu(n)) {
            imprimirTorres(n);
            printf("\nParabens! Voce completou o jogo!\n");
            break;
        }
    }

    system("pause");
    return 0;
}

