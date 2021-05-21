#include "listamonedas.h"

listamonedas::listamonedas()
{
	numero=0;
	for (int i = 0; i < max_elem; i++)
	{
		lista[i] = 0;
	}
}
bool listamonedas::agregar(Moneda* m)
{
	if (numero < max_elem)
	{
		lista[numero++] = m; // último puesto sin rellenar
		
	}
	else
	{
		return false; // capacidad máxima alcanzada
	}
	return true;
}

void listamonedas::dibuja()
{
	for (int i = 0; i < numero; i++)
	{
		lista[i]->dibuja();
	}
}

void listamonedas::eliminar(Moneda* m)
{
	for (int i = 0; i < numero; i++)
	{
		if (lista[i] == m)
		{
			eliminar(i);
			return;
		}
	}
}
void listamonedas::eliminar(int index)
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

Moneda* listamonedas::colision(personaje& h)
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