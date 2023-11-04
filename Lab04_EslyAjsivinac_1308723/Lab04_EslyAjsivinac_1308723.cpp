#include "Pil.h"
#include <ctime>
#include <stdio.h>  
#include <thread>
#include <atomic>
#include <random>
#include <conio.h>
#include <windows.h>  

void gotoxy2(int x, int y) {
	HANDLE hcon;
	hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition(hcon, dwPos);
}

int getRandomNum(int x, int y) {
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dis(x, y);
	return dis(gen);
}


void delay(int secs) {
	for (int i = (time(NULL) + secs); time(NULL) != i; time(NULL));
}

void juego(Pil pilas[7], Pil baraja, int nivel) {
	int menor = 99999999999999;
	for (int i = 0; i < 7; i++) {
		Nod* eliminado = baraja.eliminarPila();
		pilas[i] = Pil();
		pilas[i].insertar(eliminado->color, eliminado->posicion);
	}
	while (true) {

		system("cls");
		int x = 0; int y = 2;
		gotoxy2(0, 1);
		cout << "+--------------------------------------------------------------------------------+ \n";
		for (int i = 0; i < 7; i++) {
			gotoxy2(x, 0);
			cout << "G" << i << endl;
			pilas[i].imprimir(x, y, -1);
			x += 12;
		}
		gotoxy2(0, y + 12);
		cout << "+--- (Q)Salir   (R)Baraja -------------- (M)Movimiento -------------------+ \n";
		if (_kbhit()) {
			char key = _getch();
			if (key == 'Q' || key == 'q')break;
			if (key == 'R') {
				for (int i = 0; i < 7; i++) {
					Nod* eliminado = baraja.eliminarPila();
					pilas[i].insertar(eliminado->color, eliminado->posicion);
				}
			}
			if (key == 'M') {
				int origen;
				gotoxy2(0, y + 16);
				cout << "Origen: ";
				cin >> origen;

				int destino;
				gotoxy2(0, y + 18);
				cout << "Destino: ";
				cin >> destino;
				cout << "Origen: " << destino << endl;

				Nod* eliminado = pilas[origen].eliminarCola();
				if (eliminado == NULL) {
					gotoxy2(0, y + 20);
					cout << "No hay ninguna carta en este grupo \n";
				}
				else {
					pilas[destino].agregarCola(eliminado);
				}

			}
		}
		for (int i = 0; i < 7; i++) {
			if (pilas[i].verificarLetras(nivel) && pilas[i].verificarNumeros(nivel)) {
				system("cls");
				cout << "¡¡Felicidades ha Ganado!! \n";
				system("pause");
				break;
			}
		}
		delay(1);
	}
}

int main() {
	Pil pilas[7];
	Pil baraja = Pil();
	for (int i = 0; i < 52; i++) {
		int numero = getRandomNum(2, 10); //Número Random
		string letra = numero % 2 == 0 ? "R" : "N";
		baraja.insertar(letra, numero);
	}
	int nivel;
	cout << "Ingrese el nivel: 1(Facil)     2(Medio)      3(Dificil): ";
	cin >> nivel;
	int cantidad_cartas = nivel == 1 ? 3 : nivel == 2 ? 5 : nivel == 3 ? 7 : 1;
	juego(pilas, baraja, cantidad_cartas);
	cout << "Termino el juego :) \n";
	system("Pause");
}