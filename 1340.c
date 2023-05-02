#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#define MAX 100

// Estrutura da pilha
typedef struct pilha
{
    int valor;
    struct pilha *prox;
} Pilha;

Pilha *empilha(Pilha *l, int valor)
{
    Pilha *novo = (Pilha *)malloc(sizeof(Pilha));
    novo->valor = valor;
    novo->prox = l;
    return novo;
}

Pilha *desempilha(Pilha *l, int valor)
{
    if (l == NULL)
    {
        return l;
    }
    if (l->valor != valor)
    {
        return l;
    }
    Pilha *temp = l;
    l = l->prox;
    free(temp);
    return l;
}

// ESTRUTURA DA FILA
typedef struct fila
{
    int valor;
    struct fila *prox;
} Fila;

Fila *insere(Fila *l, int valor)
{
    Fila *novo = (Fila *)malloc(sizeof(Fila));
    novo->valor = valor;
    novo->prox = NULL;
    if (l == NULL)
    {
        return novo;
    }
    else
    {
        Fila *ultimo = l;
        while (ultimo->prox != NULL)
        {
            ultimo = ultimo->prox;
        }
        ultimo->prox = novo;
        return l;
    }
}

Fila *elimina_elemento(Fila *l, int valor)
{
    if (l->valor == valor)
    {
        Fila *temp = l;
        l = l->prox;
        free(temp);
        return l;
    }
    if (l == NULL)
    {
        return l;
    }
    return l;
}
void bubbleSortDescending(int n, int *v)
{
    for (int i = n - 1; i >= 1; --i)
    {
        for (int j = 0; j < i; ++j)
        {
            if (v[j] < v[j + 1])
            { // comparação invertida
                int temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
            }
        }
    }
}
int retira_elementos(int n, int *v, int m, int *v2)
{
    int result[n];
    int index = 0;

    for (int i = 0; i < n; i++)
    {
        int encontrado = 0;

        for (int j = 0; j < m; j++)
        {
            if (v[i] == v2[j])
            {
                encontrado = 1;
                break;
            }
        }

        if (!encontrado)
        {
            result[index] = v[i];
            index++;
        }
    }

    for (int i = 0; i < index; i++)
    {
        v[i] = result[i];
    }

    return index;
}
int tamanho_pilha(Pilha *pilha)
{
    Pilha *p = pilha;
    int tam = 0;
    while (p != NULL)
    {
        tam++;
        p = p->prox;
    }
    return tam;
}

int tamanho_fila(Fila *fila)
{
    Fila *p = fila;
    int tam = 0;
    while (p != NULL)
    {
        tam++;
        p = p->prox;
    }
    return tam;
}

int main()
{
    Pilha *stack = NULL;
    Fila *queue = NULL;
    int qtd;
    while (scanf("%d", &qtd) != EOF)
    {
        int valor, valor_dois, tamanho = 0, aux_impossible = 10, auxprioridade = 0, k = 0, auxfila = 0, auxpilha = 0, novo_tam, tam_fila, tam_pilha;
        int pilha_prioridade[qtd], pilha_compara[qtd], numeros_retirados[qtd], kaka = 0, numeros_colocados[qtd];
        for (int i = qtd; i > 0; i--)
        {
            scanf("%d", &valor);
            if (valor == 1)
            {
                scanf("%d", &valor_dois);
                queue = insere(queue, valor_dois);
                stack = empilha(stack, valor_dois);
                pilha_compara[k] = valor_dois;
                numeros_colocados[k] = valor_dois;
                k++;
            }
            else
            {
                scanf("%d", &valor_dois);
                queue = elimina_elemento(queue, valor_dois);
                stack = desempilha(stack, valor_dois);
                numeros_retirados[kaka] = valor_dois;
                kaka++;
                for (int j = 0; j < k; j++)
                {
                    if (pilha_compara[j] == valor_dois)
                    {
                        pilha_prioridade[tamanho] = valor_dois;
                        tamanho++;
                        auxprioridade = 1;
                        break;
                    }
                    else
                    {
                        auxprioridade = 0;
                    }
                }
            }
        }
        bubbleSortDescending(qtd - tamanho, pilha_compara);
        for (int i = 0; i < k; i++)
        {
            if (aux_impossible == 0)
            {
                break;
            }
            for (int j = 0; j < kaka; j++)
            {
                if (numeros_colocados[i] == numeros_retirados[j])
                {
                    aux_impossible = 0;
                    break;
                }
            }
        }
        novo_tam = retira_elementos(k, numeros_colocados, kaka, numeros_retirados);
        tam_pilha = tamanho_pilha(stack);
        tam_fila = tamanho_fila(queue);
        if (tam_pilha == novo_tam)
        {
            auxpilha = 1;
        }
        else
        {
            auxpilha = 0;
        }
        if (tam_fila == novo_tam)
        {
            auxfila = 1;
        }
        else
        {
            auxfila = 0;
        }
        for (int i = 0; i < tamanho; i++)
        {
            if (pilha_compara[i] != pilha_prioridade[i])
            {
                auxprioridade = 0;
            }
        }
        if (aux_impossible == 10)
        {
            printf("impossible");
        }
        else if ((auxpilha + auxfila + auxprioridade) > 1)
        {
            printf("not sure");
        }
        else if ((auxfila) == 1)
        {
            printf("queue");
        }
        else if (auxpilha == 1)
        {
            printf("stack");
        }
        else
        {
            printf("priority queue");
        }
        while (queue != NULL)
        {
            queue = elimina_elemento(queue, queue->valor);
        }
        while (stack != NULL)
        {
            stack = desempilha(stack, stack->valor);
        }
        memset(pilha_prioridade, 0, qtd * sizeof(int));
        memset(pilha_compara, 0, qtd * sizeof(int));
        memset(numeros_retirados, 0, qtd * sizeof(int));
        memset(numeros_colocados, 0, qtd * sizeof(int));
        printf("\n");
    }
    return 0;
}