#define _CRT_SECURE_NO_DEPRECATE 
#include <iostream>
using namespace std;

struct Producto
{
	int Codp;
	char Desc[30];
	float PU;
	float TotalF;
};
struct Tinfo
{
	float FactVenta;
};
struct Nodo2
{
	Tinfo Info;
	Nodo2* sig;
};

struct VProducto
{
	int Codp;
	char Desc[30];
	float PU;
	Nodo2* listaVentas;
};
struct Nodo
{
	VProducto Info;
	Nodo* sig;
};



struct Venta
{
	int Codp;
	int CantVend;
};


void Eliminar1ero2(Nodo2*& lista, Tinfo& Rprod) {
	Nodo2* ptr = lista;
	Rprod = ptr->Info;
	lista = ptr->sig;
	delete ptr;
}
void Eliminar1ero(Nodo*& lista, VProducto& Rprod) {
	Nodo* ptr = lista;
	Rprod = ptr->Info;
	lista = ptr->sig;
	delete ptr;
}
void InsertarAdelante2(Nodo2*& lista, Tinfo RInfo) {
	Nodo2* nuevo = new Nodo2();
	nuevo->Info = RInfo;
	nuevo->sig = lista;
	lista = nuevo;
}
void InsertarAdelante(Nodo*& lista, VProducto RInfo) {
	Nodo* nuevo = new Nodo();
	nuevo->Info = RInfo;
	nuevo->sig = lista;
	lista = nuevo;
}
void InsertarEnMedio(Nodo2*& lista, Tinfo Prod) {
	Nodo2* pNuevo = new Nodo2();
	pNuevo->Info = Prod;
	Nodo2* ptr = lista;
	Nodo2* antp = NULL;
	while (ptr != NULL && ptr->Info.FactVenta <= pNuevo->Info.FactVenta) {
		antp = ptr;
		ptr = ptr->sig;
	}
	antp->sig = pNuevo;
	pNuevo->sig = ptr;
}
void InsertarOrdenado(Nodo2*& lista, Tinfo Rprod) {
	if (lista == NULL || Rprod.FactVenta < lista->Info.FactVenta) {
		InsertarAdelante2(lista, Rprod);
	}
	else
	{
		InsertarEnMedio(lista, Rprod);
	}
}
void ImprimirLista(Nodo2*& lista) {
	Tinfo RFact;
	cout << "---LISTADO DE VENTAS X PROD---" << endl;
	cout << "Fact Venta" << endl;
	while (lista != NULL)
	{
		Eliminar1ero2(lista, RFact);
		cout << RFact.FactVenta << endl;
	}
}
void GenerarArchProd() {
	FILE* fprod = fopen("Productos.dat", "wb");
	Producto Rprod;
	cout << "Ingresar Codigo de Producto" << endl;
	cin >> Rprod.Codp;
	while (Rprod.Codp != 0)
	{
		cout << "Ingresar Descripcion" << endl;
		cin >> Rprod.Desc;

		cout << "Ingresar Precio unitario" << endl;
		cin >> Rprod.PU;
		Rprod.TotalF = 0;
		fwrite(&Rprod, sizeof(Rprod), 1, fprod);
		cout << "Ingresar Codigo de Producto" << endl;
		cin >> Rprod.Codp;
	}

	fclose(fprod);
}

void GenerarArchVentas() {
	FILE* fventas = fopen("Ventas.dat", "wb");
	Venta RVenta;
	cout << "Ingresar Codigo de Producto" << endl;
	cin >> RVenta.Codp;
	while (RVenta.Codp != 0)
	{
		cout << "Ingresar cantidad Vendida" << endl;
		cin >> RVenta.CantVend;

		fwrite(&RVenta, sizeof(RVenta), 1, fventas);

		cout << "Ingresar Codigo de Producto" << endl;
		cin >> RVenta.Codp;
	}

	fclose(fventas);
}
void ImprimirArchProd() {
	FILE* fprod = fopen("Productos.dat", "rb");
	Producto Rprod;
	fread(&Rprod, sizeof(Rprod), 1, fprod);
	cout << "||CodP||" << "Desc||" << "Precio" << endl;
	while (!feof(fprod))
	{
		cout << "  " << Rprod.Codp << "   " << Rprod.Desc << "  " << Rprod.PU << endl;
		fread(&Rprod, sizeof(Rprod), 1, fprod);
	}

	fclose(fprod);
}
void ImprimirArchVentas() {
	FILE* fventas = fopen("Ventas.dat", "rb");
	Venta RVenta;
	cout << "||CodP||" << "Cant Vend||" << endl;
	while (fread(&RVenta, sizeof(RVenta), 1, fventas))
	{
		cout << "  " << RVenta.Codp << "   " << RVenta.CantVend << endl;
	}

	fclose(fventas);
}
void CargaProdaLista(FILE* fprod, Nodo*& lista, int& n) {
	n = 0;
	VProducto RProd;
	while (fread(&RProd, sizeof(RProd), 1, fprod))
	{
		/*InsertarOrdenado(lista, RProd);*/
		InsertarAdelante(lista, RProd);
		n++;
	}
	fclose(fprod);
}
Nodo* BuscaProdenLista(Nodo* lista /*int n,int& j*/, int codigo) {
	//j = 0;
	Nodo* ptr = lista;
	while (ptr!=NULL &&/*j < n &&*/ ptr->Info.Codp !=codigo  ) {	//consultar por si no esta el dato	
		ptr = ptr->sig;
		/*j++;*/
	}
	return ptr;
}
void ImprimirLista(Nodo* lista, int n) {
	VProducto relim;
	Nodo* ptr;
	cout << "---INFORMES---" << endl;
	while (lista!=NULL) {
		ptr = lista;
		cout << "-----CodP: " << lista->Info.Codp << "     " << "Desc: " << lista->Info.Desc << "-----" << endl;		
		ImprimirLista(lista->Info.listaVentas);
		lista = ptr->sig;
		Eliminar1ero(ptr, relim);
	}

	
}
void EjecutarEj() {
	int j,n;
	Nodo* pos;
	FILE* fprod = fopen("Productos.dat", "rb");
	FILE* fventas = fopen("Ventas.dat", "rb");
	Nodo* lista = NULL;
	Venta Raux;
	Tinfo Rfact{};
	CargaProdaLista(fprod, lista, n);
	fread(&Raux, sizeof(Raux), 1, fventas);
	while (!feof(fventas))
	{
		pos = BuscaProdenLista(lista /*n, j*/,Raux.Codp);
		if (pos != NULL /*& j<n*/) {
			Rfact.FactVenta = pos->Info.PU * Raux.CantVend;
			InsertarOrdenado(pos->Info.listaVentas, Rfact);
		}
		else
		{
			cout << "----ERROR----" << endl;
			cout << "No existe ese producto" << endl;
		}
		fread(&Raux, sizeof(Raux), 1, fventas);
	}
	fclose(fventas);
	ImprimirLista(lista, n);



}


int main()
{
	int opcion;
	do {
		cout << "------------------------MENU------------------------" << endl;
		cout << "--------Selecciona una opcion(numero)--------" << endl;
		cout << "1- Generar Archivo de productos" << endl;
		cout << "2- Generar Archivo de Ventas" << endl;
		cout << "3-Imprimir Archivo  de Productos" << endl;
		cout << "4-Imprimir Archivo  de Ventas" << endl;
		cout << "5-Ejecutar Variante" << endl;
		cout << "0- Salir" << endl;
		cin >> opcion;

		switch (opcion)
		{
		case 0:
			cout << "--------Hasta Luego--------" << endl;
			cout << "--------Fin del Programa--------" << endl;
			break;
		case 1:
			GenerarArchProd();
			break;
		case 2:
			GenerarArchVentas();
			break;
		case 3:
			ImprimirArchProd();
			break;
		case 4:
			ImprimirArchVentas();
			break;
		case 5:
			EjecutarEj();
			break;
		default:
			cout << "--------opcion invalida, por favor ingrese una opcion valida!--------" << endl;
			break;
		}
	} while (opcion != 0);
}
