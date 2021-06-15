#include "Enemigo11.h"
//#include"freeglut.h"
//#include "ETSIDI.h"

Enemigo11::Enemigo11(float x, float y)
{
	posicion.x = x;
	posicion.y = y;
	numer = 11;
	/*velocidad.x = 0;
	velocidad.y = 0;
	aceleracion.x = 0;
	aceleracion.y = 0;*/
}

Enemigo11::~Enemigo11() {}

void Enemigo11::mueve(float t)
{
	spriteE11.loop();
}

void Enemigo11::dibuja()
{
	

	spriteE11.setPos(posicion.x, posicion.y);

	if (derecha == true)
	{
		spriteE11.flip(true, false);
	}
	else
	{
		spriteE11.flip(false, false);
	}
	

	spriteE11.draw();
	//Enemigo::dibuja();
	/*glTranslatef(posicion.x, posicion.y, 0);
	glColor3f(0.0f, 0.0f, 1.0f);
	glutSolidCube(1);
	glTranslatef(-posicion.x, -posicion.y, 0);*/
	
	
	//ETSIDI::SpriteSequence sprite("imagenes/enemigo11", 4, 2, 50, true, 0, 0, 1, 1, 0);
}
