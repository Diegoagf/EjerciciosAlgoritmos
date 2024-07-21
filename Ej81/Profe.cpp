#define _CRT_SECURE_NO_DEPRECATE 
#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

struct tVuelof {
    int codigo;
    int pasajesDisponibles;
};

struct tVueloV {
    int codigo;
    int pasajesDisponibles;
    int pasajesRechazados;
};

struct tPedido {
    int dni;
    int codigo;
    int pasajesSolicitados;
};

void generarArchivoVuelos()
{
    tVuelof rvuelos;
    FILE* f = fopen("Vuelos.dat", "wb");

    cout << "Ingrese el codigo (0 para cortar)" << endl;
    cin >> rvuelos.codigo;
    while (rvuelos.codigo != 0)
    {
        cout << "Ingrese la cantidad de pasajes disponibles: " << endl;
        cin >> rvuelos.pasajesDisponibles;
        fwrite(&rvuelos, sizeof(rvuelos), 1, f);   // write(RDest,aDest)
        cout << "Ingrese el codigo (0 para cortar)" << endl;
        cin >> rvuelos.codigo;
    }
    fclose(f);
}

void generarArchivoPedidos()
{
    tPedido pedido;

    FILE* f = fopen("Pedidos.dat", "wb");

    cout << "Ingrese el codigo (0 para cortar)" << endl;
    cin >> pedido.codigo;
    while (pedido.codigo != 0)
    {
        cout << "Ingrese la cantidad de pasajes solicitados: " << endl;
        cin >> pedido.pasajesSolicitados;
        cout << "Ingrese el DNI " << endl;
        cin >> pedido.dni;
        fwrite(&pedido, sizeof(pedido), 1, f);   // write(RDest,aDest)
        cout << "Ingrese el codigo (0 para cortar)" << endl;
        cin >> pedido.codigo;
    }
    fclose(f);
}

void leerArchivoPedidos()
{
    FILE* f = fopen("Pedidos.dat", "rb");
    tPedido pedido;
    if (f == NULL) {
        cout << "ERROR! No existe el archivo" << endl;
        return;
    }
    fread(&pedido, sizeof(pedido), 1, f);
    while (!feof(f))
    {
        cout << "Codigo: " << pedido.codigo << endl;
        cout << "DNI: " << pedido.dni << endl;
        cout << "Pasajes solicitados: " << pedido.pasajesSolicitados << endl;
        fread(&pedido, sizeof(pedido), 1, f);
    }
    fclose(f);
}

void leerArchivoVuelos()
{
    FILE* f = fopen("Vuelos.dat", "rb");
    tVuelof rvuelos;
    if (f == NULL) {
        cout << "ERROR! No existe el archivo" << endl;
        return;
    }
    fread(&rvuelos, sizeof(rvuelos), 1, f);
    while (!feof(f))
    {
        cout << "Codigo: " << rvuelos.codigo << endl;
        cout << "Pasajes disponibles: " << rvuelos.pasajesDisponibles << endl;
        fread(&rvuelos, sizeof(rvuelos), 1, f);
    }
    fclose(f);
}

int cargarVuelos(tVueloV vuelos[])
{
    FILE* f = fopen("Vuelos.dat", "rb");
    tVuelof rvuelo;
    int i = 0;
    if (f == NULL) {
        cout << "ERROR! No existe el archivo" << endl;
        return 1;
    }

    fread(&rvuelo, sizeof(rvuelo), 1, f);//Cargo los vuelos
    while (!feof(f))
    {
        vuelos[i].codigo = rvuelo.codigo;
        vuelos[i].pasajesDisponibles = rvuelo.pasajesDisponibles;
        vuelos[i].pasajesRechazados = 0;
        fread(&rvuelo, sizeof(rvuelo), 1, f);
        i++;
    }
    /* otra forma más corta de cargar directamente adentro del vector sin registro auxiliar
    while (fread (&vuelos[i], sizeof (vuelos[i]), 1, f))
    {
        i++;
    }*/
    fclose(f);
    return i;
}

void ordenoVuelos(tVueloV vuelos[], int cantidad)
{
    int pas = 1;
    bool ordenado = false;
    tVueloV rvueloAux;
    while (!ordenado)
    {
        ordenado = true;

        for (int i = 0; i <= cantidad - pas - 1; i++)
        {
            if (vuelos[i].codigo > vuelos[i + 1].codigo)
            {
                rvueloAux = vuelos[i];
                vuelos[i] = vuelos[i + 1];
                vuelos[i + 1] = rvueloAux;
                ordenado = false;
            }
        }
        pas++;
    }
}

void buscarVueloBinaria(tPedido pedido, tVueloV vuelos[], int n, int& posicion)
{

    int i = 0;
    int ti = 0;
    int tf = n - 1;
    int tm = (ti + tf) / 2;
    while (ti <= tf && (vuelos[tm].codigo != pedido.codigo))
    {

        if (vuelos[tm].codigo > pedido.codigo)
        {
            tf = tm - 1;
        }
        else
        {
            ti = tm + 1;
        }
        tm = (ti + tf) / 2;
    }
    if (ti > tf)
    {
        posicion = -1;
    }
    else
    {
        posicion = tm;
    }

}

bool buscarVuelo(tPedido pedido, tVuelof vuelos[], int cantidad, int& posicion)
{
    bool retorno = false;
    int i = 0;
    while (i < cantidad)
    {

        if (pedido.codigo == vuelos[i].codigo)
        {
            posicion = i;
            i = cantidad;
            retorno = true;

        }

        else
            i++;
    }
    return retorno;

}
void analizoPedidos(tVueloV vuelos[], int n)
{
    FILE* f = fopen("Pedidos.dat", "rb");
    tPedido rpedido;
    tVueloV vuelo;
    bool encontro;
    int posicion = 0;

    while (fread(&rpedido, sizeof(rpedido), 1, f))
    {
        cout << "Procesando el pedido, Vuelo: " << rpedido.codigo << " Cant. solicitada: " << rpedido.pasajesSolicitados << endl;

        buscarVueloBinaria(rpedido, vuelos, n, posicion);

        if (posicion != -1)
        {
            if (rpedido.pasajesSolicitados > vuelos[posicion].pasajesDisponibles)
            {
                cout << "Pedido Rechazado, pasajes solicitados para el vuelo " << rpedido.codigo << " mayor a los " << vuelos[posicion].pasajesDisponibles << " disponibles " << endl;
                vuelos[posicion].pasajesRechazados += rpedido.pasajesSolicitados;
            }
            else
            {
                cout << "DNI: " << rpedido.dni << " , pasajes vendidos: " << rpedido.pasajesSolicitados << " , codigo: " << rpedido.codigo << endl;
                vuelos[posicion].pasajesDisponibles -= rpedido.pasajesSolicitados;
            }
        }
        else
        {
            cout << "No se encontro el codigo de vuelo " << rpedido.codigo << endl;
        }
    }
    cout << endl;
    fclose(f);
}


void imprimoVuelos(tVueloV vuelos[], int cantidad)
{
    cout << "ESTADO FINAL DE LOS VUELOS " << endl;
    cout << "Codigo de Vuelo          " << "Pasajes Disponibles           " << "Pasajes no vendidos          " << endl;
    for (int cont = 0; cont < cantidad; cont++)
    {
        cout << vuelos[cont].codigo << "                        " << vuelos[cont].pasajesDisponibles << "                               " << vuelos[cont].pasajesRechazados << endl;
    }
    cout << endl;
}


// ++++++++ MAIN +++++++++

int main()
{
    tVueloV vuelos[500];
    int opcion;
    int cantidad = 0;
    int c;

    do {
        cout << "Ingrese la opcion deseada" << endl;
        cout << "1) Generar y mostrar archivo vuelos" << endl;
        cout << "2) Generar archivo pedidos" << endl;
        cout << "3) Analizar los pedidos" << endl;
        cout << "4) Leer archivo pedidos" << endl;
        cout << "5) Leer archivo vuelos" << endl;
        cout << "0) Salir" << endl;
        cin >> opcion;

        switch (opcion) {
        case 0:
            cout << "Muchas gracias por utilizar el programa" << endl;
            break;
        case 1:
            generarArchivoVuelos();
            leerArchivoVuelos();
            break;
        case 2:
            generarArchivoPedidos();
            leerArchivoPedidos;
            break;
        case 3:
            cantidad = cargarVuelos(vuelos);
            ordenoVuelos(vuelos, cantidad);
            // si quiero ver el vector ordenado - imprimoVuelos(vuelos,cantidad);
            analizoPedidos(vuelos, cantidad);
            imprimoVuelos(vuelos, cantidad);
            break;
        case 4:
            leerArchivoPedidos();
            break;
        case 5:
            leerArchivoVuelos();
            break;
        default:
            cout << "ERROR! La opcion seleccionada es invalida" << endl;
            break;
        }
    } while (opcion != 0);
    return 0;
}