#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Intercala(int p, int q, int r, int v[])
{
    int i, j, k, *w;
    w = malloc((r - p) * sizeof(int));
    i = p;
    j = q;
    k = 0;
    while (i < q && j < r)
    {
        if (v[i] <= v[j])
            w[k++] = v[i++];
        else
            w[k++] = v[j++];
    }
    while (i < q)
        w[k++] = v[i++];
    while (j < r)
        w[k++] = v[j++];
    for (i = p; i < r; i++)
        v[i] = w[i - p];
    free(w);
}
void Mergesort(int p, int r, int v[])
{
    if (p < r - 1)
    {
        int q = (p + r) / 2;
        Mergesort(p, q, v);
        Mergesort(q, r, v);
        Intercala(p, q, r, v);
    }
}
int main()
{
    int n, i;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);

    int v[n];
    srand(time(NULL));
    for (i = 0; i < n; i++)
        v[i] = rand() % 1000; // preenche o vetor com valores aleatórios entre 0 e 999

    clock_t t1 = clock(); // inicia a contagem do tempo

    Mergesort(0, n, v);

    clock_t t2 = clock();                                      // finaliza a contagem do tempo
    double elapsed_time = (t2 - t1) * 1000.0 / CLOCKS_PER_SEC; // converte o tempo para milissegundos

    printf("Tempo de execucao: %.5lf ms\n", elapsed_time);
    return 0;
}
