#include "Pil.h"
#include <stdio.h>  
#include <windows.h>  

void gotoxy(int x, int y) {
	HANDLE hcon;
	hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition(hcon, dwPos);
}

Pil::Pil() {
	this->tope = NULL;
	this->tamanio = 0;
}


void Pil::insertar(string color, int posicion) {
	Nod* nuevo_nodo = new Nod(color, posicion);
	if (this->tope == NULL) {
		this->tope = nuevo_nodo;
		this->frente = this->tope;
		this->tamanio++;
		return;
	}
	nuevo_nodo->siguiente = this->tope;
	this->tope = nuevo_nodo;
	this->tamanio++;
}

void Pil::imprimir(int x, int y, int diferencia) {
	Nod* b = this->tope;

	if (diferencia != -1) {

		for (int i = 0; i < diferencia; i++) {
			gotoxy(x, y);
			cout << endl;
			y += 1;
		}
	}
	while (b != NULL) {
		gotoxy(x, y);
		cout << b->color << ":" << b->posicion << endl;
		b = b->siguiente;
		y += 1;
	}
	cout << endl << endl;
}


void Pil::agregarPila(Nod* nuevo_nodo) {
	nuevo_nodo->siguiente = this->tope;
	this->tope = nuevo_nodo;
	this->tamanio++;
	this->reordenar();
}

void Pil::agregarCola(Nod* nuevo_nodo) {
	this->frente->siguiente = nuevo_nodo;
	this->frente = nuevo_nodo;
	this->tamanio++;
}


void Pil::reordenar() {
	Nod* aux = this->tope;
	int pos = this->tamanio;
	while (aux != NULL) {
		aux->posicion = pos;
		aux = aux->siguiente;
		pos--;
	}
}

Nod* Pil::eliminarCola() {
	if (this->frente == this->tope) {
		Nod* r = this->frente;
		this->frente = NULL;
		this->tope = NULL;
		this->tamanio = 0;
		return r;
	}
	Nod* aux = this->tope;
	Nod* eliminado = NULL;
	while (aux != NULL) {
		if (aux->siguiente == this->frente) {
			eliminado = this->frente;
			aux->siguiente = NULL;
			this->frente = aux;
			eliminado->siguiente = NULL;
			this->tamanio--;
			return eliminado;
			break;
		}
		aux = aux->siguiente;
	}
	return NULL;
}

Nod* Pil::eliminarPila() {
	if (this->tope == NULL) return NULL;
	Nod* eliminado = this->tope;
	this->tope = this->tope->siguiente;
	eliminado->siguiente = NULL;
	this->tamanio--;
	return eliminado;
}


bool Pil::verificarLetras(int cantidad) {
	int counter = 0;
	Nod* aux = this->tope;
	while (aux != NULL) {
		if (aux->siguiente != NULL) {
			if (aux->color != aux->siguiente->color) {
				counter++;
			}
		}
		aux = aux->siguiente;
	}
	return cantidad == counter;
}

bool Pil::verificarNumeros(int cantidad) {
	int counter = 0;
	Nod* aux = this->tope;
	while (aux != NULL) {
		if (aux->siguiente != NULL) {
			if (aux->posicion > aux->siguiente->posicion) {
				counter++;
			}
		}
		aux = aux->siguiente;
	}
	return cantidad == counter;
}