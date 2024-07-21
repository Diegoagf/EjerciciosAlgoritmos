#define _CRT_SECURE_NO_DEPRECATE 
#include <iostream>
#include<fstream>
#include <string>
#include <stdio.h>

using namespace std;
struct TSerie
{
	int idSerie;
	int temporada;
	int episodio;
	int descargas;
};


void EjecutarEjercicio() {
	FILE* fepisodios = fopen("Episodios.dat", "r+b");
	TSerie REp;
	cout << "---------------Listado de Descargas de Series---------------" << endl;
	int totalSeries = 0;
	int totalDesc = 0;
	fread(&REp, sizeof(REp), 1, fepisodios);
	while (!feof(fepisodios)) {

		cout << "Serie: " << REp.idSerie << endl;
		int totalDescSerie = 0;
		int totalEp = 0;
		int claveAnt = REp.idSerie;
		while ((!feof(fepisodios) && REp.idSerie==claveAnt))
		{	
			totalDescSerie = totalDescSerie + REp.descargas;
			totalDesc = totalDesc + REp.descargas;
			totalEp = totalEp + 1;
			cout << "    " << "|Temporada|" << "N de Episodio|"  << "Descargas|" << endl;
			cout << "    " << REp.temporada<< "                " << REp.episodio << "     " << REp.descargas << endl;
			fread(&REp, sizeof(REp), 1, fepisodios);
		}
		totalSeries = totalSeries + 1;
		cout << "----------------------------------------------------------------------------------------------" << endl;
		cout << "Cantidad Total de Episodios de la Serie: " << totalEp << endl;
		cout << "Total descargas de la Serie: " << totalDescSerie << endl;
		cout << "----------------------------------------------------------------------------------------------" << endl;
	}
	cout << "---------------------LISTADO FINAL---------------------" << endl;
	cout << "Cantidad Total de series: " << totalSeries << endl;
	cout << "Cantidad Total de descargas: " << totalDesc << endl;
}


void GenerarArchivoEpisodios() {
	FILE* fepisodios = fopen("Episodios.dat", "w+b");
	TSerie REp;

	cout << "Ingrese el id de la Serie" << endl;
	cin >> REp.idSerie;
	while (REp.idSerie != 0) {
		cout << "Ingrese el numero de Temporada" << endl;
		cin >> REp.temporada;

		cout << "Ingrese el numero de Episodio" << endl;
		cin >> REp.episodio;

		cout << "Ingrese la cantidad de Descargas" << endl;
		cin >> REp.descargas;

		fwrite(&REp, sizeof(REp), 1, fepisodios);
		cout << "Ingrese el id de la Serie" << endl;
		cin >> REp.idSerie;
	}
	fclose(fepisodios);
};


void ImprimirArchivoEpisodios() {
	FILE* fepisodios = fopen("Episodios.dat", "r+b");
	TSerie Registro;
	if (fepisodios == NULL) {
		cout << "Error: No Existe el Archivo " << endl;
		return;
	}
	cout << "||Id Serie||" << "Temporada||" << "Episodio||" << "Descargas||" << endl;
	while (fread(&Registro, sizeof(Registro), 1, fepisodios))
	{
		cout << Registro.idSerie << "             " << Registro.temporada << "           " << Registro.episodio <<"        "<< Registro.descargas << endl;
	}
	fclose(fepisodios);
}


int main() {

	int opcion, limProd;
	do {

		cout << "------------------------MENU------------------------" << endl;
		cout << "--------Selecciona una opcion(numero)--------" << endl;
		cout << "1- Generar Archivo de Episodios" << endl;
		cout << "2- Imprimir Archivo de Episodios" << endl;
		cout << "3- Ejecutar Ejercicio 94" << endl;
		cout << "0- Salir" << endl;
		cin >> opcion;

		switch (opcion)
		{
		case 0:
			cout << "--------Hasta Luego--------" << endl;
			cout << "--------Fin del Programa--------" << endl;
			break;
		case 1:
			GenerarArchivoEpisodios();
			break;
		case 2:
			ImprimirArchivoEpisodios();
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