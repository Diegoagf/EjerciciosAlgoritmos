
#include <iostream>
#include<fstream>
#include <string>
using namespace std;

int main()
{
    ofstream fout4;
    ofstream fout8;
    ifstream fin;
    int leg, mat;
    string linea;

    cout << "Ingrese el numero de Legajo" << endl;
    cin >> leg;
    fout4.open("Inscritos4.txt");
    fout8.open("Inscritos8.txt");
    while (leg != 0)
    {
        cout << "Ingrese el Nro de Materia a Inscribir" << endl;
        cin >> mat;
        if (mat == 4) {

            fout4 << leg << endl;
        }

        if (mat == 8) {
            fout8 << leg << endl;
        }
        cout << "Ingrese el numero de Legajo" << endl;
        cin >> leg;
    }
    fout4.close();
    fout8.close();

    cout << "Materia 4" << endl;
    fin.open("Inscritos4.txt");
    while (!fin.eof()) {
        getline(fin, linea);
        cout << linea << endl;
    }
    fin.close();

    cout << "Materia 8" << endl;
    fin.open("Inscritos8.txt");
    while (!fin.eof()) {
        getline(fin, linea);
        cout << linea << endl;
    }
    fin.close();
}
