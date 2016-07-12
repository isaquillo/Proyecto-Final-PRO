#ifndef CONTROLASISTENCIA_H
#define CONTROLASISTENCIA_H

#define TOTAL_ASISTENCIAS 34

class ControlAsistencia
{
    public:
        ControlAsistencia();
        virtual ~ControlAsistencia();
        
        bool fijaNumeroFaltas(int val) { 
            if (val >=0 && val <= TOTAL_ASISTENCIAS)
            {
                numeroFaltas = val;
            }
            return (val >=0 && val <= TOTAL_ASISTENCIAS);
        }
        bool fijaNumeroRetardos(int val) 
        { 
            if (val >=0 && val <= TOTAL_ASISTENCIAS)
            {
                numeroRetardos = val;  
            }
            return (val >=0 && val <= TOTAL_ASISTENCIAS); 
        }
        int dameNumeroFaltas() { return numeroFaltas; }
        int dameNumeroRetardos() { return numeroRetardos; }
    protected:
    private:
        int numeroFaltas;
        int numeroRetardos;
};

#endif // CONTROLASISTENCIA_H
