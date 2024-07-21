#include<iostream>
using namespace std;


float calcularimporte(float precio, float cantven);

float calcularimporte(float precio, float cantven) {
	float importe;
	importe = precio * cantven;
	return importe;
}

int main() {
	float arrprecios[4];
	int cantven;
	int nro;
	int nroprod;
	float precio;
	int prod;
	int producto;
	for (prod = 1; prod <= 4; prod++) {
		cout << "Ingrese nro del producto" << endl;
		cin >> nro;
		cout << "Ingrese precio del producto" << endl;
		cin >> arrprecios[nro - 1];
	}
	cout << "Ingrese nro del producto vendido" << endl;
	cin >> producto;
	while (producto != 0) {
		precio = arrprecios[producto - 1];
		cout << "Ingrese la cantidad vendida" << endl;
		cin >> cantven;
		cout << "El importe total de esta venta fue $ " << calcularimporte(precio, cantven) << endl;
		cout << "Ingrese nro del producto vendido" << endl;
		cin >> producto;
	}
	return 0;
}

