#define _CRT_SECURE_NO_DEPRECATE 
#include <iostream>
#include<fstream>
#include <string>
#include <stdio.h>

using namespace std;



struct tAlumno {
	int legajo;
	char ApeNombre[31];
	char Domicilio[21];
	int CodPostal;
	int  Tel;
	int Ingreso;
	char codOp;
};

void ApareoArchivos(FILE* archivo1,FILE* archivo2, FILE* actualizado) {
	tAlumno RAluA;
	tAlumno RNov;
	
	fread(&RAluA, sizeof(RAluA), 1, archivo1);
	fread(&RNov, sizeof(RNov), 1, archivo2);
	while((!feof(archivo1)) && (!feof(archivo2))){
		if (RAluA.legajo < RNov.legajo) { // es decir el alumno está en Alumnos y no en Novedades
			fwrite(&RAluA, sizeof(RAluA), 1, actualizado);
			fread(&RAluA, sizeof(RAluA), 1, archivo1);
		}
		if (RNov.legajo < RAluA.legajo) { // es decir el alumno está en Novedades y no en Alumnos
			switch (RNov.codOp)
			{
			case'A':
				fwrite(&RNov, sizeof(RNov), 1, actualizado);
				fread(&RNov, sizeof(RNov), 1, archivo2);
				break;
			case'B':
				cout << "ERROR - Baja Inexistente" << endl;
				fread(&RNov, sizeof(RNov), 1, archivo2);
				break;
			case'M':
				cout << "ERROR - Modificacion Inexistente" <<endl;
				fread(&RNov, sizeof(RNov), 1, archivo2);
				break;
			}
		}

		if (RAluA.legajo == RNov.legajo) // es decir el alumno está en ambos archivos
		{
			switch (RNov.codOp)
			{
			case'A':
				cout << "AVISO: ALTA DUPLICADA!";
				fwrite(&RAluA, sizeof(RAluA), 1, actualizado);
				fread(&RAluA, sizeof(RAluA), 1, archivo1);
				fread(&RNov, sizeof(RNov), 1, archivo2);
				break;
			case'B':
				//Al no copiar ningun registro, No estará en el nuevo archivo.
				fread(&RNov, sizeof(RNov), 1, archivo2);
				fread(&RAluA, sizeof(RAluA), 1, archivo1);
				break;
			case'M':
				fwrite(&RNov, sizeof(RNov), 1, actualizado);
				fread(&RAluA, sizeof(RAluA), 1, archivo1);
				fread(&RNov, sizeof(RNov), 1, archivo2);
				break;
			}

		}
	}
	if (!feof(archivo1)) //QUEDAN DATOS EN EL ARCHIVO1 PERO NO EN ARCHIVO 2
	{		while (!feof(archivo1)){
			fwrite(&RAluA, sizeof(RAluA), 1, actualizado);
			fread(&RAluA, sizeof(RAluA), 1, archivo1);
			}
	}
	else //QUEDAN DATOS EN EL ARCHIVO2 PERO NO EN ARCHIVO 1
	{
		while (!feof(archivo2)) {
			fwrite(&RNov, sizeof(RNov), 1, actualizado);
			fread(&RNov, sizeof(RNov), 1, archivo2);
		}
	}
	fclose(archivo1);
	fclose(archivo2);
	fclose(actualizado);
}

void BuscarInsertar(tAlumno Vector[], int& tope, tAlumno regAbuscar) {
	int pos = 0;
	while ((pos <= tope) & (Vector[pos].legajo <= regAbuscar.legajo))
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
void CargarVector(FILE* archivo, tAlumno Vector[], int& tope) {
	tAlumno Raux;
	tope = -1;
	while (fread(&Raux, sizeof(Raux), 1, archivo)) {  
		BuscarInsertar(Vector, tope, Raux);
	}
	fclose(archivo);
}


void GenerarArchivoAlumnos() {
	FILE* arch = fopen("Alumnos.dat", "w+b");
	tAlumno Ralu;
	cout << "Ingrese el legajo del alumno" << endl;
	cin >> Ralu.legajo;
	while (Ralu.legajo != 0) {

		cout << "Ingrese el Nombre y Apellido del Alumno" << endl;
		cin >> Ralu.ApeNombre;

		cout << "Ingrese el Domicilio" << endl;
		cin >> Ralu.Domicilio;

		cout << "Ingrese el codigo Postal" << endl;
		cin >> Ralu.CodPostal;

		cout << "Ingrese el Telefono" << endl;
		cin >> Ralu.Tel;

		cout << "Ingrese el ano de Ingreso" << endl;
		cin >> Ralu.Ingreso;

		fwrite(&Ralu, sizeof(Ralu), 1, arch);
		cout << "Ingrese el legajo del alumno" << endl;
		cin >> Ralu.legajo;
	}
	fclose(arch);
};
void GenerarArchivoNovedades(){
	FILE* arch = fopen("Novedades.dat", "w+b");
	tAlumno Ralu;
	cout << "Ingrese el legajo del alumno" << endl;
	cin >> Ralu.legajo;
	while (Ralu.legajo != 0) {

		cout << "Ingrese el Nombre y Apellido del Alumno" << endl;
		cin >> Ralu.ApeNombre;

		cout << "Ingrese el Domicilio" << endl;
		cin >> Ralu.Domicilio;

		cout << "Ingrese el codigo Postal" << endl;
		cin >> Ralu.CodPostal;

		cout << "Ingrese el Telefono" << endl;
		cin >> Ralu.Tel;

		cout << "Ingrese el ano de Ingreso" << endl;
		cin >> Ralu.Ingreso;

		cout << "Ingrese el codigo de operacion" << endl;
		//limpiamos el buffer de entrada
		cin.ignore(numeric_limits<int>::max(), '\n');
		cin.get(Ralu.codOp);

		fwrite(&Ralu, sizeof(Ralu), 1, arch);
		cout << "Ingrese el legajo del alumno" << endl;
		cin >> Ralu.legajo;
	}
	fclose(arch);
};


void ImprimirArchivoAlumnos() {
	FILE* arch = fopen("Alumnos.dat", "rb");
	tAlumno Registro;
	if (arch == NULL) {
		cout << "Error: No Existe el Archivo " << endl;
		return;
	}
	fread(&Registro, sizeof(Registro), 1, arch);
	cout << "|Legajo| " << "NombreApellido|" << "Domicilio|" <<"CodPostal|"<<"    Telf   |"<<"AnoIngreso|"<< endl;
	while (!feof(arch))
	{

		cout << " " << Registro.legajo << "       " << Registro.ApeNombre << "              " << Registro.Domicilio << "        " << Registro.CodPostal << "      " << Registro.Tel << "      " << Registro.Ingreso << endl;
		fread(&Registro, sizeof(Registro), 1, arch);
	}
	fclose(arch);
}
void ImprimirArchivoNovedades() {
	FILE* arch = fopen("Novedades.dat", "rb");
	tAlumno Registro;
	if (arch == NULL) {
		cout << "Error: No Existe el Archivo " << endl;
		return;
	}
	fread(&Registro, sizeof(Registro), 1, arch);
	cout << "|Legajo| " << "NombreApellido|" << "Domicilio|" << "CodPostal|" << "Telf|" << "AnoIngreso|" <<"CodOp|"<< endl;
	while (!feof(arch))
	{
		cout << " " << Registro.legajo << "       " << Registro.ApeNombre << "              " << Registro.Domicilio << "        " << Registro.CodPostal << "      " << Registro.Tel << "      " << Registro.Ingreso << "    " << Registro.codOp <<endl;
		fread(&Registro, sizeof(Registro), 1, arch);
	}
	fclose(arch);
}
void ImprimirArchivoAlumnosAct() {
	FILE* arch = fopen("AlumnosActualizado.dat", "rb");
	tAlumno Registro;
	if (arch == NULL) {
		cout << "Error: No Existe el Archivo " << endl;
		return;
	}
	fread(&Registro, sizeof(Registro), 1, arch);
	cout << "|Legajo| " << "NombreApellido|" << "Domicilio|" << "CodPostal|" << "  Telf  |" << "AnoIngreso|" << endl;
	while (!feof(arch))
	{

		cout << " " << Registro.legajo << "       " << Registro.ApeNombre << "              " << Registro.Domicilio << "        " << Registro.CodPostal << "      " << Registro.Tel << "      " << Registro.Ingreso << endl;
		fread(&Registro, sizeof(Registro), 1, arch);
	}
	fclose(arch);
}
void EjecutarEjercicio() {
	FILE* falumnos = fopen("Alumnos.dat", "rb");;
	FILE* fnovedades = fopen("Novedades.dat", "rb");
	FILE* factualizado = fopen("AlumnosActualizado.dat", "w+b");
	ApareoArchivos(falumnos,fnovedades,factualizado);
	cout << "Se Genero un Nuevo Archivo Actualizado con EXITO!" << endl;

}

int main()
{
	int opcion;
	do {

		cout << "------------------------MENU------------------------" << endl;
		cout << "--------Selecciona una opcion(numero)--------" << endl;
		cout << "1- Generar Archivo  Alumnos" << endl;
		cout << "2- Generar Archivo  Noverdad" << endl;
		cout << "3- Imprimir Archivo Alumnos" << endl;
		cout << "4- Imprimir Archivo Novedades" << endl;
		cout << "5- Ejecutar Apareo" << endl;
		cout << "6- Imprimir Archivo Alumnos ACTUALIZADO" << endl;
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
			GenerarArchivoNovedades();
			break;
		case 3:
			ImprimirArchivoAlumnos();
			break;
		case 4:
			ImprimirArchivoNovedades();
			break;
		case 5:
			EjecutarEjercicio();
			break;
		case 6:
			ImprimirArchivoAlumnosAct();
			break;
		default:
			cout << "--------opcion invalida, por favor ingrese una opcion valida!--------" << endl;
			break;
		}
	} while (opcion != 0);

}

