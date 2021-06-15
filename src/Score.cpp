#include "Score.h"

Score::Score()
{

	

}

void Score::dibuja()
{
	if (unidades >= 10)
	{
		unidades -= 10;
		decenas += 1;
	}

	if (decenas >= 10)
	{
		decenas -= 10;
		centenas += 1;
	}
	if (centenas >= 10)
	{
		centenas -= 10;
		millares += 1;
	}

	
	



	a.setPos(posicion.x, posicion.y);
	b.setPos(posicion.x-0.5, posicion.y);
	c.setPos(posicion.x-1, posicion.y);
	d.setPos(posicion.x -1.5, posicion.y);



	a.setState(unidades-1);
	b.setState(decenas-1);
	c.setState(centenas-1);
	d.setState(millares - 1);

	a.draw();
	b.draw();
	c.draw();
	d.draw();
	
}

void Score::setScore(int m, int c, int d, int u)
{
	centenas += c;
	decenas += d;
	unidades += u;
	millares += m;
}

void Score::setPos(float px, float py)
{
	posicion.x = px;
	posicion.y = py;
}

