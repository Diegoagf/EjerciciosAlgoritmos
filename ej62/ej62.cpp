#include <iostream>
using namespace std;


struct TProd{
    int cod;
    float Pu;
    int CantVen;
};
int BuscarPos(TProd Vprod[], int cod) {
    int pos = 0;
    while (cod != Vprod[pos].cod) {
        pos++;
    }
    return pos;
}
int main()
{
    TProd Vprod[4];
    int codigo, i, cantidad, pos, j;
    float total;
    for (i = 0; i < 4; i++) {
        cout << "Ingrese el codigo del producto" << endl;
        cin >> Vprod[i].cod;
        cout << "Ingrese el Precio unitario del producto" << endl;
        cin >> Vprod[i].Pu;
        Vprod[i].CantVen = 0;
    }
    cout << "-------VENTAS-------------" << endl;
    cout << "Ingrese el codigo del producto(0 para cortar)" << endl;
    cin >> codigo;
    while (codigo != 0) {
        cout << "Igrese la cantidad vendida" << endl;
        cin >> cantidad;
        pos = BuscarPos(Vprod, codigo);
        total = Vprod[pos].Pu * cantidad;
        cout << "-------VENTA REALIZADA------------" << endl;
        cout << "codigo de producto: " << codigo << endl;
        cout << "Total a Abonar: " << total << endl;
        Vprod[pos].CantVen = Vprod[pos].CantVen + cantidad;
        cout << "Ingrese el codigo del producto(0 para cortar)" << endl;
        cin >> codigo;
    }

    for (j = 0; j < 4; j++) {
        cout << "El total de unidades vendidas del producto " << Vprod[j].cod << " fue de " << Vprod[j].CantVen << endl;
    }
}