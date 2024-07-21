#include <iostream>
using namespace std;

//Error ( Conceptualmente esta bien)
void ProcesarVentas(int n, int VecCantVend[]) {
	int cantidades, cod;
	cout << "Ingrese el codigo de Producto entre 1 y " << n << " o 0 para cortar" << endl;
	cin >> cod;
	while (cod!=0)
	{
		cout << "Ingrese la cantidad vendidas de productos" << endl;
		cin >> cantidades;
		VecCantVend[cod - 1] = VecCantVend[cod - 1] + cantidades;
		cout << "Ingrese el codigo de Producto entre 1 y " << n << " o 0 para cortar" << endl;
		cin >> cod;
	}

}
//Consultar A que se refiere con la menor cantidad vendida? de todo el lote? (respondida en clase)
void ProdMenosVendidos(string VecDes[], int VecCantVend[], string VecDesMin[], int n) {
	int i;
	int cantmin = VecCantVend[0];
	for (i = 0; i <= n - 1; i++) {
		if (VecCantVend[i] <= cantmin) {
			cantmin = VecCantVend[i];
			VecDesMin[i] = VecDes[i];
		}
	}
}

//Consultar como Manejar Vector De cantVend;  y como manejar las variables de descripcion y precio.
void CargaProd(int VecCantVend[]) {

	int i, N;
	int VecDesc[100];
	float VecPU[100];
	cout << "Ingrese cuantos productos maneja" << endl;
	cin >> N;
	for (i = 0; i <= N - 1; i++) {
		cout << "Ingrese el Precio unitario del producto" << endl;
		cin >> VecPU[i];
		cout << "Ingrese la Descripcion del Producto" << endl;
		cin >> VecDesc[i];
		VecCantVend[i] = 0;
	}

}
//correcto, pero se puede hacer con registro
void CargaProd2(int VecCantVend[], string VecDesc[], float VecPU[],int& N) {

	int i;
	cout << "Ingrese cuantos productos maneja" << endl;
	cin >> N;
	for (i = 0; i <= N - 1; i++) {
		cout << "Ingrese el Precio unitario del producto" << endl;
		cin >> VecPU[i];
		cout << "Ingrese la Descripcion del Producto" << endl;
		cin >> VecDesc[i];
		VecCantVend[i] = 0;
	}

}

void AplicaDescuentos(float VecPU[], float precio, int N) {
	int i;
	for (i = 0; i <= N - 1; i++) {
		if (VecPU[i]>precio)
		{
			VecPU[i] = VecPU[i] - VecPU[i] / 10;
		}
	}
}

//Adaptado a los modulos y enunciado
int main(){
	int j,N;
	int VecCantVend[100];
	string VecDesc[100];
	string VecDesMin[100];
	float VecPU[100];
	float Precio = 50;

	CargaProd2(VecCantVend, VecDesc, VecPU, N);
	ProcesarVentas(N, VecCantVend);
	AplicaDescuentos(VecPU, Precio, N);
	ProdMenosVendidos(VecDesc, VecCantVend, VecDesMin, N);
	for (j = 0; j <= N - 1; j++) {
		cout << "Lista de Precios Unitarios" << endl;
		cout << VecPU[j] << endl;
		cout << "Productos Menos Vendidos" << endl;
		cout << VecDesMin[j] <<" Con una cantidad de "<< VecCantVend[j] << endl;

	}


}