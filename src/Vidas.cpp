#include "Vidas.h"


Vidas::Vidas(float x, float y)
{
	
	posicion.x = x;
	posicion.y = y;
	radio = 0.25;

}
void Vidas::dibuja()
{
	/*glTranslatef(posicion.x, posicion.y, -0.5);
	glutSolidSphere(radio, 10, 10);
	glTranslatef(-posicion.x, -posicion.y, +0.5);*/
	Sprite vida("imagenes/vidas.png", posicion.x, posicion.y, 1, 1);
	vida.draw();

}
Vector Vidas::getPos()
{
	return posicion;
}
float Vidas::getRadio()
{
	return radio;
}


