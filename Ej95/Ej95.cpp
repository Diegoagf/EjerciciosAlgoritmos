#define _CRT_SECURE_NO_DEPRECATE 
#include <iostream>
#include<fstream>
#include <string>
#include <stdio.h>

using namespace std;
struct Venta
{	int Cod;
	char Desc[21];
	int cantVen;
	float TotalFact;
};
struct Producto
{
	int Cod;
	char Desc[21];
	float PU;
};

void FiletoArray(Venta Arr[], FILE* file, int& n)
{
	n = 0;
	while (fread(&Arr[n], sizeof(Arr[n]), 1, file))
	{
		n++;
	}
}
bool CuestaMasdeMil(int cant, float total, float& PU) {
	PU = total / cant;
	if (PU > 1000) {
		return true;
	}
	else
	{
		return false;
	}
}
void InformesXProd(int prod,float prom, int totalfact, int cantventas300) {
	cout << "El Promedio de cantidades vendidas de las ventas del producto "<<prod <<" es :"<<prom<< endl;
	cout << "El Total facturado del producto " << prod << " es :" << totalfact << endl;
	cout << "La Cantidad de ventas de más de $3.000 del producto " << prod << " es :" << cantventas300 << endl;
}

void InformesGnrales(int cantProd) {
	cout << "La Cantidad de productos que facturaron en total más de $5.000." << " son :" << cantProd << endl;
}
void ImprimirVector(Producto VecProd[], int n) {
	cout << "||Codigo de Prod||" << "Descripcion||" << "Precio Unitario||" << endl;
	for (int j = 0; j <= n-1; j++)
	{
		cout << "         " << VecProd[j].Cod << "             " << VecProd[j].Desc << "              " << VecProd[j].PU << endl;
	}


}
void EjecutarEjercicio() {
	Producto VecProd[5000];
	Venta RVenta;
	FILE* fproductos = fopen("productos.dat", "r+b");
	//FiletoArray(VecProd, fproductos,n);
	int masde5000 = 0;
	int ind = 0;
	float PU;
	fread(&RVenta, sizeof(RVenta), 1, fproductos);
	while (!feof(fproductos)) {
		int control = RVenta.Cod;
		if (CuestaMasdeMil(RVenta.cantVen, RVenta.TotalFact, PU)) {
			VecProd[ind].Cod = RVenta.Cod;
			strcpy(VecProd[ind].Desc, RVenta.Desc);
			VecProd[ind].PU = PU;
			ind++;
		}
		int Regxprod = 0;
		float promCantVend = 0;
		int totalFactxProd = 0;
		int cantVentasxProd = 0;
		int Ventasmas3000 = 0;
		int VentasxProd = 0;
		while ((!feof(fproductos)) && (RVenta.Cod ==control) )
		{
			VentasxProd += RVenta.cantVen;
			Regxprod++;
			totalFactxProd += RVenta.TotalFact;
			if (RVenta.TotalFact > 3000) {
				cantVentasxProd += RVenta.cantVen;
			}
			fread(&RVenta, sizeof(RVenta), 1, fproductos);
		}
		promCantVend = VentasxProd / Regxprod;
		if (totalFactxProd > 5000) {
			masde5000++;
		}
		InformesXProd(RVenta.Cod, promCantVend, totalFactxProd, Ventasmas3000);
	}
	InformesGnrales(masde5000);
	//OrdenarVector(VecProd, ind);
	ImprimirVector(VecProd, ind);
	//Proceso de llamadas a BusqBin
}
void OrdenarVector(Producto VecProd[],int Nvec) {
	int pas = 1;
	bool ordenado = false;
	Producto Raux;
	while (!ordenado)
	{
		ordenado = true;
		for (int i = 0; i < Nvec - 1 - pas; i++)
		{
			if (VecProd[i].Cod > VecProd[i + 1].Cod)
			{
				Raux = VecProd[i];
				VecProd[i] = VecProd[i+1];
				VecProd[i + 1] = Raux;
				ordenado = false;
			}
		}
		pas++;
	}
	
}

void GenerarArchivoProductos() {
	FILE* fproductos = fopen("productos.dat", "w+b");
	Venta RProd;

	cout << "Ingrese el codigo de Producto" << endl;
	cin >> RProd.Cod;
	while (RProd.Cod != 0) {
		cout << "Ingrese la Descripcion" << endl;
		cin >> RProd.Desc;

		cout << "Ingrese la cantidad Vendida" << endl;
		cin >> RProd.cantVen;

		cout << "Ingrese El total Facturado en la Venta" << endl;
		cin >> RProd.TotalFact;

		fwrite(&RProd, sizeof(RProd), 1, fproductos);
		cout << "Ingrese el codigo de Producto" << endl;
		cin >> RProd.Cod;
	}
	fclose(fproductos);
};


void ImprimirArchivoProductos() {
	FILE* fproductos = fopen("productos.dat", "r+b");
	Venta Registro;
	if (fproductos == NULL) {
		cout << "Error: No Existe el Archivo " << endl;
		return;
	}
	cout << "||Codigo||" << "Descripcion||" << "Ventas||" << "Total||" << endl;
	while (fread(&Registro, sizeof(Registro), 1, fproductos))
	{
		cout << Registro.Cod << "             " << Registro.Desc << "           " << Registro.cantVen << "        " << Registro.TotalFact << endl;
	}
	fclose(fproductos);
}


int main() {

	int opcion, limProd;
	do {

		cout << "------------------------MENU------------------------" << endl;
		cout << "--------Selecciona una opcion(numero)--------" << endl;
		cout << "1- Generar Archivo de Productos" << endl;
		cout << "2- Imprimir Archivo de Productos" << endl;
		cout << "3- Ejecutar Ejercicio 95" << endl;
		cout << "0- Salir" << endl;
		cin >> opcion;

		switch (opcion)
		{
		case 0:
			cout << "--------Hasta Luego--------" << endl;
			cout << "--------Fin del Programa--------" << endl;
			break;
		case 1:
			GenerarArchivoProductos();
			break;
		case 2:
			ImprimirArchivoProductos();
			break;
		case 3:
			EjecutarEjercicio();
			break;
		default:
			cout << "--------opcion invalida, por favor ingrese una opcion valida!--------" << endl;
			break;
		}
	} while (opcion != 0);
}
