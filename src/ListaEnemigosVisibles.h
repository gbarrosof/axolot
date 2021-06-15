#pragma once
#include"Vector.h"
#include "EnemigoV.h"
#include "interaccion.h"

#define MAX_ENEMIGOS 20


class ListaEnemigosVisibles 
   
{
public:
    ListaEnemigosVisibles();
    ~ListaEnemigosVisibles();
    bool agregar(EnemigoV* e);
    void eliminar(int index);
    void elimina(int );
    int getNumero() { return numero; }
    EnemigoV* enemigo(int i) { return lis[i]; }
    void destruirContenido();
    EnemigoV* disparo(personaje p, int i);
    EnemigoV* genera(personaje p, Enemigo* e);
    void eliminar(Disparo d);

private:
    EnemigoV* lis[MAX_ENEMIGOS];
    int numero;
};

