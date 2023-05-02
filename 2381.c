#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char nome[30];
} alunos;

int main()
{
    int N, K;
    scanf("%d %d", &N, &K);
    alunos alunos[N];
    for (int i = 0; i < N; i++)
    {
        scanf("%29s", alunos[i].nome); // limita a leitura de caracteres em 29 para evitar buffer overflow
    };
    // bubble sort
    for (int i = 0; i < N - 1; i++)
    {
        for (int j = 0; j < N - i - 1; j++)
        {
            if (strcmp(alunos[j].nome, alunos[j].nome[j + 1]) > 0)
            {
                char temp[30];
                strcpy(temp, alunos[j].nome[j]);
                strcpy(alunos[j].nome[j], alunos[j].nome[j + 1]);
                strcpy(alunos[j].nome[j + 1], temp);
            }
        }
    }
    printf("%s", alunos[K].nome);
}
