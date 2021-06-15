#include "ListaDisparos.h"
//#include "Interaccion.h"

ListaDisparos::ListaDisparos()
{
	numero = 0;
	for (int i = 0; i < MAX_DISPAROS; i++)
		lista[i] = 0;
}


ListaDisparos::~ListaDisparos() {}

bool ListaDisparos::agregar(Disparo* d)
{
	if (numero < MAX_DISPAROS)
	{
		for (int i = 0; i < numero; i++)
		{
			if (d->getOri().x == lista[i]->getOri().x && d->getOri().y == lista[i]->getOri().y)
			{
				return true;
			}
		}
		lista[numero++] = d; // último puesto sin rellenar
	}
	else
	{
		return false; // capacidad máxima alcanzada
	}
		
	return true;
}
/*bool ListaDisparos::agregar(Disparo11* d)
{
	if (numero < MAX_DISPAROS)
		lista[numero++] = d; // último puesto sin rellenar
	else
		return false; // capacidad máxima alcanzada
	return true;
}
bool ListaDisparos::agregar(Disparo12* d)
{
	if (numero < MAX_DISPAROS)
		lista[numero++] = d; // último puesto sin rellenar
	else
		return false; // capacidad máxima alcanzada
	return true;
}*/

void ListaDisparos::dibuja()
{
	for (int i = 0; i < numero; i++)
	{
		lista[i]->dibuja();
	}
		
}

void ListaDisparos::mueve(float t)
{
	for (int i = 0; i < numero; i++)
		lista[i]->mueve(t);
}

void ListaDisparos::destruirContenido()
{
	for (int i = 0; i < numero; i++) // destrucción de esferas contenidas
	{
		delete lista[i];
	}
		
	numero = 0; // inicializa lista 
}

Disparo* ListaDisparos::operator [](int i)
{
	if (i >= numero)//si me paso, devuelvo la ultima
		i = numero - 1;
	if (i < 0) //si el indice es negativo, devuelvo la primera
		i = 0;
	return lista[i];
}

void ListaDisparos::eliminar(int index)
{
	if ((index < 0) || (index >= numero))
		return;
	delete lista[index];
	numero--;
	for (int i = index; i < numero; i++)
		lista[i] = lista[i + 1];
}

void ListaDisparos::eliminar(personaje& p)
{
	for (int i = 0; i < numero; i++)
	{
		float distancia= (lista[i]->getPos() - lista[i]->getOri()).modulo();;

		if (distancia > lista[i]->getAlc())
		{
			if (lista[i]->getnumer() == 1)
			{
				p.setDisparos(false);
			}
			eliminar(i);
		}
	}
	
}

Disparo* ListaDisparos::colision(personaje f)
{
	for (int i = 0; i < numero; i++)
	{
		if (interaccion::colision(f, *(lista[i])))
		{
			if (lista[i]->getnumer() == 1)
			{
				return 0;
			}
			else
			{
				return lista[i];
			}
		}
	}
	return 0; //no hay colisión
}
void ListaDisparos::chocar(Disparo* d, personaje& p)
{
	for (int i = 0; i < numero; i++)
		if (lista[i] == d)
		{
			if (lista[i]->getnumer() == 1)
			{
				p.setDisparos(false);
			}
			eliminar(i);
			return;
		}
}
bool ListaDisparos::personajeagregar()
{
	for (int i = 0; i < numero; i++)
	{
		if (lista[i]->getnumer()==1)
		{
			float distancia = (lista[i]->getPos() - lista[i]->getOri()).modulo();;
			if (distancia >= lista[i]->getAlc())
			{
				return true;
			}
		}
		
	}
	return false;
}

void ListaDisparos::eliminar(Disparo* e)
{
	for (int i = 0; i < numero; i++)
		if (lista[i] == e)
		{
			eliminar(i);
			return;
		}
}

