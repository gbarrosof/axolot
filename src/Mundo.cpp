#include "Mundo.h"
#include "freeglut.h"
#include <math.h>

void Mundo::rotarOjo()
{
	float dist = sqrt(x_ojo * x_ojo + z_ojo * z_ojo);
	float ang = atan2(z_ojo, x_ojo);
	ang += 0.05f;
	x_ojo = dist * cos(ang);
	z_ojo = dist * sin(ang);
}

void Mundo::dibuja()
{

	gluLookAt(x_ojo, y_ojo, z_ojo, // posicion del ojo
		0.0, y_ojo, 0.0, // hacia que punto mira (0,0,0)
		0.0, 1.0, 0.0); // definimos hacia arriba (eje Y)

	caja.dibuja();
	hombre.dibuja();
	plataforma.dibuja();
	disparos.dibuja();
}

void Mundo::teclaEspecial(unsigned char key)
{
	switch (key)
	{
	case GLUT_KEY_LEFT:
		hombre.setVel(-5.0f, 0.0f);
		break;
	case GLUT_KEY_RIGHT:
		hombre.setVel(5.0f, 0.0f);
		break;
	case GLUT_KEY_UP:
		if(Interaccion::contacto(hombre, caja)) 
		hombre.setVel(0.0f,15.0f);
		break;
	}
}

void Mundo::tecla(unsigned char key)
{
	switch (key)
	{
	case ' ':
	{
		Disparo* d = new Disparo();
		Vector2D pos = hombre.getPos();
		d->setPos(pos.x, pos.y+0.5);
		disparos.agregar(d);
		break;
	}
	}
}

Mundo::~Mundo()
{
}

void Mundo::mover()
{
	hombre.mueve(0.025f);
	disparos.mueve(0.025f);
	Interaccion::rebote(hombre, caja);
	Interaccion::contacto(hombre, caja);
}

void Mundo::inicializa()
{
	x_ojo = 0; y_ojo = 7.5;
	z_ojo = 30;

	plataforma.setPos(-5.0f, 9.0f, 5.0f, 9.0f);
	plataforma.setColor(255, 255, 255);

}
