#include "ListaAdjacencia.h"
#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0

#define Branco 0
#define Cinza 1
#define Preto 2

bool inicializaGrafoLista(GrafoLista* g, int vertices) {
    if (!g || vertices < 1) return false;
    g->numVertices = vertices;
    g->numArestas = 0;
    g->A = (ElemLista**)malloc(sizeof(ElemLista*) * vertices);
    int x;
    for (x = 0;x < vertices;x++) {
        g->A[x] = NULL;
    }
    return true;

}

bool exibeGrafoLista(GrafoLista* g) {
    if (!g) return;
    printf("\nImprimindo grafo (Vertices: %i; Arestas: %i).\n", g->numVertices, g->numArestas);

    ElemLista* atual;
    int x;
    for (int x = 0; x < g->numVertices; x++)
    {
        printf("[%2i]", x);
        atual = g->A[x];
        while (atual) {
            printf("->%3i", atual->vertice);
            atual = atual->prox;
        }
        printf("\n");
    }
}

bool liberaGraftoLista(GrafoLista* g) {
    if (!g) return;
    ElemLista* atual;
    ElemLista* anterior;
    int x;
    for (int x = 0; x < g->numVertices; x++)
    {
        atual = g->A[x];
        while (atual) {
            anterior = atual;
            atual = atual->prox;
            free(anterior);
        }
        free(g->A);
    }
    g->numArestas = 0;
    g->numVertices = 0;
    g->A = NULL;
}
insereArestaAux(GrafoLista* g, int v1, int v2) {
    ElemLista* novo, *anterior;
    ElemLista* atual = g->A[v1];

    while (atual && atual->vertice < v2) {
        anterior = atual;
        atual = atual->prox;
    }
    if (atual && atual->vertice == v2) return false;

    novo = (ElemLista*)malloc(sizeof(ElemLista));
    novo->vertice = v2;
    novo->prox = atual;

    if (anterior) anterior->prox = novo;
    else g->A[v1] = novo;
    return true;
}
bool insereArestaLista(GrafoLista* g, int v1, int v2) {
    if (!g) return false;
    if (v1 < 0 || v2 < 0 || v1 >= g->numVertices || v2 >= g->numVertices) return false;

    // Isso caso o grafo não seja direcionado
    if (v1 == v2) return false;


    if (insereArestaAux(g, v1, v2)) {
        insereArestaAux(g, v2, v1);
        g->numArestas++;
    }
}
bool insereArestaDirigidoLista(GrafoLista* g, int v1, int v2) {
    if (!g) return false;
    if (v1 < 0 || v2 < 0 || v1 >= g->numVertices || v2 >= g->numVertices) return false;

    // Isso caso o grafo não seja direcionado
    if (v1 == v2) return false;


    if (insereArestaAux(g, v1, v2)) {
        g->numArestas++;
    }
}

