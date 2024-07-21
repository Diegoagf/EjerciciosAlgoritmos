
#include <iostream>
using namespace std;

struct tprod {
    int Codp;
    float PU;
};

struct Nodo
{
    tprod info;
    Nodo* sig;
};
void Agregar(Nodo*& Fte, Nodo*& Fin, tprod& Rinfo)
{
    Nodo* puntero = new Nodo();
    puntero->info = Rinfo;
    puntero->sig = NULL;
    if (Fte == NULL) {
        Fte = puntero;
    }
    else
    {
        Fin->sig= puntero;
    }
    Fin = puntero;
}
void Suprimir(Nodo*& Fte, Nodo*& Fin, tprod& Rinfo)
{
    Nodo* puntero = Fte;
    Rinfo = puntero->info;
    Fte = Fte->sig;
    delete puntero;
    if (Fte == NULL) {
        Fin = NULL;
    }
}
int main()
{
    Nodo* Fte = NULL;
    Nodo* Fin = NULL;
    tprod RProd;
    cout << "Ingrese el codigo del producto (0 para cortar)" << endl;
    cin >> RProd.Codp;
    while (RProd.Codp != 0) {
        cout << "Ingrese el precio unitario" << endl;
        cin >> RProd.PU;
        Agregar(Fte, Fin, RProd);
        cout << "Ingrese el codigo del producto" << endl;
        cin >> RProd.Codp;
    }

    cout << "Producto  Precio" << endl;
    //IMPRESIÓN DE LA COLA - SE LA DESCUELGA HASTA NULL
    while (Fte != NULL) {
        Suprimir(Fte, Fin, RProd);
        cout << " " << RProd.Codp << " - " << RProd.PU << endl;
    }


}
