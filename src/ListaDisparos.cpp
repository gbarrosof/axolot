#include "ListaDisparos.h"

ListaDisparos::ListaDisparos()
{
	numero = 0;
	for (int i = 0; i < MAX_DISPAROS; i++)
		lista[i] = 0;
}

ListaDisparos::~ListaDisparos()
{
}

bool ListaDisparos::agregar(Disparo* d)
{

		if (numero < MAX_DISPAROS)
			lista[numero++] = d; // �ltimo puesto sin rellenar
		else
			return false; // capacidad m�xima alcanzada
		return true;
}

void ListaDisparos::destruirContenido()
{
	for (int i = 0; i < numero; i++) // destrucci�n de esferas contenidas
		delete lista[i];
	numero = 0; // inicializa lista 
}

void ListaDisparos::mueve(float t)
{
	for (int i = 0; i < numero; i++)
		lista[i]->mueve(t);
}

void ListaDisparos::dibuja()
{
	for (int i = 0; i < numero; i++)
		lista[i]->dibuja();
}

/*void ListaDisparos::colision(Pared p)
{
	for (int i = 0; i < numero; i++)
	{
		if (Interaccion::colision(*(lista[i]), p))
			return lista[i];
	}
	return 0; //no hay colisi�n 
}*/
