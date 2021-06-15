#include "ListaEnemigosVisibles.h"



ListaEnemigosVisibles::ListaEnemigosVisibles()
{
	numero = 0;
	for (int i = 0; i < MAX_ENEMIGOS; i++)
	{
		lis[i] = 0;
	}
}

ListaEnemigosVisibles::~ListaEnemigosVisibles() {}

bool ListaEnemigosVisibles::agregar(EnemigoV* e)
{
	if (numero < MAX_ENEMIGOS)
	{
		for (int i = 0;i< numero;i++)
		{
			if (e->getPos().x == lis[i]->getPos().x && e->getPos().y == lis[i]->getPos().y)
			{
				return true;
			}
		}
		lis[numero++] = e; // último puesto sin rellenar
	}
		
	else
		return false; // capacidad máxima alcanzada
	return true;
}

void ListaEnemigosVisibles::eliminar(int index)
{
	if ((index < 0) || (index >= numero))
		return;
	delete lis[index];
	numero--;
	for (int i = index; i < numero; i++)
		lis[i] = lis[i + 1];
}

void ListaEnemigosVisibles::elimina(int a)
{
	for (int i = 0; i < numero; i++)
	{
		if (lis[i] == lis[a])
		{
			eliminar(i);
			return;
		}
	}
		
}

/*Enemigo* ListaEnemigosVisibles::disparo(personaje f)
{
	for (int i = 0; i < numero; i++)
	{
		if (interaccion::disparo(f, *(lis[i])))
		{
			return lis[i];
		}

	}
	return 0;
}*/

void ListaEnemigosVisibles::destruirContenido()
{
	for (int i = 0; i < numero; i++) // destrucción de esferas contenidas
		delete lis[i];
	numero = 0; // inicializa lista 
}


/*bool ListaEnemigosVisibles::elim(personaje p)
{
	
	for (int i = 0; i < numero; i++)
	{
		float distancia = (lis[i]->getPos() - p.getPos()).modulo();
		if (distancia >= 6  )
		{
			return true;
		}
		
			
	}
	return false;

}*/

EnemigoV* ListaEnemigosVisibles::disparo(personaje p, int i)
{

	float distancia = (lis[i]->getPos() - p.getPos()).modulo();
	if (distancia <= 10)
	{
		return lis[i];
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
EnemigoV* ListaEnemigosVisibles::genera(personaje p, Enemigo* e)
{
	float distancia = (e->getPos() - p.getPos()).modulo();
	if (distancia <= 10)
	{
		
		//return lis[i];
	}
	else
	{
		return 0;
	}
}
void ListaEnemigosVisibles::eliminar(Disparo d)
{
	for (int i = 0; i < numero; i++)
	{
		if (d.getnumer() == 1)
		{
			float distancia = (lis[i]->getPos() - d.getPos()).modulo();
			if (distancia <= d.getAltura()+lis[i]->getRadio())
			{
				eliminar(i);
				return;
				//return lis[i];
			}
		}
	}

}