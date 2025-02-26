// ListaAdjacencia.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 1

typedef int bool;

typedef struct aux {
    int vertice;
    struct aux* prox;
} ElemLista, *PONT;

typedef struct {
    int numVertices;
    int numArestas;
    ElemLista** A;
} Grafo;

bool inicializaGrafo(Grafo* g, int vertices) {
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

void exibeGrafo(Grafo* g) {
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

bool liberaGrafo(Grafo* g) {
    if (!g) return false;

    ElemLista* atual, * apagar;
    int x;
    for (x = 0; x < g->numVertices; x++) {
        atual = g->A[x];
        while (atual) {
            apagar = atual;
            atual = atual->prox;
            free(apagar);
        }
    }
    free(g->A);
    g->numVertices = 0;
    g->numArestas = 0;
    g->A = NULL; 
}
bool insereArestaAux(Grafo* g, int v1, int v2) {
    ElemLista* novo, * ant = NULL;
    ElemLista* atual = g->A[v1];

    while (atual && atual->vertice<v2)
    {
        ant = atual;
        atual = atual->prox;
    }
    if (atual && atual->vertice == v2) return false;
    novo = (ElemLista*)malloc(sizeof(ElemLista));
    novo->vertice = v2;
    novo->prox = atual;

    if (ant) ant->prox = novo;
    else g->A[v1] = novo;
    return true;
}

bool insereAresta(Grafo* g, int v1, int v2) {
    if (!g) return false;
    if (v1 < 0 || v2 < 0 || v1 >= g->numVertices || v2 >= g->numVertices) return false;

    // Isso caso o grafo não seja direcionado
    if (v1 == v2) return false;

    if (insereArestaAux(g, v1, v2)) {
        insereArestaAux(g, v2, v1);
        g->numArestas++;
    }

}

bool removeArestaAux(Grafo* g, int v1, int v2) {

    ElemLista* ant = NULL;
    ElemLista* atual = g->A[v1];
    while (atual && atual->vertice < v2)
    {
        ant = atual;
        atual = atual->prox;
    }
    if (atual && atual->vertice == v2) {
        if (ant) ant->prox = atual->prox;
        else g->A[v1] = atual->prox;
        free(atual);
        return true;
    }
    return false;
}

bool removeAresta(Grafo* g, int v1, int v2) {
    if (!g || v1 < 0 || v2 < 0 || v1 >= g->numVertices || v2 >= g->numVertices) return false;
    if (removeArestaAux(g, v1, v2)) {
        removeArestaAux(g, v2, v1);
        return true;
    }
    return false;
}

bool arestaExiste(Grafo* g, int v1, int v2) {
    if (!g || v1 < 0 || v2 < 0 || v1 >= g->numVertices || v2 >= g->numVertices) return false;

    ElemLista* atual = g->A[v1];
    while (atual && atual->vertice < v2)
    {
        atual = atual->prox;
    }
    if (atual->vertice == v2)
        return true;
    return false;

}

int numeroDeVertices(Grafo* g) {
    if (g) return g->numVertices;
    return -1;
}

int possuiVizinhos(Grafo* g, int v) {
    if (!g || v < 0 || v >= g->numVertices )return false;
    if (!g->A[v]) return false;

    return true;

}

int retornaGrauDoVertice(Grafo* g, int v) {
    if(!g || v < 0 || v >= g->numVertices) return -1;

    int grau = 0;
    ElemLista* atual;
    atual = g->A[v];
    while (atual) {
        grau++;
        atual = atual->prox;
    }
    return grau;
}
int main()
{
    int opcao = 0;
    Grafo* g = (Grafo*)malloc(sizeof(Grafo));
    inicializaGrafo(g, 5);
    while (opcao != 10)
    {
        printf("\n\nO que você deseja fazer? \n");
        printf("1: Exibir Grafo\n");
        printf("2: Inserir Aresta\n");
        printf("3: Remover Aresta\n");
        printf("10: Encerra\n");

        scanf_s("%d", &opcao);
        system("cls");
        if (opcao == 1) {
            exibeGrafo(g);
        }
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
