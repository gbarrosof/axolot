#include "Mundo.h"
#include <string.h>
#include <stdio.h>



Mundo::Mundo()
{
	estado = start;
	
	
	flecha = 0;
}



void Mundo::inicializa()
{
	


	//ETSIDI::playMusica("sonidos/street_fighter.mp3", true);
	/*avocado = new SpriteSequence("imagenes/avocado", 6, 1, 50, true, posicion_personaje.x, posicion_personaje.y, 2, 2, 6);
	platano = new SpriteSequence("imagenes/platano", 4, 1, 50, true, posicion_personaje.x, posicion_personaje.y, 2, 2, 6);
	piña = new SpriteSequence("imagenes/piña", 6, 1, 50, true, posicion_personaje.x, posicion_personaje.y, 2, 2, 6);
	zanahoria = new SpriteSequence("imagenes/zanahoria", 6, 1, 50, true, posicion_personaje.x, posicion_personaje.y, 2, 2, 6);
	granada = new SpriteSequence("imagenes/granada", 6, 1, 50, true, bala.x, bala.y, 2, 2, 6);
	*/
	
}


void Mundo::dibuja()
{
	/*
	gluLookAt(posiocioncamara.x, posiocioncamara.y, posicionz,  // posicion del ojo
		ojo.x, ojo.y, 0,      // hacia que punto mira  (0,0,0) 
		0.0, 1.0, 0.0);*/
	if (estado == start)
	{
		
		gluLookAt(0, 0, 10,  // posicion del ojo
			0, 0, 0,      // hacia que punto mira  (0,0,0) 
			0.0, 1.0, 0.0); 
		ETSIDI::setTextColor(1, 0, 1);
		ETSIDI::setFont("fuentes/start.ttf", 50);
		ETSIDI::printxy("FRUIT SLUG", -3,2);
		ETSIDI::setTextColor(1, 1, 1);
		ETSIDI::setFont("fuentes/start.ttf", 20);
		ETSIDI::printxy("space to play ", -2,0);
		ETSIDI::printxy("controls", -2, -1);
		ETSIDI::printxy("exit", -2, -2);

		ETSIDI::printxy(">", -3, flecha);
	}

	else if (estado == play)
	{
		
		nivel.pinta();
	}
	else if (estado == pause)
	{
		
		nivel.pinta();
		ETSIDI::setTextColor(0, 1, 0);
		ETSIDI::setFont("fuentes/grasping.ttf", 30);
		ETSIDI::printxy("FRUIT SLUG", nivel.getPosOjo().x, nivel.getPosOjo().y+2);
		ETSIDI::setTextColor(1, 1, 1);
		ETSIDI::setFont("fuentes/grasping.ttf", 20);
		ETSIDI::printxy("pause ", nivel.getPosOjo().x, nivel.getPosOjo().y);
		ETSIDI::printxy("space tu return", nivel.getPosOjo().x, nivel.getPosOjo().y-1);
		
		
	}
	else if (estado == gameover)
	{

	nivel.pinta();
		ETSIDI::setTextColor(0, 1, 0);
		ETSIDI::setFont("fuentes/grasping.ttf", 30);
		ETSIDI::printxy("FRUIT SLUG", nivel.getPosOjo().x, nivel.getPosOjo().y + 2);
		ETSIDI::setTextColor(1, 1, 1);
		ETSIDI::setFont("fuentes/grasping.ttf", 20);
		ETSIDI::printxy("Has murido", nivel.getPosOjo().x, nivel.getPosOjo().y);
		ETSIDI::printxy("space to play again", nivel.getPosOjo().x, nivel.getPosOjo().y - 1);
		ETSIDI::printxy("esc para salir", nivel.getPosOjo().x, nivel.getPosOjo().y - 2);

		
		
	
	}
	else if (estado == loading)
	{
		//time_t first, second;
		//first = time(NULL);
		gluLookAt(0, 0, 10,  // posicion del ojo
			0, 0, 0,      // hacia que punto mira  (0,0,0) 
			0.0, 1.0, 0.0);

		ETSIDI::setTextColor(1, 1, 1);
		ETSIDI::setFont("fuentes/loading.ttf", 50);
		ETSIDI::printxy("FRUIT SLUG", -2, 2);

		

		ETSIDI::setTextColor(1, 1, 1);
		ETSIDI::setFont("fuentes/loading.ttf", 20);
		ETSIDI::printxy("loading...", -1, -3);


		ETSIDI::setTextColor(1, 1, 1);
		ETSIDI::setFont("fuentes/loading.ttf", 20);
		vidas.setSize(0.5,0.5);

		switch (nivel.vidas)
		{
		case (5):
		{
			vidas.setPos(1, -2);
			vidas.draw();
		}
			
		case (4):
		{
			vidas.setPos(0, -2);
			vidas.draw();
		}
		case (3):
		{
			vidas.setPos(-1, -2);
			vidas.draw();
		}
		case (2):
		{
			vidas.setPos(-2, -2);
			vidas.draw();
		}
		case (1):
		{
			vidas.setPos(-3, -2);
			vidas.draw();
		}
		}
		

		sprite1.draw();
		sprite2.draw();
		sprite3.draw();
		sprite4.draw();
		
		//second = time(NULL);
		
		//difftime(first, second);
		//
		
		nivel.inicializa(1);
		estado = dormido;
	}
	else if (estado == dormido)
	{
		gluLookAt(0, 0, 10,  // posicion del ojo
			0, 0, 0,      // hacia que punto mira  (0,0,0) 
			0.0, 1.0, 0.0);

		ETSIDI::setTextColor(1, 1, 1);
		ETSIDI::setFont("fuentes/loading.ttf", 50);
		ETSIDI::printxy("FRUIT SLUG", -2, 2);


		ETSIDI::setTextColor(1, 1, 1);
		ETSIDI::setFont("fuentes/loading.ttf", 20);
		ETSIDI::printxy("loading...", -1, -3);

		switch (nivel.vidas)
		{
		case (5):
		{
			vidas.setPos(1, -2);
			vidas.draw();
		}

		case (4):
		{
			vidas.setPos(0, -2);
			vidas.draw();
		}
		case (3):
		{
			vidas.setPos(-1, -2);
			vidas.draw();
		}
		case (2):
		{
			vidas.setPos(-2, -2);
			vidas.draw();
		}
		case (1):
		{
			vidas.setPos(-3, -2);
			vidas.draw();
		}
		}


		sprite1.draw();
		sprite2.draw();
		sprite3.draw();
		sprite4.draw();


		Sleep(2000);
		estado = play;
	}

	

	/*Moneda* coin(0);
	monedas.agregar(coin);*/
}
void Mundo::teclaespecial(unsigned char key)
{
	if (estado == start)
	{
		if (key == GLUT_KEY_DOWN )
		{
			if (flecha >= -1)
			{
				flecha -= 1;
			}
		}

		if (key == GLUT_KEY_UP)
		{
			if (flecha <= -1)
			{
				flecha += 1;
			}
		}
	}
}


void Mundo::teclado(unsigned char key)
{
	
	if(estado == start )
	{
		if (flecha == 0)
		{
			if (key == ' ')
			{
				estado = loading;
				
			}
		}
		else if (flecha == -1)
		{
			if (key == ' ')
			{
				estado = controls;
			}
			
		}
		else if (flecha == -2)
		{
			if (key == ' ')
			{
				exit(0);
			}
			
		}

		
	}
	else if (estado == pause)
	{
		if (key=='p')
		{
			estado = play;
		}
		else if (key == 27)
		{
			estado = start;
			//return;
		}
		
	}

	else if (estado == play)
	{
		nivel.teclado(key);
		if (key == 'p')
		{
			estado = pause;
		}
		else if (key == 'l')
		{
			estado = gameover;
		}
	}
	else if (estado == gameover)
	{
		if (key == ' ')
		{
			estado = play;
			//return;
		}
		if (key == 27)
		{
			estado = start;
			//return;
		}
	}
	

}

void Mundo::mueve()
{
	
	

	if (estado == play)
	{
		nivel.mueve();
	}

}
