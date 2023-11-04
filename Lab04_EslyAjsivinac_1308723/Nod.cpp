#include "Nod.h"

Nod::Nod(string color, int posicion) {
	this->color = color;
	this->posicion = posicion;
	this->siguiente = NULL;
}