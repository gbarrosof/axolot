
#include"Icono.h"
Icono::Icono() {
	tipo = 1;
}
Icono::~Icono() {}

void Icono::dibuja(int a, float x, float y)
{
	switch (a)
	{
	case (1):
		{
			aguacate.setPos(x - 7.5, y + 5.5);
			aguacate.draw();
			break;
		}
	case(2):
		{
			pina.setPos(x -7.5, y +5.5);
			pina.draw();
			break;
		}
	case (3):
		{
		platano.setPos(x - 7.5, y + 5.5);
		platano.draw();
			break;
		}
	}
}
