#include "listapinchos.h"

listapinchos::listapinchos()
{
	numero = 0;
	for (int i = 0; i < max_elem; i++)
	{
		lista[i] = 0;
	}
}
bool listapinchos::agregar(Pincho* p)
{
	if (numero < max_elem)
	{
		lista[numero++] = p; // �ltimo puesto sin rellenar

	}
	else
	{
		return false; // capacidad m�xima alcanzada
	}
	return true;
}

void listapinchos::dibuja()
{
	for (int i = 0; i < numero; i++)
	{
		lista[i]->dibuja();
	}
}

bool listapinchos::colision(personaje& h)
{
	for (int i = 0; i < numero; i++)
	{

		if (interaccion::colision(h, *(lista[i])))
		{
			return true;
		}

	}
	return false;

	//no hay colisi�n

}

void listapinchos::destruirContenido()
{
	for (int i = 0; i < numero; i++)
	{
		delete lista[i]; // destrucci�n de esferas contenidas
	}
	numero = 0; // inicializa lista
}
