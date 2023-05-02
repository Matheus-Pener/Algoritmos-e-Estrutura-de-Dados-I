#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct lista
{
    char nome[20];
    struct lista *prox;
};

typedef struct lista Lista;

Lista *inicializa()
{
    return NULL;
}

Lista *insere(Lista *l, char *nome)
{
    Lista *novo = (Lista *)malloc(sizeof(Lista));
    strcpy(novo->nome, nome);
    novo->prox = l;
    return novo;
}

void imprime(Lista *l)
{
    Lista *p;
    for (p = l; p != NULL; p = p->prox)
    {
        if (p->prox == NULL)
        {
            printf("%s", p->nome);
        }
        else
        {
            printf("%s ", p->nome);
        }
    }
    printf("\n");
}

Lista *busca(Lista *l, char *nome)
{
    Lista *p;
    for (p = l; p != NULL; p = p->prox)
    {
        if (strcmp(p->nome, nome) == 0)
        {
            return p;
        }
    }
    return NULL;
}

Lista *insere_amigos(Lista *l1, Lista *l2, char *nome)
{
    Lista *p, *novo_inicio = NULL, *amigo_indicado = NULL;

    if (strcmp(nome, "nao") != 0)
    {
        amigo_indicado = busca(l1, nome);
    }

    if (amigo_indicado == NULL)
    { // se o amigo indicado não está na primeira lista
        // concatenar as duas listas
        for (p = l2; p != NULL; p = p->prox)
        {
            if (busca(l1, p->nome) == NULL)
            {
                novo_inicio = insere(novo_inicio, p->nome);
            }
        }
        for (p = l1; p != NULL; p = p->prox)
        {
            novo_inicio = insere(novo_inicio, p->nome);
        }
    }
    else
    { // se o amigo indicado está na primeira lista
        Lista *q;
        for (q = l1; q != NULL; q = q->prox)
        {
            novo_inicio = insere(novo_inicio, q->nome);
            if (q == amigo_indicado)
            { // encontrou o amigo indicado
                for (p = l2; p != NULL; p = p->prox)
                {
                    if (busca(l1, p->nome) == NULL)
                    { // adiciona os amigos da segunda lista que não estão na primeira
                        novo_inicio = insere(novo_inicio, p->nome);
                    }
                }
            }
        }
    }

    return novo_inicio;
}

int main()
{
    char amigos_atual[200], novos_amigos[200], amigo_indicado[20];
    Lista *l1 = inicializa();
    Lista *l2 = inicializa();

    // lê a primeira lista de amigos
    fgets(amigos_atual, 200, stdin);
    char *token = strtok(amigos_atual, " \n");
    while (token != NULL)
    {
        l1 = insere(l1, token);
        token = strtok(NULL, " \n");
    }

    // lê a segunda lista de amigos
    fgets(novos_amigos, 200, stdin);
    token = strtok(novos_amigos, " \n");
    while (token != NULL)
    {
        l2 = insere(l2, token);
        token = strtok(NULL, " \n");
    }

    // lê o nome do amigo indicado ou a palavra "nao"
    fgets(amigo_indicado, 20, stdin);
    amigo_indicado[strcspn(amigo_indicado, "\n")] = '\0'; // remove o caractere '\n' da string

    // chama a função que insere os amigos na lista e imprime o resultado
    Lista *l3 = insere_amigos(l1, l2, amigo_indicado);
    imprime(l3);
    return 0;
}