#include "Bandera.h"

Bandera::Bandera()
{

}



void Bandera::dibuja()
{
	
	glTranslatef(0, 0, - 1);
	SpriteS1.setPos(posicion.x-1, posicion.y-1);
	SpriteS1.flip(true, false);
	SpriteS1.draw();
	glTranslatef(0, 0, 1);


}

void Bandera::mueve()
{
	SpriteS1.loop();
}



Vector Bandera::getPos()
{
	return posicion;
}


void Bandera::setPos(float x, float y)
{
	posicion.x = x;
	posicion.y = y;
}
