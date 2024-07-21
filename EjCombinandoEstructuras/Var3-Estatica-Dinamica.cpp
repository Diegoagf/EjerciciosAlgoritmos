//#define _CRT_SECURE_NO_DEPRECATE 
//#include <iostream>
//using namespace std;
//
//struct Producto
//{
//	int Codp;
//	char Desc[30];
//	float PU;
//	float TotalF;
//};
//struct Tinfo
//{
//	float FactVenta;
//};
//struct Nodo
//{
//	Tinfo Info;
//	Nodo* sig;
//};
//struct VProducto
//{
//    int Codp;
//    char Desc[30];
//    float PU;
//	Nodo *listaVentas;
//};
//
//struct Venta
//{
//    int Codp;
//    int CantVend;
//};
//
//
//void Eliminar1ero(Nodo*& lista, Tinfo& Rprod) {
//	Nodo* ptr = lista;
//	Rprod = ptr->Info;
//	lista = ptr->sig;
//	delete ptr;
//}
//void InsertarAdelante(Nodo*& lista, Tinfo RInfo) {
//	Nodo* nuevo = new Nodo();
//	nuevo->Info = RInfo;
//	nuevo->sig = lista;
//	lista = nuevo;
//}
//void InsertarEnMedio(Nodo*& lista, Tinfo Prod) {
//	Nodo* pNuevo = new Nodo();
//	pNuevo->Info = Prod;
//	Nodo* ptr = lista;
//	Nodo* antp = NULL;
//	while (ptr != NULL && ptr->Info.FactVenta<= pNuevo->Info.FactVenta) {
//		antp = ptr;
//		ptr = ptr->sig;
//	}
//	antp->sig = pNuevo;
//	pNuevo->sig = ptr;
//}
//void InsertarOrdenado(Nodo*& lista, Tinfo Rprod) {
//	if (lista == NULL || Rprod.FactVenta < lista->Info.FactVenta) {
//		InsertarAdelante(lista, Rprod);
//	}
//	else
//	{
//		InsertarEnMedio(lista, Rprod);
//	}
//}
//void ImprimirLista(Nodo*& lista) {
//	Tinfo RFact;		
//	cout << "---LISTADO DE VENTAS X PROD---" << endl;
//	cout << "Fact Venta" << endl;
//	while (lista != NULL)
//	{
//		Eliminar1ero(lista, RFact);
//		cout << RFact.FactVenta << endl;
//	}
//}
//void GenerarArchProd() {
//	FILE* fprod = fopen("Productos.dat", "wb");
//	Producto Rprod;
//	cout << "Ingresar Codigo de Producto" << endl;
//	cin >> Rprod.Codp;
//	while (Rprod.Codp!=0)
//	{
//		cout << "Ingresar Descripcion" << endl;
//		cin >> Rprod.Desc;
//
//		cout << "Ingresar Precio unitario" << endl;
//		cin >> Rprod.PU;
//		Rprod.TotalF = 0;
//		fwrite(&Rprod, sizeof(Rprod), 1, fprod);
//		cout << "Ingresar Codigo de Producto" << endl;
//		cin >> Rprod.Codp;
//	}
//
//	fclose(fprod);
//}
//
//void GenerarArchVentas() {
//	FILE* fventas = fopen("Ventas.dat", "wb");
//	Venta RVenta;
//	cout << "Ingresar Codigo de Producto" << endl;
//	cin >> RVenta.Codp;
//	while (RVenta.Codp != 0)
//	{
//		cout << "Ingresar cantidad Vendida" << endl;
//		cin >> RVenta.CantVend;
//
//		fwrite(&RVenta, sizeof(RVenta), 1, fventas);
//
//		cout << "Ingresar Codigo de Producto" << endl;
//		cin >> RVenta.Codp;
//	}
//
//	fclose(fventas);
//}
//void ImprimirArchProd() {
//	FILE* fprod = fopen("Productos.dat", "rb");
//	Producto Rprod;
//	fread(&Rprod, sizeof(Rprod), 1, fprod);
//	cout << "||CodP||" << "Desc||" <<"Precio"<< endl;
//	while (!feof(fprod))
//	{
//		cout << "  " << Rprod.Codp << "   " << Rprod.Desc <<"  "<<Rprod.PU<< endl;
//		fread(&Rprod, sizeof(Rprod), 1, fprod);
//	}
//	
//	fclose(fprod);
//}
//void ImprimirArchVentas() {
//	FILE* fventas = fopen("Ventas.dat", "rb");
//	Venta RVenta;
//	cout << "||CodP||" << "Cant Vend||" << endl;
//	while (fread(&RVenta,sizeof(RVenta),1,fventas))
//	{
//		cout << "  " << RVenta.Codp << "   " << RVenta.CantVend <<  endl;
//	}
//
//	fclose(fventas);
//}
//void CargaProdaVec(FILE* fprod, VProducto VecProd[],int& n) {
//	n = 0;
//	Producto RProd;
//	while (fread(&RProd, sizeof(RProd), 1, fprod))
//	{
//		VecProd[n].Codp = RProd.Codp;
//		strcpy(VecProd[n].Desc, RProd.Desc);
//		VecProd[n].PU = RProd.PU;
//		VecProd[n].listaVentas = NULL;
//		n++;
//	}
//	fclose(fprod);
//}
//int BuscaProdenVec(VProducto VecProd[], int n, int codigo) {
//	int posicion = 0;
//	while (posicion < n  && codigo != VecProd[posicion].Codp) {
//		posicion++;
//	}
//	if (posicion == n) {
//		return -1;
//	}
//	else
//	{
//		return posicion;
//	}
//} 
//void ImprimirVecLista(VProducto VecProd[], int n){
//	cout << "---INFORMES---" << endl;
//	for (int i = 0; i < n; i++)
//	{ 
//		cout << "-----CodP: " << VecProd[i].Codp << "     " << "Desc: " << VecProd[i].Desc << "-----" << endl;
//		ImprimirLista(VecProd[i].listaVentas);
//	}
//}
//void EjecutarEj() {
//	int n,pos;
//	FILE* fprod = fopen("Productos.dat", "rb");
//	FILE* fventas= fopen("Ventas.dat", "rb");
//	VProducto VecProd[500];
//	Venta Raux;
//	Tinfo Rfact{};
//	CargaProdaVec(fprod, VecProd,n);
//	fread(&Raux, sizeof(Raux), 1, fventas);
//	while (!feof(fventas))
//	{
//		pos = BuscaProdenVec(VecProd, n, Raux.Codp);
//		if (pos != -1) {
//			Rfact.FactVenta = VecProd[pos].PU * Raux.CantVend;
//			InsertarOrdenado(VecProd[pos].listaVentas, Rfact);
//		}
//		else
//		{
//			cout << "----ERROR----" << endl;
//			cout << "No existe ese producto" << endl;
//		}
//		fread(&Raux, sizeof(Raux), 1, fventas);
//	}
//	fclose(fventas);
//	ImprimirVecLista(VecProd, n);
//		
//
//
//}
//
//
//int main()
//{
//	int opcion;
//	do {
//		cout << "------------------------MENU------------------------" << endl;
//		cout << "--------Selecciona una opcion(numero)--------" << endl;
//		cout << "1- Generar Archivo de productos" << endl;
//		cout << "2- Generar Archivo de Ventas" << endl;
//		cout << "3-Imprimir Archivo  de Productos" << endl;
//		cout << "4-Imprimir Archivo  de Ventas" << endl;
//		cout << "5-Ejecutar Variante" << endl;
//		cout << "0- Salir" << endl;
//		cin >> opcion;
//
//		switch (opcion)
//		{
//		case 0:
//			cout << "--------Hasta Luego--------" << endl;
//			cout << "--------Fin del Programa--------" << endl;
//			break;
//		case 1:
//			GenerarArchProd();
//			break;
//		case 2:
//			GenerarArchVentas();
//			break;
//		case 3:
//			ImprimirArchProd();
//			break;
//		case 4:
//			ImprimirArchVentas();
//			break;
//		case 5:
//			EjecutarEj();
//			break;
//		default:
//			cout << "--------opcion invalida, por favor ingrese una opcion valida!--------" << endl;
//			break;
//		}
//	} while (opcion != 0);
//}
