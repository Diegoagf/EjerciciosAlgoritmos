#include <iostream>
using namespace std;

struct Producto {
	int codigo;
	int Stock;
};
struct Pedido {
	int codigo;
	int cantSolic;
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
		while ((ptr != NULL) && (pNue->info.codigo >= ptr->info.codigo))
		{
			antp = ptr;
			ptr = ptr->sig;
		}
		antp->sig = pNue;
		pNue->sig = ptr;
	}
}

Nodo* BuscarProducto(Nodo* lista, Pedido RPed) {
	Nodo* ptr = lista;
	while ((ptr != NULL) && (ptr->info.codigo!=RPed.codigo)) {
		ptr = ptr->sig;
	}
	return ptr;
}

bool HayStock(Producto& Rprod, Pedido RPed) {
	if (Rprod.Stock >= RPed.cantSolic) {
		Rprod.Stock -= RPed.cantSolic;
		return true;
	}
	else
	{
		return false;
	}
}
void LllenarLista(Nodo*& lista, Producto& RProd, int& n) {
	cout << "Ingrese el codigo del producto (0 para cortar)" << endl;
	cin >> RProd.codigo;
	while (RProd.codigo != 0) {
		n++;
		cout << "Ingrese Stock" << endl;
		cin >> RProd.Stock;
		InsertOrd(lista, RProd);
		cout << "Ingrese el codigo del producto" << endl;
		cin >> RProd.codigo;
	}
}

void ImprimirLista(Nodo* lista) {
	cout << "Producto   Stock" << endl;
	while (lista != NULL) {
		/*Eliminar1ero(lista, RProd);*/
		cout << " " << lista->info.codigo << "    -     " << lista->info.Stock << endl;
		lista = lista->sig;
	}

}

void EjecutarEjercicio(Nodo* lista, int n) {
	Pedido RPed;
	cout << "-------VENTAS-------" << endl;
	cout << "Ingrese el codigo del producto (0 para cortar)" << endl;
	cin >> RPed.codigo;
	while (RPed.codigo != 0) {
		
		Nodo* posicion = BuscarProducto(lista, RPed);
		if (posicion != NULL) {
			cout << "Ingrese cantidad solicitada" << endl;
			cin >> RPed.cantSolic;
			if (HayStock(posicion->info,RPed)) {
				cout << "Cantidad Vendida: " << RPed.cantSolic << endl;
			}
			else
			{
				cout << "No se puede realizar la Venta - Stock Insuficiente" << endl;
			}
		}
		else
		{
			cout<<"Producto No Encontrado en Lista"<<endl;
		}
		
		cout << "Ingrese el codigo del producto" << endl;
		cin >> RPed.codigo;
	}
	cout << "------Stock Restante-------" << endl;
	ImprimirLista(lista);

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
		cout << "1- Generar Lista de productos" << endl;
		cout << "2- Imprimir Lista de Productos" << endl;
		cout << "3-Realizar Pedidos" << endl;
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
			ImprimirLista(lista);
			break;
		case 3:
			EjecutarEjercicio(lista, n);
			break;
		default:
			cout << "--------opcion invalida, por favor ingrese una opcion valida!--------" << endl;
			break;
		}
	} while (opcion != 0);
}



