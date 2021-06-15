#include "ListaEnemigos.h"
//#include "Interaccion.h"

ListaEnemigos::ListaEnemigos()
{
	numero = 0;
	for (int i = 0; i < MAX_ENEMIGOS; i++)
	{
		lista[i] = 0;
	}
}

ListaEnemigos::~ListaEnemigos() {}

bool ListaEnemigos::agregar(Enemigo* e)
{
	if (numero < MAX_ENEMIGOS)
		lista[numero++] = e; // último puesto sin rellenar
	else
		return false; // capacidad máxima alcanzada
	return true;
}

/*bool ListaEnemigos::agregar(Enemigo11* d)
{
	if (numero < MAX_ENEMIGOS)
		lista[numero++] = d; // último puesto sin rellenar
	else
		return false; // capacidad máxima alcanzada
	return true;
}

bool ListaEnemigos::agregar(Enemigo12* d)
{
	if (numero < MAX_ENEMIGOS)
		lista[numero++] = d; // último puesto sin rellenar
	else
		return false; // capacidad máxima alcanzada
	return true;
}*/

void ListaEnemigos::dibuja()
{
	for (int i = 0; i < numero; i++)
	{
		lista[i]->dibuja();
	}
		
}



void ListaEnemigos::mueve(float t)
{
	for (int i = 0; i < numero; i++)
	{
		lista[i]->mueve(t);
	}
}

void ListaEnemigos::destruirContenido()
{
	for (int i = 0; i < numero; i++) // destrucción de esferas contenidas
		delete lista[i];
	numero = 0; // inicializa lista 
}

void ListaEnemigos::eliminar(int index)
{
	if ((index < 0) || (index >= numero))
		return;
	delete lista[index];
	numero--;
	for (int i = index; i < numero; i++)
		lista[i] = lista[i + 1];
}

/*void ListaEnemigos::eliminar(Enemigo* e)
{
	for (int i = 0; i < numero; i++)
		if (lista[i] == e)
		{
			eliminar(i);
			return;
		}
}*/
bool ListaEnemigos::eliminar(Disparo d)
{
	for (int i = 0; i < numero; i++)
	{
		if (d.getnumer() == 1)
		{
			if (interaccion::colision(d, *lista[i]))
			{
				eliminar(i);
				return true;
			}
		}
	}
	return false;
		
		
}



Enemigo* ListaEnemigos::colision(personaje f)
{
	for (int i = 0; i < numero; i++)
	{
		if (interaccion::colision(f, *(lista[i])))
		{
			return lista[i];
		}
	}
	return 0; //no hay colisión
}

Enemigo* ListaEnemigos::operator [](int i)
{
	if (i >= numero)//si me paso, devuelvo la ultima
		i = numero - 1;
	if (i < 0) //si el indice es negativo, devuelvo la primera
		i = 0;
	return lista[i];
}

Enemigo* ListaEnemigos::disparo(personaje p, int i)
{
	
		float distancia = (lista[i]->getPos() - p.getPos()).modulo();
		if (distancia <= 5)
		{
			return lista[i];
		}
		else

		{
			return 0;
		}
		/*if (interaccion::disparo(f, *(lista[i])))
		{
			return lista[i];
		}*/
}





