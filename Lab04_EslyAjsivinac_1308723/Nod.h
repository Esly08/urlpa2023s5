#pragma once
#include <iostream>
using namespace std;

class Nod
{
	//atributos
public:
	string color;
	int posicion;
	Nod* siguiente;
	Nod(string, int);
};