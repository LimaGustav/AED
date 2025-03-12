// SistemaUnificado.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>
#include <stdlib.h>
#include "MatrixAdjacencia.h"

int showMenu() {

    int opcao = 0;
    printf("\n\nO que você deseja fazer? \n");
    printf("1: Exibir Grafo\n");
    printf("2: Inserir Aresta\n");
    printf("3: Remover Aresta\n");
    printf("4: Busca em Profundidade\n");
    printf("0: Encerra\n");
    scanf_s("%d", &opcao);
    
    return opcao;
}


int main()
{
    int tipoGrafo = 0;
    int implementacao = 0;
    int opcao = 1;
    int invalido = -1;
    int vertices = 10;

    printf("Qual Grafo você quer usar?\n\n1 - Nao Dirigido\n2 - Dirigido\n3 - Nao Dirigido Ponderado\n4 - Dirigido Ponderado\n> ");
    scanf_s("%d", &tipoGrafo);
    printf("Qual implementação deseja usar?\n1 - Matriz de adjacencia\n2 - Lisata de adjacencia\n> ");
    scanf_s("%d", &implementacao);

    system("cls");
    GrafoMatriz* gMatriz = (GrafoMatriz*) malloc(sizeof(GrafoMatriz));

    if (tipoGrafo <3)
        inicializaGrafoMatriz(gMatriz,vertices,0);
    else
        inicializaGrafoMatriz(gMatriz,vertices,-1);


    while (opcao != 0) 
    {
        opcao = showMenu();
        switch (opcao)
        {
        case 1: // Exibir grafo
            
            if (implementacao == 1)
                exibeGrafoMatriz(gMatriz);

            break;
        case 2: { // Inserir aresta
            int v1;
            int v2;
            printf("\nVertice 1: ");
            scanf_s("%d", &v1);
            printf("\nVertice 2: ");
            scanf_s("%d", &v2);

            if (implementacao == 1 && tipoGrafo == 1) // Insere aresta em matriz de adjacencia não dirigido
                insereArestaMatriz(gMatriz, v1, v2);

            else if (implementacao == 1 && tipoGrafo == 2) // Insere aresta em matriz de adjacencia dirigido
                insereArestaDirigidoMatriz(gMatriz, v1, v2);

            else if (implementacao == 1 && tipoGrafo == 3)  // Insere aresta em matriz de adjacencia não dirigido ponderado
            {
                
                float peso;
                printf("Informe o peso: ");
                scanf_s("%f", &peso);
                insereArestaPonderadoMatriz(gMatriz, v1, v2,peso);
            }
            else if (implementacao == 1 && tipoGrafo == 4) // Insere aresta em matriz de adjacencia dirigido ponderado
            {
                
                float peso;
                printf("Informe o peso: ");
                scanf_s("%f", &peso);
                insereArestaDirigidoPonderadoMatriz(gMatriz, v1, v2, peso);
            }
            if (implementacao == 2 && tipoGrafo == 1)

            break;
        }
        case 3: {
            int v1;
            int v2;
            printf("\nVertice 1: ");
            scanf_s("%d", &v1);
            printf("\nVertice 2: ");
            scanf_s("%d", &v2);

            if (implementacao == 1 && tipoGrafo == 1) // Remove aresta em matriz de adjacencia não dirigido
                removeArestaMatriz(gMatriz, v1, v2, 0);

            else if (implementacao == 1 && tipoGrafo == 2) // Remove aresta em matriz de adjacencia dirigido
                removeArestaDirigidoMatriz(gMatriz, v1, v2, 0);

            else if (implementacao == 1 && tipoGrafo == 3)  // Remove aresta em matriz de adjacencia não dirigido ponderado
                removeArestaMatriz(gMatriz, v1, v2, -1);

            else if (implementacao == 1 && tipoGrafo == 4) // Insere aresta em matriz de adjacencia dirigido ponderado
                removeArestaDirigidoMatriz(gMatriz, v1, v2, -1);
            break;
        }
        case 4:
            
            break;

        default:
            break;
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
