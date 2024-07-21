#include <iostream>
using namespace std;

struct TProd {
	int codigo;
	float Pu;
	int CantVend;
};

struct TVenta {
	int cantvendida;
	int Stock;
};

struct TipoProd {
	float precio;
	string Desc;
	float Nuevoprecio;
};

struct ProdMenos {
	int cantVend;
	string Descripcion;
};


void CargaProd(TProd Productos[],int& n) {
	cout << "Ingrese N";
	cin >> n;
	for (int i; i <= n - 1; i++) {
		cout << "Ingrese codigo de prodcto";
		cin >> Productos[i].codigo;
		cout << "Ingrese Precio unitario";
		cin >> Productos[i].Pu;

		Productos[i].CantVend = 0;
	}
}


void ProcesarVentas(TVenta Productos[])  {
	int cod, cantVend;
	cout << "Ing Cód Prod entre 1 y 35 (0 para cortar)";
	cin >> cod;
	while (cod != 0) {
		cout << "Ing Cantidad Vendida del producto";
		cin >> cantVend;
		Productos[cod - 1].cantvendida = Productos[cod - 1].cantvendida + cantVend;
		Productos[cod - 1].Stock = Productos[cod - 1].Stock - cantVend;

		cout << "Ing Cód Prod entre 1 y 35 (0 para cortar)";
		cin >> cod;
	}

}

void AplicaDescuentos(TipoProd Productos[], float precio,int N) {
	for (int i = 0; i <= N - 1; i++) {
		if (Productos[i].precio>precio)
		{
			Productos[i].Nuevoprecio = Productos[i].precio - precio / 10;
			cout << Productos[i].Desc << endl;
		}
		else
		{
			Productos[i].Nuevoprecio = Productos[i].precio;
		}
	}
}

void ProdMenosVendidos(ProdMenos Prod[],string VDes[],int cantmin, int n,int& limMenor) {
	limMenor = 0;
	for (int i = 0; i <= n - 1; i++) {
		if (Prod[i].cantVend == cantmin) {
			VDes[i] = Prod[i].Descripcion;
			limMenor++;
		}
	}
}






int main() {
	TProd Productos[100];
	TVenta Ventas[100];
	TipoProd Prod[100];
	ProdMenos ProdMenores[100];
	string Vdesc[100];


	int N, cantMin, LimiteMenor;
	float p;
	CargaProd(Productos, N);
	ProcesarVentas(Ventas);
	AplicaDescuentos(Prod,p, N);
	ProdMenosVendidos(ProdMenores, Vdesc, cantMin, N, LimiteMenor);

}
