#include "Plataforma.h"


Plataforma::Plataforma()
{
	
}

Plataforma::Plataforma(float x, float y)
{
	posicion.x = x;
	posicion.y = y;
}
void Plataforma::dibuja(char lvl, char m, int px, int py)
{
	switch (lvl)
	{
	case(1):
	{
		if (m == 1)
		{
			ETSIDI::Sprite SpriteP1("imagenes/mapa1/plataforma1.png", py, -px, 1, 1);
			SpriteP1.draw();
		}
		if (m == 2)
		{
			ETSIDI::Sprite SpriteP2("imagenes/mapa1/plataforma2.png", py, -px, 1, 1);
			SpriteP2.draw();
		}
		if (m == 3)
		{
			ETSIDI::Sprite SpriteP1("imagenes/mapa1/plataforma1.png", py, -px, 1, 1);
			SpriteP1.flip(true, false);
			SpriteP1.draw();
		}

		break;
	}
	case(2):
	{
		if (m == 1)
		{
			ETSIDI::Sprite SpriteP1("imagenes/mapa2/plataforma1.png", py, -px, 1, 1);
			SpriteP1.draw();
		}
		if (m == 2)
		{
			ETSIDI::Sprite SpriteP2("imagenes/mapa2/plataforma2.png", py, -px, 1, 1);
			SpriteP2.draw();
		}
		if (m == 3)
		{
			ETSIDI::Sprite SpriteP1("imagenes/mapa2/plataforma1.png", py, -px, 1, 1);
			SpriteP1.flip(true, false);
			SpriteP1.draw();
		}

		break;
	}
	case(3):
	{
		if (m == 1)
		{
			ETSIDI::Sprite SpriteP1("imagenes/mapa3/plataforma1.png", py, -px, 1, 1);
			SpriteP1.draw();
		}
		if (m == 2)
		{
			ETSIDI::Sprite SpriteP2("imagenes/mapa3/plataforma2.png", py, -px, 1, 1);
			SpriteP2.draw();
		}
		if (m == 3)
		{
			ETSIDI::Sprite SpriteP1("imagenes/mapa3/plataforma1.png", py, -px, 1, 1);
			SpriteP1.flip(true, false);
			SpriteP1.draw();
		}

		break;
	}
	}


}
Vector Plataforma::getPos()
{
	return posicion;
}
void Plataforma::setPos(float x, float y)
{
	posicion.x = x;
	posicion.y = y;
}