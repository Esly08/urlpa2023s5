#include "pch.h"
#include "Ordenamiento.h"

void Ordenamiento::selectionSortG(Pokemon arr[], int tamanio) {
	for (int i = 0; i < tamanio - 1; i++) {
		int generacion_menor = arr[i].generacion;
		int posicion_menor = i;
		Pokemon _menor = arr[i];
		for (int j = i + 1; j < tamanio; j++) {
			if (arr[j].generacion < generacion_menor) {
				generacion_menor = arr[j].generacion;
				_menor = arr[j];
				posicion_menor = j;
			}
		}
		Pokemon temp = arr[posicion_menor];
		arr[posicion_menor] = arr[i];
		arr[i] = temp;
	}
	//imprimirArr(arr, 10);
}

void Ordenamiento::selectionSortN(Pokemon arr[], int tamanio) {
	for (int i = 0; i < tamanio - 1; i++) {
		int generacion_menor = arr[i].numero_nacional;
		int posicion_menor = i;
		Pokemon _menor = arr[i];
		for (int j = i + 1; j < tamanio; j++) {
			if (arr[j].numero_nacional < generacion_menor) {
				generacion_menor = arr[j].numero_nacional;
				_menor = arr[j];
				posicion_menor = j;
			}
		}
		Pokemon temp = arr[posicion_menor];
		arr[posicion_menor] = arr[i];
		arr[i] = temp;
	}
	//imprimirArr(arr, 10);
}

void intercambio(Pokemon* a, Pokemon* b) {
	Pokemon t = *a;
	*a = *b;
	*b = t;
}

int mitad(Pokemon arr[], int menor, int mayor) {
	int pivote = mayor;
	int i = (menor - 1);
	for (int j = menor; j <= mayor - 1; j++) {
		if (arr[j].numero_nacional <= arr[pivote].numero_nacional) {
			i++;
			intercambio(&arr[i], &arr[j]);
		}
	}
	intercambio(&arr[i + 1], &arr[mayor]);
	return (i + 1);
}

int mitadG(Pokemon arr[], int menor, int mayor) {
	int pivote = mayor;
	int i = (menor - 1);
	for (int j = menor; j <= mayor - 1; j++) {
		if (arr[j].generacion <= arr[pivote].generacion) {
			i++;
			intercambio(&arr[i], &arr[j]);
		}
	}
	intercambio(&arr[i + 1], &arr[mayor]);
	return (i + 1);
}

void Ordenamiento::quickSortN(Pokemon arr[], int menor, int mayor)
{
	if (menor < mayor) {
		int indice = mitad(arr, menor, mayor);
		quickSortG(arr, menor, indice - 1);
		quickSortG(arr, indice + 1, mayor);
	}
}

void Ordenamiento::quickSortG(Pokemon arr[], int menor, int mayor)
{
	if (menor < mayor) {
		int indice = mitadG(arr, menor, mayor);
		quickSortG(arr, menor, indice - 1);
		quickSortG(arr, indice + 1, mayor);
	}
}

void Ordenamiento::shellSortN(Pokemon arr[], int size) {
	int n = size;

	for (int gap = n / 2; gap > 0; gap /= 2) {
		for (int i = gap; i < n; i++) {
			Pokemon temp = arr[i];
			int j;

			for (j = i; j >= gap && arr[j - gap].numero_nacional > temp.numero_nacional; j -= gap) {
				arr[j] = arr[j - gap];
			}

			arr[j] = temp;
		}
	}
}

void Ordenamiento::shellSortG(Pokemon arr[], int size) {
	int n = size;

	for (int gap = n / 2; gap > 0; gap /= 2) {
		for (int i = gap; i < n; i++) {
			Pokemon temp = arr[i];
			int j;

			for (j = i; j >= gap && arr[j - gap].generacion > temp.generacion; j -= gap) {
				arr[j] = arr[j - gap];
			}

			arr[j] = temp;
		}
	}
}