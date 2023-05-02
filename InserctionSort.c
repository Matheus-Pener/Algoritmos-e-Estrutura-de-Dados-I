#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void InsertionSort(int n, int v[])
{
    int i, j, x;
    for (i = 1; i < n; i++)
    {
        x = v[i];
        j = i - 1;
        while (j >= 0 && v[j] > x)
        {
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = x;
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
    InsertionSort(n, v);
    clock_t fim = clock();
    double tempo = (double)(fim - inicio) / CLOCKS_PER_SEC * 1000; // tempo em milissegundos
    printf("\nExecution time: %.5f milessegundos\n", tempo);

    // liberar espaço de memória alocado para o vetor
    free(v);

    return 0;
}
