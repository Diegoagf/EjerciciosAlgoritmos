#define _CRT_SECURE_NO_DEPRECATE 
#include <iostream>
#include<fstream>
#include <stdio.h>

using namespace std;



struct tProd {
	int Cod;
	float PU;
	int Stk;
};

void ActualizarStock(tProd Vprod[],int n) {
	FILE* archivo = fopen("ProductosStock.dat", "r+b");
	/*tProd Rprod;*/
	for (int i = 0; i < n; i++)
	{
		fwrite(&Vprod[i], sizeof(Vprod[i]), 1, archivo);
	}
	fclose(archivo);
}

bool VerificaryDescontarStock(tProd& prod,int cantidad){
	bool haystock;
	if (cantidad <= prod.Stk) {
		haystock = true;
		prod.Stk = prod.Stk - cantidad;
	}
	else
	{
		haystock = false;
	}
	return haystock;
}

int BuscarPedido(tProd Vprod[], int hasta, int codigo) {
	int posicion = 0;
	while ((Vprod[posicion].Cod != codigo) && (posicion < hasta)) {
		posicion++;
	}
	if (posicion == hasta) {
		posicion = -1;
	}
	return posicion;
}

void GenerarArchivo() {
	FILE* archivo = fopen("ProductosStock.dat", "w+b");
	tProd Rprod;

	cout << "Ingrese el codigo del producto" << endl;
	cin >> Rprod.Cod;
	while (Rprod.Cod != 0) {
		cout << "Ingrese precio unitario del Producto" << endl;
		cin >> Rprod.PU;
		cout << "Ingrese cantidad en Stock" << endl;
		cin >> Rprod.Stk;
		fwrite(&Rprod, sizeof(Rprod), 1, archivo);
		cout << "Ingrese el codigo del producto" << endl;
		cin >> Rprod.Cod;
	}


	fclose(archivo);
};


void ProcesarArchivo() {
	FILE* archivo = fopen("ProductosStock.dat", "r+b");
	tProd RProd;
	tProd Vprod[30];
	int ind, codigo, cantPed, pos;
	float importe;
	ind = 0;
	if (archivo == NULL) {
		cout << "Error: No Existe el Archivo " << endl;
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
		pos = BuscarPedido(Vprod, ind, codigo);
		if (pos != -1) {
			cout << "Ingrese la cantidad Pedida del producto" << endl;
			cin >> cantPed;
			if (VerificaryDescontarStock(Vprod[pos],cantPed)) {
				importe = cantPed * Vprod[pos].PU;
				cout << "--------SE REALIZO EL PEDIDO CON EXITO-------" << endl;
				cout << "El pedido solicitado tuvo un costo de " << importe << endl;
			}
			else
			{
				cout << "--------NO SE PROCESO EL PEDIDO--------" << endl;
				cout << "No puede entregarse el pedido por stock insuficiente" << endl;
			}
		}
		else
		{
			cout << "--------ERROR -------" << endl;
			cout << "El producto solicitado no existe " << endl;
		}
		cout << "Ingrese el codigo del producto" << endl;
		cin >> codigo;
	}
	ActualizarStock(Vprod,ind);

}

void ImprimirArchivo() {
	FILE* archivo = fopen("ProductosStock.dat", "r+b");
	tProd Registro;
	if (archivo == NULL) {
		cout << "Error: No Existe el Archivo " << endl;
	}
	cout << "||Codigo de Producto||" << "Precio Unitario||" << "Stock||"<<endl;
	while (fread(&Registro, sizeof(Registro), 1, archivo))
	{
		cout << "         " << Registro.Cod << "             " << Registro.PU <<"              "<<Registro.Stk<< endl;
	}
	fclose(archivo);
}

//void EscribirArchivo() {
//	FILE* archivo = fopen("ProductosStock.dat", "r+b");
//	tProd RProd;
//	tProd Vprod[30];
//	int ind, codigo, cantPed, pos;
//	float importe;
//	ind = 0;
//	if (archivo == NULL) {
//
//	}
//	else
//	{
//		cout << "Ingrese el codigo del producto" << endl;
//		cin >> RProd.Cod;
//		fseek(archivo, 0,SEEK_END);
//		while (RProd.Cod!=0)
//		{
//			cout << "Ingrese precio unitario del Producto" << endl;
//			cin >> RProd.PU;
//			cout << "Ingrese cantidad en Stock" << endl;
//			cin >> RProd.Stk;
//			fwrite(&RProd, sizeof(RProd), 1, archivo);
//			cout << "Ingrese el codigo del producto" << endl;
//			cin >> RProd.Cod;
//		}		
//	}
//	fclose(archivo);
//}


int main()
{
	int opcion, limProd;
	do {

		cout << "------------------------MENU------------------------" << endl;
		cout << "--------Selecciona una opcion(numero)--------" << endl;
		cout << "1- Generar Archivo" << endl;
		cout << "2- Imprimir Archivo" << endl;
		cout << "3- Procesar Archivo" << endl;
		//cout << "4- Agregar Datos al archivo" << endl;
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
		case 4:
			/*EscribirArchivo();*/
			break;
		default:
			cout << "--------opcion invalida, por favor ingrese una opcion valida!--------" << endl;
			break;
		}
	} while (opcion != 0);

}


//void CargaVec(tprod VP[]; int& n) {
//	tProd RProd;
//	int i = 0;
//	FILE* aProds = fopen("Productos.dat", "rb");
//	while (fread(&RProd, sizeof(RProd), 1, aProds) {  // o directamente fread(&VP[i], sizeof (VP[i]), 1, aProds)  sin la linea de abajo
//		VP[i] = RProd;
//		i++;
//	};
//	n = i;
//	fclose(aProds);
//};
//Modelo de carga de archivo a vector


//void ActualizarStock(tProd Vprod[], int n) {
//	FILE* archivo = fopen("ProductosStock.dat", "r+b");
//	//tProd Rprod; //REGITRO LOCAL
//	for (int i = 0; i < n; i++)
//	{
//		fwrite(&Vprod[i], sizeof(Vprod[i]), 1, archivo);
//	}
//	fclose(archivo);
//}