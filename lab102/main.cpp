#include "Bibliotecas/AuxiliaryFunctions.hpp"




int main() {

    struct Nodo *listaCuenta;
    CrearLista_cuenta(listaCuenta, "ArchivosDeDatos/CuentasBancarias.csv");

    struct Nodo *act = listaCuenta;

    // while (act) {
    //     cout << act->cuenta.codigo << "   -   " <<
    //         act->cuenta.nombre << "   -   " <<
    //             act->cuenta.saldo << "   -   " <<
    //                 act->cuenta.fechaSobregiro << "   -   " << endl;
    //     act=act->siguiente;
    // }
    //



    leer_movimientos(listaCuenta, "ArchivosDeDatos/MovimientosDeCuentas.csv");
    imprimir_nuevo(listaCuenta, "ArchivosDeReporte/report_nuevo.txt");


    eliminarSaldosPositivos(listaCuenta);

    imprimir_nuevo(listaCuenta, "ArchivosDeReporte/report_nuevo_nuevo.txt");


    return 0;
}
