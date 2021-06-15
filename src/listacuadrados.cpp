#include "listacuadrados.h"

listacuadrados::listacuadrados()
{
	numero = 0;
	for (int i = 0; i < max_elem; i++)
	{
		lista[i] = 0;
	}
}
bool listacuadrados::agregar(cubo* c)
{
	if (numero < max_elem)
	{
		lista[numero++] = c; // último puesto sin rellenar

	}
	else
	{
		return false; // capacidad máxima alcanzada
	}
	return true;
}

void listacuadrados::dibuja(char lvl, char m,int px, int py )
{
	for (int i = 0; i < numero; i++)
	{
		lista[i]->dibuja(lvl, m, px, py);
	}
}

void listacuadrados::colision(personaje& h)
{
	for (int i = 0; i < numero; i++)
	{

		interaccion::colision(h, *(lista[i]));

	}
}

bool listacuadrados::colision(Disparo* d)
{
	for (int i = 0; i < numero; i++)
	{

		if (interaccion::colision(*d, *(lista[i])))
		{
			return true;
		}

	}
	return false;
}




void listacuadrados::destruirContenido()
{
	for (int i = 0; i < numero; i++)
	{
		delete lista[i]; // destrucción de esferas contenidas
	}
	numero = 0; // inicializa lista
}

