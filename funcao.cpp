#include <iostream>
#include <locale.h>
#include <math.h>
#include <stdlib.h>
#include "interface.h"

using namespace std;

struct Ponto;
struct List
{
	int Quantidade;
	
	Ponto listaPontos[Limite];
};

List* criaLista()
{
	List* Pont;
	Pont = (List*)malloc(sizeof(List));

	if (Pont == NULL) {
		return 0;
	}
	Pont->Quantidade = 0;
}

// Informar o tamanho da lista
int tamanhoDaLista(List* Pont)
{
	if (Pont== NULL){
		cout << "\nERROR"<<endl;
		return -1;
	}
	else
	{
		return Pont->Quantidade;
	}
}
//---------------

// Verifica se a lista está cheia 
int listaCheia(List* Pont)
{
	if (Pont == NULL) {
		cout << "\nERROR" << endl;
		return -1;
	}
	else
	{
		return (Pont->Quantidade == Limite);
		// Se retornar 1 significa que atingiu o maximo.
		// Se retornar 0 siginifica que ainda tem espaço na lista.
	}
}
//---------------

// Verifica se a lista está vazia
int listaVazia(List* Pont)
{
	if (Pont == NULL) {
		cout << "\nERROR" << endl;
		return -1;
	}
	else
	{
		return (Pont->Quantidade == 0);
		// Se retornar 1 significa que está vazia.
		// Se retornar 0 siginifica que tem condeudo na lista.
	}
}
//---------------

// Colocar um valor novo no final da lista
int incereNoFinal(List* Pont, Ponto ponto)
{
	if (Pont == NULL) {
		cout << "\nERROR" << endl;
		return 0;
	}
	else if(listaCheia(Pont))
	{
		cout << "\nLista cheia"<<endl;
		return 0;
	}
	else
	{
		Pont->listaPontos [Pont->Quantidade] = ponto;
		Pont->Quantidade++;
		return 1;
	}
}
//---------------

// Colocar um valor novo no inicio da lista
int incereNoInicio(List* Pont, Ponto ponto)
{
	if (Pont == NULL) {
		cout << "\nERROR" << endl;
		return 0;
	}
	else if (listaCheia(Pont))
	{
		cout << "\nLista cheia" << endl;
		return 0;
	}
	else
	{
		for (int i= Pont->Quantidade;i>=0;i--)
		{
			Pont->listaPontos[i + 1] = Pont->listaPontos[i];
		}
		Pont->listaPontos[0] = ponto;
	}
}
//---------------

// Colocar valor na posição anterior a "X" (Obs: SÓ SE FOR MENOR QUE X)
int incereNoOrdenadoX(List* Pont, Ponto ponto)
{
	if (Pont == NULL) {
		cout << "\nERROR" << endl;
		return 0;
	}
	else if (listaCheia(Pont))
	{
		cout << "\nLista cheia" << endl;
		return 0;
	}
	else
	{
		// Verificar se o valor informado se encaixa na posção anterior a de X

		int loop = 0;
		while (loop < Pont->Quantidade && Pont->listaPontos[loop].x < ponto.x)
		{
			loop++;
		}

		for (int i = Pont->Quantidade - 1; i >= loop; i--)
		{
			Pont->listaPontos[i + 1] = Pont->listaPontos[i];
		}

		Pont->listaPontos[loop] = ponto;
		Pont->Quantidade++;
		return 1;
	}
}
//---------------

// Imprimi no console todos os valores da lista
void imprimirLista(List* Pont)
{
	for (int i = 0; i < Pont->Quantidade; i++) {
		cout <<i+1<<" - "<< "( X = "<<Pont->listaPontos[i].x<<", Y = "<<Pont->listaPontos[i].y<<" )\n";
	}
}
//---------------

// Limpa dados ques estão na lista
void liberarLista(List* Pont)
{
	free(Pont); 
}
//---------------

int removeFinal(List* Pont) {

	if (Pont == NULL) {
		cout << "\nERROR" << endl;
		return 0;
	}
	else if (Pont->Quantidade==0)
	{
		cout << "\nLista vazia!" << endl;
		return 0;
	}
	else
	{
		Pont->Quantidade--;
		return 1;
	}
}


int removeInicio(List* Pont) {

	if (Pont == NULL) {
		cout << "\nERROR" << endl;
		return 0;
	}
	else if (Pont->Quantidade==0)
	{
		cout << "\nLista vazia!" << endl;
		return 0;
	}
	else
	{
		for (int i = 0; i < Pont->Quantidade;i++) {

			Pont->listaPontos[i] = Pont->listaPontos[i + 1];	
		}
		Pont->Quantidade--;
		return 1;
	}
}


int removeOrdenadoY(List* Pont, float yPonto) {

	if (Pont == NULL) {
		cout << "\nERROR" << endl;
		return 0;
	}
	else if (Pont->Quantidade == 0) {
		cout << "Lista vazia!" << endl;
		return 0;
	}
	else
	{
		int i = 0;
		while (i < Pont->Quantidade && Pont->listaPontos[i].y != yPonto) {
			i++; 
		}
		
		if (i == Pont->Quantidade) {
			cout << "Elemento não encontrado!" << endl;
			return 0;
		}

		for (int x = i; x < Pont->Quantidade; x++) {
			Pont->listaPontos[x] = Pont->listaPontos[x + 1];
		}
		Pont->Quantidade--;
		return 1;
	}

}


int consultaListaPosicao(List *Pont, int Posicao, Ponto *ponto) {

	if (Pont == NULL) {
		cout << "\nERROR" << endl;
		return 0;
	}
	else if (Posicao <= 0 || Posicao > Pont->Quantidade)
	{
		cout << "Elemento não encontrado!"<<endl;
		return 0;
	}
	else
	{
		*ponto = Pont->listaPontos[Posicao - 1];
		return 1;
	}
}


int consultaPeloElementoX(List *Pont, float xPonto, Ponto *ponto) {

	if (Pont == NULL) {
		cout << "\nERROR" << endl;
		return 0;
	}
	else
	{
		int i = 0;
		while (i < Pont->Quantidade && Pont->listaPontos[i].x != xPonto)
		{
			i++;
		}if (i == Pont->Quantidade)
		{
			cout << "Elemento não encontrado!" << endl;
			return 1;
		}

		*ponto = Pont->listaPontos[i];
		return 1;
	}

}