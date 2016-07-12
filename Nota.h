#ifndef NOTA_H
#define NOTA_H

#include <iostream>
#include <cstdlib>

using namespace std;

class Nota
{
    public:
        Nota();
        virtual ~Nota();
        bool fijaDescripcion (string val)
    {
        descripcion = val;
        return true;
    };
    string dameDescripcion()
    {
        return descripcion;
    }
    protected:
    private:
        string descripcion;
};

#endif // NOTA_H
