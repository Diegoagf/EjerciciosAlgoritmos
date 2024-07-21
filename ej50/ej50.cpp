
#include<iostream>
using namespace std;

#define ARREGLO_MAX 100
void SumarValor(int ParaSumar, int& Sumatoria);
float CalcularPromedio(int valores, int cantidad);


int main() {
	int ace;
	int arredad[ARREGLO_MAX];
	int cedad;
	int edad;
	int i;
	int j;
	int n;
	float prom;
	ace = 0;
	cedad = 0;
	cout << "Ingrese el numero de alumnos(max 70)" << endl;
	cin >> n;
	for (i = 0; i <= n - 1; i++) {
		cout << "Ingrese la edad" << endl;
		cin >> arredad[i];
		SumarValor(arredad[i], ace);
	}
	prom = CalcularPromedio(ace, n);
	cout << "El promedio de edad de los alumnos es " << prom << endl;
	for (j = 0; j <= n - 1; j++) {
		if (arredad[j] > prom) {
			SumarValor(1, cedad);
		}
	}
	cout << "La cantidad de edades que son mayores al promedio es " << cedad << endl;
	return 0;
}

float CalcularPromedio(int valores, int cantidad) {
	if (cantidad != 0){
		return valores/cantidad;
	}
	else
	{
		cout << "No hay ningun alumno para sacar el promedio";
		return 0;
	}
	
}

void SumarValor(int ParaSumar, int& Sumatoria) {
	Sumatoria = Sumatoria + ParaSumar;
}

