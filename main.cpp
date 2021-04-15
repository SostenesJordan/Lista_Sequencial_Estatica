#include <iostream>
#include <locale.h>
#include <math.h>
#include <stdlib.h>
#include "interface.h"



int main()
{
	using namespace std;

	setlocale(LC_ALL, "Portuguese");

	List* ListaPontosXY;
	Ponto p, *PontP;
	
	PontP = &p;
	int i = 1, Auxiliar = 0;
	char menu;

	ListaPontosXY = criaLista();

	

	while (i != 0) {

		printf("\n##############################################");
		printf("\n#           MENU - Lista Ordenada            #");
		printf("\n#                                            #");
		printf("\n#	Digite a op\207\706o desejada              #");
		printf("\n#                                            #");
		printf("\n#	 1 = consultar lista                       #");
		printf("\n#	 2 = imprimir lista                        #");
		printf("\n#	 3 = inserir no incio da lista             #");
		printf("\n#	 4 = inserir no final da lista             #");
		printf("\n#	 5 = inserrir ordenado a X                 #");
		printf("\n#	 6 = remover no inicio da lista            #");
		printf("\n#	 7 = remover no final da lista             #");
		printf("\n#	 8 = remover ordenado a Y                  #");
		printf("\n#	 9 = consultar lista pela posição          #");
		printf("\n#	 10 = Consultar pelo X do ponto            #");
		printf("\n#	 Qualquer outra tecla o programa irá sair  #");
		printf("\n#                                            #");
		printf("\n##############################################");
		printf("\n\n");

		cin >> menu;

		menu = toupper(menu); // -> vai passar o caractere informado para MAIUSCULO

		switch (menu)
		{
			case '1': // mostrar quantidade de elementos
				Auxiliar = tamanhoDaLista(ListaPontosXY);
				cout << "Elementos na Lista :" << Auxiliar << endl;
				break;

			case '2': // imprimi a lista
				imprimirLista(ListaPontosXY);
				break;

			case '3': //incere no inicio
				cout << "Informe o valor x :"; cin >> p.x;
				cout << "Informe o valor y :"; cin >> p.y;
				Auxiliar = incereNoInicio(ListaPontosXY,p);

				if (Auxiliar == 0) {
					cout << "ERROR" << endl;
				}
				break;

			case '4': // incere no final
				cout << "Informe o valor x :"; cin >> p.x;
				cout << "Informe o valor y :"; cin >> p.y;
				Auxiliar = incereNoFinal(ListaPontosXY, p);
				if (Auxiliar == 0) {
					cout << "ERROR" << endl;
				}
				break;

			case '5': // incere ordenado a x
				cout << "Informe o valor x :"; cin >> p.x;
				cout << "Informe o valor y :"; cin >> p.y;
				Auxiliar = incereNoOrdenadoX(ListaPontosXY, p);
				if (Auxiliar == 0) {
					cout << "ERROR" << endl;
				}
				break;

			case '6': // remover no incio
				Auxiliar = removeInicio(ListaPontosXY);
				if (Auxiliar == 0) {
					cout << "ERROR" << endl;
				}
				break;

			case '7': // remover no final
				Auxiliar = removeFinal(ListaPontosXY);
				if (Auxiliar == 0) {
					cout << "ERROR" << endl;
				}
				break;

			case '8': // remover ordenado a y
				cout << "Informe o ponto y para remover :"; cin >> p.y;
				Auxiliar = removeOrdenadoY(ListaPontosXY, p.y);
				if (Auxiliar == 0) {
					cout << "ERROR" << endl;
				}
				break;

			case '9': // consultar pela posição
				cout << "Informe a posição que deseja acessar :"; cin >> Auxiliar;
				Auxiliar = consultaListaPosicao(ListaPontosXY, Auxiliar, PontP);
				if (Auxiliar == 0) {
					cout << "ERROR" << endl;
				}
				cout << "Ponto solicitado em (X,Y) :" << p.x << "," << p.y << ")" << endl;
				break;

			case '10': // consulta pelo valor x dos pontos
				cout << "Informeo valor x que deseja acessar :"; cin >> p.x;
				Auxiliar = consultaPeloElementoX(ListaPontosXY,p.x , PontP);
				if (Auxiliar == 0) {
					cout << "ERROR" << endl;
				}
				cout << "Ponto solicitado em (X,Y) :" << p.x << "," << p.y << ")" << endl;
				break;

			default:
				cout << "saindo..." << endl;
				liberarLista(ListaPontosXY);
				exit(0);
				break;
			

				
		}
	}
	 
	return 0;
}
