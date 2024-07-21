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
//
//struct Venta
//{
//	int Codp;
//	int CantVend;
//};
//struct Nodo
//{
//	Producto Info;
//	Nodo* sig;
//};
//
//void InsertarAdelante(Nodo*& lista, Producto RInfo) {
//	Nodo* nuevo = new Nodo();
//	nuevo->Info = RInfo;
//	nuevo->sig = lista;
//	lista = nuevo;
//}
//void InsertarEnMedio(Nodo*& lista, Producto Prod) {
//	Nodo* pNuevo = new Nodo();
//	pNuevo->Info = Prod;
//	Nodo* ptr = lista;
//	Nodo* antp = NULL;
//	while (ptr!=NULL && ptr->Info.Codp <= pNuevo->Info.Codp) {
//		antp = ptr;
//		ptr = ptr->sig;
//	}
//	antp->sig = pNuevo;
//	pNuevo->sig = ptr;
//}
//void InsertarOrdenado(Nodo*& lista, Producto Rprod) {
//	if (lista == NULL || Rprod.Codp < lista->Info.Codp) {
//		InsertarAdelante(lista, Rprod);
//	}
//	else
//	{
//		InsertarEnMedio(lista, Rprod);
//	}
//}
//Nodo* BuscaProdenLista(Nodo*& lista, int n, int codigo) {
//	Nodo* ptr = lista;
//	while (ptr!=NULL && ptr->Info.Codp!=codigo)
//	{
//		ptr = ptr->sig;
//	}
//	return ptr;
//}
//
//void Eliminar1ero(Nodo*& lista, Producto& Rprod) {
//	Nodo* ptr = lista;
//	Rprod = ptr->Info;
//	lista = ptr->sig;
//	delete ptr;
//}
//void GenerarArchProd() {
//	FILE* fprod = fopen("Productos.dat", "wb");
//	Producto Rprod;
//	cout << "Ingresar Codigo de Producto" << endl;
//	cin >> Rprod.Codp;
//	while (Rprod.Codp != 0)
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
//	cout << "||CodP||" << "Desc||" << "Precio" << endl;
//	while (!feof(fprod))
//	{
//		cout << "  " << Rprod.Codp << "   " << Rprod.Desc << "  " << Rprod.PU << endl;
//		fread(&Rprod, sizeof(Rprod), 1, fprod);
//	}
//
//	fclose(fprod);
//}
//void ImprimirArchVentas() {
//	FILE* fventas = fopen("Ventas.dat", "rb");
//	Venta RVenta;
//	cout << "---FACTURACION TOTAL X PROD---" << endl;
//	cout << "||CodP||" << "Cant Vend||" << endl;
//	while (fread(&RVenta, sizeof(RVenta), 1, fventas))
//	{
//		cout << "  " << RVenta.Codp << "   " << RVenta.CantVend << endl;
//	}
//
//	fclose(fventas);
//}
//void CargaProdaLista(FILE* fprod, Nodo*& lista, int& n) {
//	n = 0;
//	Producto RProd;
//	while (fread(&RProd, sizeof(RProd), 1, fprod))
//	{
//		InsertarOrdenado(lista, RProd);
//		/*InsertarAdelante(lista, RProd);*/
//		n++;
//	}
//	fclose(fprod);
//}
//
//void ImprimirLista(Nodo* &lista, int n) {
//	Producto Rprod;
//	cout << "---FACTURACION TOTAL X PROD---" << endl;
//	cout << "Codp   Desc  Total Fact" << endl;
//	while (lista!=NULL)
//	{
//		Eliminar1ero(lista, Rprod);
//		cout << Rprod.Codp << "  " << Rprod.Desc << "  " << Rprod.TotalF << endl;
//	}
//}
//void EjecutarEj() {
//	int n;
//	FILE* fprod = fopen("Productos.dat", "rb");
//	FILE* fventas = fopen("Ventas.dat", "rb");
//	Nodo* lista = NULL;
//	Venta Raux;
//	CargaProdaLista(fprod, lista, n);
//	fread(&Raux, sizeof(Raux), 1, fventas);
//	while (!feof(fventas))
//	{
//		Nodo* pos = BuscaProdenLista(lista, n, Raux.Codp);
//		if (pos != NULL) {
//			pos->Info.TotalF += pos->Info.PU * (Raux.CantVend);
//		}
//		else
//		{
//			cout << "----ERROR----" << endl;
//			cout << "No existe ese producto" << endl;
//		}
//		fread(&Raux, sizeof(Raux), 1, fventas);
//	}
//	fclose(fventas);
//	ImprimirLista(lista, n);
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
