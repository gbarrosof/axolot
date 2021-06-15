#include "PowerUp.h"

PowerUp::PowerUp()
{

}

PowerUp::PowerUp(float x, float y)
{
	posicion.x = x;
	posicion.y = y;
	radio = 0.25;

}
void PowerUp::dibuja()
{

	ETSIDI::Sprite sprite{ "imagenes/powerup.png", posicion.x, posicion.y, 1, 1 };
	sprite.draw();

}
Vector PowerUp::getPos()
{
	return posicion;
}
float PowerUp::getRadio()
{
	return radio;
}

