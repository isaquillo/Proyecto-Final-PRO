#ifndef MATERIA_H
#define MATERIA_H

#include <iostream>
#include <cstdlib>

#define PRIMERA_HORA_INICIO 7
#define ULTIMA_HORA_INICIO 19
#define PRIMERA_HORA_FINAL 9
#define ULTIMA_HORA_FINAL 21

using namespace std;

class Materia {
public:
    Materia();
    virtual ~Materia();
    bool fijaNombre(string val) {
        nombreMateria = val;
        return true;
    }
    bool fijaAcronimo(string val) {
        acronimo = val;
        return true;
    }
    bool fijaProfesor(string val) {
        profesor = val;
        return true;
    }
    bool fijaDiasSemana(string val) {
        diasSemana = val;
        return true;
    }
    bool fijaHoraInicio(int val){
        if (val >= PRIMERA_HORA_INICIO && val <= ULTIMA_HORA_INICIO)
        {
            horaInicio = val;
        }
        return (val >= PRIMERA_HORA_INICIO && val <= ULTIMA_HORA_INICIO);
    }
    bool fijaHoraFinal(int val){
        if (val >= PRIMERA_HORA_FINAL && val <= ULTIMA_HORA_FINAL)
        {
            horaFinal = val;
        }
        return (val >= PRIMERA_HORA_FINAL && val <= ULTIMA_HORA_FINAL);
    }

    string dameNombreMateria() {
        return nombreMateria;
    }
    string dameAcronimo() {
        return acronimo;
    }
    string dameProfesor() {
        return profesor;
    }
    string dameDiasSemana() {
        return diasSemana;
    }
    int dameHoraInicio(){
        return horaInicio;
    }
    int dameHoraFinal(){
        return horaFinal;
    }
    
protected:
private:
    string nombreMateria;
    string acronimo;
    string profesor;
    string diasSemana;
    int horaInicio;
    int horaFinal;
};

#endif // MATERIA_H
