#include "pch.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
	//Posiciones iniciales 
	int TP = 1; //Tortuga posicion
	int LP = 1; //Liebre posicion

	//Generación de números aleatorios
	srand(time(0)); //srand número aleatorios

	cout << "BANG!" << endl;
	cout << "¡Y ARRANCANN!" << endl;

	while (TP < 70 && LP < 70) {
		int TM = rand() % 10 + 1; //Tortuga movimiento
		int LM = rand() % 10 + 1; //Liebre movimiento
		//rand definimos el rango de números aleatorios que tenemos que utilizar

		//Liebre
		if (LM >= 1 && LM <= 2) {
			LP += 9;
		}
		else if (LM >= 3 && LM <= 4) {
			LP -= 12;
		}
		if (LP < 1) {
			LP = 1;
		}
		else if(LM > 5 && LM <=8){
			LP += 1;
		}
		else {
			LP -= 2;
			if (LP < 1) {
				LP -= 1;
			}
		}

		//Tortuga.
		if (TM >= 1 && TM <= 5) {
			TP += 3;
		}
		else if (TM >= 6 && TM <= 7) {
			TP -= 6;
		}
		if (TP < 1) {
			TP = 1;
		}
		else {
			TP += 1;
		}

		//Representación de la carrera.
		for (int i = 1; i <= 70; i++) {
			if (i == LP && i == TP) {
				cout << "¡OUCH!";
			} 
			else if (i == LP) {
				cout << "H";
			}
			else if (i == TP) {
				cout << "T";
			}
			else {
				cout << " ";
			}
		}
		cout << endl;

		//Comprobar la llegada de la T y H al cuadro de 70.
		if (TP >= 70 && LP >= 70) {
			cout << "ES UN EMPATE!!! :)" << endl;
		}
		else if (LP >= 70) {
			cout << "LA LIEBRE HA GANADO, ¡NI HABLAR!" << endl;
		}
		else if (TP >= 70) {
			cout << "LA TORTUGA HA GANADO, ¡BRAVOO!" << endl;
		}
	}
	return 0;
}
//La tortuga siempre gana, ya que sus movimientos son más ventajosos que los de la liebre.