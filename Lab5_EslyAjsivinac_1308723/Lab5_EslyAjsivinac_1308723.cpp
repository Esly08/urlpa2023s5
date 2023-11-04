#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Pokemon.h"
#include "Ordenamiento.h"
using namespace std;

vector<string> dividir(string cadena, char referencia) {
	vector<string> cadenas;
	string nueva = "";
	for (int i = 0; i < cadena.length(); i++) {
		if (cadena[i] == referencia) {
			cadenas.push_back(nueva);
			nueva = "";
		}
		else {
			nueva += cadena[i];
		}
	}
	cadenas.push_back(nueva);
	for (const string& subcadena : cadenas) {
		cout << subcadena << " ";
	}
	return cadenas;
}

void leerArchivo(Pokemon(&pokemon)[126]) {
	int posicion = 0;
	fstream lectura;
	lectura.open("Poquedex.txt", ios::in);
	if (lectura.is_open() == false) {
		cout << "Ups! Ocurrió un error al abrir el archivo :( \n";
	}
	else {
		string linea;
		while (getline(lectura, linea)) {
			vector<string> cadenas = dividir(linea, ' ');
			int nn = atoi(cadenas[0].c_str());
			string nombre = cadenas[1];
			int generacion = atoi(cadenas[2].c_str());
			Pokemon pk = Pokemon(nn, nombre, generacion);
			pokemon[posicion] = pk;
			posicion++;
		}
	}
	lectura.close();
}

void imprimirArr(Pokemon arr[], int tamanio) {
	for (int i = 0; i < 90; i++)
	{
		arr[i].Imprimir();
	}
}

int main()
{
	Pokemon pokemon[126];
	leerArchivo(pokemon);
	imprimirArr(pokemon, 126);
	cout << "==================== DATOS ORDENADOS ====================== \n\n";
	cout << "Selection Sort Generacion";
	Ordenamiento::selectionSortG(pokemon, 126);
	cout << "Selection Sort National Number";
	Ordenamiento::selectionSortN(pokemon, 126);
	cout << "Quick Sort Generacion";
	Ordenamiento::quickSortG(pokemon, 0, 126);
	cout << "Quick Sort National Number";
	Ordenamiento::quickSortN(pokemon,0,126);
	cout << "Shell Sort Generacion";
	Ordenamiento::shellSortG(pokemon, 126);
	cout << "Shell Sort National Number";
	Ordenamiento::shellSortN(pokemon, 126);
	
}