#include<iostream>
using namespace std;

int  main() {
	int candidatos[10];
	int voto;
	int iarray;
	int cmax;
	int ganador;
	int cvoto = 0;
	iarray = 0;
	cout << "ELECCIONES 2022" << endl;
	for (int i = 0;  i < 10; i++)
	{
		candidatos[i] = cvoto;
	}
	cout << "Ingrese su voto" << endl;
	cin >> voto;
	while (voto!=0)
	{		
		candidatos[voto - 1] = candidatos[voto - 1] + 1;
		cout << "Ingrese su voto" << endl;
		cin >> voto;
	}
	for (int i = 0; i < 10; i++)
	{
		cout << "candidato "<< i+1 << " con un numero de votos "<<candidatos[i] << endl;
		if (i == 0 || candidatos[i] > cmax) {
			cmax = candidatos[i];
			ganador = i+1;
		}
	}
	cout << "El ganador de la eleccion fue el candidato " << ganador << endl;


}
