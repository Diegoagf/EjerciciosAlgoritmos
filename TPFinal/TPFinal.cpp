#define _CRT_SECURE_NO_DEPRECATE 
#include <iostream>
#include<fstream>
#include <string>
#include <stdio.h>
#include<cstring>
using namespace std;

struct Alumno {
	int Leg;
	char NyAP[30];
	int Ant;
};
struct Materia {
	int Cod;
	char Nombre[30];
	int Cap;
};
struct MateriaVector {
	int Cod;
	char Nombre[30];
	int Cap;
	int  AcuAlu;
	int cantAlu;
};
struct Inscripcion {
	int Leg;
	int CodM;
};
struct Nodo {
	Alumno Info;
	Nodo* sgte;
};

void CargarVecAlu(FILE* fAlumnos, Alumno VecAlu[], int& tope1) {
	tope1 = 0;
	while (fread(&VecAlu[tope1],sizeof(VecAlu[tope1]),1,fAlumnos))
	{  
		tope1++;
	}
	tope1 = tope1 - 1;
}

void CargarVecMat(FILE* fMaterias, MateriaVector VecMat[],int&tope2) {
	tope2 = 0;
	Materia RMat;
	while (fread(&RMat, sizeof(RMat), 1, fMaterias))
	{
		MateriaVector Raux;
		Raux.Cod = RMat.Cod;
		strcpy(Raux.Nombre, RMat.Nombre);
		Raux.Cap = RMat.Cap;
		Raux.cantAlu = 0;
		Raux.AcuAlu = 0;
		VecMat[tope2] = Raux;
		tope2++;
	}
	tope2 = tope2 - 1;
}
int BuscarVecAlu(Alumno VecAlu[],int tope, int leg) {
	int pos = 0;
	while (pos <= tope && VecAlu[pos].Leg != leg)
	{
		pos++;
	}
	if (pos > tope) {
		return -1;
	}
	else
	{
		return pos;
	}
}

int BuscarVecMat(MateriaVector VecMat[], int tope, int cod) {
	int pos = 0;
	while (pos <= tope && VecMat[pos].Cod != cod)
	{
		pos++;
	}
	if (pos > tope) {
		return -1;
	}
	else
	{
		return pos;
	}
}
Nodo* BuscarLista(Nodo* lista, Alumno RInfo) {
	Nodo* ptr = lista;
	while (ptr!=NULL && ptr->Info.Leg!=RInfo.Leg)
	{
		ptr = ptr->sgte;
	}
	return ptr;
}

void InsOrdenado(Nodo*& lista, Alumno Rinfo) {
	Nodo* Pnuevo = new Nodo();
	Pnuevo->Info = Rinfo;
	if (lista == NULL ||strcmp(Rinfo.NyAP, lista->Info.NyAP)==-1){		
		Pnuevo->sgte = lista;
		lista = Pnuevo;
	}
	else {
		Nodo* ptr = lista;
		Nodo* antp = NULL;
		while (ptr!=NULL && strcmp(Pnuevo->Info.NyAP,ptr->Info.NyAP) >=0 )
		{
			antp = ptr;
			ptr = ptr->sgte;
		}
		antp->sgte = Pnuevo;
		Pnuevo->sgte = ptr;
	}
}

void InsOrdSinRepetir(Nodo*&lista, Alumno RInfo) {
	Nodo* pos = BuscarLista(lista, RInfo);
	if (pos == NULL) {
		InsOrdenado(lista,RInfo);
	}
}

void InformesxMat(MateriaVector VecMat[],int tope) {
	int AluNoIns = 0;
	for (int i = 0; i <= tope; i++)
	{	
		cout << "---MATERIA: " << VecMat[i].Nombre << " ---" << endl;
		if (VecMat[i].cantAlu != 0) {
			float prom = (float)VecMat[i].AcuAlu / VecMat[i].cantAlu;
			cout << "Promedio de antiguedad de los alumnos inscriptos: " << prom << " años"<<endl;
		}
		else
		{
			cout << "NO HAY INSCRIPTOS EN ESTA MATERIA" << endl;
			AluNoIns++;
		}
		
	}
	cout << "---------------------------------------------------" << endl;
	cout << "---Cantidad de Materias sin Alumnos Inscritos: " << AluNoIns << endl;
	cout << "---------------------------------------------------" << endl;
}

void InformeLista(Nodo* lista) {
	Nodo* ptr = lista;
	cout << "---LISTADO ALUMNOS NO INSCRIPTOS POR FALTA DE CAPACIDAD DE MATERIA---" << endl;
	cout << "||Nomb y AP||" << "Leg||" << endl;
	while (ptr!=NULL)
	{
		cout << "    " << ptr->Info.NyAP << "        " << ptr->Info.Leg << endl;
		ptr = ptr->sgte;
	}
}

void ProcesarInformacion() {
	Alumno VecAlu[1000];
	MateriaVector VecMat[40];
	int tope1, tope2;
	Nodo* listaAluNoIns = NULL;
	FILE* fAlumnos = fopen("Alumnos.dat", "r+b");
	FILE * fMaterias = fopen("Materias.dat", "r+b");
	CargarVecAlu(fAlumnos,VecAlu,tope1);
	CargarVecMat(fMaterias,VecMat,tope2);
	fclose(fAlumnos);
	fclose(fMaterias);

	FILE * fInscrip = fopen("Inscripciones.dat", "r+b");
	Inscripcion RIns;
	int acum =
	fread(&RIns, sizeof(RIns), 1, fInscrip);
	while (!feof(fInscrip)) {
		int posAlu = BuscarVecAlu(VecAlu, tope1,RIns.Leg);
		int posMat = BuscarVecMat(VecMat, tope2,RIns.CodM);
		if (posMat != -1 && posAlu!=-1) {
			if (VecMat[posMat].Cap>0) { 
			
				VecMat[posMat].AcuAlu += VecAlu[posAlu].Ant;
				VecMat[posMat].cantAlu++;
				VecMat[posMat].Cap--;
			}
			else
			{
				InsOrdSinRepetir(listaAluNoIns,VecAlu[posAlu]);
			}
		}
		fread(&RIns, sizeof(RIns), 1, fInscrip);
	}
	fclose(fInscrip);
	cout << "----INFORMES----" << endl;
	InformesxMat(VecMat, tope2); //Se informa primeramente la info por materia y luego los materias con 0 inscriptos, ya que se recorre una sola vez el vector( si se quiere informar primero las materias con 0 inscriptos se recorreria dos veces el vector)
	InformeLista(listaAluNoIns);

}

void GenerarArchivoInscripciones() {
	FILE* arch = fopen("Inscripciones.dat", "w+b");
	Inscripcion Registro;

	cout << "Ingrese el Legajo del alumno" << endl;
	cin >> Registro.Leg;
	while (Registro.Leg != 0) {
		cout << "Ingrese el codigo de la materia a Inscribir" << endl;
		cin >> Registro.CodM;

		fwrite(&Registro, sizeof(Registro), 1, arch);
		cout << "Ingrese el Legajo del alumno" << endl;
		cin >> Registro.Leg;
	}
	fclose(arch);
};

void GenerarArchivoMaterias() {
	FILE* arch = fopen("Materias.dat", "w+b");
	Materia Registro;

	cout << "Ingrese el codigo de la Materia" << endl;
	cin >> Registro.Cod;
	while (Registro.Cod != 0) {
		cout << "Ingrese el nombre de la materia" << endl;
		cin.ignore(numeric_limits<int>::max(), '\n');     //para limpiar el buffer
		cin.getline(Registro.Nombre, 30);

		cout << "Ingrese la Capacidad" << endl;
		cin >> Registro.Cap;

		fwrite(&Registro, sizeof(Registro), 1, arch);
		cout << "Ingrese el codigo de la Materia" << endl;
		cin >> Registro.Cod;
	}
	fclose(arch);
};

void GenerarArchivoAlumnos() {
	FILE* arch = fopen("Alumnos.dat", "w+b");
	Alumno Registro;

	cout << "Ingrese el Legajo del Alumno" << endl;
	cin >> Registro.Leg;
	while (Registro.Leg != 0) {
		cout << "Ingrese el Nombre y Apellido" << endl;
		cin.ignore(numeric_limits<int>::max(), '\n');     //para limpiar el buffer
		cin.getline(Registro.NyAP,30);     

		cout << "Ingrese los años de antiguedad" << endl;
		cin >> Registro.Ant;

		fwrite(&Registro, sizeof(Registro), 1, arch);
		cout << "Ingrese el Legajo del Alumno" << endl;
		cin >> Registro.Leg;
	}
	fclose(arch);
};

void ImprimirArchivoInscripciones() {
	FILE* arch = fopen("Inscripciones.dat", "r+b");
	Inscripcion Registro;
	if (arch == NULL) {
		cout << "Error: No Existe el Archivo " << endl;
		return;
	}
	cout << "||Legajo||" << "Cod Materia||" << endl;
	fread(&Registro, sizeof(Registro), 1, arch);
	while (!feof(arch))
	{
		cout << "    " << Registro.Leg << "           " << Registro.CodM << endl;
		fread(&Registro, sizeof(Registro), 1, arch);
	}
	fclose(arch);
}

void ImprimirArchivoMaterias() {
	FILE* arch = fopen("Materias.dat", "r+b");
	Materia Registro;
	if (arch == NULL) {
		cout << "Error: No Existe el Archivo " << endl;
		return;
	}
	cout << "||Cod||" << "Nombre||" << "Capacidad||" << endl;
	fread(&Registro, sizeof(Registro), 1, arch);
	while (!feof(arch))
	{
		cout << "   " << Registro.Cod << "      " << Registro.Nombre << "      " << Registro.Cap << endl;
		fread(&Registro, sizeof(Registro), 1, arch);
	}
	fclose(arch);
}


void ImprimirArchivoAlumnos() {
	FILE* arch = fopen("Alumnos.dat", "r+b");
	Alumno Registro;
	if (arch == NULL) {
		cout << "Error: No Existe el Archivo " << endl;
		return;
	}
	cout << "||Legajo||" << "Nombre y Ape||" << "Antiguedad||" << endl;
	fread(&Registro, sizeof(Registro), 1, arch);
	while (!feof(arch))
	{
		cout << "    " << Registro.Leg << "        " << Registro.NyAP << "          " << Registro.Ant << endl;
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
		cout << "1- Generar Archivo de ALUMNOS" << endl;
		cout << "2- Imprimir Archivo de ALUMNOS" << endl;
		cout << "3- Generar Archivo de MATERIAS" << endl;
		cout << "4- Imprimir Archivo de MATERIAS" << endl;
		cout << "5- Generar Archivo de INSCRIPCIONES" << endl;
		cout << "6 Imprimir Archivo de INSCRIPCIONES" << endl;
		cout << "7- Obtener Datos Estadisticos de las Inscripciones " << endl;
		cout << "0- Salir" << endl;
		cin >> opcion;

		switch (opcion)
		{
		case 0:
			cout << "--------Hasta Luego--------" << endl;
			cout << "--------Fin del Programa--------" << endl;
			break;
		case 1:
			GenerarArchivoAlumnos();
			break;
		case 2:
			ImprimirArchivoAlumnos();
			break;
		case 3:
			GenerarArchivoMaterias();
			break;
		case 4:
			ImprimirArchivoMaterias();
			break;
		case 5:
			GenerarArchivoInscripciones();
			break;
		case 6:
			ImprimirArchivoInscripciones();
			break;
		case 7:
			ProcesarInformacion();
			break;
		default:
			cout << "--------opcion invalida, por favor ingrese una opcion valida!--------" << endl;
			break;
		}
	} while (opcion != 0);
}
