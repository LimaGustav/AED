#ifndef _MATRIX_ADJACENCIA_H
#define _MATRIX_ADJACENCIA_H

typedef int bool;
typedef struct {
    int numVertices;
    int numArestas;
    bool** matriz;
} Grafo;

bool inicializaGrafo(Grafo* g, int vertices);

bool exibeGrafo(Grafo* g);

bool liberaGrafto(Grafo* g);

bool insereAresta(Grafo* g, int v1, int v2);

bool removeAresta(Grafo* g, int v1, int v2);

bool arestaExiste(Grafo* g, int v1, int v2);


int numeroDeVertices(Grafo* g);

int numeroDeArestas(Grafo* g);

int numeroDeArestas2(Grafo* g);

bool possuiVizinhos(Grafo* g, int v);

bool retornaGrauDoVertice(Grafo* g, int v);

void visitaEmProfundidade(Grafo* g, int atual, bool* visitado, int anterior);

void buscaProfundidade(Grafo* g);

void buscaProfundidadeCores(Grafo* g);



#endif // !_MATRIX_ADJACENCIA_H
