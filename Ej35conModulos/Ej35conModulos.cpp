// Este codigo ha sido generado por el modulo psexport 20180802-w32 de PSeInt.
// Es posible que el codigo generado no sea completamente correcto. Si encuentra
// errores por favor reportelos en el foro (http://pseint.sourceforge.net).

#include<iostream>
using namespace std;

// Para las variables que no se pudo determinar el tipo se utiliza la constante
// SIN_TIPO. El usuario debe reemplazar sus ocurrencias por el tipo adecuado
// (usualmente int,float,string o bool).
#define SIN_TIPO string

// Para leer variables de texto se utiliza el operador << del objeto cin, que
// lee solo una palabra. Para leer una linea completa (es decir, incluyendo los
// espacios en blanco) se debe utilzar getline (ej, reemplazar cin>>x por
// getline(cin,x)), pero obliga a agregar un cin.ignore() si antes del getline
// se leyó otra variable con >>.

// Declaraciones adelantadas de las funciones
void imprimirresultados(int sumapos, int sumaneg, float promedio);
bool estaentre50100(float val);
float sacarpromedio(float valores, float cantidad);
void iniciarvariables(float& v1, float& v2, float& v3, float& v4);
void sumarvalores(float sumando, float& suma);

void imprimirresultados(int sumapos, int sumaneg, float promedio) {
	cout << "La suma de los positivos es " << sumapos << endl;
	cout << "La suma de los negativos es " << sumaneg << endl;
	cout << "El promedio de los valoresque estan entre 50 y 100 es " << promedio << endl;
}

bool estaentre50100(float val) {
	bool esta;
	if (val > 50 && val < 100) {
		esta = true;
	}
	else {
		esta = false;
	}
	return esta;
}

float sacarpromedio(float valores, float cantidad) {
	float promedio;
	if (cantidad == 0) {
		cout << "No hay valores para el promedio" << endl;
		promedio = 0;
	}
	else {
		promedio = valores / cantidad;
	}
	return promedio;
}

void iniciarvariables(int& v1, int& v2, int& v3, int& v4) {
	v1 = 0;
	v2 = 0;
	v3 = 0;
	v4 = 0;
}

void sumarvalores(int sumando, int& suma) {
	suma = suma + sumando;
}

int main() {
	int acum;
	int cont;
	int sumneg;
	int sumpos;
	int val;
	iniciarvariables(sumpos, sumneg, acum, cont);
	cout << "Ingrese un valor(corta con -9999)" << endl;
	cin >> val;
	while (val != -9999) {
		if (val > 0) {
			sumarvalores(val, sumpos);
			if (estaentre50100(val)) {
				acum = acum + val;
				cont = cont + 1;
			}
		}
		else {
			sumarvalores(val, sumneg);
		}
		cout << "Ingrese un valor(corta con -9999)" << endl;
		cin >> val;
	}
	imprimirresultados(sumpos, sumneg, sacarpromedio(acum, cont));
	return 0;
}

