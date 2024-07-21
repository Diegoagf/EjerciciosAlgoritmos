#include <iostream>
using namespace std;

struct Producto {
    int codigo;
    float PrecioUn;
};
struct Nodo {
	Producto info;
	Nodo* sig;
};
void Pop(Nodo*& pila, Producto& Rinfo)
{
	Nodo* Npuntero = pila;
	Rinfo = Npuntero->info;
	pila = Npuntero->sig;
	delete Npuntero;
}
void Push(Nodo*& pila, Producto& Rinfo)
{
	Nodo* puntero = new Nodo();
	puntero->info = Rinfo;
	puntero->sig = pila;
	pila = puntero;
}
void LllenarPila(Nodo*& pila, Producto& RProd,int& n) {
	cout << "Ingrese el codigo del producto (0 para cortar)" << endl;
	cin >> RProd.codigo;
	while (RProd.codigo != 0) {
		n++;
		cout << "Ingrese el precio unitario" << endl;
		cin >> RProd.PrecioUn;
		Push(pila, RProd);
		cout << "Ingrese el codigo del producto" << endl;
		cin >> RProd.codigo;
	}
}

void VaciareImprimirPila(Nodo*& pila, Producto& RProd){
	cout << "Producto   Precio" << endl;
	while (pila != NULL) {
		Pop(pila, RProd);
		cout << " " << RProd.codigo << "    -     " << RProd.PrecioUn << endl;
	}

}

void EjecutarEjercicio(Nodo*pila, int n) {
	Nodo* pilaAux = NULL;
	Producto RAux, RProd;
	
	for (int i = n; i >4; i--)
	{		
		Pop(pila, RAux);
		Push(pilaAux, RAux);
	}
	if (n > 4) {
		Pop(pila, RAux);
	}
	while (pilaAux!=NULL)
	{
		Pop(pilaAux, RAux);
		Push(pila, RAux);
	}

	VaciareImprimirPila(pila, RProd);
}
int main()
{
	int opcion;
	int n = 0;
	Nodo* pila = NULL;
	Producto RProd;
	do {

		cout << "------------------------MENU------------------------" << endl;
		cout << "--------Selecciona una opcion(numero)--------" << endl;
		cout << "1- Llenar Pila" << endl;
		cout << "2- Desapilar e Imprimir Pila" << endl;
		cout << "3-Ejecutar Ejercicio" << endl;
		cout << "0- Salir" << endl;
		cin >> opcion;

		switch (opcion)
		{
		case 0:
			cout << "--------Hasta Luego--------" << endl;
			cout << "--------Fin del Programa--------" << endl;
			break;
		case 1:
			LllenarPila(pila, RProd,n);
			break;
		case 2:
			VaciareImprimirPila(pila, RProd);
			break;
		case 3:
			EjecutarEjercicio(pila,n);
			break;
		default:
			cout << "--------opcion invalida, por favor ingrese una opcion valida!--------" << endl;
			break;
		}
	} while (opcion != 0);
}


