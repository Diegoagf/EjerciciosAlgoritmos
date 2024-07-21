#define _CRT_SECURE_NO_DEPRECATE 
#include <iostream>
#include<fstream>
#include <string>
#include <stdio.h>

using namespace std;



struct tAlumno {
	int Leg;
	string Mat; // No usar string
	float Par1;
	float Par2;
	float RecP1;
	float RecP2;
	bool aprobado;
};

int Promociona(tAlumno alumno) {
	if (alumno.aprobado) {
		if (alumno.Par1 >= 8 && alumno.Par2 >= 8) {
			return 1;
		}
		if (alumno.RecP1 >= 8 && alumno.Par2 >= 8) {
			return 1;
		}
		if (alumno.RecP2 >= 8 && alumno.Par1 >= 8) {
			return 1;
		}
		return 0;
	}
	return 0;
}


bool Aprobo(int par1, int par2, int rec1, int rec2) {
	if (rec1 != 0 || rec2 != 0) {
		if (rec1>=6 && par2>=6) {
			return true;
		}
		if (rec2 >= 6 && par1 >= 6) {
			return true;
		}
		if (rec1 >= 6 && rec2 > 6) {
			return true;
		}
		return false;
	}
	else {
		if (par1 >= 6 && par2 >= 6) {
			return true;
		}
		else {
			return false;
		}
	}
}

void GenerarArchivo() {
	FILE* arch = fopen("NotasAlumnos.dat", "w+b");
	tAlumno alumno;
	string materia;

	cout << "Ingrese la Materia" << endl;
	cin >> materia;
	cout << "Ingrese el legajo del alumno" << endl;
	cin >> alumno.Leg;
	while (alumno.Leg != 0) {
		alumno.Mat = materia;
		alumno.RecP1 = 0;
		alumno.RecP2 = 0;

		cout << "Ingrese Nota del 1er Parcial" << endl;
		cin >> alumno.Par1;
		if (alumno.Par1 < 6) {
			cout << "Ingrese Nota del 1er Recperatorio del Parcial" << endl;
			cin >> alumno.RecP1;
		}
		cout << "Ingrese Nota del 2do Parcial" << endl;
		cin >> alumno.Par2;
		if (alumno.Par2 < 6) {
			cout << "Ingrese Nota del 2do Recperatorio del Parcial" << endl;
			cin >> alumno.RecP2;
		}
		alumno.aprobado= Aprobo(alumno.Par1,alumno.Par2,alumno.RecP1,alumno.RecP2);
		fwrite(&alumno, sizeof(alumno), 1, arch);
		cout << "Ingrese el legajo del alumno" << endl;
		cin >> alumno.Leg;
	}


	fclose(arch);
};


void ImprimirArchivo() {
	FILE* arch = fopen("NotasAlumnos.dat", "r+b");
	tAlumno alu;
	if (arch == NULL) {
		cout << "Error: No Existe el Archivo " << endl;
	}
	else {
		cout << "||Legajo||" <<"Materia||" <<"1P||" <<"2P||" <<"1R||" <<"2R||" << endl;
		fread(&alu, sizeof(alu), 1, arch);
		while (!feof(arch))
		{
			cout <<"     "<< alu.Leg << "    " << alu.Mat << "    " << alu.Par1 << "   " << alu.Par2 << "   " << alu.RecP1 << "   " << alu.RecP2 << endl;
			fread(&alu, sizeof(alu), 1, arch);
		}
		fclose(arch);
	}
	
}

void ProcesarArchivo() {
	FILE* arch = fopen("NotasAlumnos.dat", "r+b");
	tAlumno alu;
	int Promocionados = 0;
	string linea;
	if (arch == NULL) {
		cout << "Error: No Existe el Archivo " << endl;
	}
	else
	{
		cout << "------Aprobados------" << endl;
		cout << "||Legajo||" << endl;
		fread(&alu, sizeof(alu), 1, arch);
		while (!feof(arch)) {
			if (alu.aprobado) {			
				cout << "     " << alu.Leg << endl;
				Promocionados = Promocionados + Promociona(alu);								
				
			}
			fread(&alu, sizeof(alu), 1, arch);
		}
		cout << "------Promocionados------" << endl;
		cout << " La cantidad de Promocionados es " << Promocionados << endl;
		fclose(arch);
	}
	
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
	} while (opcion != 0);

}


