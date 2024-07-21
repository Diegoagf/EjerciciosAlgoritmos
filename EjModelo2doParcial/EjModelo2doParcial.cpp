//#define _CRT_SECURE_NO_DEPRECATE 
//#include <iostream>
//#include<fstream>
//#include <stdio.h>
//
//using namespace std;
//
//
//
//struct tProd {
//	int Cod;
//	float Fact;
//};
//
//struct Nodo {
//	tProd Info;
//	Nodo* sgte;
//};
//
//void GenerarArchivo() {
//	FILE* archivo = fopen("Productos.dat", "w+b");
//	tProd Rprod;
//
//	cout << "Ingrese el codigo del producto" << endl;
//	cin >> Rprod.Cod;
//	while (Rprod.Cod != 0) {
//		cout << "Ingrese Facturacion" << endl;
//		cin >> Rprod.Fact;
//		fwrite(&Rprod, sizeof(Rprod), 1, archivo);
//		cout << "Ingrese el codigo del producto" << endl;
//		cin >> Rprod.Cod;
//	}
//
//
//	fclose(archivo);
//};
//
//
//
//void ImprimirArchivo() {
//	FILE* archivo = fopen("Productos.dat", "r+b");
//	tProd Registro;
//	if (archivo == NULL) {
//		cout << "Error: No Existe el Archivo " << endl;
//	}
//	cout << "||Codigo||" << "Fact||" << endl;
//	while (fread(&Registro, sizeof(Registro), 1, archivo))
//	{
//		cout << "  " << Registro.Cod << "         " << Registro.Fact  << endl;
//	}
//	fclose(archivo);
//}
//
//void InsertarAdelante(Nodo*& lista, tProd RInfo) {
//	Nodo* nuevo = new Nodo();
//	nuevo->Info = RInfo;
//	nuevo->sgte = lista;
//	lista = nuevo;
//}
////void EscribirArchivo() {
////	FILE* archivo = fopen("ProductosStock.dat", "r+b");
////	tProd RProd;
////	tProd Vprod[30];
////	int ind, codigo, cantPed, pos;
////	float importe;
////	ind = 0;
////	if (archivo == NULL) {
////
////	}
////	else
////	{
////		cout << "Ingrese el codigo del producto" << endl;
////		cin >> RProd.Cod;
////		fseek(archivo, 0,SEEK_END);
////		while (RProd.Cod!=0)
////		{
////			cout << "Ingrese precio unitario del Producto" << endl;
////			cin >> RProd.PU;
////			cout << "Ingrese cantidad en Stock" << endl;
////			cin >> RProd.Stk;
////			fwrite(&RProd, sizeof(RProd), 1, archivo);
////			cout << "Ingrese el codigo del producto" << endl;
////			cin >> RProd.Cod;
////		}		
////	}
////	fclose(archivo);
////}
//void Modulo(Nodo*lista, tProd Vtas100200[], int&tope) {
//	tope = 0;
//	Nodo* aux = NULL;
//	Nodo* antp = NULL;
//	Nodo* ptr = lista;
//
//	while(ptr != NULL){
//	if(ptr->Info.Fact >= 100 && ptr->Info.Fact <= 200) {
//		aux = ptr;
//		Vtas100200[tope] = ptr->Info;
//		tope++;
//		if(antp == NULL) {
//			aux = ptr;
//			ptr = ptr->sgte;
//			lista = ptr;
//			delete aux;
//		}
//		else{
//			aux = ptr;
//			ptr = ptr->sgte;
//			antp->sgte = ptr;
//			delete aux;
//		}
//	}
//	else{
//		antp = ptr;
//		ptr = ptr->sgte;
//	}
//}
//tope--;
//
//}
//void ImprimirLista(Nodo*lista) {
//	tProd RFact;
//	cout << "---LISTADO---" << endl;
//	cout << "COd   Fact" << endl;
//	Nodo* ptr = lista;
//	while (ptr != NULL)
//	{
//		cout << ptr->Info.Cod <<"   "<< ptr->Info.Fact<< endl;
//		ptr = ptr->sgte;
//	}
//}
//void imprimoVector(tProd Vtas100200[], int tope)
//{
//	cout << "LISTADO FINAL " << endl;
//	cout << "Codigo " << "Facturacion       " << endl;
//	for (int cont = 0; cont <= tope; cont++)
//	{
//		cout << Vtas100200[cont].Cod << "     " << Vtas100200[cont].Fact << endl;
//	}
//}
//int main()
//{
//	int opcion, tope;
//	do {
//
//		cout << "------------------------MENU------------------------" << endl;
//		cout << "--------Selecciona una opcion(numero)--------" << endl;
//		cout << "1- Generar Archivo" << endl;
//		cout << "2- Imprimir Archivo" << endl;
//		cout << "3- Eejecutar Modulo" << endl;
//		//cout << "4- Agregar Datos al archivo" << endl;
//		cout << "0- Salir" << endl;
//		cin >> opcion;
//		tProd Vtas100200[100];
//		Nodo* lista = NULL;
//		FILE* archivo = fopen("Productos.dat", "r+b");
//		switch (opcion)
//		{
//		case 0:
//			cout << "--------Hasta Luego--------" << endl;
//			cout << "--------Fin del Programa--------" << endl;
//			break;
//		case 1:
//			GenerarArchivo();
//			break;
//		case 2:
//			ImprimirArchivo();
//			break;
//		case 3:
//			tProd Rventa;
//			while (fread(&Rventa,sizeof(Rventa),1,archivo))
//			{
//				InsertarAdelante(lista, Rventa);
//			}
//			/*ImprimirLista(lista);*/
//			Modulo(lista, Vtas100200, tope);
//			imprimoVector(Vtas100200, tope);
//			break;
//		default:
//			cout << "--------opcion invalida, por favor ingrese una opcion valida!--------" << endl;
//			break;
//		}
//	} while (opcion != 0);
//
//}
//
//
////void CargaVec(tprod VP[]; int& n) {
////	tProd RProd;
////	int i = 0;
////	FILE* aProds = fopen("Productos.dat", "rb");
////	while (fread(&RProd, sizeof(RProd), 1, aProds) {  // o directamente fread(&VP[i], sizeof (VP[i]), 1, aProds)  sin la linea de abajo
////		VP[i] = RProd;
////		i++;
////	};
////	n = i;
////	fclose(aProds);
////};
////Modelo de carga de archivo a vector
//
//
////void ActualizarStock(tProd Vprod[], int n) {
////	FILE* archivo = fopen("ProductosStock.dat", "r+b");
////	//tProd Rprod; //REGITRO LOCAL
////	for (int i = 0; i < n; i++)
////	{
////		fwrite(&Vprod[i], sizeof(Vprod[i]), 1, archivo);
////	}
////	fclose(archivo);
////}