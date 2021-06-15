#include "Suelo.h"

cubo::cubo()
{
	
}

cubo::cubo(float x, float y)
{
	posicion.x = x;
	posicion.y = y;
}

void cubo::dibuja( char lvl, char m, int px, int py)
{
	switch (lvl)
	{
	case(1):
	{
		if (m == 1)
		{
			ETSIDI::Sprite SpriteS1("imagenes/mapa1/suelo1.png", py, -px, 1, 1);
			SpriteS1.flip(true, false);
			SpriteS1.draw();
		}
		if (m == 2)
		{
			ETSIDI::Sprite SpriteS2("imagenes/mapa1/suelo2.png", py, -px, 1, 1);
			SpriteS2.draw();
		}
		if (m == 3)
		{
			ETSIDI::Sprite SpriteS1("imagenes/mapa1/suelo1.png", py, -px, 1, 1);
			SpriteS1.draw();
		}

		break;
	}
	case(2):
	{
		if (m == 1)
		{
			ETSIDI::Sprite SpriteS1("imagenes/mapa2/suelo1.png", py, -px, 1, 1);
			SpriteS1.flip(true, false);
			SpriteS1.draw();
		}
		if (m == 2)
		{
			ETSIDI::Sprite SpriteS2("imagenes/mapa2/suelo2.png", py, -px, 1, 1);
			SpriteS2.draw();
		}
		if (m == 3)
		{
			ETSIDI::Sprite SpriteS1("imagenes/mapa2/suelo1.png", py, -px, 1, 1);
			SpriteS1.draw();
		}

		break;
	}
	case(3):
	{
		if (m == 1)
		{
			ETSIDI::Sprite SpriteS1("imagenes/mapa3/suelo1.png", py, -px, 1, 1);
			SpriteS1.flip(true, false);
			SpriteS1.draw();
		}
		if (m == 2)
		{
			ETSIDI::Sprite SpriteS2("imagenes/mapa3/suelo2.png", py, -px, 1, 1);
			SpriteS2.draw();
		}
		if (m == 3)
		{
			ETSIDI::Sprite SpriteS1("imagenes/mapa3/suelo1.png", py, -px, 1, 1);
			SpriteS1.draw();
		}

		break;
	}
		
	}
	
	
}
Vector cubo::getPos()
{
	return posicion;
}
void cubo::setPos(float x, float y)
{
	posicion.x = x;
	posicion.y = y;
}
