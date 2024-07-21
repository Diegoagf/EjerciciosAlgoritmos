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
void verificarvalor1020(float val, bool& hubo);
void imprimirresultado(bool& flag);

int main() {
	bool flag;
	int val;
	flag = false;
	cout << "Ingrese un valor" << endl;
	cin >> val;
	while (val != 0) {
		verificarvalor1020(val, flag);
		cout << "Ingrese un valor" << endl;
		cin >> val;
	}
	imprimirresultado(flag);
	return 0;
}

void verificarvalor1020(float val, bool& hubo) {
	if (val > 10 && val < 20) {
		hubo = true;
	}
}

void imprimirresultado(bool& flag) {
	if (flag == true) {
		cout << "Hubo un valor entre 10 y 20" << endl;
	}
	else {
		cout << "No hubo un valor entre 10 y 20" << endl;
	}
}

