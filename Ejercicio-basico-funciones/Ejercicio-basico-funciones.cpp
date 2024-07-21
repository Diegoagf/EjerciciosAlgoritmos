// Este codigo ha sido generado por el modulo psexport 20180802-w32 de PSeInt.
// Es posible que el codigo generado no sea completamente correcto. Si encuentra
// errores por favor reportelos en el foro (http://pseint.sourceforge.net).

#include<iostream>
using namespace std;


// Para leer variables de texto se utiliza el operador << del objeto cin, que
// lee solo una palabra. Para leer una linea completa (es decir, incluyendo los
// espacios en blanco) se debe utilzar getline (ej, reemplazar cin>>x por
// getline(cin,x)), pero obliga a agregar un cin.ignore() si antes del getline
// se leyó otra variable con >>.

// Declaraciones adelantadas de las funciones
int calcularsuma(int a, int b);
void calcularsumavoid(int a, int b, int& sumaref);

int calcularsuma(int a, int b) {
	int suma;
	suma = a + b;
	return suma;
}

int main() {
	int sumaref;
	int val1;
	int val2;
	cout << "Ingrese un 1er valor" << endl;
	cin >> val1;
	cout << "Ingrese un 2do valor" << endl;
	cin >> val2;
	cout << "La suma por no void es " << calcularsuma(val1, val2) << endl;
	calcularsumavoid(val1, val2, sumaref);
	cout << "La suma por void es " << sumaref << endl;
	return 0;
}

void calcularsumavoid(int a, int b, int& sumaref) {
	sumaref = a + b;
}

