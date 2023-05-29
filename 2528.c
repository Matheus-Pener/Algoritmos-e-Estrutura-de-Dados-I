#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define MAX_N 1000
#define INF INT_MAX

int grafo[MAX_N][MAX_N];
bool visitado[MAX_N];
int distancia[MAX_N];

int Menor_distancia(int N) {
    int menorDistancia = INF;
    int menorIndice = -1;

    for (int i = 0; i < N; i++) {
        if (!visitado[i] && distancia[i] < menorDistancia) {
            menorDistancia = distancia[i];
            menorIndice = i;
        }
    }

    return menorIndice;
}

void dijkstra(int origem, int destino, int cidadeProibida, int N) {
    for (int i = 0; i < N; i++) {
        distancia[i] = INF;
        visitado[i] = false;
    }

    distancia[origem] = 0;

    for (int i = 0; i < N - 1; i++) {
        int u = Menor_distancia(N);
        visitado[u] = true;

        for (int v = 0; v < N; v++) {
            if (!visitado[v] && grafo[u][v] != INF && distancia[u] + grafo[u][v] < distancia[v] && v != cidadeProibida) {
                distancia[v] = distancia[u] + grafo[u][v];
            }
        }
    }
}

int main() {
    int N, M;
    while (scanf("%d %d", &N, &M) != EOF) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (i == j) {
                    grafo[i][j] = 0;
                } else {
                    grafo[i][j] = INF;
                }
            }
        }
        for (int i = 0; i < M; i++) {
            int A, B;
            scanf("%d %d", &A, &B);
            grafo[A - 1][B - 1] = 1;
            grafo[B - 1][A - 1] = 1;
        }

        int C, R, E;
        scanf("%d %d %d", &C, &R, &E);

        dijkstra(C - 1, R - 1, E - 1, N);

        int menorTempo = distancia[R - 1];
        printf("%d\n", menorTempo);
    }

    return 0;
}
