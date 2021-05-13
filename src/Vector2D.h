#pragma once
class Vector2D
{
public:
	float y;
	float x;

	Vector2D(float xv = 0.0f, float yv = 0.0f); // (1)constructor
	float modulo(); // (2) modulo del vector
	float argumento(); // (3) argumento del vector
	Vector2D unitario(); // (4) devuelve un vector unitario
	Vector2D operator - (Vector2D v); // (5) resta de vectores
	Vector2D operator + (Vector2D v); // (6) suma de vectores
	float operator *(Vector2D v); // (7) producto escalar
	Vector2D operator *(float u); // (8) producto por un escalar 
};