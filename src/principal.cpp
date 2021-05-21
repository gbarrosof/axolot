#include<stdio.h>
#include "freeglut.h"
#include "Mundo.h"
#include "ETSIDI.h"

using namespace ETSIDI;

SpriteSequence *explosion2;

Mundo mundo;

/*void dibujasprites(const char* texturePath)
{
	ETSIDI::Sprite Sprite(texturePath);
	Sprite.setPos(0, 105);
	Sprite.setSize(2, 2);
	Sprite.draw();

}*/
int i=0;




bool a;


void OnDraw(void)
{
	//Borrado de la pantalla
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//Para definir el punto de vista
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	
	

	//explosion("imagenes/explosion.png");

	
	//explosion("imagenes/explosion.png", 0);
	
	//fondos
	mundo.dibuja();
	//muñeco("imagenes/zanahoria.png");

	//dibujasprites("imagenes/images.png");
	
	


	

	/*glTranslatef(0, 10, 3);
	print("Go", "fuentes/grasping.ttf", 70);
	glTranslatef(0, -2, 0);
	print("curre", "fuentes/Bitwise.ttf", 70);
	glTranslatef(0, -7, -3);*/

	//no borrar esta linea ni poner nada despues
	glutSwapBuffers();
} //esta funcion sera llamada para dibujar

void OnTimer(int value); //esta funcion sera llamada cuando transcurra una temporizacion
void OnKeyboardDown(unsigned char key, int x, int y); //cuando se pulse una tecla	
void Mouse(int button, int state, int x, int y);
void onSpecialKeyboardDown(int key, int x, int y);

int main(int argc, char* argv[])
{

	

	//Inicializar el gestor de ventanas GLUT
	//y crear la ventana
	glutInit(&argc, argv);
	glutInitWindowSize(800, 600);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow("Fruit_Slug");

	//habilitar luces y definir perspectiva
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);
	glMatrixMode(GL_PROJECTION);
	gluPerspective(40.0, 800 / 600.0f, 0.1, 150);
	//gluPerspective(40.0, 8/6, 0.1, 150);

	//

	//Registrar los callbacks
	glutDisplayFunc(OnDraw);
	glutTimerFunc(25, OnTimer, 0);//le decimos que dentro de 25ms llame 1 vez a la funcion OnTimer()
	glutKeyboardFunc(OnKeyboardDown);

	glutSpecialFunc(onSpecialKeyboardDown);

	glutMouseFunc(Mouse);
	
	
	//dibujamapa();
	
	mundo.inicializa();
	explosion2 = new SpriteSequence("imagenes/explosion.png", 5, 5, 100, true, 2, 10, 5, 5, 0);
	
	
	//explosion2 = new SpriteSequence("imagenes/explosion.png", 5, 5, 100, true, 2, 10, 5, 5, 0);

	//pasarle el control a GLUT,que llamara a los callbacks
	glutMainLoop();

	return 0;
}

void OnKeyboardDown(unsigned char key, int x_t, int y_t)
{
	//poner aqui el código de teclado
	mundo.teclado(key);
	
	if (key == 'z')
	{
		i += 1;
	}
	
	/*if (key == ' ')
	{
		explosion2->draw();
		a = 1;
	}
	else
	{
		a = 0;
	}*/
	if (key == 'p')
	{
		ETSIDI::stopMusica();
	}
		

	glutPostRedisplay();
}
void Mouse(int button, int state, int x, int y)
{
	mundo.teclaespecial(state);
}


void OnTimer(int value)
{
	mundo.mueve();
	//poner aqui el código de animacion
	/*if (a==1)
	{
		explosion2->loop();
		int estado = explosion2->getState();
		if (estado >= 8)
		{
			//explosion2->setState(0, false);
			delete explosion2;
		}
	}*/
	//no borrar estas lineas
	glutTimerFunc(25, OnTimer, 0);
	glutPostRedisplay();
}

void onSpecialKeyboardDown(int key, int x, int y)
{
	mundo.teclaespecial(key);
}

