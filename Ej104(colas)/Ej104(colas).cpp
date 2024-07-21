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
void Agregar(Nodo*& Fte, Nodo*& Fin, Producto& Rinfo)
{
	Nodo* puntero = new Nodo();
	puntero->info = Rinfo;
	puntero->sig = NULL;
	if (Fte == NULL) {
		Fte = puntero;
	}
	else
	{
		Fin->sig = puntero;
	}
	Fin = puntero;
}
void Suprimir(Nodo*& Fte, Nodo*& Fin, Producto& Rinfo)
{
	Nodo* puntero = Fte;
	Rinfo = puntero->info;
	Fte = Fte->sig;
	delete puntero;
	if (Fte == NULL) {
		Fin = NULL;
	}
}
void LllenarCola(Nodo*& Fte, Nodo*& Fin, Producto& RProd, int& n) {
	cout << "Ingrese el codigo del producto (0 para cortar)" << endl;
	cin >> RProd.codigo;
	while (RProd.codigo != 0) {
		n++;
		cout << "Ingrese el precio unitario" << endl;
		cin >> RProd.PrecioUn;
		Agregar(Fte, Fin, RProd);
		cout << "Ingrese el codigo del producto" << endl;
		cin >> RProd.codigo;
	}
}

void VaciareImprimirCola(Nodo*& Fte, Nodo*& Fin, Producto& RProd) {
	cout << "Producto   Precio" << endl;
	while (Fte != NULL) {
		Suprimir(Fte,Fin,RProd);
		cout << " " << RProd.codigo << "    -     " << RProd.PrecioUn << endl;
	}

}

void EjecutarEjercicio(Nodo*& Fte, Nodo*& Fin, int n) {
	Producto RAux, RProd;
	for (int i = 1; i <= n; i++)
	{
		if (i != 4) {
			Suprimir(Fte, Fin, RAux);
			Agregar(Fte, Fin, RAux);
		}
		else
		{
			Suprimir(Fte, Fin, RAux);
		}
	}
	VaciareImprimirCola(Fte, Fin, RProd);
}
int main()
{
	int opcion;
	int n = 0;
	Nodo* FteC = NULL;
	Nodo* FinC = NULL;
	Producto RProd;
	do {

		cout << "------------------------MENU------------------------" << endl;
		cout << "--------Selecciona una opcion(numero)--------" << endl;
		cout << "1- Llenar cola" << endl;
		cout << "2- Vaciar e Imprimir Pila" << endl;
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
			LllenarCola(FteC,FinC, RProd, n);
			break;
		case 2:
			VaciareImprimirCola(FteC, FinC, RProd);
			n = 0;
			break;
		case 3:
			EjecutarEjercicio(FteC, FinC, n);
			n = 0;
			break;
		default:
			cout << "--------opcion invalida, por favor ingrese una opcion valida!--------" << endl;
			break;
		}
	} while (opcion != 0);
}



