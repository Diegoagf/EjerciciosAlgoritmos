#define _CRT_SECURE_NO_DEPRECATE 
#include <iostream>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

using namespace std;


struct tVta
{
    int CodP;
    int Suc;
    float Fact;
};

struct Nodo
{
    tVta info;
    Nodo* sig;
};

void menu(int* operacion)
{
    cout << "   1 - Generar Archivo" << endl;
    cout << "   2 - Mostrar el Archivo" << endl;
    cout << "   3 - Cargar la lista desde el archivo" << endl;
    cout << "   4 - Mostrar la lista" << endl;
    cout << "   5 - Cargar el vector y mostrar" << endl;
    cout << "   0 - Salir del programa" << endl;
    cout << "----------------------------------------" << endl;
    cout << " Ingrese una opciOn:";
    cin >> *operacion;
}

void salir(void)
{
    puts("\nFin del programa");
}

/********************
 *  ARCHIVOS
 ********************/
void archivo_crear(const char* NomArchivo)
{
    tVta RVta;
    FILE* fVta;

    fVta = fopen("ventas.dat", "wb");

    cout << " Codigo Prod:";
    cin >> RVta.CodP;
    while (RVta.CodP != 0)
    {
        cout << " Sucursal:";
        cin >> RVta.Suc;
        cout << " Facturacion:";
        cin >> RVta.Fact;
        //Guarda el dato en el archivo
        fwrite(&RVta, sizeof(RVta), 1, fVta);
        cout << "----------------------------------------" << endl;
        cout << " Codigo Prod:";
        cin >> RVta.CodP;
    }
    fclose(fVta);
}

void archivo_mostrar(const char* NomArchivo)
{
    FILE* fVta;
    tVta RVta;

    cout << "CodP" << "\t\t" << "Suc" << "\t\t" << "Fact" << endl;

    fVta = fopen(NomArchivo, "rb");
    fread(&RVta, sizeof(tVta), 1, fVta);
    while (!feof(fVta))
    {
        cout << RVta.CodP << "\t\t" << RVta.Suc << "\t\t" << RVta.Fact << endl;
        fread(&RVta, sizeof(tVta), 1, fVta);
    }
    fclose(fVta);
}

/********************
 *  lISTAS
 ********************/

void insertarAlFinal(Nodo*& LVta, tVta RVta)
{
    Nodo* nuevo = new Nodo();
    nuevo->info = RVta;
    nuevo->sig = NULL;
    if (LVta == NULL)
    {
        LVta = nuevo;
    }
    else
    {
        Nodo* aux = LVta;

        while (aux->sig != NULL)
        {
            aux = aux->sig;
        }
        aux->sig = nuevo;
    }
}


Nodo* buscar(Nodo* LVta, tVta RVta)
{
    Nodo* aux = LVta;
    bool no_encontrado = true;
    while ((aux != NULL) && (no_encontrado))
    {
        if ((aux->info.CodP == RVta.CodP) && (aux->info.Suc == RVta.Suc))
            no_encontrado = false;
        aux = aux->sig;
    }
    return aux;
}


void insertarSinRepetir(Nodo*& LVta, tVta RVta)
{
    Nodo* p = buscar(LVta, RVta);
    if (p == NULL) insertarAlFinal(LVta, RVta);
}

void insertarSinRepetir2(Nodo*& LVta, tVta RVta)
{
    Nodo* aux = LVta;
    Nodo* auxAnt = NULL;
    bool no_encontrado = true;



    if (LVta == NULL)
    {
        Nodo* nuevo = new Nodo();
        nuevo->info = RVta;
        nuevo->sig = NULL;
        LVta = nuevo;
    }
    else
    {
        while ((aux != NULL) && (no_encontrado))
        {

            if ((aux->info.CodP == RVta.CodP) && (aux->info.Suc == RVta.Suc))
            {
                no_encontrado = false;

            }
            auxAnt = aux;
            aux = aux->sig;
        }
        if (no_encontrado)
        {
            Nodo* nuevo = new Nodo();
            nuevo->info = RVta;
            nuevo->sig = NULL;
            auxAnt->sig = nuevo;
        }
    }


}


int lista_cargar(const char* NomArchivo, Nodo*& LVta)
{
    FILE* fVta;
    tVta RVta;
    int cont = 0;;

    fVta = fopen("ventas.dat", "rb");
    if (fVta == NULL)
    {
        cout << "Error al leer el archivo." << endl;
    }
    else
    {
        fread(&RVta, sizeof(tVta), 1, fVta);
        while (!feof(fVta))
        {
            insertarSinRepetir2(LVta, RVta);
            cont = cont + 1;
            fread(&RVta, sizeof(tVta), 1, fVta);
        }
    }
    fclose(fVta);
    return cont;
}

void lista_mostrar(Nodo*& LVta)
{
    Nodo* aux = LVta;

    cout << "CodP" << "\t\t" << "Suc" << "\t\t" << "Fact" << endl;
    while (aux != NULL)
    {
        cout << aux->info.CodP << "\t\t" <<
            aux->info.Suc << "\t\t" <<
            aux->info.Fact << endl;
        aux = aux->sig;
    }

}
/********************
 *  VECTOR
 ********************/

void cargar_vector(Nodo*& LVta, int* cNodos)
{
    tVta vAux[1000];
    Nodo* aux = LVta;
    Nodo* auxAnt = NULL;
    int i = 0;
    int j = *cNodos;
    while (aux != NULL)
    {
        if ((aux->info.Fact <= 200) && (aux->info.Fact >= 100))
        {
            vAux[i].CodP = aux->info.CodP;
            vAux[i].Suc = aux->info.Suc;
            vAux[i].Fact = aux->info.Fact;
            i++;
            j--;

            if (auxAnt == NULL)
            {
                LVta = aux->sig;
            }
            else
            {
                auxAnt->sig = aux->sig;
            }
            delete aux;
            aux = LVta;
        }
        else
        {
            auxAnt = aux;
            aux = aux->sig;
        }
    }

    *cNodos = j;

    cout << "CodP" << "\t\t" << "Suc" << "\t\t" << "Fact" << endl;
    for (int h = 0; h < (i); h++)
    {
        cout << vAux[h].CodP << "\t\t" <<
            vAux[h].Suc << "\t\t" <<
            vAux[h].Fact << endl;

    }
}

int main()
{
    Nodo* LVta = NULL;

    int cant_nodos; //lista

    int op = 0;
    do
    {
        system("cls"); //cls para windows y clear es para linux
        menu(&op); //Pasaje por referencia.
        switch (op)
        {
        case 0:
            salir();
            break;
        case 1://crar el archivo
            archivo_crear("ventas.dat");
            break;
        case 2://mostrar el archivo
            system("cls");
            archivo_mostrar("ventas.dat");
            system("PAUSE");
            break;
        case 3: //Cargar el archivo en la lista
            system("cls");
            cant_nodos = lista_cargar("ventas.dat", LVta);
            system("PAUSE");
            break;
        case 4: //Mostrar la lista
            system("cls");
            lista_mostrar(LVta);
            system("PAUSE");
            break;
        case 5: //Cargar vector 100-200
            system("cls");
            cargar_vector(LVta, &cant_nodos);
            system("PAUSE");
            break;


        default:
            cout << "Opción no válida." << endl;
            break;
        }
    } while (op != 0);
    return 0;
}