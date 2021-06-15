#pragma once
class Vector
{
public:
	float y;
	float x;

	Vector(float xv = 0.0f, float yv = 0.0f); // (1)constructor
	float modulo(); // (2) modulo del vector
	float argumento(); // (3) argumento del vector
	Vector unitario(); // (4) devuelve un vector unitario
	Vector operator - (Vector v); // (5) resta de vectores
	Vector operator + (Vector v); // (6) suma de vectores
	float operator *(Vector v); // (7) producto escalar
	Vector operator *(float u); // (8) producto por un escalar 
};