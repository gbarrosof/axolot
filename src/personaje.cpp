#include "personaje.h"
#include "freeglut.h"
#include <math.h>

personaje::personaje()
{
	death = false;
	altura = 0.7f;
	aceleracion.y = -20.0f;
	posicion.x = 5;
	posicion.y = -17;
	aceleracion.x = 0;
	velocidad.x = 0;
	velocidad.y = 0;
	salto = false;
	tipo = 1;
	aguacate.setCenter(0.75, 0.25);
	aguacate.setSize(1.75, 1.75);
	pina.setCenter(0.7, 0.25);
	pina.setSize(2.25, 2.25);
	platano.setCenter(0.7, 0.25);
	platano.setSize(1.75, 1.75);
}


void personaje::dibuja()
{

	switch (tipo)
	{
	case(1):
	{
		aguacate.setPos(posicion.x, posicion.y - altura);
		
		if (velocidad.x > 0.01)
		{
			aguacate.setState(aguacate.getState(), false);
			aguacate.flip(false, false);
		}
		else if (velocidad.x < -0.01)
		{
			aguacate.setState(aguacate.getState(), false);
			aguacate.flip(true, false);
		}
		else
		{
			aguacate.setState(2, true);
		}

		if (aguacate.getState() == 5)
		{
			aguacate.setState(1, false);
		}

		if (velocidad.y != 0 && salto == 0)
		{
			aguacate.setState(5, false);
		}

		aguacate.draw();
		break;
	}
	case(2):
	{
		pina.setPos(posicion.x, posicion.y - altura);
		if (velocidad.x > 0.01)
		{
			pina.setState(pina.getState(), false);
			pina.flip(false, false);
		}
		else if (velocidad.x < -0.01)
		{
			pina.setState(pina.getState(), false);
			pina.flip(true, false);
		}
		else
		{

			pina.setState(2, true);
		}

		if (pina.getState() == 1)
		{
			pina.setState(2, false);
		}

		if (velocidad.y != 0 && salto == 0)
		{
			pina.setState(1, false);
		}

		
		pina.draw();
		break;
	}
	case(3):
	{
		platano.setPos(posicion.x, posicion.y - altura);
		if (velocidad.x > 0.01)
		{
			platano.setState(platano.getState(), false);
			platano.flip(false, false);
		}
		else if (velocidad.x < -0.01)
		{
			platano.setState(platano.getState(), false);
			platano.flip(true, false);
		}
		else
		{
			platano.setState(2, true);
		}

		if (platano.getState() == 3)
		{
			platano.setState(1, false);
		}

		if (velocidad.y != 0 && salto == 0)
		{
			platano.setState(3, false);
		}
		
		platano.draw();
		break;
	}
	}
	glPopMatrix();
}

void personaje::mueve(float t)
{
	
	if (velocidad.y < 0)
	{
		salto = false;
	}

	posicion = posicion + velocidad * t + aceleracion * (0.5f * t * t);
	velocidad = velocidad + aceleracion * t;

	switch (tipo)
	{
	case(1):
	{
		aguacate.loop();
		break;
	}
	case(2):
	{
		pina.loop();
		break;
	}
	case(3):
	{
		platano.loop();
		break;
	}
	}

	if (aceleracion.x == -20 && velocidad.x < 1)
	{
		velocidad.x = 0;
		aceleracion.x = 0;
	}

	if (aceleracion.x == 20 && velocidad.x > -1)
	{
		velocidad.x = 0;
		aceleracion.x = 0;
	}
	
	if (velocidad.x > 6)
	{
		velocidad.x = 6;
	}

	if (velocidad.x < -6)
	{
		velocidad.x = -6;
	}
}

void personaje::setVel(float vx, float vy)
{
	velocidad.x = vx;
	velocidad.y = vy;
}



float personaje::getAltura()
{
	return altura;
}

Vector personaje::getPos()
{
	return posicion;
}

void personaje::setAc(float x, float y)
{
	aceleracion.x = x;
	aceleracion.y = y;
}

void personaje::setTipo(int t)
{
	tipo = t;
	if (tipo > 3)
	{
		tipo = 3;
	}
}
