#include <iostream>
#include <iostream>
using namespace std;
#include <fstream>
#include <cstring>
#include "Bibliotecas/DatosRandom.h"
#include "Bibliotecas/Nodo.h"
#include "Bibliotecas/FuncionesAuxiliares.h"

int main(int argc,char **argv) {
    struct Nodo *lista;
    cargarLista(lista,"ArchivosDeDatos/dataset.csv");
    emitirLista(lista,"ArchivosDeReporte/Reporte.txt");
    eliminarDatosPequeños(lista);
    emitirLista(lista,"ArchivosDeReporte/ReporteDeMayores.txt");
    return 0;
}