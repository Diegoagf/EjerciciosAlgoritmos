//#include<iostream>
//using namespace std;
//
//struct tAlumno {
//	string Nombre;
//	int Edad;
//};
//float SacarProm(int sum, int n) {;
//	if (n != 0) {
//		return sum / n;
//		
//	}
//	else {
//		cout << "No hay alumnos para sacar el promedio" << endl;
//		return 0;
//	}
//}
//
//int main() {
//	int i, n, acum; 
//	float prom;
//	acum = 0;
//	tAlumno VecAlumnos[70];
//	cout << "Ingrese la cantidad de alumnos" << endl;
//	cin >> n;
//	for (i = 0; i < n; i++) {
//		cout << "Ingrese el nombre del alumno" << endl;
//		cin >> VecAlumnos[i].Nombre;
//		cout << "Ingrese la edad del alumno" << endl;
//		cin >> VecAlumnos[i].Edad;
//		acum= acum + VecAlumnos[i].Edad;
//	}
//	prom = SacarProm(acum, n);
//	cout << "El promedio de los alumnos es " << prom << endl;
//
//	for (i = 0; i < n; i++) {
//		if (VecAlumnos[i].Edad > prom) {
//			cout << "El Alumno " << VecAlumnos[i].Nombre << " Supero el promedio con una edad de" << VecAlumnos[i].Edad << endl;
//		}
//	}
//
//
//}