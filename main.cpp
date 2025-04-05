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

void buscarPorNumero(string nombres[], float notas[], int cantidad) {
    int numAlumno;
    cout << "\nIngrese el numero del alumno (1 a " << cantidad << "): ";
    cin >> numAlumno;

    int index = numAlumno - 1;
    if (index >= 0 && index < cantidad) {
        cout << "Alumno: " << nombres[index] << " - Nota: ";
        if (notas[index] >= 0)
            cout << notas[index] << endl;
        else
            cout << "(Eliminada)\n";
    } else {
        cout << "Numero fuera de rango.\n";
    }
}

void modificarNota(string nombres[], float notas[], int cantidad) {
    int numAlumno;
    cout << "\nA que alumno queres modificarle la nota? (1 a " << cantidad << "): ";
    cin >> numAlumno;

    int index = numAlumno - 1;
    if (index >= 0 && index < cantidad) {
        cout << "Nota actual de " << nombres[index] << ": " << notas[index] << endl;
        cout << "Ingrese la nueva nota: ";
        cin >> notas[index];
        cout << "Nota actualizada con exito.\n";
    } else {
        cout << "Numero fuera de rango.\n";
    }
}

void eliminarNota(string nombres[], float notas[], int cantidad) {
    int numAlumno;
    cout << "\nA que alumno queres eliminarle la nota? (1 a " << cantidad << "): ";
    cin >> numAlumno;

    int index = numAlumno - 1;
    if (index >= 0 && index < cantidad) {
        notas[index] = -1;
        cout << "Nota eliminada con exito.\n";
    } else {
        cout << "Numero fuera de rango.\n";
    }
}

void guardarArchivo(string nombres[], float notas[], int cantidad) {
    ofstream archivo("calificaciones.txt");

    if (archivo.is_open()) {
        archivo << "Registro de Calificaciones\n";
        for (int i = 0; i < cantidad; i++) {
            archivo << (i + 1) << ". " << nombres[i] << " - Nota: ";
            if (notas[i] >= 0)
                archivo << notas[i];
            else
                archivo << "(Eliminada)";
            archivo << "\n";
        }
        archivo.close();
        cout << "Datos guardados en calificaciones.txt\n";
    } else {
        cout << "Error al guardar el archivo.\n";
    }
}
