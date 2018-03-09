#include <iostream>
#include "Trabajador.h"
#define LNG 10
#include <stdlib.h>

using namespace std;

int menu()
{
    int opcion = 0;
    system("cls");
    cout << "1. Agregar trabajador a la lista\n";
    cout << "2. Buscar y mostrar datos del trabador\n";
    cout << "3. Mostrar lista\n";
    cout << "4. Salir\n";
    cout << "Ingresar opcion: ";
    cin  >> opcion;
    return opcion;
}

Trabajador *guardarTrabajador()
{
    int codigo = 0;
    char nombre[LNG];
    float sueldo;
    cout << "Ingresar codigo: ";
    cin >> codigo;
    cout << "Ingresar nombre: ";
    cin >> nombre;
    cout << "Ingresar sueldo: ";
    cin >> sueldo;
    Trabajador *employee;
    employee = new Trabajador(codigo, nombre, sueldo);
    return employee;
}

int posicionTrabajador(Trabajador *employee[], int codigo)
{
    bool matched = false;
    int length = LNG, index = 0, indicator = -1;
    while(!matched && index < length)
    {
        if(employee[index]->getCodigoTrabajador() == codigo)
        {
            indicator = index;
            matched = !matched;
        }
        else
        {
            index++;
        }
    }
    return indicator;
}

void mostrarTrabajadorEncontrado(Trabajador *employee[], int position)
{
    cout << "----------------------------------------------\n";
    cout << "Codigo de trabajado: " << employee[position]->getCodigoTrabajador() << endl;
    employee[position]->mostrarNombreTrabajador();
    cout << "\nSueldo Mensual: " << employee[position]->getSueldoMensual() << endl;
    cout << "Descuento AFP: " << employee[position]->getDescuentoAfp() << endl;
    cout << "Descuento ISSS: " << employee[position]->getDescuentoIsss() << endl;
    cout << "Descuento ISR: " << employee[position]->getDescuentoIsr() << endl;
    cout << "Total a Pagar: " << employee[position]->getTotalPagar() << endl;
    cout << "----------------------------------------------\n";
    system("pause");
}

int main()
{
    int opcion = 0, times = 0;
    int codigo = 0;
    int positionWorker = 0;

    Trabajador *employee[LNG];
    do
    {
        opcion = menu();

        switch(opcion)
        {
        case 1:
            if(times < 10)
            {
                employee[times] = guardarTrabajador();
                times++;
            }
            else
            {
                cout << "No se pueden almacenar mas objetos porque la lista esta llena\n";
                system("pause");
            }
            break;
        case 2:
            cout << "Ingresar codigo de trabajador: ";
            cin >> codigo;
            positionWorker =  posicionTrabajador(employee, codigo);
            if(positionWorker == -1)
            {
                cout << "Trabajador no encontrado\n";
                system("pause");
            }
            else
            {
                mostrarTrabajadorEncontrado(employee, positionWorker);
            }
            //cout << "Posicion: " << positionWorker;
            break;
        case 3:
            for(int i=0; i < times; i++)
            {
                cout << "----------------------------------------------\n";
                cout << "Codigo de trabajado: " << employee[i]->getCodigoTrabajador() << endl;
                employee[i]->mostrarNombreTrabajador();
                cout << "\nSueldo Mensual: " << employee[i]->getSueldoMensual() << endl;
                cout << "----------------------------------------------\n";
            }
            system("pause");
            break;
        default:
            cout << "Opcion no valida\n";
            system("pause");
        }


    } while(opcion!=4);

    return 0;
}
