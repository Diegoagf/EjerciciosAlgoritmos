#define _CRT_SECURE_NO_DEPRECATE 
#include <iostream>
#include<fstream>
#include <string>
#include <stdio.h>

using namespace std;



struct tRegistro {
	int codProd;
	int CantVen;
};



void GenerarArchivo() {
	FILE* arch = fopen("Productos.dat", "w+b");
	tRegistro Registro;
	cout << "Ingrese el codigo del producto" << endl;
	cin >> Registro.codProd;
	while (Registro.codProd != 0) {
		cout << "Ingrese cantidad vendida" << endl;
		cin >> Registro.CantVen;

		fwrite(&Registro, sizeof(Registro), 1, arch);
		cout << "Ingrese el codigo del producto" << endl;
		cin >> Registro.codProd;
	}
	

	fclose(arch);
};


void ProcesarArchivo() {
	
}

void ImprimirArchivo() {
	FILE* arch = fopen("Productos.dat", "r+b");
	tRegistro Registro;
	if (arch == NULL) {
		cout << "Error: No Existe el Archivo " << endl;
		return;
	}
	fread(&Registro, sizeof(Registro), 1, arch);
	while (!feof(arch))
	{
		cout << "Codigo de Producto: " << Registro.codProd << endl;
		cout << "Cantidad Vendida: " << Registro.CantVen << endl;
		fread(&Registro, sizeof(Registro), 1, arch);
	}
	fclose(arch);
}


int main()
{
	int opcion;
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
	}
	while (opcion !=0);

}


