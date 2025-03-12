#ifndef _MATRIX_ADJACENCIA_H
#define _MATRIX_ADJACENCIA_H

typedef float bool;
typedef struct {
    int numVertices;
    int numArestas;
    bool** matriz;
} GrafoMatriz;



bool inicializaGrafoMatriz(GrafoMatriz* g, int vertices,float invalido);

bool exibeGrafoMatriz(GrafoMatriz* g);

bool liberaGraftoMatriz(GrafoMatriz* g);

bool insereArestaMatriz(GrafoMatriz* g, int v1, int v2);

bool insereArestaDirigidoMatriz(GrafoMatriz* g, int v1, int v2);

/// <summary>
/// Grafo ponderado não dirigido
/// </summary>
/// <param name="g"></param>
/// <param name="v1"></param>
/// <param name="v2"></param>
/// <param name="peso"></param>
/// <returns></returns>
bool insereArestaPonderadoMatriz(GrafoMatriz* g, int v1, int v2, float peso);

bool insereArestaDirigidoPonderadoMatriz(GrafoMatriz* g, int v1, int v2,float peso);

bool removeArestaMatriz(GrafoMatriz* g, int v1, int v2,float invalido);
bool removeArestaDirigidoMatriz(GrafoMatriz* g, int v1, int v2,float invalido);

bool arestaExisteMatriz(GrafoMatriz* g, int v1, int v2);


int numeroDeVerticesMatriz(GrafoMatriz* g);

int numeroDeArestasMatriz(GrafoMatriz* g);

int numeroDeArestasMatriz2(GrafoMatriz* g);

bool possuiVizinhosMatriz(GrafoMatriz* g, int v);

bool retornaGrauDoVerticeMatriz(GrafoMatriz* g, int v);
bool retornaGrauDoVerticeDirigidoMatriz(GrafoMatriz* g, int v);

void buscaProfundidadeMatriz(GrafoMatriz* g);

void buscaProfundidadeCoresMatriz(GrafoMatriz* g);



#endif // !_MATRIX_ADJACENCIA_H
