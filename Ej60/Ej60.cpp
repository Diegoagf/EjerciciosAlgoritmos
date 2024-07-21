#include <iostream>
using namespace std;


struct Producto {
	int codigo;
	float precio;
};
struct ProductoVendido {
	int codigo;
	int cantven;
};
float calcularimporte(float precio, float cantven);

float calcularimporte(float precio, float cantven) {
	float importe;
	importe = precio * cantven;
	return importe;
}


int main()
{
	int arrprecios[2];
	int cantven;
	int nroprod;
	float precio;
	int pd;
	Producto prod;
	ProductoVendido Prds;
	for (pd = 0; pd < 2; pd++) {
		cout << "Ingrese el codigo del producto(1 a 10)" << endl;
		cin >> prod.codigo;
		cout << "Ingrese precio del producto" << endl;
		cin >> prod.precio;
		arrprecios[prod.codigo-1] = prod.precio;
	}
	cout << "Ingrese codigo del producto VENDIDO" << endl;
	cin >> Prds.codigo;
	while (Prds.codigo != 0) {
		precio = arrprecios[Prds.codigo - 1];
		cout << "Ingrese la cantidad vendida" << endl;
		cin >> Prds.cantven;
		cout << "El importe total de esta venta fue $ " << calcularimporte(precio, Prds.cantven) << endl;
		cout << "Ingrese nro del producto vendido" << endl;
		cin >> Prds.codigo;
	}
	return 0;
}