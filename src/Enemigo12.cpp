#include "Enemigo12.h"
#include"freeglut.h"

Enemigo12::Enemigo12(float x, float y)
{
	posicion.x = x;
	posicion.y = y;
	numer = 12;
	/*velocidad.x = 3;
	velocidad.y = 0;
	aceleracion.x = 0;
	aceleracion.y = 0;*/
}

Enemigo12::~Enemigo12() {}

void Enemigo12::mueve(float t)
{
	spriteE12.loop();

	
}

void Enemigo12::dibuja()
{
	spriteE12.setPos(posicion.x, posicion.y);
	
	if (derecha==true)
	{
		spriteE12.flip(true, false);
	}
	else
	{
		spriteE12.flip(false, false);
	}
	
	

	spriteE12.draw();
	/*glTranslatef(posicion.x, posicion.y, 0);
	glColor3f(0.0f, 1.0f, 0.0f);
	glutSolidCube(1);
	glTranslatef(-posicion.x, -posicion.y, 0);*/
	//ETSIDI::SpriteSequence sprite("imagenes/enemigo12", 4, 1, 50, true, 0, 0, 1, 1, 0);
}

