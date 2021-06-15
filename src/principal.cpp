#include<stdio.h>
#include "freeglut.h"
#include "Mundo.h"

Mundo mundo;


void OnDraw(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	mundo.dibuja();

	glutSwapBuffers();
} 

void OnTimer(int value); //esta funcion sera llamada cuando transcurra una temporizacion
void OnKeyboardDown(unsigned char key, int x, int y); //cuando se pulse una tecla	
void onSpecialKeyboardDown(int key, int x, int y);
void KeyboardUp(unsigned char key, int x, int y);



int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitWindowSize(800, 600);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow("Fruit_Slug");
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);
	glMatrixMode(GL_PROJECTION);
	gluPerspective(40.0, 800 / 600.0f, 0.1, 150);
	glutDisplayFunc(OnDraw);
	glutTimerFunc(25, OnTimer, 0);

	glutSetKeyRepeat(GLUT_KEY_REPEAT_OFF);
	glutKeyboardUpFunc(KeyboardUp);
	glutKeyboardFunc(OnKeyboardDown);
	glutSpecialFunc(onSpecialKeyboardDown);
	glutSetKeyRepeat;
	
	mundo.inicializa();
	glutMainLoop();

	return 0;
}

void OnKeyboardDown(unsigned char key, int x_t, int y_t)
{
	mundo.teclado(key);
	glutPostRedisplay();
}
void Mouse(int button, int state, int x, int y)
{
	mundo.teclaespecial(state);
}


void OnTimer(int value)
{
	mundo.mueve();
	glutTimerFunc(25, OnTimer, 0);
	glutPostRedisplay();
}

void onSpecialKeyboardDown(int key, int x, int y)
{
	mundo.teclaespecial(key);
}

void KeyboardUp(unsigned char key, int x, int y)
{
	mundo.teclamovimiento(key);
}
