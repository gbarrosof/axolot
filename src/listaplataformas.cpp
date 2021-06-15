#include "listaplataformas.h"

listaplataformas::listaplataformas()
{
	numero = 0;
	for (int i = 0; i < max_elem; i++)
	{
		lista[i] = 0;
	}
}
bool listaplataformas::agregar(Plataforma* p)
{
	if (numero < max_elem)
	{
		lista[numero++] = p; // último puesto sin rellenar
	}
	else
	{
		return false; // capacidad máxima alcanzada
	}
	return true;
}

/*void listaplataformas::dibuja()
{
	for (int i = 0; i < numero; i++)
	{
		lista[i]->dibuja();
	}
}*/

void listaplataformas::colision(personaje& h)
{
	for (int i = 0; i < numero; i++)
	{

		interaccion::colision(h, *(lista[i]));

	}

	//no hay colisión

}



void listaplataformas::destruirContenido()
{
	for (int i = 0; i < numero; i++)
	{
		delete lista[i]; // destrucción de esferas contenidas
	}
	numero = 0; // inicializa lista
}
