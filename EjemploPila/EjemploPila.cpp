
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
void Pop(Nodo*& pila, tprod& Rinfo)
{
    Nodo* Npuntero = pila;
    Rinfo = Npuntero->info;
    pila = Npuntero->sig;
    delete Npuntero;
}
void Push(Nodo*& pila, tprod& Rinfo)
{
    Nodo* puntero = new Nodo();
    puntero->info = Rinfo;
    puntero->sig = pila;
    pila = puntero;
}
int main()
{
    Nodo* pila = NULL;
    tprod RProd;
    cout << "Ingrese el codigo del producto (0 para cortar)" << endl;
    cin >> RProd.Codp;
    while (RProd.Codp!=0) {
        cout << "Ingrese el precio unitario" << endl;
        cin >> RProd.PU;
        Push(pila, RProd);
        cout << "Ingrese el codigo del producto" << endl;
        cin >> RProd.Codp;
    }

    cout << "Producto  Precio" << endl;
    while (pila != NULL) {
        Pop(pila, RProd);
        cout << " " << RProd.Codp << " - " << RProd.PU << endl;
    }


}
