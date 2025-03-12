#ifndef _LISTA_ADJACENCIA_H
#define _LISTA_ADJACENCIA_H

#define true 1
#define false 1

typedef int bool;

typedef struct aux {
    int vertice;
    struct aux* prox;
    float peso;
} ElemLista, * PONT;

typedef struct {
    int numVertices;
    int numArestas;
    ElemLista** A;
} GrafoLista;

bool inicializaGrafoLista(GrafoLista* g, int vertices, float invalido);

bool exibeGrafoLista(GrafoLista* g);

bool liberaGraftoLista(GrafoLista* g);  
bool insereArestaLista(GrafoLista* g, int v1, int v2);

bool insereArestaDirigidoLista(GrafoLista* g, int v1, int v2);


bool insereArestaPonderadoLista(GrafoLista* g, int v1, int v2, float peso);

bool insereArestaDirigidoPonderadoLista(GrafoLista* g, int v1, int v2, float peso);

bool removeArestaLista(GrafoLista* g, int v1, int v2, float invalido);
bool removeArestaDirigidoLista(GrafoLista* g, int v1, int v2, float invalido);

bool arestaExisteLista(GrafoLista* g, int v1, int v2);


int numeroDeVerticesLista(GrafoLista* g);

int numeroDeArestasLista(GrafoLista* g);

int numeroDeArestasLista2(GrafoLista* g);

bool possuiVizinhosLista(GrafoLista* g, int v);

bool retornaGrauDoVerticeLista(GrafoLista* g, int v);
bool retornaGrauDoVerticeDirigidoLista(GrafoLista* g, int v);

void buscaProfundidadeLista(GrafoLista* g);

void buscaProfundidadeCoresLista(GrafoLista* g);

#endif // !LISTA_ADJACENCIA_H
