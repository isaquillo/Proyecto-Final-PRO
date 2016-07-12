/*
    Nombre: Larios Díaz Isaac
    Tiempo invertido: 04:36
*/
#include <iostream>
#include <cstdlib>
#include "OtroCodigo.h"

#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif // _WIN32
#define EVALUACION 1
#define MATERIAS 2
#define TAREAS 3
#define AGENDA 4
#define NOTAS 5
#define SALIR 6

extern void pausar();

using namespace std;


int main() {
    int opcion;
    bool salir; // Variable bandera
    do {
        system(CLEAR);
        cout << "MI BLOCK DE NOTAS" << endl << endl;
        cout << "Men\xA3 principal" << endl;
        cout << "1) Evaluaci\xA2n del curso" << endl;
        cout << "2) Gesti\xA2n de Materias" << endl;
        cout << "3) Gesti\xA2n de Tareas" << endl;
        cout << "4) Agenda" << endl;
        cout << "5) Notas" << endl;
        cout << "6) Salir" << endl << endl;
        cout << "Elige una opci\xA2n: ";
        cin >> opcion;
        salir = false;
        switch(opcion) {
        case EVALUACION:
            evaluaCurso();
            break;
        case MATERIAS:
            gestionaMateria();
            break;
        case TAREAS:
            gestionaTarea();
            break;
        case AGENDA:
            gestionaAgenda();
            break;
        case NOTAS:
            gestionaNotas();
            break;
        case SALIR:
            salir = true;
            break;
        default:
            cout << "Opci\xA2n no existente. Vuelve a elegir..." << endl;
            cin.ignore();
            pausar();
        }
    }while (!salir);

    return 0;
}
