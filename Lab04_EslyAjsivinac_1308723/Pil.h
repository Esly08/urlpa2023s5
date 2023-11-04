#pragma once
#include "Nod.h"

class Pil
{
public:
	Nod* tope;
	Nod* frente;
	int tamanio;
	Pil();
	void insertar(string, int);
	void imprimir(int, int, int);
	Nod* eliminarPila();
	Nod* eliminarCola();
	void agregarPila(Nod*);
	void agregarCola(Nod*);
	void reordenar();
	bool verificarNumeros(int);
	bool verificarLetras(int);

};