// MatrixAdjacencia.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0

typedef int bool;
typedef struct {
    int numVertices;
    int numArestas;
    bool** matriz;
} Grafo;

bool inicializaGrafo(Grafo* g, int vertices) {
    if (g == NULL || vertices < 1) return false;
    g->numVertices = vertices;
    g->numArestas = 0;
    int x,y;
    g->matriz = (bool**)malloc(sizeof(bool*) * vertices);
    for (x = 0; x < vertices;x++) {
        g->matriz[x] = (bool*) malloc(sizeof(bool) * vertices);
        for (y = 0;y < vertices;y++)
            g->matriz[x][y] = false;
    }
    return true;
}

bool exibeGrafo(Grafo* g) {
    if (g == NULL) return false;

    int x, y;
    printf("Imprimindo grafo (Vertices: %i; Arestas: %i).\n", g->numVertices, g->numArestas);
    for (x = 0;x < g->numVertices;x++) printf("\t%5i", x);
    printf("\n");

    for (x = 0;x < g->numVertices;x++) {
        printf("%i", x);
        for (y = 0;y < g->numVertices;y++)
            printf("\t%5i", g->matriz[x][y]);
        printf("\n");
    }

    return true;
}

bool liberaGrafto(Grafo* g) {
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

bool insereAresta(Grafo* g, int v1, int v2) {
    if (g == NULL) return false;
    if (v1 < 0 || v2 < 0 || v1 >= g->numVertices || v2 >= g->numVertices) return false;

    
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

bool removeAresta(Grafo* g, int v1, int v2) {
    if (g == NULL) return false;
    if (v1 < 0 || v2 < 0 || v1 >= g->numVertices || v2 >= g->numVertices ) return false;
    if (g->matriz[v1][v2] == false) return false;

    g->matriz[v1][v2] = false;

    // Caso o grafo seja direcionado não adiciona essa linha
    g->matriz[v2][v1] = false;

    g->numArestas--;
    return true;

}

bool arestaExiste(Grafo* g, int v1, int v2) {
    if (g == NULL) return false;
    if (v1 < 0 || v2 < 0 || v1 >= g->numVertices || v2 >= g->numVertices) return false;
    if (g->matriz[v1][v2] == false) return false;
    
    return true;
}

int numeroDeVertices(Grafo* g) {
    if (g != NULL) return g->numVertices;
    return -1;
}

int numeroDeArestas(Grafo* g) {
    if (g != NULL) return g->numArestas;
    return -1;
}

int numeroDeArestas2(Grafo* g) {
    if (g == NULL) return -1;
    int x, y, arestas = 0;
    for (int x = 0; x < g->numVertices; x++)
        // x+1 faz com que conte apenas aquilo que está acima da diagonal principal da matrix
        // Caso seja um grafo direcionado deve ser contado a matrix inteira
        for (int y = x+1; y < g->numVertices; y++)
        {
            if (g->matriz[x][y]) arestas++;
        }
    return arestas;
}

bool possuiVizinhos(Grafo* g, int v) {
    if (!g) return false;
    if (v < 0 || v >= g->numVertices) return false;

    int x;
    for (int x = 0; x < g->numVertices; x++)
        if (g->matriz[v][x]) return true;

    return false;
}

bool retornaGrauDoVertice(Grafo* g, int v) {
    if (!g) return false;
    if (v < 0 || v >= g->numVertices) return false;

    int x,grau = 0;
    for (int x = 0; x < g->numVertices; x++)
        if (g->matriz[v][x]) grau++;

        // Para grafo direcionado adiciona essa linha
        //if (g->matriz[x][v]) grau++;

    return grau;
}

int main()
{
    int opcao = 0;
    Grafo* g = (Grafo*)malloc(sizeof(Grafo));
    inicializaGrafo(g,5);
    while (opcao != 10)
    {
        printf("O que você deseja fazer? \n");
        printf("1: Exibir Grafo\n");
        printf("2: Inserir Aresta\n");
        printf("3: Remover Aresta\n");
        printf("10: Encerra\n");

        scanf_s("%d", &opcao);
        system("cls");
        if (opcao == 1) {
            exibeGrafo(g);
        }
        if (opcao == 2) {
            int v1, v2;
            printf("Insira o vertice inicial: ");
            scanf_s("%d", &v1);

            printf("Insira o vertice final: ");
            scanf_s("%d", &v2);
            insereAresta(g, v1, v2);
        }
        if (opcao == 3) {
            int v1, v2;
            printf("Insira o vertice inicial: ");
            scanf_s("%d", &v1);

            printf("Insira o vertice final: ");
            scanf_s("%d", &v2);
            removeAresta(g, v1, v2);
        }

        
    }
}


