#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void InsereEmHeap(int m, int v[])
{
    int f = m + 1;
    while ((f > 1 && v[f / 2] < v[f]))
    {
        int t = v[f / 2];
        v[f / 2] = v[f];
        v[f] = t;
        f = f / 2;
    }
}

void SacodeHeap(int m, int v[])
{
    int t, f = 2;
    while (f <= m)
    {
        if (f < m && v[f] < v[f + 1])
            ++f;
        if (v[f / 2] >= v[f])
            break;
        t = v[f / 2];
        v[f / 2] = v[f];
        v[f] = t;
        f *= 2;
    }
}

void Heapsort(int n, int v[])
{
    int m;
    for (m = 1; m < n; m++)
        InsereEmHeap(m, v);
    for (m = n; m > 1; m--)
    {
        int t = v[1];
        v[1] = v[m];
        v[m] = t;
        SacodeHeap(m - 1, v);
    }
}

int main()
{
    int n, i;
    clock_t start, end;
    double elapsed_time;

    printf("Entre com o numero de elementos: ");
    scanf("%d", &n);

    int v[n];
    srand(time(NULL)); // semente para geracao de numeros aleatorios
    for (i = 0; i < n; i++)
    {
        v[i] = rand() % 1000; // gera numeros aleatorios entre 0 e 999
    }
    start = clock(); // inicio da contagem do tempo

    Heapsort(n, v);

    end = clock();                                                  // fim da contagem do tempo
    elapsed_time = ((double)(end - start)) * 1000 / CLOCKS_PER_SEC; // tempo em milissegundos
    printf("Tempo de execucao: %.5f ms\n", elapsed_time);

    return 0;
}
