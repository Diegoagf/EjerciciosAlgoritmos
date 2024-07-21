//#define _CRT_SECURE_NO_DEPRECATE 
//#include <iostream>
//#include<string.h>
//
//using namespace std;
//
//struct tProd {
//    int codP;
//    char desc[20];
//    float pu;
//};
//struct tVenta {
//    int codP;
//    int cantV;
//};
//struct NodoVenta {
//    tVenta info;
//    NodoVenta* sig;
//};
//struct NodoProd {
//    tProd info;
//    NodoProd* sig;
//    NodoVenta* ventas;
//};
//
//
//void InsertaAlFinal(NodoProd*& lista, NodoProd*& ult, tProd rinfo) {
//    NodoProd* pnue = new NodoProd();
//    pnue->info = rinfo;
//    pnue->sig = NULL;
//    if (lista == NULL)
//        lista = pnue;
//    else
//        ult->sig = pnue;
//    ult = pnue;
//    return;
//}
//
//NodoVenta* InsertaNodoVenta(NodoVenta*& lista, tVenta rinfov) {
//    NodoVenta* pnue = new NodoVenta();
//    NodoVenta* aux = lista;
//
//    pnue->info = rinfov;
//    pnue->sig = NULL;
//
//    if (lista == NULL || rinfov.cantV < lista->info.cantV) {
//        lista = pnue;
//        return pnue;
//    }
//
//    while (aux->sig != NULL && rinfov.cantV > aux->sig->info.cantV) {
//        aux = aux->sig;
//    }
//
//    pnue->sig = aux->sig,
//        aux->sig = pnue;
//    return pnue;
//}
//
//void Elimina1erNodo(NodoProd* ptr) {
//    delete ptr;
//};
//
//void Elimina1erNodoVenta(NodoVenta* ptr) {
//    delete ptr;
//};
//
//void ImprimeListaVentas(NodoVenta*& lista) {
//    NodoVenta* ptr;
//
//    cout << "####Detalle####" << endl;
//    cout << "\n" << endl;
//    cout << "---------" << endl;
//    cout << "|CantV  |" << endl;
//    cout << "---------" << endl;
//
//    while (lista != NULL) {
//        ptr = lista;
//        cout << lista->info.cantV << endl;
//        lista = ptr->sig;
//        Elimina1erNodoVenta(ptr);
//    }
//
//    cout << "---------" << endl;
//    cout << "\n" << endl;
//}
//
//NodoProd* BuscarProdenLista(NodoProd* lista, int codP) {
//    NodoProd* ptr = lista;
//    while (ptr != NULL && ptr->info.codP != codP)
//        ptr = ptr->sig;
//    return ptr;
//};
//
//int CargaProdsaLista(NodoProd*& lista, NodoProd*& lfin) {
//    int cantidad = 0;
//    tProd prod;
//    FILE* fprod = fopen("Productos.dat", "rb");
//    fread(&prod, sizeof(prod), 1, fprod);
//
//    while (!feof(fprod)) {
//        InsertaAlFinal(lista, lfin, prod);
//        cantidad++;
//        fread(&prod, sizeof(prod), 1, fprod);
//    }
//    fclose(fprod);
//    return cantidad;
//};
//
//void ProcesarVentas(NodoProd* l) {
//    tVenta venta;
//    FILE* fVentas = fopen("Ventas.dat", "rb");
//    fread(&venta, sizeof(venta), 1, fVentas);
//
//    while (!feof(fVentas)) {
//        NodoProd* prod = BuscarProdenLista(l, venta.codP);
//        InsertaNodoVenta(prod->ventas, venta);
//        /*
//            Si fuera Pila:
//            push(prod->ventas, venta);
//        */
//        /*
//            Si fuera Cola:
//            agregar(prod->ventasFte, prod->ventasFin, venta):
//        */
//        fread(&venta, sizeof(venta), 1, fVentas);
//    }
//    fclose(fVentas);
//    return;
//};
//
//void ImprimeProductos(NodoProd*& lista) {
//    NodoProd* ptr;
//
//    cout << "####INFORMES####" << endl;
//    cout << "\n" << endl;
//    cout << "---------------------------------------------------------------------" << endl;
//    cout << "|CodP             |Desc          |Total Facturado                    |" << endl;
//    cout << "---------------------------------------------------------------------" << endl;
//
//    while (lista != NULL) {
//        ptr = lista;
//        cout << lista->info.codP << "         |";
//        cout << lista->info.desc << "         |";
//        ImprimeListaVentas(lista->ventas);
//        lista = ptr->sig;
//        Elimina1erNodo(ptr);
//    }
//
//    cout << "-----------------------------------------" << endl;
//    cout << "\n" << endl;
//}
//
//int main() {
//    NodoProd* lista = NULL;
//    NodoProd* ult = NULL;
//
//    int cantElementos = CargaProdsaLista(lista, ult);
//    if (cantElementos > 0) {
//        ProcesarVentas(lista);
//        ImprimeProductos(lista);
//    }
//    else {
//        cout << "No se encontraron prods.";
//    }
//
//    system("pause");
//    return EXIT_SUCCESS;
//};