#include "Enemigo10.h"


Enemigo10::Enemigo10(float x, float y)
{
	posicion.x = x;
	posicion.y = y;
	numer = 10;
	/*velocidad.x = 0;
	velocidad.y = 0;
	aceleracion.x = 0;
	aceleracion.y = 0;*/
}

Enemigo10::~Enemigo10() {}

void Enemigo10::mueve(float t)
{
	//Enemigo::mueve(t);
	spriteE10.loop();
}

void Enemigo10::dibuja()
{
	//Enemigo::dibuja();
	spriteE10.setPos(posicion.x, posicion.y);

	if (derecha == true)
	{
		spriteE10.flip(true, false);
	}
	else
	{
		spriteE10.flip(false, false);
	}
	

	spriteE10.draw();
}

/*void Enemigo10::disparo(float x, float y)
{

}*/
