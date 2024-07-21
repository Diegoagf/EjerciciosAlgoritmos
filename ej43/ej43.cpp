
#include<iostream>
using namespace std;

// Declaraciones adelantadas de las funciones
bool esmaximo(int val, int& max);
void imprimirressede(int emp2540, int suetotals);
void imprimirresgen(int sede, int empleado, int totalsueldos);
void manejosueldos(int sueldo, int& emp2540, int& suetotals, int& totalsue);

bool esmaximo(int val, int& max) {
	bool maximo;
	if (val > max) {
		max = val;
		maximo = true;
	}
	else {
		maximo = false;
	}
	return maximo;
}

void imprimirressede(int emp2540, int suetotals) {
	cout << "La cantidad de empleados que ganan entre 25mil 40mil pesos de esta sede es " << emp2540 << endl;
	cout << "El Importe total de sueldos a abonar por los empleados de esta sede " << suetotals << endl;
}

void imprimirresgen(int sede, int empleado, int totalsueldos) {
	cout << "El nro de sede con mayor cantidad de empleados es la " << sede << endl;
	if (empleado == 0) {
		cout << "No hay ningun empleado con TipoTarea 1" << endl;
	}
	else {
		cout << "DNI del empleado de TipoTarea 1, con mayor sueldo es " << empleado << endl;
	}
	cout << "El Importe total de sueldos a abonar entre todos los empleados de la empresa es " << totalsueldos << endl;
}

int main() {
	string bs;
	int cantemple;
	int cantemplemax;
	int dni;
	int dnimax;
	int emp2540;
	int n;
	int ns;
	int nsmax;
	int sue;
	int suemax;
	int suetotals;
	int totalsue;
	int tt;
	nsmax = 0;
	dnimax = 0;
	suemax = 0;
	totalsue = 0;
	cantemplemax = 0;
	for (n = 1; n <= 3; n++) {
		cantemple = 1;
		emp2540 = 0;
		suetotals = 0;
		cout << "Ingrese el numero de sede" << endl;
		cin >> ns;
		cout << "Ingrese el barrio de la sede" << endl;
		cin >> bs;
		cout << "Ingrese el Dni del empleado" << endl;
		cin >> dni;
		while (dni != 0) {
			cout << "Ingrese el Sueldo del empleado" << endl;
			cin >> sue;
			manejosueldos(sue, emp2540, suetotals, totalsue);
			cout << "Ingrese el Tipo de Tarea que realiza(1 a 5)" << endl;
			cin >> tt;
			if (tt == 1 && esmaximo(sue, suemax)) {
				dnimax = dni;
			}
			cout << "Ingrese el Dni del empleado" << endl;
			cin >> dni;
		}
		if (esmaximo(cantemple, cantemplemax)) {
			nsmax = ns;
		}
		imprimirressede(emp2540, suetotals);
	}
	imprimirresgen(nsmax, dnimax, totalsue);
	return 0;
}

void manejosueldos(int sueldo, int& emp2540, int& suetotals, int& totalsue) {
	totalsue = totalsue + sueldo;
	suetotals = suetotals + sueldo;
	if (sueldo > 25000 && sueldo < 40000) {
		emp2540 = emp2540 + 1;
	}
}

