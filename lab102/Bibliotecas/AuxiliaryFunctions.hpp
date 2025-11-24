//
// Created by GRINGO on 24/11/2025.
//

#ifndef LAB102_AUXILIARYFUNCTIONS_HPP
#define LAB102_AUXILIARYFUNCTIONS_HPP

#include "Utils.hpp"

void CrearLista_cuenta(struct Nodo * &listaCuenta, const char * file_name);
void open_read( ifstream & input, const char * file_name);
char * read_str( ifstream & input, char delim, int max);
void Insertarordenado(struct Nodo *&listaCuenta, struct Cuenta dato);
void leer_movimientos(struct Nodo *&listaCuenta, const char * file_name);
int read_date( ifstream & input);
int read_int(ifstream &input);
double read_double(ifstream &input);
void print_line(ofstream &output, char caract, int size) ;
void print_date(ofstream &output, int fecha) ;
struct Nodo * buscarCliente(struct Nodo * listaCuenta, int codigo_leido);

void imprimir_nuevo(struct Nodo * listaCuenta, const char * file_name);

// for (int i = 0; buffer[i]; i++) {
//     if (buffer[i] >= 'a' and buffer[i] <= 'z' ) {
//         buffer[i] = buffer[i] - 32;
//     }
// }
void open_print( ofstream & output, const char * file_name);
void eliminarSaldosPositivos(struct Nodo * &listaCuenta);








#endif //LAB102_AUXILIARYFUNCTIONS_HPP