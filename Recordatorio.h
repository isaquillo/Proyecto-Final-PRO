#ifndef RECORDATORIO_H
#define RECORDATORIO_H
#include <iostream>
#define PRIMERA_HORA_INICIO 7
#define ULTIMA_HORA_INICIO 19
#define PRIMERA_HORA_FINAL 9
#define ULTIMA_HORA_FINAL 21

using namespace std;

class Recordatorio
{
    public:
        Recordatorio();
        virtual ~Recordatorio();
    bool fijaAsunto(string val)
    {
        asunto = val;
        return true;
    }
    bool fijaTipo(char val)
    {
        tipo = val;
        return true;
    }
    bool fijaFecha(string val)
    {
        fecha = val;
        return true;
    }
    bool fijaHora(int val)
    {
        if (val >= PRIMERA_HORA_INICIO && val <= ULTIMA_HORA_INICIO)
        {
            hora = val;
            return true;
        }
        return (val >= PRIMERA_HORA_INICIO && val <= ULTIMA_HORA_INICIO);

    }
    string dameAsunto()
    {
        return asunto;
    }
    char dameTipo()
    {
        return tipo;
    }
    string dameFecha()
    {
        return fecha;
    }
    int dameHora()
    {
        return hora;
    }
    protected:
    private:
        string asunto;
    char tipo;
    string fecha;
    int hora;
};

#endif // RECORDATORIO_H
