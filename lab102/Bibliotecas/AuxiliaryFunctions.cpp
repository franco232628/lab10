//
// Created by GRINGO on 24/11/2025.
//

#include "AuxiliaryFunctions.hpp"




void CrearLista_cuenta(struct Nodo *&listaCuenta, const char *file_name) {
    ifstream input;
    open_read(input, file_name);
    listaCuenta = nullptr;

    struct Cuenta dato;
    int codigo_leido;
    while (true) {
        // 58477632,Larriega Velasquez Moises Roberto,23326.62
        input >> codigo_leido;
        if (input.eof()) break;
        input.get();
        dato.codigo = codigo_leido;
        dato.nombre = read_str(input, ',', 50);
        input >> dato.saldo;

        dato.fechaSobregiro = 0;
        if (dato.saldo < 0) dato.sobregiro = true;
        else dato.sobregiro = false;
        Insertarordenado(listaCuenta, dato);
    }
}

void open_read(ifstream &input, const char *file_name) {
    input.open(file_name, ios::in);
    if (!input.is_open()) {
        cout << "No se pudo abrir" << file_name << endl;
        exit(1);
    }
}

char * read_str(ifstream &input, char delim, int max) {
    char *str, buffer[max];
    input >>ws;
    input.getline(buffer, max, delim);
    str = new char[strlen(buffer) + 1];
    strcpy(str, buffer);
    return str;
}

void Insertarordenado(struct Nodo *&listaCuenta, struct Cuenta dato) {
    struct Nodo *p =listaCuenta;
    struct Nodo *ant = nullptr;
    struct Nodo *nuevo = new struct Nodo;

    nuevo->cuenta = dato;

    while (p) {
        if (p->cuenta.codigo > dato.codigo) break;
        ant = p;
        p = p->siguiente;
    }
    nuevo->siguiente = p;

    if (ant == nullptr) listaCuenta = nuevo;
    else ant->siguiente = nuevo;
}
//
// struct Nodo *p = listaCuenta;
// struct Nodo *ant = nullptr;
// struct Nodo *nuevo = new struct Nodo;
//
// nuevo->cuenta = dato;
//
// while (p) {
//     if (p->cuenta.codigo > dato.codigo) break;
//     ant = p;
//     p = p->siguiente;
// }
//
// nuevo->siguiente = p;
//
// if (ant == nullptr) listaCuenta = nuevo;
// else ant->siguiente = nuevo;

void leer_movimientos(struct Nodo *&listaCuenta, const char *file_name) {

    ifstream input;
    open_read(input, file_name);
    int fecha_leida, codigo_leido;
    char c;
    double saldo_mov;

    struct Nodo *p;

    while (true) {
        fecha_leida = read_date(input);
        if (input.eof()) break;
        input.get();
        while (true) {
            input >> codigo_leido >> c >> saldo_mov;
            p = buscarCliente(listaCuenta, codigo_leido);

            double saldoAnterior = p->cuenta.saldo;
            p->cuenta.saldo += saldo_mov;
            if (saldoAnterior> 0 and p->cuenta.saldo<0){
                p->cuenta.sobregiro = true;
                p->cuenta.fechaSobregiro = fecha_leida;
            }
            c = input.get();
            if (c == '\n' or input.eof()) break;
        }
    }
}


struct Nodo * buscarCliente(struct Nodo *listaCuenta, int codigo_leido) {
    struct Nodo *p = listaCuenta;

    while (p) {
        if (p->cuenta.codigo == codigo_leido) return p;
        p = p->siguiente;
    }
    return nullptr;
}

int read_date(ifstream &input) {
    int dd, mm, aa;
    char c;

    input >> dd >>c>>mm>>c>>aa;
    return aa*10000 + mm*100 + dd;
}
int read_int(ifstream &input) {
    int num;
    input >> num;
    input.get();
    return num;
}


double read_double(ifstream &input) {
    double num;
    input >> num;
    input.get();
    return num;
}



void print_line(ofstream &output, char caract, int size) {
    for (int i=0; i<size; i++) output.put(caract);
    output << endl;
}

void print_date(ofstream &output, int fecha) {
    int dia=fecha%100;
    int mes = (fecha/100)%100;
    int anho = fecha/10000;

    output << right << setfill('0') << setw(2) << dia << '/' << setw(2) << mes << '/'
        << setw(4) << anho;
    output << setfill(' ');
}

void open_print(ofstream &output, const char *file_name) {
    output.open(file_name, ios::out);
    if (!output.is_open()) {
        cout << "Error opening file!" << file_name << endl;
        exit(1);
    }
}

void eliminarSaldosPositivos(struct Nodo *&listaCuenta) {
    struct Nodo *p = listaCuenta;
    struct Nodo *ant = nullptr;
    struct Nodo *eliminar;

    while (p) {
        if (p->cuenta.saldo > 0) {
            eliminar = p;
            if (ant == nullptr) {
                listaCuenta = p->siguiente;
                p=p->siguiente;
            }else {
                ant->siguiente = p->siguiente;
                p = ant->siguiente;
            }
            delete eliminar;
        }
        else {
            ant = p;
            p = p->siguiente;
        }
    }
}



// struct Nodo *p = listaCuenta;
// struct Nodo *ant = nullptr;
// struct Nodo *eliminar;
//
// while (p) {
//     if (p->cuenta.saldo > 0) {
//         eliminar = p;
//         if (ant ==nullptr) {
//             listaCuenta = p->siguiente;
//             p = p->siguiente;
//         }else {
//             ant->siguiente = p->siguiente;
//             p = ant->siguiente;
//         }
//         delete eliminar;
//     }
//     else {
//         ant = p;
//         p = p->siguiente;
//     }
//
// }
//
//




void imprimir_nuevo(struct Nodo *listaCuenta, const char *file_name){
    ofstream output;
    open_print(output, file_name);
    struct Nodo *act = listaCuenta ;

    output << right << setw((140+24)/2) << "BANCO De LOS CLIENTES Tp"<< endl;
    output << right << setw((140+54)/2) << "LISTADO DE LAS CUENTAS DE AHORROS DE NUESTROS CLIENTES"<< endl;
    print_line(output, '=', 140);
    output << left << setw(5)<< "No." << setw(11) << "CUENTA"<< setw(50) << "CLIENTE" <<setw(12)<< right
    << "SALDO" << setw(20) << "SOBREGIRADA" << setw(40) << "FECHA DEL ULTIMO SOBREGIRO"<<endl;
    int i=1;

    while (act) {
        output << setfill('0') << setw(2) << i << setfill(' ') << ")  ";
        output<<setw(11)<<left<<act->cuenta.codigo;
        int size=0;
        for (int i = 0; act->cuenta.nombre[i]; i++) {
            if (act->cuenta.nombre[i] >= 'a' and act->cuenta.nombre[i] <= 'z' ) {
                act->cuenta.nombre[i] = act->cuenta.nombre[i] - 32;
            }
            size++;
        }
        output<<setw(47)<<left<<act->cuenta.nombre;
        for(int i =0; i<size-47; i++) output.put(' ');
        output<<fixed;
        output.precision(2);
        output<<setw(16)<< right<<act->cuenta.saldo;

        if (act->cuenta.sobregiro) output << setw(14) << "SI";
        else output << setw(14)<< "NO";
        for (int j =0; j<25; j++) output.put(' ');
        if (act->cuenta.fechaSobregiro ==0) output << "--/--/----";
        else print_date(output, act->cuenta.fechaSobregiro);
        output << endl;
        act = act->siguiente;
        i++;
    }
    print_line(output, '=', 140);
}
