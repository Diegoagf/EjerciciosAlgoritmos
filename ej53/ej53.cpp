#include<iostream>
#include <array>
using namespace std;
#include <iostream>
#define ARREGLO_MAX 100
int main()
{
	int alumnos[ARREGLO_MAX];
	int maxalun[ARREGLO_MAX];
	int nota;
	int iarray;
	int nmax;
	int Pnmax;
	iarray = 0;
	nmax = 0;
	cout << "Ingrese Nota final del alumno" << endl;
	cin >> nota;
	while (nota != 0)
	{
		alumnos[iarray] = nota;
		iarray++;
		cout << "Ingrese Nota final del alumno" << endl;
		cin >> nota;

	}
	for (int i = 0; i < 100; i++)
	{
		if (i==0|| alumnos[i]>nmax ) {
			nmax = alumnos[i];
		}
	}
	cout << "La nota maxima fue " << nmax << endl;
	cout << "La compartieron los alumnos" << endl;
	for (int j = 0; j < 100; j++)
	{
		if (alumnos[j] == nmax) {
			cout << j+1 << endl;
		}
	}
    
}