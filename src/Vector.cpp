#include "Vector.h"
#include "freeglut.h"
#include <math.h>

Vector::Vector(float xv, float yv)
{
	x = xv;
	y = yv;
}

float Vector::modulo()
{
	return (float)sqrt(x * x + y * y);
}

float Vector::argumento()
{
	return (float)atan2(y, x);
}

Vector Vector::unitario()
{
	Vector retorno(x, y);
	float mod = modulo();
	if (mod > 0.00001)
	{
		retorno.x /= mod;
		retorno.y /= mod;
	}
	return retorno;
}

Vector Vector::operator-(Vector v)
{
	Vector res;
	res.x = x - v.x;
	res.y = y - v.y;
	return res;
}

Vector Vector::operator+(Vector v)
{
	Vector res;
	res.x = x + v.x;
	res.y = y + v.y;
	return res;
}

float Vector::operator*(Vector v)
{
	float res;
	res = (x * v.x) + (y * v.y);
	return res;
}

Vector Vector::operator*(float u)
{
	Vector v;
	v.x = x * u;
	v.y = y * u;
	return v;
}
