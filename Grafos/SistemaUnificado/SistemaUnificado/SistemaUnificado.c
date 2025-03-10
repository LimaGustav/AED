// SistemaUnificado.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>
#include <stdlib.h>
#include "MatrixAdjacencia.h"

int main()
{
    int opcao = 0;
    Grafo* g = (Grafo*)malloc(sizeof(Grafo));
    inicializaGrafo(g, 5);
    while (opcao != 10)
    {
        printf("O que você deseja fazer? \n");
        printf("1: Exibir Grafo\n");
        printf("2: Inserir Aresta\n");
        printf("3: Remover Aresta\n");
        printf("4: Busca em Profundidade\n");
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
        if (opcao == 4)
        {
            buscaProfundidade(g);
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
