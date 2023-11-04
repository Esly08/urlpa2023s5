#pragma once
#include <iostream>
using namespace std;

class Pokemon
{
public:
	int numero_nacional;
	string nombre;
	int generacion;
	Pokemon(int, string, int);
	Pokemon();
	void Imprimir();
};
