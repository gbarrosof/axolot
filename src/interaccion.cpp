#include "Interaccion.h"
#include "freeglut.h"
bool interaccion::colision(personaje& h, cubo c)
{


		Vector vert1, vert2, vert3, vert4;
		vert1.x = c.getPos().x + 0.5;
		vert1.y = c.getPos().y + 0.5;

		vert2.x = c.getPos().x - 0.5;
		vert2.y = c.getPos().y + 0.5;

		

		if ((h.getPos().x - h.getAltura() > vert2.x + 1) || (h.getPos().x + h.getAltura() < vert2.x))
		{
			
			return false;
		}
		if (h.getPos().y - h.getAltura() > vert2.y || h.getPos().y + h.getAltura() < vert2.y - 1)
		{
			
			return false;
		}
		else
		{

			 
			if (vert2.y > h.getPos().y - h.getAltura()/2 && vert2.x > h.getPos().x)
			{

				h.setPos(vert2.x - h.getAltura(), h.getPos().y);
				h.setVel(0, h.getVel().y);

			}


			else if (vert2.y > h.getPos().y - h.getAltura()/2 && vert1.x < h.getPos().x)
			{

				h.setPos(vert1.x + h.getAltura(), h.getPos().y);
				h.setVel(0, h.getVel().y);
				
			}
			

			if ((h.getPos().x - h.getAltura() >= vert2.x + 1) || (h.getPos().x + h.getAltura() <= vert2.x))
			{
				return false;
			}
			else if (h.getVel().y <= 0 )
			{
				h.setPos(h.getPos().x, vert2.y + h.getAltura());
				h.setVel(h.getVel().x, 0);
				h.salto = true;
			}	
			
			
		}
	
	return true;
	
}




bool interaccion::colision(personaje& p, Moneda m)
{

	float distancia = (m.posicion - p.getPos()).modulo();
	if (distancia <= m.radio + p.getAltura())
	{
		return true;
	}
	return false;
}


bool interaccion::colision(personaje& h, Plataforma pl)
{


	Vector vert1, vert2, vert3, vert4;
	vert1.x = pl.getPos().x + 0.5;
	vert1.y = pl.getPos().y + 0.5;

	vert2.x = pl.getPos().x - 0.5;
	vert2.y = pl.getPos().y + 0.5;

	



	if ((h.getPos().x - h.getAltura() > vert2.x + 1) || (h.getPos().x + h.getAltura() < vert2.x))
	{

		return false;
	}
	if (h.getPos().y - h.getAltura() > vert2.y || h.getPos().y + h.getAltura() < vert2.y - 1)
	{

		return false;
	}
	else if ( h.getVel().y <= 0 && h.getPos().y - h.getAltura()/2 >= vert2.y)
	{
		
		
			h.setPos(h.getPos().x, vert2.y + h.getAltura());
			h.setVel(h.getVel().x, 0);
			h.salto = true;
		
		
	}


	return true;

}

bool interaccion::colision(personaje& p, PowerUp PU)
{

	float distancia = (PU.posicion - p.getPos()).modulo();
	if (distancia <= PU.radio + p.getAltura())
	{
		return true;
	}
	return false;
}

bool interaccion::vacio(personaje p)
{
	if (p.getPos().y <= -21)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool interaccion::colision(personaje h, Pincho pi)
{
	Vector  vert2;


	vert2.x = pi.getPos().x - 0.5;
	vert2.y = pi.getPos().y + 0.5;


	if ((h.getPos().x - h.getAltura()/2 >= vert2.x + 1) || (h.getPos().x + h.getAltura()/2 <= vert2.x))
	{

		return false;
	}
	if (h.getPos().y - h.getAltura()/2 >= vert2.y || h.getPos().y + h.getAltura()/2 <= vert2.y - 1)
	{

		return false;
	}
	else
	{

		return true;
	}


	
}

bool interaccion::colision(personaje h, Bandera b)
{
	Vector  vert2;


	vert2.x = b.getPos().x - 0.5;
	vert2.y = b.getPos().y + 0.5;


	if ((h.getPos().x - h.getAltura() >= vert2.x + 3) || (h.getPos().x + h.getAltura() <= vert2.x))
	{

		return false;
	}
	if (h.getPos().y - h.getAltura() >= vert2.y || h.getPos().y + h.getAltura() <= vert2.y - 3)
	{

		return false;
	}
	else
	{
		
		return true;
	}

}

bool interaccion::colision(personaje p, Vidas *v)
{

	float distancia = (v->getPos() - p.getPos()).modulo();
	if (distancia <= v->radio + p.getAltura())
	{
		return true;
	}
	return false;
}


bool interaccion::colision(personaje p, Enemigo& e)
{
	float distancia = (e.getPos() - p.getPos()).modulo();


	if (distancia <= e.getRadio() + p.getAltura())
	{
		return true;

	}
	return false;
 }

bool interaccion::disparo(personaje p, Enemigo e)
{
	float distancia = (e.getPos() - p.getPos()).modulo();
	if (distancia - 5 <= e.getRadio() + p.getAltura())
	{
		return true;
	}
	return false;
}
bool interaccion::disparoeliminar(Disparo d)
{
	return false;
}


bool interaccion::colision(personaje p, Disparo d)
{

	float distancia = (d.posicion - p.getPos()).modulo();
	if (distancia <= d.radio + p.getAltura())
	{
		return true;
	}
	return false;
}

bool interaccion::colision(Disparo d, cubo c)
{
	Vector  vert2;

	vert2.x = c.getPos().x - 0.5;
	vert2.y = c.getPos().y + 0.5;

	if ((d.getPos().x  >= vert2.x + 1) || (d.getPos().x  <= vert2.x))
	{
		return false;
	}
	if (d.getPos().y  >= vert2.y || d.getPos().y <= vert2.y - 1)
	{
		return false;
	}
	else
	{
		return true;
	}

}
bool interaccion::colision(Disparo d, Enemigo e)
{
	float distancia = (d.posicion - e.getPos()).modulo();
	if (distancia <= d.radio + e.getRadio())
	{
		return true;
	}
	return false;
}

bool interaccion::rango(Disparo d, int rang)
{
	float distancia = d.getPos().modulo();
	if (distancia - rang >= d.getRadio() + d.getOri().modulo())
	{
		return true;
	}
	return false;
}



