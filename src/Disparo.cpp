#include "Disparo.h"
#include "freeglut.h"

Disparo::Disparo(float x, float y, float alc, int t)
{
	radio = 0.25;
	alcance = alc; 
	numer = 1;
	posicion.x = x;
	posicion.y = y;
	origen.x = x;
	origen.y = y;
	tipo = t;
	velocidad.x = -10;
	velocidad.y = 0;
	
}

Disparo::Disparo()
{
	

}

Disparo::~Disparo() {}

void Disparo::setRadio(float r)
{
	radio = r;
}



void Disparo::setOri(Vector ori)
{
	origen = ori;
	posicion = ori;
}

void Disparo::setPos(Vector pos)
{
	
}

void Disparo::dibuja()
{
	switch (tipo)
	{
	case(3):
	{
		/*glColor3f(0, 250, 0);
		glTranslatef(posicion.x, posicion.y, 0);
		glutSolidSphere(radio, 20, 20);
		glTranslatef(-posicion.x, -posicion.y, 0);*/


		//DisparoPL.setPos(posicion.x+0.5, posicion.y);
		if (velocidad.x < 0)
		{
			DisparoPL.setPos(posicion.x-0.25 , posicion.y);
			DisparoPL.flip(true, false);
		}
		else
		{
			DisparoPL.setPos(posicion.x +0.25, posicion.y);
		}

		DisparoPL.draw();

		break;
	}
	case (2):
	{
		/*glColor3f(0, 250, 0);
		glTranslatef(posicion.x, posicion.y, 0);
		glutSolidSphere(radio, 20, 20);
		glTranslatef(-posicion.x, -posicion.y, 0);*/

		
		DisparoPi.setSize(1, 1);
		if (velocidad.x < 0)
		{
			DisparoPi.setPos(posicion.x+1, posicion.y - 1);
			DisparoPi.flip(true, false);
		}
		else
		{
			DisparoPi.setPos(posicion.x-1, posicion.y - 1);
		}
		DisparoPi.draw();
		break;
	}
	case(1):
	{
		/*glColor3f(0, 250, 0);
		glTranslatef(posicion.x, posicion.y, 0);
		glutSolidSphere(radio, 20, 20);
		glTranslatef(-posicion.x, -posicion.y, 0);*/

		
		DisparoAg.setSize(0.5, 0.25);
		if (velocidad.x < 0)
		{
			DisparoAg.setPos(posicion.x + 0.5, posicion.y - 0.5);
			DisparoAg.flip(true, false);
		}
		else
		{
			DisparoAg.setPos(posicion.x - 0.5, posicion.y - 0.5);
		}
		DisparoAg.draw();
		break;
	}
	}
	
	/*glColor3f(255, 0, 255);
	glTranslatef(posicion.x, posicion.y, 0);
	glutSolidSphere(radio, 20, 20); 
	glTranslatef(-posicion.x, -posicion.y, 0);*/
}

void Disparo::mueve(float t)
{
	if (tipo == 3)
	{
		DisparoPL.loop();
	}
	
	
	posicion.x = posicion.x + velocidad.x * t + 0.5f * aceleracion.x * t * t;
	posicion.y = posicion.y + velocidad.y * t + 0.5f * aceleracion.y * t * t;
	velocidad.x = velocidad.x + aceleracion.x * t;
	velocidad.y = velocidad.y + aceleracion.y * t;
}

void Disparo::setVel(float x, float y)
{
	
	velocidad.x = x;
	velocidad.y = y;
}
Vector Disparo::getOri()
{
	return origen;
}