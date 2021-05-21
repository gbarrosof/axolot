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

void listacuadrados::dibuja()
{
	for (int i = 0; i < numero; i++)
	{
		lista[i]->dibuja();
	}
}

void listacuadrados::colision(personaje& h)
{
	for (int i = 0; i < numero; i++)
	{
		if (interaccion::colision(h, *(lista[i])))
		{
			
		}
	}
	//no hay colisión

}