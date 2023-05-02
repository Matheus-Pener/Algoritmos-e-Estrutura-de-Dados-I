#include <stdio.h>
#include <stdlib.h>

void bolha(int n, int *v)
{
    for (int i = n - 1; i >= 1; --i)
    {
        for (int j = 0; j < i; ++j)
        {
            if (v[j] > v[j + 1])
            {
                int temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int qtd, valor, valor_dois, tamanho = 0, aux = 0, k = 0;

    scanf("%d", &qtd);

    int pilha_prioridade[qtd], pilha_compara[qtd];

    for (int i = qtd; i > 0; i--)
    {
        scanf("%d %d", &valor, &valor_dois);
        if (valor == 1)
        {
            pilha_compara[i - 1] = valor_dois;
        }
        else
        {
            pilha_prioridade[tamanho] = valor_dois;
            tamanho++;
        }
    }

    return 0;
}
