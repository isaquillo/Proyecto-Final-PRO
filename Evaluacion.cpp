#include "Evaluacion.h"

#define TOTAL_ACTIVIDADES 9
#define TOTAL_EXAMENES 3

Evaluacion::Evaluacion()
{
    int i;
    numTareas = 0;
    for (i=0; i<TOTAL_ACTIVIDADES; i++)
    {
    	califActividades[i] = 0;
    }
    for (i=0; i<TOTAL_EXAMENES; i++)
    {
    	califExamenes[i] = 0;
    }
}

Evaluacion::~Evaluacion()
{
    //dtor
}

