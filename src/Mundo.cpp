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
	if (estado == start)
	{
		ETSIDI::playMusica("sonidos/Start.mp3", true);
	}
}


void Mundo::dibuja()
{
	
	if (estado == start)
	{
		nivel.setnivel(1);
		nivel.Vida.setVidas(5);

		nivel.pinchos.destruirContenido();
		nivel.plataformas.destruirContenido();
		nivel.cuadraditos.destruirContenido();

		gluLookAt(0, 0, 50,  
			0, 0, 0,      
			0.0, 1.0, 0.0); 
		ETSIDI::setTextColor(1, 0, 1);
		ETSIDI::setFont("fuentes/start.ttf", 50);
		ETSIDI::printxy("FRUIT SLUG", -12,8);
		ETSIDI::setTextColor(1, 1, 1);
		ETSIDI::setFont("fuentes/start.ttf", 20);
		ETSIDI::printxy("space to play ", -8,0);
		ETSIDI::printxy("controls", -8, -4);
		ETSIDI::printxy("exit", -8, -8);

		ETSIDI::printxy(">", -12, flecha);

		ETSIDI::setFont("fuentes/Bitwise.ttf", 10);
		ETSIDI::setTextColor(0, 0, 1);
		
		ETSIDI::printxy("Gonzalo Barroso Fernández", 8, -13);
		ETSIDI::printxy("Santiago Galicia Gonzalez", 8, -14);
		ETSIDI::printxy("Victor Herranz Gumiel", 8, -15);

	}

	else if (estado == play )
	{
		nivel.pinta();
	}
	else if (estado == powerup)
	{
		nivel.pinta();

		glTranslatef(0, 0, 1.1);
		cambio.setPos(nivel.fruta.getPos().x, nivel.fruta.getPos().y);
		cambio.draw();
		glTranslatef(0, 0, -1.1);

	}
	else if (estado == controls)
	{
		gluLookAt(0, 0, 20,  
			0, 0, 0,      
			0.0, 1.0, 0.0);
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/controls.png").id);
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);
		glTexCoord2d(0, 1);    glVertex3f(-15, -15, -20);
		glTexCoord2d(1, 1);    glVertex3f(15, -15, -20);
		glTexCoord2d(1, 0);    glVertex3f(15, 15, -20);
		glTexCoord2d(0, 0);    glVertex3f(-15, 15, -20);
		glEnd();
		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);
	}

	else if (estado == pause)
	{
		
		nivel.pinta();

		ETSIDI::setTextColor(1, 1, 1);
		ETSIDI::setFont("fuentes/Action_Force_Normal.ttf", 40);
		ETSIDI::printxy("FRUIT SLUG", nivel.getPosOjo().x-2.5, nivel.getPosOjo().y+3);
		ETSIDI::setTextColor(1, 0, 0.7);
		ETSIDI::setFont("fuentes/Action_Force_Normal.ttf", 70);
		ETSIDI::printxy("pause ", nivel.getPosOjo().x-2.5, nivel.getPosOjo().y-1);
		ETSIDI::setTextColor(1, 0, 0.4);
		ETSIDI::setFont("fuentes/Action_Force_Normal.ttf", 25);
		ETSIDI::printxy("space tu return", nivel.getPosOjo().x-2.5, nivel.getPosOjo().y - 3);
		ETSIDI::printxy("esc to exit", nivel.getPosOjo().x - 1.5, nivel.getPosOjo().y - 5);
		
		
	}
	else if (estado == gameover)
	{
	nivel.pinta();

		ETSIDI::setTextColor(1, 1, 1);
		ETSIDI::setFont("fuentes/Bloody.ttf", 40);
		ETSIDI::printxy("FRUIT SLUG", nivel.getPosOjo().x-2.5, nivel.getPosOjo().y + 3);
		ETSIDI::setTextColor(1, 0, 0);
		ETSIDI::setFont("fuentes/Bloody.ttf", 40);
		ETSIDI::printxy("Has muerto", nivel.getPosOjo().x-2.5, nivel.getPosOjo().y-1);
		ETSIDI::setFont("fuentes/Bloody.ttf", 20);
		ETSIDI::setTextColor(0.75, 0, 1);
		ETSIDI::printxy("space to play again", nivel.getPosOjo().x-2.5, nivel.getPosOjo().y - 4);
		ETSIDI::printxy("esc to exit", nivel.getPosOjo().x-1.5, nivel.getPosOjo().y - 5);

		ETSIDI::stopMusica();
	}
	else if (estado == loading)
	{
		ETSIDI::stopMusica();

		gluLookAt(0, 0, 10,  
			0, 0, 0,      
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

		switch (nivel.Vida.getVidas())
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
		
		
		nivel.fruta.setdeath(false);
		nivel.fruta.setDisparos(false);
		nivel.enemigos.destruirContenido();
		nivel.visibles.destruirContenido();
		nivel.disparos.destruirContenido();
		nivel.monedas.destruirContenido();
		nivel.PowerUps.destruirContenido();


		nivel.inicializa(nivel.getNivel());
		estado = dormido;
	}
	else if (estado == dormido)
	{
		gluLookAt(0, 0, 10, 
			0, 0, 0,      
			0.0, 1.0, 0.0);

		ETSIDI::setTextColor(1, 1, 1);
		ETSIDI::setFont("fuentes/loading.ttf", 50);
		ETSIDI::printxy("FRUIT SLUG", -2, 2);


		ETSIDI::setTextColor(1, 1, 1);
		ETSIDI::setFont("fuentes/loading.ttf", 20);
		ETSIDI::printxy("loading...", -1, -3);

		switch (nivel.Vida.getVidas())
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
	else if (estado==loose)
	{
	ETSIDI::stopMusica();

	gluLookAt(10, ojo, 50,  
		10, ojo, 0,      
		0.0, 1.0, 0.0);

	ETSIDI::setTextColor(1, 1, 0);
	ETSIDI::setFont("fuentes/texto.ttf", 15);
	ETSIDI::printxy("La Republica se desmorona bajo los", -10, 0);
	ETSIDI::printxy("constantes ataques del poderoso imperio", -10, -3);
	ETSIDI::printxy("guiados por Rayo, el mono loco,", -10, -6);
	ETSIDI::printxy("los droides salen al ataque con armas", -10, -9);
	ETSIDI::printxy("imprevisibles y novedosas", -10, -12);
	ETSIDI::printxy("con las que derrotan a las tropas rebeldes.", -10, -15);

	ETSIDI::setFont("fuentes/texto.ttf", 50);
	ETSIDI::setTextColor(1, 1, 1);
	ETSIDI::printxy("GAMEOVER", -5, -30);

	if (ojo<=-40)
	{
		ETSIDI::setTextColor(1, 1, 0);
		ETSIDI::setFont("fuentes/texto.ttf", 15);
		ETSIDI::printxy("(press any key)", 0, -45);
	}

	}
	else if (estado == credits)
	{

	gluLookAt(10, ojo, 50,  
		10, ojo, 0,     
		0.0, 1.0, 0.0);

	ETSIDI::setTextColor(1, 1, 0);
	ETSIDI::setFont("fuentes/texto.ttf", 15);
	ETSIDI::printxy("Los heroes rebeldes lo han conseguido ", -10, 3);
	ETSIDI::printxy("pese a la superioridad en armas y efectivos", -10, -0);
	ETSIDI::printxy("la República Frutísitica ha conseguido", -10, -3);
	ETSIDI::printxy("vencer de la mano del comandante Aguacate, ", -10, -6);
	ETSIDI::printxy("capitán Banano y la mercenaria Pina.", -10, -9);
	ETSIDI::printxy("Se visualiza un nuevo futuro donde", -10, -12);
	ETSIDI::printxy("las frutas cobran una mayor importancia.", -10, -15);

	ETSIDI::setTextColor(1, 1, 1);
	ETSIDI::setFont("fuentes/texto.ttf", 37);
	ETSIDI::printxy("Gracias por jugar", -10, -20);

	ETSIDI::setFont("fuentes/texto.ttf", 15);
	ETSIDI::printxy("Creditos:", -10, -25);
	ETSIDI::setTextColor(1, 1, 0);
	ETSIDI::printxy("Santiago Galicia Gonzalez", -5, -30);
	ETSIDI::printxy("Gonzalo Barroso Fernández", -5, -32);
	ETSIDI::printxy("Victor Herranz Gumiel", -5, -34);


	}

	
	else if (estado == story)
	{
	gluLookAt(10, ojo, 50,  
		10, ojo, 0,      
		0.0, 1.0, 0.0);
	ETSIDI::setTextColor(1, 1, 0);
	ETSIDI::setFont("fuentes/texto.ttf", 15);
	ETSIDI::printxy("La Republica Frutista esta sumida", -11, 0);
	ETSIDI::printxy("en el caos. El gran incremento de secuestros", -11, -3);
	ETSIDI::printxy("y la subida de los impuestos en los locales", -11, -6);
	ETSIDI::printxy("están creando una gran barrera entre ambos ", -11, -9);
	ETSIDI::printxy("bandos mientras el imperio centra sus ", -11, -12);
	ETSIDI::printxy("esfuerzos en realizar bloqueos a los grandes", -11, -15);
	ETSIDI::printxy("barcos donde se movilizan las tropas ", -11, -18);
	ETSIDI::printxy("de la republica el Congreso debate   ", -11, -21);
	ETSIDI::printxy("interminablemente esta alarmante cadena ", -11, -24);
	ETSIDI::printxy("de acontecimientos .Un acuerdo entre ambos ", -11, -27);
	ETSIDI::printxy("bandos se ve muy lejano por lo que una serie ", -11, -30);
	ETSIDI::printxy("de heroes han salido a plantar cara.", -11, -33);
	ETSIDI::printxy("¿Seran capaces de derrotar al imperio?", -11, -36);

	}

}
void Mundo::teclaespecial(unsigned char key)
{
	if (estado == start)
	{
		if (key == GLUT_KEY_DOWN)
		{
			if (flecha >= -4)
			{
				ETSIDI::play("sonidos/move_menu.wav");
				flecha -= 4;
			}
		}

		if (key == GLUT_KEY_UP)
		{
			if (flecha <= -4)
			{
				ETSIDI::play("sonidos/move_menu.wav");
				flecha += 4;
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
				ETSIDI::play("sonidos/start_play.wav");
				estado = story;
				
			}
		}
		else if (flecha == -4)
		{
			if (key == ' ')
			{
				estado = controls;
			}
			
		}
		else if (flecha == -8)
		{
			if (key == ' ')
			{
				exit(0);
			}
		}
	}

	else if (estado==controls)
	{
		if (key == 27)
		{
			estado = start;
		}
	}
	else if (estado == pause)
	{
		if (key == ' ')
		{
			estado = play;
		}
		else if (key == 27)
		{
			ETSIDI::stopMusica();
			estado = start;
			ETSIDI::playMusica("sonidos/Start.mp3", true);
		}
		
	}

	else if (estado == play)
	{
		nivel.teclado(key);
		if (key == 27)
		{
			estado = pause;
		}
		
	}
	else if (estado == gameover)
	{
		if (key == ' ')
		{
			estado = loading;
		}
		if (key == 27)
		{
			estado = start;
		}
	}
	else if (estado == loose)
	{
		if (ojo <= -40 && key != 0)
		{
			estado = start;
			ojo = 20;
		}
	}
		
	

}

void Mundo::mueve()
{
	
	

	if (estado == play)
	{
		nivel.mueve();

		if (nivel.fruta.getdeath() && nivel.Vida.getVidas() != 0)
		{
			ETSIDI::play("sonidos/muerte.wav");
			estado = gameover;
			
		}
		else if (nivel.Vida.getVidas() == 0)
		{
			ETSIDI::play("sonidos/muerte.wav");
			estado = loose;
		}


		if (nivel.getpowerup()==true)
		{

			estado = powerup;
			nivel.setpowerup(false);
		}
		

		if (interaccion::colision(nivel.fruta, nivel.bandera))
		{
			if (nivel.getNivel() == 3)
			{
				estado = credits;
				return;
			}

			nivel.setnivel(nivel.getNivel() + 1);
			nivel.pinchos.destruirContenido();
			nivel.plataformas.destruirContenido();
			nivel.cuadraditos.destruirContenido();
			ETSIDI::stopMusica();

			estado = loading;
		}

	}

	if (estado == powerup)
	{
		cambio.loop();
		if (cambio.getState() == 24)
		{
			nivel.fruta.setVel(0, 0);
			estado = play;
			cambio.setState(0, false) ;
		}

	}

	if (estado == pause)
	{
		nivel.fruta.setAc(0, nivel.fruta.getAc().y);
		nivel.fruta.setVel(0, 0);
	}

	if (estado == loose)
	{
		
		if (ojo >= -40)
		{
			ojo -= 0.1;
		}

	}

	if (estado == story )
	{

		if (historia)
		{
			ojo -= 0.05;
			if (ojo <= -55)
			{
				historia = false;
				estado = loading;
				ojo = 20;
			}
		}
		else 
		{
			estado = loading;
		}
	}

	if (estado == credits)
	{
		ojo -= 0.05;
		if (ojo <= -53)
		{
			ETSIDI::playMusica("sonidos/Start.mp3", true);
			estado = start;
			ojo = 20;
		}
	}
	

}

void Mundo::teclamovimiento(unsigned char key)
{
	if (estado == play)
	{
		nivel.teclamovimiento(key);
	}
}
