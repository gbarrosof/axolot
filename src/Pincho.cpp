#include "Pincho.h"

Pincho::Pincho()
{

}

Pincho::Pincho(float x, float y)
{
	posicion.x = x;
	posicion.y = y;
}

void Pincho::dibuja()
{

	SpriteS1.setPos(posicion.x, posicion.y-0.1);
	SpriteS1.flip(true, false);
	SpriteS1.draw();


}
Vector Pincho::getPos()
{
	return posicion;
}
void Pincho::setPos(float x, float y)
{
	posicion.x = x;
	posicion.y = y;
}
