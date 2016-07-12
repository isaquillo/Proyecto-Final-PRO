#ifndef OTROCODIGO_H_INCLUDED
#define OTROCODIGO_H_INCLUDED

#include <iostream>
#include <cstdlib>
#include <string>
#include <iomanip>

#include "AdminNotas.h"
#include "ControlAsistencia.h"
#include "Evaluacion.h"
#include "Materia.h"
#include "Nota.h"
#include "Recordatorio.h"
#include "Tarea.h"

using namespace std;

#define TOTAL_ACTIVIDADES 9
#define TOTAL_EXAMENES 3
#define TOTAL_NOTAS 3
#define TOTAL_TAREAS 10
#define CALIF_MAXIMA 100
#define CALIF_MINIMA 60
#define TOTAL_ASISTENCIAS 34
#define RETARDOS_POR_FALTA 3
#define PORC_TAREAS 7
#define PORC_ACTIVIDADES 63
#define PORC_EXAMENES 30
#define ASISTENCIA_MINIMA 80

#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif // _WIN32

// Prototipos de funciones
void mensajeCaptura (bool capturax);
void evaluaCurso();
void capturaAsistencia(ControlAsistencia &control);
void capturaEvaluandos(Evaluacion &eval);
void calculaResultados(ControlAsistencia &control, Evaluacion &eval);
void imprimeResultados();
void gestionaMateria();
void gestionaTarea();
void gestionaAgenda();
void gestionaNotas();

void pausar();

// Variables globales
float totalAsistencias;
float porcentajeAsistencia;
float calificacionFinal;
float puntosTareas;
float puntosExamenes;
float puntosActividades;
float califExamenes;
float califActividades;


void evaluaCurso() {
    Evaluacion eval;
    ControlAsistencia control;
    capturaAsistencia(control);
    capturaEvaluandos(eval);
    calculaResultados(control, eval);
    imprimeResultados();
}

void capturaAsistencia(ControlAsistencia &control) {
    // Declaracion de variables
    bool captura;
    int entero;
    system(CLEAR);
    cout << "-----CONTROL DE ASISTENCIA-----" << endl;
    cout << "Cuantas veces faltaste\? ";
    cin >> entero;
    captura = control.fijaNumeroFaltas(entero);
    mensajeCaptura(captura);
    cout << "Cuantos retardos tuviste\? ";
    cin >> entero;
    captura = control.fijaNumeroRetardos(entero);
    mensajeCaptura(captura);
    cout << "Faltas acumuladas:    " << control.dameNumeroFaltas() << endl;
    cout << "Retardos acumulados:  " << control.dameNumeroRetardos() << endl << endl;
}
void capturaEvaluandos(Evaluacion &eval) {
    // Declaracion de variables
    bool captura;
    int entero;
    float real;
    int i;
    cout << "-----REGISTRO DE EVALUANDOS-----" << endl;
    cout << "Tareas entregadas: ";
    cin >> entero;
    captura = eval.fijaNumTareas(entero);
    mensajeCaptura(captura);
    i = 0;
    while (i<TOTAL_ACTIVIDADES) {
        cout << "Calificacion Actividad " << i+1 << ": ";
        cin >> real;
        captura = eval.fijaCalifActividades(i,real);
        mensajeCaptura(captura);
        i++;
    }
    i=0;
    while ( i<TOTAL_EXAMENES) {
        cout << "Calificacion Examen " << i+1 << ": ";
        cin >> real;
        captura = eval.fijaCalifExamenes(i,real);
        mensajeCaptura(captura);
        i++;
    }
    cout << endl << "Tareas entregadas: " << eval.dameNumTareas() << endl;
    for (i = 0; i<TOTAL_ACTIVIDADES; i++) {
        cout << "Calificacion Actividad " << i+1 << ": ";
        cout << eval.dameCalifActividad(i) << endl;
    }
    for (i=0; i<TOTAL_EXAMENES; i++) {
        cout << "Calificacion Examen " << i+1 << ": ";
        cout << eval.dameCalifExamenes(i) << endl;
    }
    cin.ignore();
    pausar();
}

void calculaResultados(ControlAsistencia &control, Evaluacion &eval)
{
    int i;
    puntosTareas = ((float)eval.dameNumTareas() * PORC_TAREAS / C_100) * TOTAL_TAREAS;
    califActividades = 0;
    for(i = 0; i < TOTAL_ACTIVIDADES; i ++)
    {
        califActividades += eval.dameCalifActividad(i);
    }
    puntosActividades = (califActividades * PORC_ACTIVIDADES / C_100) / TOTAL_ACTIVIDADES;
    califExamenes = 0;
    for(i = 0; i < TOTAL_EXAMENES; i ++)
    {
        califExamenes += eval.dameCalifExamenes(i);
    }
    puntosExamenes =(califExamenes * PORC_EXAMENES / C_100)/TOTAL_EXAMENES;
    totalAsistencias = ((TOTAL_ASISTENCIAS) - ((float)control.dameNumeroFaltas() +
                    ((float)control.dameNumeroRetardos() / RETARDOS_POR_FALTA)));
    porcentajeAsistencia = (totalAsistencias * C_100) / TOTAL_ASISTENCIAS;
    calificacionFinal = puntosTareas + puntosActividades + puntosExamenes;
}

void imprimeResultados()
{
    bool derecho;
    bool aprobado;
    derecho = (porcentajeAsistencia >= ASISTENCIA_MINIMA)? true: false;
    aprobado = (calificacionFinal >= CALIF_MINIMA)? true: false;
    system(CLEAR);
    cout << "-----EVALUACION FINAL-----" << endl << endl;
    cout << "Tareas\tActividades\tEx\xA0menes" << endl;
    cout << setiosflags(ios::fixed);
    cout << setprecision(2) << puntosTareas<<"\t";
    cout << setprecision(2) <<puntosActividades;
    cout <<"\t\t" << setprecision(2) <<puntosExamenes<<endl;
    cout <<"Total de asistencias      =   " << setprecision(2) << setw(7) << totalAsistencias;
    cout << endl;
    cout <<"Porcentaje de asistencias =   " << setprecision(2) << setw(7) << porcentajeAsistencia;
    derecho? cout << " Tiene derecho": cout << " No tiene derecho";
    cout <<  endl;
    cout <<"Calificaci\xA2n Final        =   " <<setprecision(2) << setw(7) << calificacionFinal;
    cout << " Calificaci\xA2n ";
    aprobado? cout << "aprobatoria" : cout << "no aprobatoria";
    cout << endl;
    cout << "Alumn@";
    (derecho && aprobado)? cout << " aprobad@" : cout << " no aprobad@";
    cout << endl;
    pausar();
}

void gestionaMateria() {
    Materia mat;
    // Declaracion de variables
    string cadena;
    int entero;
    bool captura;
    system(CLEAR);
    cout << "-----GESTION DE MATERIA-----" << endl << endl;
    cout << "Datos de la materia..." << endl;
    cin.ignore();
    cout << "Nombre: ";
    getline(cin, cadena);
    captura = mat.fijaNombre(cadena);
    mensajeCaptura(captura);
    cout << "Acronimo: ";
    getline(cin, cadena);
    captura = mat.fijaAcronimo(cadena);
    mensajeCaptura(captura);
    cout << "Profesor: ";
    getline(cin, cadena);
    captura = mat.fijaProfesor(cadena);
    mensajeCaptura(captura);
    cout << "Dias de la semana: ";
    getline(cin, cadena);
    captura = mat.fijaDiasSemana(cadena);
    mensajeCaptura(captura);
    cout << "Hora de inicio: ";
    cin >> entero;
    captura = mat.fijaHoraInicio(entero);
    mensajeCaptura(captura);
    cout << "Hora de salida: ";
    cin >> entero;
    captura = mat.fijaHoraFinal(entero);
    mensajeCaptura(captura);
    cout << endl << endl;
    cout << "Nombre: " << mat.dameNombreMateria() << endl;
    cout << "Acronimo: " << mat.dameAcronimo() << endl;
    cout << "Profesor: " << mat.dameProfesor() << endl;
    cout << "Dias de clase: " << mat.dameDiasSemana() << endl;
    cout << "Hora de inicio: " << mat.dameHoraInicio() << endl;
    cout << "Hora de salida: " << mat.dameHoraFinal() << endl << endl;
    cin.ignore();
    pausar();
}

void gestionaTarea() {
    Tarea tarea;
    // Declaracion de variables
    string cadena;
    bool captura;
    system(CLEAR);
    cout << "-----GESTION DE TAREA-----" << endl << endl;
    cin.ignore();
    cout << "Materia: ";
    getline(cin, cadena);
    captura = tarea.fijaMateria(cadena);
    mensajeCaptura(captura);
    cout << "Asunto: ";
    getline(cin, cadena);
    captura = tarea.fijaAsunto(cadena);
    mensajeCaptura(captura);
    cout << "Descripcion: ";
    getline(cin, cadena);
    captura = tarea.fijaDescripcion(cadena);
    mensajeCaptura(captura);
    cout << "Fecha de entrega: ";
    getline(cin, cadena);
    captura = tarea.fijaFechaEntrega(cadena);
    mensajeCaptura(captura);
    cout << endl << endl;
    cout << "Asunto: " << tarea.dameAsunto() << endl;
    cout << "Materia: " << tarea.dameMateria() << endl;
    cout << "Descripcion: " << tarea.dameDescripcion() << endl;
    cout << "Fecha de entrega: " << tarea.dameFechaEntrega() << endl << endl;
    pausar();
}

void gestionaAgenda() {
    Recordatorio record;
    // Declaracion de variables
    string cadena;
    bool captura;
    char caracter;
    int entero;
    int hora;
    system(CLEAR);
    cout << "-----DATOS DEL RECORDATORIO-----" << endl << endl;
    cin.ignore();
    cout << "Asunto: "    ;
    getline(cin,cadena);
    captura = record.fijaAsunto(cadena);
    mensajeCaptura(captura);
    cout << "Tipo de recordatorio (n = normal, i = importante): ";
    cin >> caracter;
    captura = record.fijaTipo(caracter);
    mensajeCaptura(captura);
    cin.ignore();
    cout << "Fecha: ";
    getline(cin,cadena);
    captura = record.fijaFecha(cadena);
    mensajeCaptura(captura);
    cout << "Hora: ";
    cin >> entero;
    captura = record.fijaHora(entero);
    mensajeCaptura(captura);
    cout << endl << endl;
    cout << "Asunto: " << record.dameAsunto() << endl;
    cout << "Tipo de recordatorio: " << record.dameTipo() << endl;
    cout << "Fecha: " << record.dameFecha() << endl;
    hora = record.dameHora();
    cout << "Hora: " << (hora >= 10)? cout << hora << ":00" << endl:
         cout << "0" << hora << ":00" << endl;
    cout << endl;
    cin.ignore();
    pausar();
}

void gestionaNotas() {
    AdminNotas admin;
    // Declaracion de variables
    string cadena;
    bool captura;
    int i;
    system(CLEAR);
    cout << "-----CAPTURA DE NOTAS-----" << endl << endl;
    cin.ignore();
    for (i = 1; i <= TOTAL_NOTAS; i++) {
        cout << "Descripcion de la nota " << i << ": ";
        getline(cin,cadena);
        captura = admin.fijaNota(i,cadena);
        mensajeCaptura(captura);
    }
    cout << endl << endl;
    for (i = 1; i <= TOTAL_NOTAS; i++) {
        cout << "Descripcion Nota " << i << ": ";
        cout << admin.dameNota(i) << endl;
    }
    pausar();
}

void mensajeCaptura (bool capturax) {
    if (capturax) {
        cout << "\r...Dato introducido exitosamente..." << endl;
    } else {
        cout << "...El dato no se guard\xA2..." << endl;
    }
}
void pausar(){
    cout << endl << "Presione ENTER para continuar...";
    cin.ignore();
}

#endif // OTROCODIGO_H_INCLUDED
