#ifndef TRABAJADOR_H_INCLUDED
#define TRABAJADOR_H_INCLUDED
#define LNG 10
#include <string.h>
#include <iostream>
using namespace std;

class Trabajador
{
    private:
        int codigoTrabajador;
        char nombreTrabajador[LNG];
        float sueldoMensual;
        float descuentoIsss;
        float descuentoAfp;
        float descuentoIsr;
        float totalPagar;
    public:
        Trabajador(int, char[],float);
        int getCodigoTrabajador();
        void mostrarNombreTrabajador();
        float getSueldoMensual();
        float getDescuentoIsss();
        float getDescuentoAfp();
        float getDescuentoIsr();
        float getTotalPagar();
};


#endif // TRABAJADOR_H_INCLUDED
