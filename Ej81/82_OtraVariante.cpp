//#define _CRT_SECURE_NO_DEPRECATE 
//#include <iostream>
//#include<fstream>
//#include <string>
//#include <stdio.h>
//
//using namespace std;
//struct Tvuelo
//{
//	int codigo;
//	int PasajeDisponibles;
//	int PasajesRechazados;
//};
//struct TPedido
//{
//	int Dni;
//	int codigoVuelo;
//	int PasajeSolicitados;
//};
//
//
//
//int BuscarEnVector(Tvuelo PasajesDisponibles[], int limite, int codigo);
//void CargaVector(Tvuelo PasajesDisponibles[], int& tope);
//void ImprimirVector(Tvuelo PasajesDisponibles[], int tope);
//void OrdenarVector(Tvuelo PasajesDisponibles[], int tope);
//
//void BuscarInsertar(Tvuelo PasajesDisponibles[], int& tope, Tvuelo regAbuscar) {
//	int pos = 0;
//	while ((pos<= tope)&(PasajesDisponibles[pos].codigo<= regAbuscar.codigo))
//	{
//		pos++;
//	}
//	if (pos<= tope) {
//		for (int j = tope; j >= pos; j--)
//		{
//			PasajesDisponibles[j + 1] = PasajesDisponibles[j];
//		}
//	}
//	PasajesDisponibles[pos] = regAbuscar;
//	/*cout << PasajesDisponibles[pos].codigo << endl;*/
//	tope++;
//}
//
//void EjecutarEjercicio() {
//	int tope,n,posicion;
//	TPedido Rventa;
//	Tvuelo PasajesDisponibles[500];
//	FILE* fpedidos = fopen("Pedidos.dat", "rb");
//	CargaVector(PasajesDisponibles, tope);
//	
//	
//	while (fread(&Rventa, sizeof(Rventa), 1, fpedidos)) {
//				   posicion = BuscarEnVector(PasajesDisponibles, tope, Rventa.codigoVuelo);
//				   if (posicion != -1) {
//					   if (Rventa.PasajeSolicitados <= PasajesDisponibles[posicion].PasajeDisponibles) {
//						   cout << "-------COMPRA REALIZADA-------" << endl;
//						   cout << "||DNI del Solicitante||" << "Cantidad de Pasajes Vendidos||" << "Cod de Vuelo||" << endl;
//						   cout << "         " << Rventa.Dni << "             " << Rventa.PasajeSolicitados << "              " << Rventa.codigoVuelo << endl;
//						   PasajesDisponibles[posicion].PasajeDisponibles = PasajesDisponibles[posicion].PasajeDisponibles - Rventa.PasajeSolicitados;
//					   }
//					   else
//					   {
//						   cout << "Pedido Rechazado, pasajes solicitados mayor a los disponibles" << endl;
//						   PasajesDisponibles[posicion].PasajesRechazados = Rventa.PasajeSolicitados;
//					   }
//				   }
//				}
//	
//	ImprimirVector(PasajesDisponibles, tope);
//	
//
//
//
//}
//
//int BuscarEnVector(Tvuelo PasajesDisponibles[],int limite,int codigo) {
//	int pos = 0;
//	int ti = 0;
//	int tf = limite;
//	int tm = (ti + tf) / 2;
//	while ((ti<=tf) && (PasajesDisponibles[tm].codigo!=codigo)) {
//		if (PasajesDisponibles[tm].codigo > codigo) {
//			tf = tm - 1;
//		}
//		else
//		{
//			ti = tm + 1;
//		}
//		tm = (ti + tf) / 2;
//	}
//	if (ti >tf) {
//		pos = -1;
//	}
//	else
//	{
//		pos = tm;
//	}
//	return pos;
//}
//void OrdenarVector(Tvuelo PasajesDisponibles[],int tope){
//	int pas = 1;
//	    bool ordenado = false;
//	    Tvuelo vueloAux;
//	    while (!ordenado)
//	    {
//	        ordenado = true;
//	
//	        for (int i = 0; i <= tope - pas - 1; i++)
//	        {
//	            if (PasajesDisponibles[i].codigo > PasajesDisponibles[i + 1].codigo)
//	            {
//	                vueloAux = PasajesDisponibles[i];
//					PasajesDisponibles[i] = PasajesDisponibles[i + 1];
//					PasajesDisponibles[i + 1] = vueloAux;
//	                ordenado = false;
//	            }
//	        }
//	        pas++;
//	    }
//}
//
//
//void ImprimirVector(Tvuelo PasajesDisponibles[], int tope) {
//	cout << "||Codigo de Vuelo||" << "P. Disponbles||" << "P. NO disponibles||" << endl;
//	for (int j = 0; j <= tope; j++)
//	{
//		cout << "         " << PasajesDisponibles[j].codigo << "             " << PasajesDisponibles[j].PasajeDisponibles << "              " << PasajesDisponibles[j].PasajesRechazados << endl;
//	}
//		
//	
//}
//
//void GenerarArchivoVuelos() {
//	FILE* archivo = fopen("Vuelos.dat", "w+b");
//	Tvuelo RVuelo;
//
//	cout << "Ingrese el codigo del vuelo" << endl;
//	cin >> RVuelo.codigo;
//	while (RVuelo.codigo != 0) {
//		cout << "Ingrese Pasajes disponibles" << endl;
//		cin >> RVuelo.PasajeDisponibles;
//		RVuelo.PasajesRechazados = 0;
//		fwrite(&RVuelo, sizeof(RVuelo), 1, archivo);
//		cout << "Ingrese el codigo del vuelo" << endl;
//		cin >> RVuelo.codigo;
//	}
//
//
//	fclose(archivo);
//};
//
//void GenerarArchivoPedidos() {
//	FILE* archivo = fopen("Pedidos.dat", "w+b");
//	TPedido RPedido;
//
//	cout << "Ingrese el Dni del solicitante" << endl;
//	cin >> RPedido.Dni;
//	while (RPedido.Dni != 0) {
//		cout << "Ingrese el codigo de vuelo" << endl;
//		cin >> RPedido.codigoVuelo;
//		cout << "Ingrese cantidad de pasajes solicitdados" << endl;
//		cin >> RPedido.PasajeSolicitados;
//
//		fwrite(&RPedido, sizeof(RPedido), 1, archivo);
//		cout << "Ingrese el Dni del solicitante" << endl;
//		cin >> RPedido.Dni;
//	}
//
//
//	fclose(archivo);
//}
//
//void ImprimirArchivoVuelos() {
//	FILE* archivo = fopen("Vuelos.dat", "r+b");
//	Tvuelo Registro;
//	if (archivo == NULL) {
//		cout << "Error: No Existe el Archivo " << endl;
//		return;
//	}
//	cout << "||Codigo de Vuelo||" << "P. Disponbles||" << "P.Rechazados||" << endl;
//	while (fread(&Registro, sizeof(Registro), 1, archivo))
//	{
//		cout << "         " << Registro.codigo << "             " << Registro.PasajeDisponibles << "              " << Registro.PasajesRechazados << endl;
//	}
//	fclose(archivo);
//}
//
//void ImprimirArchivoPedidos() {
//	FILE* archivo = fopen("Pedidos.dat", "r+b");
//	TPedido Registro;
//	if (archivo == NULL) {
//		cout << "Error: No Existe el Archivo " << endl;
//		return;
//	}
//	cout << "||DNI del Solicitante||" << "Codigo de vuelo||" << "Pasajes solicitados||" << endl;
//	while (fread(&Registro, sizeof(Registro), 1, archivo))
//	{
//		cout << "         " << Registro.Dni << "             " << Registro.codigoVuelo << "              " << Registro.PasajeSolicitados << endl;
//	}
//	fclose(archivo);
//}
//
//void CargaVector(Tvuelo PasajesDisponibles[],int& tope) {
//	FILE* aVuelos = fopen("Vuelos.dat", "rb");
//	Tvuelo Rvuelo;
//	tope = -1;
//	while (fread(&Rvuelo, sizeof(Rvuelo), 1, aVuelos)) {  // o directamente fread(&VP[i], sizeof (VP[i]), 1, aProds)  sin la linea de abajo
//		BuscarInsertar(PasajesDisponibles, tope, Rvuelo);
//	}
//	fclose(aVuelos);
//
//}
//
//int main() {
//
//	int opcion, limProd;
//	do {
//
//		cout << "------------------------MENU------------------------" << endl;
//		cout << "--------Selecciona una opcion(numero)--------" << endl;
//		cout << "1- Generar Archivo de Vuelos" << endl;
//		cout << "2- Generar Archivo de Pedidos" << endl;
//		cout << "3- Imprimir Archivo de Vuelos" << endl;
//		cout << "4- Imprimir Archivo de Pedidos" << endl;
//		cout << "5- Ejecutar Ejercicio 82" << endl;
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
//			GenerarArchivoVuelos();
//			break;
//		case 2:
//			GenerarArchivoPedidos();
//			break;
//		case 3:
//			ImprimirArchivoVuelos();
//			break;
//		case 4:
//			ImprimirArchivoPedidos();
//			break;
//		case 5:
//			EjecutarEjercicio();
//			break;
//		default:
//			cout << "--------opcion invalida, por favor ingrese una opcion valida!--------" << endl;
//			break;
//		}
//	} while (opcion != 0);
//}