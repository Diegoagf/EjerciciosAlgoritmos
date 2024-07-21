#include <iostream>
using namespace std;
using std::cout;
using std::cin;
using std::endl;


void imprimirResultados(int empleados, float promedad, string NombreyApellido, bool Prioritario);
float CalcularPromedio(int valores, int cantidad);
void obtenerDatos(int& dni, int& edad, int& tramite, bool& prioritario, int& empleados, int& cedad, int& acedad, bool& flagprio);
int main() {

	//Ejercicio 39
	int edad,dni, tramite, empleados, maxedad, cedad, acedad;
	empleados = 0; maxedad = -INFINITY; cedad = 0; acedad = 0;
	bool prioritario, flagprio;
	flagprio = false;
	string nombreApellido, respuesta, NombreMaximo;
	NombreMaximo = "";
	cout << "Ingrese DNI (0 Detiene)\n";
	cin >> dni;
	obtenerDatos(dni,edad,tramite,prioritario,empleados,cedad,acedad,flagprio);
	
	imprimirResultados(empleados, CalcularPromedio(acedad, cedad),NombreMaximo,flagprio);

	
}

void obtenerDatos(int& dni, int& edad, int& tramite, bool& prioritario, int& empleados, int& cedad, int& acedad, bool&flagprio){
	double prom;
	 int maxedad = -INFINITY;
	flagprio = false;
	string nombreApellido, respuesta, NombreMaximo;
	NombreMaximo = "";
	
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
}

float CalcularPromedio(int valores, int cantidad) {
	float prom;
	if (cantidad != 0) {
		prom = valores / cantidad;
		return prom;
	}
	else {
		return 0;
	}
}

void imprimirResultados(int empleados,float promedad, string NombreyApellido, bool Prioritario) {
	cout << "Cantidad de empleados que esperan para el tipo de trámite 2 o 4: ";
	cout << empleados;
	cout << "\nEdad promedio de los clientes Prioritarios que esperan para los trámites 1, 2 o 3: ";
	if (promedad != 0) {		
		cout << promedad;
	}
	else
	{
		cout << "No hubo clientes";
	}

	cout << "\n Nombre y Apellido del cliente de mayor edad que llega para el tramite 1 o 5: ";
	cout << NombreyApellido;
	if (Prioritario)
	{
		cout << "\n Hubo al menos un cliente Prioritario de menos de 30 anos";
	}
	else {
		cout << "\n NO Hubo un cliente Prioritario de menos de 30 anos";
	}


}