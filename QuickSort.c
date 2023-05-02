#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int Separa(int p, int r, int v[])
{
    int c, j, k, t;
    c = v[r];
    j = p;
    for (k = p; k < r; k++)
    {
        if (v[k] <= c)
        {
            t = v[j];
            v[j] = v[k];
            v[k] = t;
            j++;
        }
    }
    v[r] = v[j];
    v[j] = c;
    return j;
}

void Quicksort(int p, int r, int v[])
{
    int j;
    if (p < r)
    {
        j = Separa(p, r, v);
        Quicksort(p, j - 1, v);
        Quicksort(j + 1, r, v);
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
    Quicksort(0, n - 1, v);
    clock_t fim = clock();
    double tempo = (double)(fim - inicio) / CLOCKS_PER_SEC * 1000; // tempo em milissegundos
    printf("\nExecution time: %.5f milessegundos\n", tempo);

    // liberar espaço de memória alocado para o vetor
    free(v);

    return 0;
}
