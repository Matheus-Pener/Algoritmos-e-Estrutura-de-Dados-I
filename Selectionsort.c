#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void SelectionSort(int n, int v[])
{
    int i, j, min_idx, temp;
    for (i = 0; i < n - 1; i++)
    {
        min_idx = i;
        for (j = i + 1; j < n; j++)
            if (v[j] < v[min_idx])
                min_idx = j;
        temp = v[i];
        v[i] = v[min_idx];
        v[min_idx] = temp;
    }
}

int main()
{
    int n;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);

    // alocar espaço de memória para o vetor
    int *v = (int *)malloc(n * sizeof(int));

    // preencher o vetor com valores aleatórios
    srand(time(NULL)); // inicializar o gerador de números aleatórios
    for (int i = 0; i < n; i++)
    {
        v[i] = rand() % 100; // gerar um número aleatório entre 0 e 99
    }

    // classificar o vetor
    clock_t inicio = clock();
    SelectionSort(n, v);
    clock_t fim = clock();
    double tempo = (double)(fim - inicio) / CLOCKS_PER_SEC * 1000; // tempo em milissegundos
    printf("\nExecution time: %.5f milessegundos\n", tempo);
    // liberar espaço de memória alocado para o vetor
    free(v);

    return 0;
}
