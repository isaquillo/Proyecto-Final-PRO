#ifndef TAREA_H
#define TAREA_H

#include <iostream>
#include <cstdlib>

using namespace std;

class Tarea {
public:
    Tarea();
    virtual ~Tarea();

    bool fijaAsunto(string val) {
        asunto = val;
        return true;
    }
    bool fijaDescripcion(string val) {
        descripcion = val;
        return true;
    }
    bool fijaMateria(string val) {
        materia = val;
        return true;
    }
    bool fijaFechaEntrega(string val){
        fechaEntrega = val;
        return true;
    }
    string dameAsunto() {
        return asunto;
    }
    string dameDescripcion() {
        return descripcion;
    }
    string dameMateria() {
        return materia;
    }
    string dameFechaEntrega(){
        return fechaEntrega;
    }
protected:
private:
    string asunto;
    string descripcion;
    string materia;
    string fechaEntrega;
};

#endif // TAREA_H
