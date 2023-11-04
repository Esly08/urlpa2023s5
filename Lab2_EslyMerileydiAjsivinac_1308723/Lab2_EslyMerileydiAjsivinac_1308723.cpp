#include "pch.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace System;
using namespace System::Collections::Generic;
using namespace System::IO;

bool EsPalindromo(String^ palabra) {
    int length = palabra->Length;
    for (int i = 0; i < length / 2; i++) {
        if (palabra[i] != palabra[length - i - 1]) {
            return false;
        }
    }
    return true;
}

int ConvertToDecimal(String^ number, int base) {
    int decimalValue = 0;
    int power = 1;

    for (int i = number->Length - 1; i >= 0; i--) {
        Char c = number[i];
        int digit = (Char::IsDigit(c) ? (c - '0') : (c - 'A' + 10));
        decimalValue += digit * power;
        power *= base;
    }

    return decimalValue;
}

String^ ConvertFromDecimal(int decimalValue, int base) {
    List<Char> resultChars;

    while (decimalValue > 0) {
        int remainder = decimalValue % base;
        resultChars.Add(ConvertToBaseNChar(remainder));
        decimalValue /= base;
    }

    resultChars.Reverse();
    return gcnew String(resultChars.ToArray());
}

int main(array<System::String^>^ args)
{
    String^ archivo = "input.txt"; // Nombre del archivo de entrada
    String^ linea;
    List<String^>^ palabrasPalindromas = gcnew List<String^>();

    // Abre el archivo de texto
    StreamReader^ reader = File::OpenText(archivo);

    while ((linea = reader->ReadLine()) != nullptr) {
        array<Char>^ separadores = { ',' };
        array<String^>^ palabras = linea->Split(separadores, StringSplitOptions::RemoveEmptyEntries);

        for each (String ^ palabra in palabras) {
            palabra = palabra->Trim(); // Elimina espacios en blanco alrededor de la palabra
            palabra = palabra->ToLower(); // Convierte la palabra a minúsculas para comparar

            if (EsPalindromo(palabra)) {
                palabrasPalindromas->Add(palabra);
            }
        }
    }

    reader->Close();

    Console::WriteLine("Palabras palíndromas encontradas:");

    for each (String ^ palabra in palabrasPalindromas) {
        Console::WriteLine(palabra);
    }

    Console::WriteLine("Total de palabras palíndromas encontradas: {0}", palabrasPalindromas->Count);

    // Luego puedes agregar aquí la lógica de conversión de base m a base n
    // utilizando las funciones ConvertToDecimal y ConvertFromDecimal.

    return 0;
}
