#ifndef ADMINNOTAS_H
#define ADMINNOTAS_H

#include "Nota.h"

class AdminNotas
{
    public:
        AdminNotas();
        virtual ~AdminNotas();
        bool fijaNota (int numero, string val){
        switch (numero)
        {
        case 1:
            nota1.fijaDescripcion(val);
            break;
        case 2:
            nota2.fijaDescripcion(val);
            break;
        case 3:
            nota3.fijaDescripcion(val);
            break;
        default:
            ;
        }
        return true;
    }
    string dameNota(int numero)
    {
        string cadena;
        switch (numero)
        {
        case 1:
            cadena = nota1.dameDescripcion();
            break;
        case 2:
            cadena = nota2.dameDescripcion();
            break;
        case 3:
            cadena = nota3.dameDescripcion();
            break;
        default:
            ;
        }
        return cadena;
    }
    protected:
    private:
        Nota nota1;
        Nota nota2;
        Nota nota3;
};

#endif // ADMINNOTAS_H
