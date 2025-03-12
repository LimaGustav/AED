#include "MatrixAdjacencia.h"
#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0

#define Branco 0
#define Cinza 1
#define Preto 2


bool inicializaGrafoMatriz(GrafoMatriz* g, int vertices,float invalido) {
    if (g == NULL || vertices < 1) return false;
    g->numVertices = vertices;
    g->numArestas = 0;
    int x, y;
    g->matriz = (bool**)malloc(sizeof(bool*) * vertices);
    for (x = 0; x < vertices;x++) {
        g->matriz[x] = (bool*)malloc(sizeof(bool) * vertices);
        for (y = 0;y < vertices;y++)
            g->matriz[x][y] = invalido;
    }
    return true;
}

bool exibeGrafoMatriz(GrafoMatriz* g) {
    if (g == NULL) return false;

    int x, y;
    printf("Imprimindo grafo (Vertices: %i; Arestas: %i).\n", g->numVertices, g->numArestas);
    for (x = 0;x < g->numVertices;x++) printf("\t%5i", x);
    printf("\n");

    for (x = 0;x < g->numVertices;x++) {
        printf("%i", x);
        for (y = 0;y < g->numVertices;y++)
            printf("\t%5.1f", g->matriz[x][y]);
        printf("\n");
    }

    return true;
}

bool liberaGraftoMatriz(GrafoMatriz* g) {
    if (g == NULL) return false;

    int x;
    for (x = 0; x < g->numVertices; x++)
        free(g->matriz[x]);
    free(g->matriz);
    g->numArestas = 0;
    g->numVertices = 0;
    g->matriz = NULL;
    return true;
}

bool insereArestaMatriz(GrafoMatriz* g, int v1, int v2) {
    if (g == NULL) return false;
    if (v1 < 0 || v2 < 0 || v1 >= g->numVertices || v2 >= g->numVertices || v1 == v2) return false;


    if (g->matriz[v1][v2] == true) {
        printf("Essa aresta já existe");
        return false;
    }

    // Grafo não direcionado
    g->matriz[v1][v2] = true;

    // Caso o grafo seja direcionado não adiciona essa linha
    g->matriz[v2][v1] = true;

    g->numArestas++;
    return true;
}

bool insereArestaDirigidoMatriz(GrafoMatriz* g, int v1, int v2) {
    if (g == NULL) return false;
    if (v1 < 0 || v2 < 0 || v1 >= g->numVertices || v2 >= g->numVertices) return false;


    if (g->matriz[v1][v2] == true) {
        printf("Essa aresta já existe");
        return false;
    }

    g->matriz[v1][v2] = true;


    g->numArestas++;
    return true;
}

bool insereArestaPonderadoMatriz(GrafoMatriz* g, int v1, int v2, float peso) {
    if (g == NULL) return false;
    if (v1 < 0 || v2 < 0 || v1 >= g->numVertices || v2 >= g->numVertices || v1 == v2) return false;


    if (g->matriz[v1][v2] == true) {
        printf("Essa aresta já existe");
        return false;
    }

    // Grafo não direcionado
    g->matriz[v1][v2] = peso;

    // Caso o grafo seja direcionado não adiciona essa linha
    g->matriz[v2][v1] = peso;

    g->numArestas++;
    return true;
}

bool insereArestaDirigidoPonderadoMatriz(GrafoMatriz* g, int v1, int v2, float peso) {
    if (g == NULL) return false;
    if (v1 < 0 || v2 < 0 || v1 >= g->numVertices || v2 >= g->numVertices || v1 == v2) return false;


    if (g->matriz[v1][v2] == true) {
        printf("Essa aresta já existe");
        return false;
    }

    // Grafo não direcionado
    g->matriz[v1][v2] = peso;

    g->numArestas++;
    return true;
}

bool removeArestaMatriz(GrafoMatriz* g, int v1, int v2,float invalido) {
    if (g == NULL) return false;
    if (v1 < 0 || v2 < 0 || v1 >= g->numVertices || v2 >= g->numVertices) return false;
    if (g->matriz[v1][v2] == false) return false;

    g->matriz[v1][v2] = invalido;

    // Caso o grafo seja direcionado não adiciona essa linha
    g->matriz[v2][v1] = invalido;

    g->numArestas--;
    return true;

}

bool removeArestaDirigidoMatriz(GrafoMatriz* g, int v1, int v2, float invalido) {
    if (g == NULL) return false;
    if (v1 < 0 || v2 < 0 || v1 >= g->numVertices || v2 >= g->numVertices) return false;
    if (g->matriz[v1][v2] == false) return false;

    g->matriz[v1][v2] = invalido;

    g->numArestas--;
    return true;
}

bool arestaExisteMatriz(GrafoMatriz* g, int v1, int v2) {
    if (g == NULL) return false;
    if (v1 < 0 || v2 < 0 || v1 >= g->numVertices || v2 >= g->numVertices) return false;
    if (g->matriz[v1][v2] == false) return false;

    return true;
}

int numeroDeVerticesMatriz(GrafoMatriz* g) {
    if (g != NULL) return g->numVertices;
    return -1;
}

int numeroDeArestasMatriz(GrafoMatriz* g) {
    if (g != NULL) return g->numArestas;
    return -1;
}

int numeroDeArestasMatriz2(GrafoMatriz* g) {
    if (g == NULL) return -1;
    int x, y, arestas = 0;
    for (int x = 0; x < g->numVertices; x++)
        // x+1 faz com que conte apenas aquilo que está acima da diagonal principal da matrix
        // Caso seja um grafo direcionado deve ser contado a matrix inteira
        for (int y = x + 1; y < g->numVertices; y++)
        {
            if (g->matriz[x][y]) arestas++;
        }
    return arestas;
}

bool possuiVizinhosMatriz(GrafoMatriz* g, int v) {
    if (!g) return false;
    if (v < 0 || v >= g->numVertices) return false;

    int x;
    for (int x = 0; x < g->numVertices; x++)
        if (g->matriz[v][x]) return true;

    return false;
}

bool retornaGrauDoVerticeMatriz(GrafoMatriz* g, int v) {
    if (!g) return false;
    if (v < 0 || v >= g->numVertices) return false;

    int x, grau = 0;
    for (int x = 0; x < g->numVertices; x++)
        if (g->matriz[v][x]) grau++;

    // Para grafo direcionado adiciona essa linha
    //if (g->matriz[x][v]) grau++;

    return grau;
}
bool retornaGrauDoVerticeDirigidoMatriz(GrafoMatriz* g, int v) {
    if (!g) return false;
    if (v < 0 || v >= g->numVertices) return false;

    int x, grau = 0;
    for (int x = 0; x < g->numVertices; x++) {
            if (g->matriz[v][x]) grau++;
        // Para grafo direcionado adiciona essa linha
        if (g->matriz[x][v]) grau++;
    }

    return grau;
}
void visitaEmProfundidade(GrafoMatriz* g, int atual, bool* visitado, int anterior) {
    printf("Visitando vertice: %3i (anterior: %3i)\n", atual, anterior);

    visitado[atual] = true;
    int x;
    for (x = 0; x < g->numVertices; x++) {
        if (g->matriz[atual][x] && !visitado[x])
            visitaEmProfundidade(g, x, visitado, atual);
    }
}

void buscaProfundidadeMatriz(GrafoMatriz* g) {
    if (!g || g->numVertices < 1) return;
    int x;
    bool* visitado = (bool*)malloc(sizeof(bool) * g->numVertices);
    for (x = 0;x < g->numVertices;x++) visitado[x] = false;

    for (x = 0;x < g->numVertices;x++) {
        if (visitado[x] == false)
            visitaEmProfundidade(g, x, visitado, -1);
    }
    free(visitado);
}

void buscaProfundidadeCoresMatriz(GrafoMatriz* g) {
    if (!g || g->numVertices < 1) return;
    int* cor = (int)malloc(sizeof(int) * g->numVertices);
    int* tDescoberta = (int)malloc(sizeof(int) * g->numVertices);
    int* tTermino = (int)malloc(sizeof(int) * g->numVertices);
    int* anterior = (int)malloc(sizeof(int) * g->numVertices);
    int* tempo = (int)malloc(sizeof(int));
    *tempo = 0;

    int x;
    for (int x = 0; x < g->numVertices; x++)
    {
        cor[x] = Branco;
        tTermino[x] = anterior[x] = tDescoberta[x] = -1;
    }

}