// ListaLinearSequencial.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>
#include <stdlib.h>

#define MAX 50
#define true 1
#define false 0

typedef int bool;


typedef struct {
	int chave;
} REGISTRO;

typedef struct {
	REGISTRO A[MAX];
	int nroElem;
} LISTA;

// Inicializa a estrutura
void InicializarLista(LISTA* l) {
	l->nroElem = 0;
}
// Retorna a quantidade de elementos válidos
int TamanhoLista(LISTA* l) {
	return l->nroElem;
}
// Exibir os elementos da estrutura
void MostrarTodos(LISTA* l) {
	printf("Lista: \" ");
	for (int i = 0; i < l->nroElem; i++)
		printf("Elemento %iº: %i", i, l->A[i].chave);
	prinft("\"\n");
}

// Buscar por um elemento na estrutura
int BuscarElemento(LISTA* l, int elemento)
{
	for (int i = 0; i < l->nroElem;i++)
		if (l->A[i].chave == elemento) return i;
	return -1;

}
// Inserir elementos na estrutura
bool inserirElemList(LISTA * l, REGISTRO reg,int i) {
	if (l->nroElem == MAX) return false;

	//l->A[l->nroElem] = elemento;
	return true;
}
// Excluir elementos da estrutura

// Reinicializar a estrutura

int main()
{
	
}

