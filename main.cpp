#include <iostream>
#include <fstream>
using namespace std;

const int MAX_ALUMNOS = 100;

void ingresarDatos(string nombres[], float notas[], int& cantidad) {
    cout << "\nCuantos alumnos vas a registrar? ";
    cin >> cantidad;

    if (cantidad > 0 && cantidad <= MAX_ALUMNOS) {
        for (int i = 0; i < cantidad; i++) {
            cout << "Ingrese el nombre del alumno #" << i + 1 << ": ";
            cin.ignore();
            getline(cin, nombres[i]);

            cout << "Ingrese la nota de " << nombres[i] << ": ";
            cin >> notas[i];
        }
    } else {
        cout << "Cantidad no valida.\n";
        cantidad = 0;
    }
}

void mostrarDatos(string nombres[], float notas[], int cantidad) {
    cout << "\n--- Lista de Calificaciones ---\n";
    for (int i = 0; i < cantidad; i++) {
        cout << (i + 1) << ". " << nombres[i] << " - Nota: ";
        if (notas[i] >= 0)
            cout << notas[i] << endl;
        else
            cout << "(Eliminada)\n";
    }
}
