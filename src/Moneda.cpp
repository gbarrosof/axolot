#include "Moneda.h"


Moneda::Moneda(float x, float y)
{
	posicion.x = x;
	posicion.y = y;
	radio = 0.25;
	
}
void Moneda::dibuja()
{
	/*glTranslatef(posicion.x, posicion.y, -0.5);
	glutSolidSphere(radio, 10, 10);
	glTranslatef(-posicion.x, -posicion.y, +0.5);*/
	Sprite moneda("imagenes/moneda.png", posicion.x, posicion.y, 1, 1);
	moneda.draw();
	
}
Vector Moneda::getPos()
{
	return posicion;
}
float Moneda::getRadio()
{
	return radio;
}