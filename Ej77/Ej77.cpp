#define _CRT_SECURE_NO_DEPRECATE 
#include <iostream>
#include<fstream>
#include <string>
#include <stdio.h>

using namespace std;



struct tProd {
	int Cod;
	float PU;
};

int BuscarPedido(tProd Vprod[], int hasta, int codigo) {
	int posicion = 0;
	while ((Vprod[posicion].Cod!=codigo) && (posicion<hasta)) {
		posicion++;
	}
	if (posicion == hasta) {
		posicion = -1;
	}
	return posicion;
}

void GenerarArchivo() {
	FILE* archivo = fopen("PreciosProductos.dat", "w+b");
	tProd Rprod;

	cout << "Ingrese el codigo del producto" << endl;
	cin >> Rprod.Cod;
	while (Rprod.Cod != 0) {
		cout << "Ingrese precio unitario del Producto" << endl;
		cin >> Rprod.PU;
		fwrite(&Rprod, sizeof(Rprod), 1, archivo);
		cout << "Ingrese el codigo del producto" << endl;
		cin >> Rprod.Cod;
	}


	fclose(archivo);
};


void ProcesarArchivo() {
	FILE* archivo = fopen("PreciosProductos.dat", "r+b");
	tProd RProd;
	tProd Vprod[30];
	int ind, codigo, cantPed,pos;
	float importe;
	ind = 0;
	if (archivo == NULL) {
		cout << "Error: No Existe el Archivo " << endl;
		throw;
	}
	else
	{
		while (fread(&RProd, sizeof(RProd), 1, archivo))
		{
			Vprod[ind] = RProd;
			ind++;
		}
		fclose(archivo);
	}	
	cout << "-----PEDIDOS-----" << endl;
	cout << "Ingrese el codigo del producto" << endl;
	cin >> codigo;
	while (codigo != 0) {
		pos = BuscarPedido(Vprod,ind,codigo);
		if (pos != -1) {
			cout << "Ingrese la cantidad Pedida del producto" << endl;
			cin >> cantPed;
			importe = cantPed * Vprod[pos].PU;
			cout << "El pedido solicitado tiene un costo de " << importe << endl;
		}
		else
		{
			cout << "El producto solicitado no existe " << endl;
		}
		cout << "Ingrese el codigo del producto" << endl;
		cin >> codigo;
	}
	

}

void ImprimirArchivo() {
	FILE* archivo = fopen("PreciosProductos.dat", "r+b");
	tProd Registro;
	if (archivo == NULL) {
		cout << "Error: No Existe el Archivo " << endl;
		return;
	}
	cout << "||Codigo de Producto||" << "Precio Unitario||" << endl;
	while (fread(&Registro, sizeof(Registro), 1, archivo))
	{		
		cout << "         " << Registro.Cod <<"             "<<Registro.PU<< endl;
	}
	fclose(archivo);
}


int main()
{
	int opcion,limProd;
	do {

		cout << "------------------------MENU------------------------" << endl;
		cout << "--------Selecciona una opcion(numero)--------" << endl;
		cout << "1- Generar Archivo" << endl;
		cout << "2- Imprimir Archivo" << endl;
		cout << "3- Procesar Archivo" << endl;
		cout << "0- Salir" << endl;
		cin >> opcion;

		switch (opcion)
		{
		case 0:
			cout << "--------Hasta Luego--------" << endl;
			cout << "--------Fin del Programa--------" << endl;
			break;
		case 1:
			GenerarArchivo();
			break;
		case 2:
			ImprimirArchivo();
			break;
		case 3:
			ProcesarArchivo();
			break;
		default:
			cout << "--------opcion invalida, por favor ingrese una opcion valida!--------" << endl;
			break;
		}
	} while (opcion != 0);

}


