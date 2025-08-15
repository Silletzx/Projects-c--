
#include <stdio.h>  // Biblioteca padr�o de entrada e sa�da (printf, scanf)
#include <stdlib.h> // Biblioteca para fun��es utilit�rias, como malloc e free

int main() {
    int N, i; // Declara vari�veis inteiras: N para o tamanho do vetor, i para o �ndice do loop

    // Solicita ao usu�rio o tamanho do vetor
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &N);

    // Aloca dinamicamente mem�ria para o vetor de tamanho N
    // malloc retorna um ponteiro para o espa�o de mem�ria alocado
    int *vetor = (int *)malloc(N * sizeof(int));

    // Verifica se a aloca��o de mem�ria foi bem-sucedida
    if (vetor == NULL) {
        printf("Erro ao alocar memoria.\n");
        return 1; // Encerra o programa caso n�o tenha sido poss�vel alocar mem�ria
    }

    // Loop para preencher o vetor com valores fornecidos pelo usu�rio
    for (i = 0; i < N; i++) {
        printf("Digite o valor %d: ", i + 1);
        scanf("%d", &vetor[i]); // Armazena o valor na posi��o i do vetor
    }

    // Exibe os elementos do vetor em ordem inversa
    printf("Vetor na ordem inversa:\n");
    for (i = N - 1; i >= 0; i--) {
        printf("%d ", vetor[i]); // Imprime cada elemento do final para o in�cio
    }

    printf("\n");

    // Libera a mem�ria alocada dinamicamente para evitar vazamentos
    free(vetor);
    
    system("pause"); // Pausa o programa para que o usu�rio veja o resultado (Windows)
    return 0;        // Finaliza o programa com sucesso
}
