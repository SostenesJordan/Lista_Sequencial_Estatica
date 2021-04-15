#define Limite 10
struct Ponto
{
	float x, y;

};

struct List;

List* criaLista();

int tamanhoDaLista(List *Pont);

int listaCheia(List *Pont);

int listaVazia(List *Pont);

int incereNoFinal(List *Pont, Ponto ponto);

int incereNoInicio(List *Pont, Ponto ponto);

int incereNoOrdenadoX(List *Pont, Ponto ponto);

void imprimirLista(List *Pont);

void liberarLista(List *Pont);

int removeFinal(List *Pont);

int removeInicio(List *Pont);

int removeOrdenadoY(List* Pont, float yPonto);

int consultaListaPosicao(List *Pont, int Posicao, Ponto *ponto);

int consultaPeloElementoX(List *Pont, float xPonto, Ponto *ponto);