#include <iostream>
using namespace std;

struct tVuelo {       //necesito este vector para cargar los datos más un campo para acumular rechazos
    int CodVuelo;
    int CantPasDis;
    int PasNoVend;
};

struct tPedido {       //no es necesario este registro; sería sólo una cuestión organizativa
    int CodVuelo;
    int CantPasSol;
};

void BuscarenVec(tVuelo vvuelos[], int CodVuelo, int& pos) {
    pos = 0;
    //   while(pedidos.CodVuelo.compare(vuelos[pos].CodVuelo) != 0){    si el cod de vuelo fuese de tipo cadena de caracteres
    while (vvuelos[pos].CodVuelo != CodVuelo) {
        pos++;
    };
};

int BuscarPasaje(tVuelo vvuelos[], int cod, int n) {
    int pos;
    for ( pos= 0; pos <= n-1; pos++)
    {
        if (cod == vvuelos[pos].CodVuelo)
        {
            return pos;
        }
    }
    return -1;
}

// Este BuscarenVec2 es por si hay que considerar que el elemento a buscar puede no estar
// en este ejercicio no es necesario ya que el usuario ingresa pedidos de vuelos existentes
void BuscarenVec2(tVuelo vvuelos[], int n, int CodVuelo, int& pos) {
    pos = 0;
    while ((vvuelos[pos].CodVuelo != CodVuelo) && (pos < n)) {
        pos++;
    };
    if (pos == n) {
        pos = -1;    // -1 como señal de no encontrado 
    }
};

//En este caso se recibe todo el vector como parámetro aunque se trabajará con una sola posición
void AnalizarDisponibilidad(tPedido Rpedido, tVuelo vvuelo[], int pos) {
    if (Rpedido.CantPasSol <= vvuelo[pos].CantPasDis) {
        cout << "--INFORMACION DE LA VENTA--" << endl;
        cout << "Cod de vuelo: " << Rpedido.CodVuelo << endl;
        cout << "Pasajes vendidos: " << Rpedido.CantPasSol << endl;
        vvuelo[pos].CantPasDis = vvuelo[pos].CantPasDis - Rpedido.CantPasSol;
    }
    else {
        cout << "-- No hay suficientes pasajes para dicho vuelo --" << endl;
        vvuelo[pos].PasNoVend = vvuelo[pos].PasNoVend + Rpedido.CantPasSol;
    }

};

//En este otro caso se recibe sólo el REGISTRO de la posición del vector con la que se trabajará
void AnalizarDisponibilidad2(tPedido Rpedido, tVuelo& Rvuelo) {
    if (Rpedido.CantPasSol <= Rvuelo.CantPasDis) {
        cout << "--INFORMACION DE LA VENTA--" << endl;
        cout << "Cod de vuelo: " << Rpedido.CodVuelo << endl;
        cout << "Pasajes vendidos: " << Rpedido.CantPasSol << endl;
        Rvuelo.CantPasDis = Rvuelo.CantPasDis - Rpedido.CantPasSol;
    }
    else {
        cout << "-- No hay suficientes pasajes para dicho vuelo --" << endl;
        Rvuelo.PasNoVend = Rvuelo.PasNoVend + Rpedido.CantPasSol;
    }

};

void Informes(tVuelo vvuelos[], int n) {
    int i;
    cout << "--- LISTADO ---" << endl;
    for (i = 0; i <= n - 1; i++) {
        cout << endl;
        cout << endl;
        cout << "CODIGO DE VUELO: " << vvuelos[i].CodVuelo << endl;
        cout << "Pasajes disponibles: " << vvuelos[i].CantPasDis << endl;
        cout << "Pasajes no vendidos: " << vvuelos[i].PasNoVend << endl;
        cout << "------------------------" << endl;
    };
}

int main() {
    tVuelo vvuelos[500];
    tPedido Rpedido;
    int i, pos, n;

    cout << "Ingrese cantidad de vuelos" << endl;
    cin >> n;
    cout << "--INFORMACION DE LOS VUELOS--" << endl;
    for (i = 0; i <= n - 1; i++) {
        cout << "Ingrese el codigo de vuelo: ";
        cin >> vvuelos[i].CodVuelo;
        cout << "Cantidad de pasajes disponibles: ";
        cin >> vvuelos[i].CantPasDis;
        vvuelos[i].PasNoVend = 0;
    };
    cout << "---------------------" << endl;


    cout << "--VENTA DE PASAJES--" << endl;
    cout << "Ing el codigo de vuelo deseado: ";
    cin >> Rpedido.CodVuelo;
    while (Rpedido.CodVuelo != 0) {
        cout << "Ingr la cant de pasajes solicit: ";
        cin >> Rpedido.CantPasSol;
        BuscarenVec(vvuelos, Rpedido.CodVuelo, pos);  //normalmente se pasa el n del vector pero acá no es necesario porque encuentra seguro el dato 
  //      BuscarenVec2(vvuelos,n,Rpedido.CodVuelo,pos);
  //      if pos == 1 quiere decir que no lo encontró
         /*pos = BuscarPasaje(vvuelos, Rpedido.CodVuelo,n);*/
        AnalizarDisponibilidad2(Rpedido, vvuelos[pos]);    //sólo paso esa pos del vector QUE ES UN REGISTRO 
  //      AnalizarDisponibilidad(Rpedido,vvuelos,pos);     //paso todo el vector (no es necesario ya que voy a trabajar con la posic pos)
        cout << "---------------------" << endl;;
        cout << "Ing el codigo de vuelo deseado: ";
        cin >> Rpedido.CodVuelo;
    };

    Informes(vvuelos, n);

    cout << "---------FIN DEL PROGRAMA---------";
    return 0;
}