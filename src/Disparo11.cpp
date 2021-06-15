#include "Disparo11.h"
#include <math.h>
#include "freeglut.h"

Disparo11::Disparo11(float x, float y, float posx, float posy)
{
	posicion.x = x;
	posicion.y = y;
	origen.x = x;
	origen.y = y;
	alcance = 15;
	numer = 11;
	personaje.x = posx;
	personaje.y = posy;

	velocidad.x = 0;
	velocidad.y = 0;
	aceleracion.x = 0;
	aceleracion.y = 0;
	radio = 0.4;

	a = false;
}

Disparo11::~Disparo11() {}

void Disparo11::dibuja()
{
	
	/*glColor3f(0, 0, 255);
	glTranslatef(posicion.x, posicion.y, 0);
	glutSolidSphere(radio, 20, 20);
	glTranslatef(-posicion.x, -posicion.y, 0);*/

	spriteD11.setSize(3.5, 3.5);


	if (velocidad.x < 0)
	{
		spriteD11.setPos(posicion.x - 2.3, posicion.y - 2.25);
		
	}
	else
	{
		spriteD11.flip(true, false);
		spriteD11.setPos(posicion.x + 2.3, posicion.y - 2.25);
	}

	spriteD11.draw();
	//ETSIDI::SpriteSequence sprite("imagenes/disparo11", 9, 1, 50, true, 0, 0, 1, 1, 0);
}
void Disparo11::mueve(float t)
{
	if (a == false)
	{
		float dist = (origen - personaje).modulo();
		float ang = atanf((origen.y - personaje.y) / (origen.x - personaje.x));

		Vector dis;
		dis.x = cos(ang);
		dis.y = sin(ang);
		if (personaje.x >= origen.x)
		{
			velocidad.x = velocidad.x * dis.x;
			velocidad.y = velocidad.y * dis.y;
		}
		else
		{
			velocidad.x = velocidad.x * dis.x;
			velocidad.y = velocidad.y * dis.y*(-1);
		}

		a = true;
	}
	else
	{
		posicion.x = posicion.x + velocidad.x * t + 0.5f * aceleracion.x * t * t;
		posicion.y = posicion.y + velocidad.y * t + 0.5f * aceleracion.y * t * t;
		velocidad.x = velocidad.x + aceleracion.x * t;
		velocidad.y = velocidad.y + aceleracion.y * t;
	}
		
	
	
	//velocidad.x = 
/*
	*/
}