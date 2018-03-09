#include "Trabajador.h"


Trabajador::Trabajador(int codigo, char nombre[],float sueldo)
{
    this->codigoTrabajador = codigo;
    strcpy(this->nombreTrabajador, nombre);
    this->sueldoMensual = sueldo;

}
int Trabajador::getCodigoTrabajador()
{
    return this->codigoTrabajador;
}
void Trabajador::mostrarNombreTrabajador()
{
    cout << "Nombre de trabajador: " << this->nombreTrabajador;
}
float Trabajador::getSueldoMensual()
{
    return this->sueldoMensual;
}
float Trabajador::getDescuentoIsss()
{
    return this->sueldoMensual * 0.03;
}
float Trabajador::getDescuentoAfp()
{
    return this->sueldoMensual * 0.075;
}
float Trabajador::getDescuentoIsr()
{
    int sueldo = this->sueldoMensual;
    return (sueldo >= 472.01 && sueldo <= 895.24) ? sueldo * 0.1:
            (sueldo >= 895.25 && sueldo <= 2038.1) ? sueldo * 0.2:
            (sueldo > 2038.11) ? sueldo * 0.3:
                0;
}
float Trabajador::getTotalPagar()
{
    return this->sueldoMensual - (this->getDescuentoAfp() + this->getDescuentoIsr() + this->getDescuentoIsss());
}
