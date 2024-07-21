// Ejercicios.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
using namespace std;
using std::cout; 
using std::cin; 
using std::endl;

//void ej21()
//{
//    int cantidad, valoruno,valordos,suma;
//    cout << "Hola!\n";
//    cout << "Ingrese la cantidad de pares de valores\n";
//    cin >> cantidad;
//    for (size_t i = 0; i < cantidad; i++)
//    {
//        cout << "\nIngrese el primer valor\n";
//        cin >> valoruno;
//        cout << "Ingrese el segundo valor\n";
//        cin >> valordos;
//        suma = valoruno + valordos;
//        cout <<"La suma es ";
//        cout << suma;
//    }
//
//}
//void main()
//{
//    int zona, valoruno, valordos, suma;
//    bool flag = true;
//    cout << "Ingresar una Zona entera entre 1 y 10\n";
//    cin >> zona;
//    while(flag)
//    {        
//        
//        if (0 <=zona && zona<= 10) {
//            flag = false;
//        }
//        else {
//            cout << "Dije Ingresar una Zona entera entre 1 y 10\n";
//            cin >> zona;
//        }
//    }
// 
//    cout << "Zona ok entre 1 y 10";
//
//}
// 
//void main()
//{
//    int zona, valoruno, valordos, suma;
//    bool flag = false; 
//    do
//    {
//        cout << "Ingresar una Zona entera entre 1 y 10\n";
//        cin >> zona;
//        if (0 <= zona && zona <= 10) {
//            flag = true;
//        }
//    } while (!flag);    
//    cout << "Zona ok entre 1 y 10";
//
//}
//void main()
//{
//    //Ejercicio 32
//    int l1, l2, l3, total, per, equi, isoc, esc;
//    total = 0; per = 0; esc = 0; equi = 0; isoc = 0; esc = 0; 
//    cout << "Ingrese primer lado\n";
//    cin >> l1;
//    while (l1>0)
//    {       
//        cout << "Ingrese segundo lado\n";
//        cin >> l2;
//        cout << "Ingrese tercer lado\n";
//        cin >> l3;
//        if (l1 == l2 && l2==l3)
//        {            
//            equi++;
//        }
//        if (l1!=l2 && l2!=l3 && l1!=l3)
//        {
//            esc++;
//        }
//        if (l1==l2 || l2==l3 || l1==l3)
//        {            
//            isoc++;
//        }
//        
//        per = l1 + l2 + l3;
//        cout << "perimetro= ";
//        cout << per;
//        total = total + per;
//        cout << "Ingrese primer lado\n";
//        cin >> l1;
//    }
//    cout << "La suma de todos los perimetros es ";
//    cout << total;
//    cout << "\n";
//    cout << "Total de triangulos Equilateros: ";
//    cout << equi;
//    cout << "\n";
//    cout << "Total de triangulos Isoceles: ";
//    cout << isoc;
//    cout << "\n";
//    cout << "Total de triangulos Escalenos: ";
//    cout << esc;
//    
//}

//int main(){
// Ejercicio  34
//	int alumnos, nota, promo, acum, aprob;
//	double prom;
//	promo = 0; acum = 0; aprob = 0; prom = 0;
//	cout << "Ingrese la cantidad de alumnos del curso\n";
//	cin >> alumnos;
//	for (size_t i = 1; i <=alumnos; i++)
//	{
//		cout << "Ingrese nota del ";
//		cout << i; cout << "\n";
//		cin >> nota;
//		if (nota >= 6) {
//			acum = acum + nota;
//			aprob++;
//		}
//		if(nota>=8)
//		{
//			promo++;
//		}
//	}
//	if (aprob!=0){
//		prom = acum / aprob;
//		cout << "El promedio de los que aprobaron es ";
//		cout << prom;
//	}
//	else
//	{
//		cout << "El promedio de los que aprobaron es 0";
//	}
//	cout << "\n";
//	cout << "La cantidad de los que promocionaron es ";
//	cout << promo;
//}

//int main() {
//	//Ejercicio 37
//	int valor, maximo, contador, posmax, minimo,maxrang;
//	maximo = INT16_MIN; contador = 0; posmax = 0; minimo = INT_MAX; maxrang = INT16_MIN;
//	cout << "Ingrese valor( 0 Detiene)\n";
//	cin >> valor;
//	while (valor!=0)
//	{
//		contador++;
//		if(valor>maximo)
//		{
//			maximo = valor;
//			posmax = contador;
//		}
//		if (valor > 0)
//		{
//			if (valor < minimo) {
//				minimo = valor;
//			}
//		}
//		if (valor >= -500 && valor <= -200) {
//			if (valor > maxrang) {
//				maxrang = valor;
//			}
//		}
//		cout << "Ingrese valor( 0 Detiene)\n";
//		cin >> valor;
//	}
//	cout << "El  mayor valor del cojunto es ";
//	cout << maximo;
//	cout << "\nEl maximo esta en la posicion: ";
//	cout << posmax;
//	cout << "\nEl  menor valor positivo del cojunto es ";
//	cout << minimo;
//	cout << "\nEl  mayor valor del cojunto entre -500 a -200 es ";
//	cout << maxrang;
//
//}

//int main() {
//	//Ejercicio 38
//	int valor;
//	bool Hay;
//	Hay = false;
//	cout << "Ingrese valor( 0 Detiene)\n";
//	cin >> valor;
//	while (valor!=0)
//	{
//		if (valor > 10 && valor < 20) 
//		{
//			Hay = true;
//		}
//		cout << "Ingrese valor( 0 Detiene)\n";
//		cin >> valor;
//	}
//	if (Hay) 
//	{
//		cout << "Hubo un valor entre 10 y 20";
//	}
//	else
//	{
//		cout << "NO Hubo un valor entre 10 y 20";
//	}
//
//}
int main() {
	//Ejercicio 39
	int edad, dni, tramite, empleados, maxedad, cedad, acedad;
	double prom;
	empleados = 0; maxedad = -INFINITY; cedad = 0; acedad = 0;
	bool prioritario, flagprio;
	flagprio = false;
	string nombreApellido, respuesta, NombreMaximo;
	NombreMaximo = "";
	cout << "Ingrese DNI (0 Detiene)\n";
	cin >> dni;
	while (dni != 0)
	{
		cout << "Ingrese Nombre y Apellido\n";
		cin >> nombreApellido;
		cout << "Ingrese Edad\n";
		cin >> edad;
		cout << "Ingrese Tipo de Tramite(1-5)\n";
		cin >> tramite;
		cout << "Prioritario(Si o No)\n";
		cin >> respuesta;
		if (respuesta == "Si" || respuesta == "si") {
			prioritario = true;
		}
		else {
			prioritario = false;
		}
		cout << "Ingrese DNI (0 Detiene)\n";
		cin >> dni;

		if (tramite == 2 || tramite == 4)
		{
			empleados++;
		}

		if (prioritario && (tramite == 1 || tramite == 2 | tramite == 3)) {

			acedad = acedad + edad;
			cedad++;
		}

		if (tramite == 1 || tramite == 5)
		{
			if (edad > maxedad)
			{
				maxedad = edad;
				NombreMaximo = nombreApellido;
			}

		}
		if (prioritario && edad < 30)
		{
			flagprio = true;
		}
	}
	cout << "Cantidad de empleados que esperan para el tipo de trámite 2 o 4: ";
	cout << empleados;
	cout << "\nEdad promedio de los clientes Prioritarios que esperan para los trámites 1, 2 o 3: ";
	if (cedad != 0) {
		prom = acedad / cedad;
		cout << prom;
	}
	else
	{
		cout << "No hubo clientes";
	}

	cout << "\n Nombre y Apellido del cliente de mayor edad que llega para el tramite 1 o 5: ";
	cout << NombreMaximo;
	if (flagprio)
	{
		cout << "\n Hubo al menos un cliente Prioritario de menos de 30 anos";
	}
	else {
		cout << "\n NO Hubo un cliente Prioritario de menos de 30 anos";
	}


}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
