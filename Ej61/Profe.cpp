#include <iostream>
using namespace std;

struct tAlu {
    int Ed;
    string Nom;
};

void CargaVec(tAlu vAlu[], int n, int& sumedades) {
    int i;
    for (i = 0; i <= n - 1; i++) {
        cout << "Ing edad:" << endl;
        cin >> vAlu[i].Ed;
        cout << "Ing nom:" << endl;
        cin >> vAlu[i].Nom;
        sumedades = sumedades + vAlu[i].Ed;
    }
}

float CalcularProm(int sumedades, int n) {
    float Prom;
    Prom = sumedades / (n * 1.0);
    return Prom;
    // o directo return sumedades /(n*1.0)
}

int main() {
    int ce, i, n, sumedades;
    tAlu vAlu[70];
    float promedades;
    // 50) Se conocen las edades de los N alumnos de un curso (N<=70)
    // Informar la edad promedio de éste y la cantidad de edades que superaron dicho promedio
    // int vEd[70]
    sumedades = 0;
    cout << "Ing. cant. de alumnos del curso (máx. 70)" << endl;
    cin >> n;
    CargaVec(vAlu, n, sumedades);

    promedades = CalcularProm(sumedades, n);
    cout << "El promedio de edad del curso es " << promedades << endl;
    // verifico Edades mayores al promedio
    cout << endl;
    cout << "Los alumnos que superaron al promedio son " << endl;
    for (i = 0; i <= n - 1; i++) {
        if (vAlu[i].Ed > promedades) {
            cout << vAlu[i].Nom << "  " << vAlu[i].Ed << endl;
        }
    }
    return 0;
}