#include <stdio.h>
#include <stdlib.h>

int main() {
    // Declaração das variáveis para armazenar as dimensões das matrizes
    int linhasA, colunasA;
    int linhasB, colunasB;
    int i, j, k;

    // Solicita ao usuário a dimensão da matriz A
    printf("Digite o numero de linhas da matriz A: ");
    scanf("%d", &linhasA);
    printf("Digite o numero de colunas da matriz A: ");
    scanf("%d", &colunasA);

    // Solicita ao usuário a dimensão da matriz B
    printf("Digite o numero de linhas da matriz B: ");
    scanf("%d", &linhasB);
    printf("Digite o numero de colunas da matriz B: ");
    scanf("%d", &colunasB);

    // Verifica se a multiplicação é possível:
    // O número de colunas de A deve ser igual ao número de linhas de B
    if (colunasA != linhasB) {
        printf("\nNao e possivel multiplicar: colunas de A devem ser iguais as linhas de B.\n");
        return 0; // Encerra o programa caso não seja possível multiplicar
    }

    // Declaração das matrizes com as dimensões escolhidas pelo usuário
    // OBS: uso de VLA (Variable-Length Arrays) disponível a partir do C99
    float A[linhasA][colunasA];
    float B[linhasB][colunasB];
    float C[linhasA][colunasB]; // Matriz resultado com dimensões de linhasA x colunasB

    // Preenchimento da matriz A com valores fornecidos pelo usuário
    printf("\nDigite os elementos da matriz A (%dx%d):\n", linhasA, colunasA);
    for(i = 0; i < linhasA; i++) {
        for(j = 0; j < colunasA; j++) {
            scanf("%f", &A[i][j]); // Leitura dos elementos
        }
    }

    // Preenchimento da matriz B com valores fornecidos pelo usuário
    printf("\nDigite os elementos da matriz B (%dx%d):\n", linhasB, colunasB);
    for(i = 0; i < linhasB; i++) {
        for(j = 0; j < colunasB; j++) {
            scanf("%f", &B[i][j]); // Leitura dos elementos
        }
    }

    // Impressão da matriz A para conferência
    printf("\nMatriz A:\n");
    for(i = 0; i < linhasA; i++) {
        for(j = 0; j < colunasA; j++) {
            printf("%.2f ", A[i][j]); // Impressão com 2 casas decimais
        }
        printf("\n"); // Quebra de linha após cada linha da matriz
    }

    // Impressão da matriz B para conferência
    printf("\nMatriz B:\n");
    for(i = 0; i < linhasB; i++) {
        for(j = 0; j < colunasB; j++) {
            printf("%.2f ", B[i][j]); // Impressão com 2 casas decimais
        }
        printf("\n"); // Quebra de linha após cada linha da matriz
    }

    // Multiplicação das matrizes A e B
    // Cada elemento C[i][j] é a soma dos produtos A[i][k] * B[k][j]
    for(i = 0; i < linhasA; i++) {
        for(j = 0; j < colunasB; j++) {
            C[i][j] = 0; // Inicializa o elemento da matriz C
            for(k = 0; k < colunasA; k++) {
                C[i][j] += A[i][k] * B[k][j]; // Soma os produtos conforme a regra da multiplicação de matrizes
            }
        }
    }

    // Impressão da matriz resultante C (resultado da multiplicação A x B)
    printf("\nResultado da multiplicacao (AxB):\n");
    for(i = 0; i < linhasA; i++) {
        for(j = 0; j < colunasB; j++) {
            printf("%.2f ", C[i][j]); // Impressão com 2 casas decimais
        }
        printf("\n"); // Quebra de linha após cada linha da matriz
    }

    // Pausa a execução do programa até que o usuário pressione uma tecla
    system("pause");

    return 0; // Indica que o programa terminou com sucesso
}
