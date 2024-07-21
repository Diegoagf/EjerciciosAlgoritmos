#define _CRT_SECURE_NO_DEPRECATE 
#include <iostream>
#include<fstream>
#include <string>
#include <stdio.h>

using namespace std;



struct tFinal {
	int legajo;
	int CodMat;
	char ApeNombre[26];
};

void GrabarAArch(tFinal VecFINALESACT[], int tope3) {
	FILE* AFinalAct = fopen("FinalesActualizados", "wb");
	for (int i = 0; i <= tope3; i++)
	{
		fwrite(&VecFINALESACT[i], sizeof(VecFINALESACT[i]), 1, AFinalAct);
	}
	fclose(AFinalAct);
}
void Apareo(tFinal v1[], int tope1, tFinal v2[], int tope2, tFinal v_apareo[], int& tope3) {
	int i = 0;
	int j = 0;
	int k = 0;

	tope3 = tope1 + tope2;
	while ((i <= tope1) && (j <= tope2)) {

		if (v1[i].CodMat < v2[j].CodMat) {
			v_apareo[k] = v1[i];
			i++;
		}
		else {
			v_apareo[k] = v2[j];
			j++;
		}
		k++;
	}

	if (i > tope1) {
		for (j; j <= tope2; j++) {
			v_apareo[k] = v2[j];
			k++;
		}
		/*
		while(j <= tope2) {
			v_apareo[k] = v2[j];
			k++;
			j++;
		}*/

	}

	else {
		for (i; i <= tope1; i++) {
			//while(i <= tope1)
			v_apareo[k] = v1[i];
			k++;
		}
	}
}
void ImprimirVector(tFinal Vector[], int tope) {
	cout << "||Legajo||" << "Cod Materia||" << "Alumno||" << endl;
	for (int j = 0; j <= tope; j++)
	{
		cout << "         " << Vector[j].legajo << "             " << Vector[j].CodMat << "              " << Vector[j].ApeNombre<< endl;
	}


}
void BuscarInsertar(tFinal Vector[], int& tope, tFinal regAbuscar) {
	int pos = 0;
	while ((pos <= tope) & (Vector[pos].CodMat <= regAbuscar.CodMat))
	{
		pos++;
	}
	if (pos <= tope) {
		for (int j = tope; j >= pos; j--)
		{
			Vector[j + 1] = Vector[j];
		}
	}
	Vector[pos] = regAbuscar;
	tope++;
}
void CargarVector(FILE* archivo,tFinal Vector[],int&tope) {
	tFinal Raux;
	tope = -1;
	while (fread(&Raux, sizeof(Raux), 1, archivo)) {  // o directamente fread(&VP[i], sizeof (VP[i]), 1, aProds)  sin la linea de abajo
		BuscarInsertar(Vector, tope, Raux);
	}
	fclose(archivo);
}


void GenerarArchivoFinales() {
	FILE* arch = fopen("Finales.dat", "w+b");
	tFinal Rfinal;
	cout << "Ingrese el legajo del alumno" << endl;
	cin >> Rfinal.legajo;
	while (Rfinal.legajo != 0) {
		cout << "Ingrese el codigo de materia" << endl;
		cin >> Rfinal.CodMat;

		cout << "Ingrese el Nombre y Apellido del Alumno" << endl;
		cin >> Rfinal.ApeNombre;

		fwrite(&Rfinal, sizeof(Rfinal), 1, arch);
		cout << "Ingrese el legajo del alumno" << endl;
		cin >> Rfinal.legajo;
	}


	fclose(arch);
};
void GenerarArchivoFinalesHoy() {
	FILE* arch = fopen("DiaFinales.dat", "w+b");
	tFinal Rfinal;
	cout << "Ingrese el legajo del alumno" << endl;
	cin >> Rfinal.legajo;
	while (Rfinal.legajo != 0) {
		cout << "Ingrese el codigo de materia" << endl;
		cin >> Rfinal.CodMat;

		cout << "Ingrese el Nombre y Apellido del Alumno" << endl;
		cin >> Rfinal.ApeNombre;

		fwrite(&Rfinal, sizeof(Rfinal), 1, arch);
		cout << "Ingrese el legajo del alumno" << endl;
		cin >> Rfinal.legajo;
	}


	fclose(arch);
};


void ImprimirArchivoFinales() {
	FILE* arch = fopen("Finales.dat", "rb");
	tFinal Registro;
	if (arch == NULL) {
		cout << "Error: No Existe el Archivo " << endl;
		return;
	}
	fread(&Registro, sizeof(Registro), 1, arch);
	while (!feof(arch))
	{
		cout << "|Legajo| " << "Cod Materia|" << "Alumno|" << endl;
		cout << Registro.legajo <<"   "<<Registro.CodMat<<"    "<<Registro.ApeNombre<< endl;
		fread(&Registro, sizeof(Registro), 1, arch);
	}
	fclose(arch);
}
void ImprimirArchivoFinalesHoy() {
	FILE* arch = fopen("DiaFinales.dat", "rb");
	tFinal Registro;
	if (arch == NULL) {
		cout << "Error: No Existe el Archivo " << endl;
		return;
	}
	fread(&Registro, sizeof(Registro), 1, arch);
	while (!feof(arch))
	{
		cout << "|Legajo| " << "Cod Materia|" << "Alumno|" << endl;
		cout << Registro.legajo << "   " << Registro.CodMat << "    " << Registro.ApeNombre << endl;
		fread(&Registro, sizeof(Registro), 1, arch);
	}
	fclose(arch);
}
void ImprimirArchivoFinalesAct() {
	FILE* arch = fopen("FinalesActualizados", "rb");
	tFinal Registro;
	if (arch == NULL) {
		cout << "Error: No Existe el Archivo " << endl;
		return;
	}
	cout << "|Legajo| " << "Cod Materia|" << "Alumno|" << endl;
	
	while (fread(&Registro, sizeof(Registro), 1, arch))
	{
		cout << Registro.legajo << "   " << Registro.CodMat << "    " << Registro.ApeNombre << endl;
	}
	fclose(arch);
}
void EjecutarEjercicio() {
	tFinal VecFINALES[100];
	tFinal VecDIAFINALES[100];
	tFinal VecFINALESACT[200];
	int tope1, tope2,tope3;
	FILE* Afinales = fopen("Finales.dat", "rb");
	FILE* AHoyfinales = fopen("DiaFinales.dat", "rb");
	CargarVector(Afinales, VecFINALES, tope1);
	CargarVector(AHoyfinales, VecDIAFINALES, tope2);
	/*ImprimirVector(VecFINALES, tope1);
	ImprimirVector(VecDIAFINALES, tope2);*/
	Apareo(VecFINALES, tope1, VecDIAFINALES, tope2, VecFINALESACT, tope3);
	ImprimirVector(VecFINALESACT, tope3);
	GrabarAArch(VecFINALESACT, tope3);

}

int main()
{
	int opcion;
	do {

		cout << "------------------------MENU------------------------" << endl;
		cout << "--------Selecciona una opcion(numero)--------" << endl;
		cout << "1- Generar Archivo  Finales" << endl;
		cout << "2- Generar Archivo  Finales HOY" << endl;
		cout << "3- Imprimir Archivo Finales" << endl;
		cout << "4- Imprimir Archivo Finales HOY" << endl;
		cout << "5- Ejecutar ej 91" << endl;
		cout << "6- Imprimir Archivo Finales ACTUALIZADO" << endl;
		cout << "0- Salir" << endl;
		cin >> opcion;

		switch (opcion)
		{
		case 0:
			cout << "--------Hasta Luego--------" << endl;
			cout << "--------Fin del Programa--------" << endl;
			break;
		case 1:
			GenerarArchivoFinales();
			break;
		case 2:
			GenerarArchivoFinalesHoy();
			break;
		case 3:
			ImprimirArchivoFinales();
			break;
		case 4:
			ImprimirArchivoFinalesHoy();
			break;
		case 5:
			EjecutarEjercicio();
			break;
		case 6:
			ImprimirArchivoFinalesAct();
			break;
		default:
			cout << "--------opcion invalida, por favor ingrese una opcion valida!--------" << endl;
			break;
		}
	} while (opcion != 0);

}




//91) Apareo de vectores
//Se dispone de dos vectores de no más de 100 elementos(puede cargarlos a partir de archivos), uno con la inscripción de alumnos a exámenes finales VecFINALES y otro con las inscripciones del día de hoy VecDIAFINALES, ambos ordenados ascendente por código de materia y con el siguiente diseño :
//
//a.1Nro de legajo(8 dígitos) 	a.2 Código de materia(6 dígitos) 	a.3 ApeNom(25caract)
//
//Se pide desarrollar un programa que genere un nuevo vector de inscripciones a finales VecFINALESACT resultante del apareo de los dos conjuntos anteriores, con el mismo orden y diseño.
//Luego de generado el vector, imprímalo con un módulo y luego grábelo con otro llamado GrabaAArch a un archivo VecFINALESACT.DAT
