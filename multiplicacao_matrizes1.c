#include <stdio.h>
#include <stdlib.h>

int main() {
    // Declara��o das vari�veis para armazenar as dimens�es das matrizes
    int linhasA, colunasA;
    int linhasB, colunasB;
    int i, j, k;

    // Solicita ao usu�rio a dimens�o da matriz A
    printf("Digite o numero de linhas da matriz A: ");
    scanf("%d", &linhasA);
    printf("Digite o numero de colunas da matriz A: ");
    scanf("%d", &colunasA);

    // Solicita ao usu�rio a dimens�o da matriz B
    printf("Digite o numero de linhas da matriz B: ");
    scanf("%d", &linhasB);
    printf("Digite o numero de colunas da matriz B: ");
    scanf("%d", &colunasB);

    // Verifica se a multiplica��o � poss�vel:
    // O n�mero de colunas de A deve ser igual ao n�mero de linhas de B
    if (colunasA != linhasB) {
        printf("\nNao e possivel multiplicar: colunas de A devem ser iguais as linhas de B.\n");
        return 0; // Encerra o programa caso n�o seja poss�vel multiplicar
    }

    // Declara��o das matrizes com as dimens�es escolhidas pelo usu�rio
    // OBS: uso de VLA (Variable-Length Arrays) dispon�vel a partir do C99
    float A[linhasA][colunasA];
    float B[linhasB][colunasB];
    float C[linhasA][colunasB]; // Matriz resultado com dimens�es de linhasA x colunasB

    // Preenchimento da matriz A com valores fornecidos pelo usu�rio
    printf("\nDigite os elementos da matriz A (%dx%d):\n", linhasA, colunasA);
    for(i = 0; i < linhasA; i++) {
        for(j = 0; j < colunasA; j++) {
            scanf("%f", &A[i][j]); // Leitura dos elementos
        }
    }

    // Preenchimento da matriz B com valores fornecidos pelo usu�rio
    printf("\nDigite os elementos da matriz B (%dx%d):\n", linhasB, colunasB);
    for(i = 0; i < linhasB; i++) {
        for(j = 0; j < colunasB; j++) {
            scanf("%f", &B[i][j]); // Leitura dos elementos
        }
    }

    // Impress�o da matriz A para confer�ncia
    printf("\nMatriz A:\n");
    for(i = 0; i < linhasA; i++) {
        for(j = 0; j < colunasA; j++) {
            printf("%.2f ", A[i][j]); // Impress�o com 2 casas decimais
        }
        printf("\n"); // Quebra de linha ap�s cada linha da matriz
    }

    // Impress�o da matriz B para confer�ncia
    printf("\nMatriz B:\n");
    for(i = 0; i < linhasB; i++) {
        for(j = 0; j < colunasB; j++) {
            printf("%.2f ", B[i][j]); // Impress�o com 2 casas decimais
        }
        printf("\n"); // Quebra de linha ap�s cada linha da matriz
    }

    // Multiplica��o das matrizes A e B
    // Cada elemento C[i][j] � a soma dos produtos A[i][k] * B[k][j]
    for(i = 0; i < linhasA; i++) {
        for(j = 0; j < colunasB; j++) {
            C[i][j] = 0; // Inicializa o elemento da matriz C
            for(k = 0; k < colunasA; k++) {
                C[i][j] += A[i][k] * B[k][j]; // Soma os produtos conforme a regra da multiplica��o de matrizes
            }
        }
    }

    // Impress�o da matriz resultante C (resultado da multiplica��o A x B)
    printf("\nResultado da multiplicacao (AxB):\n");
    for(i = 0; i < linhasA; i++) {
        for(j = 0; j < colunasB; j++) {
            printf("%.2f ", C[i][j]); // Impress�o com 2 casas decimais
        }
        printf("\n"); // Quebra de linha ap�s cada linha da matriz
    }

    // Pausa a execu��o do programa at� que o usu�rio pressione uma tecla
    system("pause");

    return 0; // Indica que o programa terminou com sucesso
}
