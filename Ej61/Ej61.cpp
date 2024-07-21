//
//#include<iostream>
//using namespace std;
//
//#define ARREGLO_MAX 70
//
//struct Talumnno
//{
//	string nombre;
//	int edad;
//};
//void SumarValor(int ParaSumar, int& Sumatoria);
//float CalcularPromedio(int valores, int cantidad);
//
//
//int main() {
//	int ace;
//	Talumnno arrAlumnos[ARREGLO_MAX];
//	Talumnno Ralumno;
//	int cedad;
//	int edad;
//	int i;
//	int j;
//	int n;
//	float prom;
//	ace = 0;
//	cedad = 0;
//	cout << "Ingrese el numero de alumnos(max 70)" << endl;
//	cin >> n;
//	for (i = 0; i <= n - 1; i++) {
//		cout << "Ingrese el nombre del alumno" << endl;
//		cin >> Ralumno.nombre;
//		cout << "Ingrese la edad" << endl;
//		cin >> Ralumno.edad;
//		arrAlumnos[i] = Ralumno;
//		SumarValor(Ralumno.edad, ace);
//	}
//	prom = CalcularPromedio(ace, n);
//	cout << "El promedio de edad de los alumnos es " << prom << endl;
//	for (j = 0; j <= n - 1; j++) {
//		if (arrAlumnos[j].edad > prom) {
//			cout << "El alumno "<< arrAlumnos[j].nombre <<" con una edad de " << arrAlumnos[j].edad <<endl;
//		}
//	}
//	return 0;
//}
//
//float CalcularPromedio(int valores, int cantidad) {
//	if (cantidad != 0) {
//		return valores / cantidad;
//	}
//	else
//	{
//		cout << "No hay ningun alumno para sacar el promedio";
//		return 0;
//	}
//
//}
//
//void SumarValor(int ParaSumar, int& Sumatoria) {
//	Sumatoria = Sumatoria + ParaSumar;
//}
//
