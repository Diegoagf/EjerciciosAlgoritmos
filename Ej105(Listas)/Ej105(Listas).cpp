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
void Eliminar1ero(Nodo*& lista, Producto& Rinfo)
{
	Nodo* Npuntero = lista;
	Rinfo = Npuntero->info;
	lista = Npuntero->sig;
	delete Npuntero;
}

void InsertOrd(Nodo*& lista, Producto& RProd) {
	Nodo* pNue = new Nodo();
	pNue->info = RProd;
	if (lista == NULL || pNue->info.codigo < lista->info.codigo)
	{
		pNue->sig = lista;
		lista = pNue;
	}
	else
	{
		Nodo* ptr = lista;
		Nodo* antp{};
		while ((ptr!=NULL) && (pNue->info.codigo>ptr->info.codigo) )
		{
			antp = ptr;
			ptr = ptr->sig;
		}
		antp->sig = pNue;
		pNue->sig = ptr;
	}
	

}
void LllenarLista(Nodo*& lista, Producto& RProd, int& n) {
	cout << "Ingrese el codigo del producto (0 para cortar)" << endl;
	cin >> RProd.codigo;
	while (RProd.codigo != 0) {
		n++;
		cout << "Ingrese el precio unitario" << endl;
		cin >> RProd.PrecioUn;
		InsertOrd(lista, RProd);
		cout << "Ingrese el codigo del producto" << endl;
		cin >> RProd.codigo;
	}
}

void ImprimirLista(Nodo*& lista, Producto& RProd) {
	cout << "Producto   Precio" << endl;
	while (lista != NULL) {
		Eliminar1ero(lista, RProd);
		cout << " " << RProd.codigo << "    -     " << RProd.PrecioUn << endl;
	}

}

void EjecutarEjercicio(Nodo* pila, int n) {
	
}
int main()
{
	int opcion;
	int n = 0;
	Nodo* lista = NULL;
	Producto RProd;
	do {

		cout << "------------------------MENU------------------------" << endl;
		cout << "--------Selecciona una opcion(numero)--------" << endl;
		cout << "1- Llenar Lista" << endl;
		cout << "2- Imprimir Lista" << endl;
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
			LllenarLista(lista, RProd, n);
			break;
		case 2:
			ImprimirLista(lista, RProd);
			break;
		case 3:
			/*EjecutarEjercicio(pila, n);*/
			break;
		default:
			cout << "--------opcion invalida, por favor ingrese una opcion valida!--------" << endl;
			break;
		}
	} while (opcion != 0);
}



