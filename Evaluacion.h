#ifndef EVALUACION_H
#define EVALUACION_H

#define TOTAL_ACTIVIDADES 9
#define TOTAL_EXAMENES 3
#define TOTAL_TAREAS 10
#define C_100 100
#define C_0 0


class Evaluacion
{
    public:
        Evaluacion();
        virtual ~Evaluacion();

        bool fijaNumTareas(int val) {
            if (val >= C_0 && val <= TOTAL_TAREAS)
            {
                numTareas = val;
            }
            return (val >= C_0 && val <= TOTAL_TAREAS);
        }

        bool fijaCalifActividades(int x, float val) {
            if (val >= 0 && val <= C_100)
            {
                califActividades[x] = val;
            }
            return (val >= 0 && val <= C_100);
        }

        bool fijaCalifExamenes(int x, float val) {
            if (val >= 0 && val <= C_100)
            {
                califExamenes[x] = val;
            }
            return (val >= 0 && val <= C_100);
        }

        int dameNumTareas()
    {
        return numTareas;
    }
    float dameCalifActividad(int i)
    {
        return califActividades[i];
    }
    float dameCalifExamenes(int i)
    {
        return califExamenes[i];
    }
    protected:
    private:
        int numTareas;
        float califActividades[TOTAL_ACTIVIDADES];
        float califExamenes[TOTAL_EXAMENES];
};

#endif // EVALUACION_H
