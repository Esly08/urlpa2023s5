#include "pch.h"
#include "Pokemon.h"

Pokemon::Pokemon(int nn, string n, int g) {
	this->numero_nacional = nn;
	this->nombre = n;
	this->generacion = g;
}

Pokemon::Pokemon() {

}

void Pokemon::Imprimir() {
	cout << "NN: " << this->numero_nacional << "  Nombre: " << this->nombre << "  Generacion: " << this->generacion << endl;
}