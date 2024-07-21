//#include <iostream>
//using namespace std;
//
//struct Tvuelo
//{
//	int codigo;
//	int PasajeDisponibles;
//	int PasajesRechazados;
//};
//struct TVenta
//{
//	int codigoVuelo;
//	int PasajeSolicitados;
//};
//
//
//
//int BuscarEnVector(Tvuelo PasajesDisponibles[], int limite, int codigo);
//void Informes(Tvuelo PasajesDisponibles[], int limite);
//void Venta(Tvuelo& vuelo, int pasSolic, int limite);
//
//int main() {
//	int i,N;
//	Tvuelo Rvuelo;
//	TVenta Rventa;
//	Tvuelo PasajesDisponibles[500];
//	cout << "Ingrese la cantidad de vuelos" << endl;
//	cin >> N;
//	for (i = 0; i < N; i++) {
//		cout << "Ingrese el codigo de vuelo" << endl;
//		cin >> PasajesDisponibles[i].codigo;
//		cout << "Ingrese la cantidad de pasajes Disponibles" << endl;
//		cin >> PasajesDisponibles[i].PasajeDisponibles;
//	    PasajesDisponibles[i].PasajesRechazados = 0;
//	}
//	cout << "Ingrese el codigo de vuelo vendido( 0 para cortar)" << endl;
//	cin >> Rventa.codigoVuelo;
//	while (Rventa.codigoVuelo != 0)
//	{
//		int posicion = BuscarEnVector(PasajesDisponibles, N, Rventa.codigoVuelo);
//		cout << endl<<posicion;
//		cout << "Ingrese la cantidad de Pasajes Que desea comprar" << endl;
//		cin >> Rventa.PasajeSolicitados;
//		Venta(PasajesDisponibles[posicion], Rventa.PasajeSolicitados, N);
//
//		cout << "Ingrese el codigo de vuelo vendido( 0 para cortar)" << endl;
//		cin >> Rventa.codigoVuelo;
//	}
//	Informes(PasajesDisponibles, N);
//
//}
//
//int BuscarEnVector(Tvuelo PasajesDisponibles[],int limite,int codigo) {
//	for (int j = 0; j < limite; j++) {
//		if (PasajesDisponibles[j].codigo == codigo)
//		{
//			return j;
//		}		
//	}
//}
//void Venta(Tvuelo& vuelo, int pasSolic,int limite) {
//	if (pasSolic <= vuelo.PasajeDisponibles) {
//		cout << "COMPRA REALIZADA CON EXITO" << endl;
//		cout << "-------------------------------------------------------" << endl;
//		cout << "Codigo  de Vuelo " <<vuelo.codigo << endl;
//		cout << "Pasajes Comprados " << pasSolic << endl;
//		vuelo.PasajeDisponibles = vuelo.PasajeDisponibles - pasSolic;
//
//	}
//	else {
//		cout << "No se puede hacer esta Venta"<< endl;
//		vuelo.PasajesRechazados = vuelo.PasajesRechazados + pasSolic;
//	}
//}
//void Informes(Tvuelo PasajesDisponibles[],int limite) {
//	cout << "FIN DEL PROGRAMA" << endl;
//	cout << "-------------------------------------------------------" << endl;
//	for (int ind = 0; ind < limite; ind++) {	
//		cout << "Codigo  de Vuelo " << PasajesDisponibles[ind].codigo << endl;
//		cout << "Pasajes Disponibles " << PasajesDisponibles[ind].PasajeDisponibles << endl;
//		cout << "Total Pasajes Rechazados " << PasajesDisponibles[ind].PasajesRechazados << endl;
//		cout << "-------------------------------------------------------" << endl;
//	}
//
//}