#include "cubo.h"

cubo::cubo(float x, float y)
{
	posicion.x = x;
	posicion.y = y;
}

void cubo::dibuja()
{

	/*glTranslatef(posicion.x, posicion.y,0 );
	glColor3ub(0, 200, 0);
	glutWireCube(1);
	glTranslatef(-posicion.x, -posicion.y,0);*/
}
Vector cubo::getPos()
{
	return posicion;
}
