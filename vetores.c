
#include <stdio.h>  // Biblioteca padrão de entrada e saída (printf, scanf)
#include <stdlib.h> // Biblioteca para funções utilitárias, como malloc e free

int main() {
    int N, i; // Declara variáveis inteiras: N para o tamanho do vetor, i para o índice do loop

    // Solicita ao usuário o tamanho do vetor
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &N);

    // Aloca dinamicamente memória para o vetor de tamanho N
    // malloc retorna um ponteiro para o espaço de memória alocado
    int *vetor = (int *)malloc(N * sizeof(int));

    // Verifica se a alocação de memória foi bem-sucedida
    if (vetor == NULL) {
        printf("Erro ao alocar memoria.\n");
        return 1; // Encerra o programa caso não tenha sido possível alocar memória
    }

    // Loop para preencher o vetor com valores fornecidos pelo usuário
    for (i = 0; i < N; i++) {
        printf("Digite o valor %d: ", i + 1);
        scanf("%d", &vetor[i]); // Armazena o valor na posição i do vetor
    }

    // Exibe os elementos do vetor em ordem inversa
    printf("Vetor na ordem inversa:\n");
    for (i = N - 1; i >= 0; i--) {
        printf("%d ", vetor[i]); // Imprime cada elemento do final para o início
    }

    printf("\n");

    // Libera a memória alocada dinamicamente para evitar vazamentos
    free(vetor);
    
    system("pause"); // Pausa o programa para que o usuário veja o resultado (Windows)
    return 0;        // Finaliza o programa com sucesso
}
