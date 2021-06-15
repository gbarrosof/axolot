#include "listaPowerUps.h"

listaPowerUps::listaPowerUps()
{
	numero = 0;
	for (int i = 0; i < max_elem; i++)
	{
		lista[i] = 0;
	}
}

bool listaPowerUps::agregar(PowerUp* PU)
{
	if (numero < max_elem)
	{
		lista[numero++] = PU; // último puesto sin rellenar
	}
	else
	{
		return false; // capacidad máxima alcanzada
	}
	return true;
}

void listaPowerUps::dibuja()
{
	for (int i = 0; i < numero; i++)
	{
		lista[i]->dibuja();
	}
}

void listaPowerUps::eliminar(PowerUp* PU)
{
	for (int i = 0; i < numero; i++)
	{
		if (lista[i] == PU)
		{
			eliminar(i);
			return;
		}
	}
}
void listaPowerUps::eliminar(int index)
{
	if ((index < 0) || (index >= numero))
	{
		return;
	}

	delete lista[index];
	numero--;
	for (int i = index; i < numero; i++)
	{
		lista[i] = lista[i + 1];
	}

}

PowerUp* listaPowerUps::colision(personaje& h)
{
	for (int i = 0; i < numero; i++)
	{
		if (interaccion::colision(h, *(lista[i])))
		{
			return lista[i];
		}
	}
	return 0; //no hay colisión

}



void listaPowerUps::destruirContenido()
{
	for (int i = 0; i < numero; i++)
	{
		delete lista[i]; // destrucción de esferas contenidas
	}
	numero = 0; // inicializa lista
}
