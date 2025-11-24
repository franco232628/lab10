//
// Created by aml on 24/11/2025.
//
#include <iostream>
#include <iomanip>
using namespace std;
#include <fstream>
#include <cstring>
#include "DatosRandom.h"
#include "Nodo.h"
#include "FuncionesAuxiliares.h"
#define MAX 200
#define TAMLINEA 70

void cargarLista(struct Nodo *&lista,const char *nameArch) {
    struct DatosRandom nuevoDatoRandom{};
    ifstream input;abrirInput(input,nameArch);
    lista=nullptr;
    while (true) {
        readStructRandom(nuevoDatoRandom,input);
        if (input.eof()) break;
        insertarNodoOrdenado(nuevoDatoRandom,lista);
    }
    //esas son las chicas con las que no me hablo de primer ciclo
}

void readStructRandom(struct DatosRandom &nuevoDatoRandom,ifstream &input) {
    nuevoDatoRandom.dato1=readInt(input);
    if (input.eof()) return;
    nuevoDatoRandom.dato2=readInt(input);
    nuevoDatoRandom.cad1=readStr(input,'\n',true);
}

void insertarNodoOrdenado(const struct DatosRandom &nuevoDatoRandom,struct Nodo *&lista) {
    struct Nodo *nuevo,*p=lista,*ant=nullptr;
    nuevo=new struct Nodo;
    nuevo->data=nuevoDatoRandom;
    while (p and ((strcmp(nuevo->data.cad1,p->data.cad1)>0 or (strcmp(nuevo->data.cad1,p->data.cad1)==0 and nuevo->data.dato1>p->data.dato1)))) {
        ant=p;
        p=p->siguiente;
    }
    nuevo->siguiente=p;
    if (ant) ant->siguiente=nuevo;
    else lista=nuevo;
}

void emitirLista(struct Nodo *lista,const char *nameArch) {
    struct Nodo *p=lista;
    ofstream rep;abrirOutput(rep,nameArch);
    rep<<setw((TAMLINEA+30)/2)<<"REPORTE DE PRODUCTOS DE HELENA"<<endl;
    line(rep,TAMLINEA,'=');
    rep<<"CODIGO DEL PRODUCTO"<<setw(2)<<" "<<"STOCK DEL PRODUCTO"<<setw(2)<<" "<<"NOMBRE DEL PRODUCTO"<<endl;
    line(rep,TAMLINEA,'-');
    while (p) {
        rep<<setw(5)<<" "<<(p->data.dato1)<<setw(18)<<(p->data.dato2)<<setw(15)<<" "<<(p->data.cad1)<<endl;
        p=p->siguiente;
    }
}

void eliminarDatosPequeños(struct Nodo *&lista) {
    struct Nodo *p=lista,*ant=nullptr,*sale;
    while (p) {
        if (p->data.dato2>100) {
            //Se mantiene el dato porque es normal xddd
            ant=p;
            p=p->siguiente;
        }
        else {
            sale=p;
            if (ant==nullptr) {
                lista=p->siguiente;
                p=lista;
            }
            else {
                ant->siguiente=p->siguiente;
                p=p->siguiente;
            }
            delete []sale->data.cad1;
            delete sale;
        }
    }
}

//Funciones Secundarias

int readInt(ifstream &input) {
    int data;
    input>>data;
    input.get();
    return data;
}

char *readStr(ifstream &input,char delim,bool mayus) {
    char *cad,buff[MAX];
    input.getline(buff,MAX,delim);
    if (input.eof()) return nullptr;
    if (mayus) cadToMayus(buff);
    cad=new char[strlen(buff)+1];
    strcpy(cad,buff);
    return cad;
}

void cadToMayus(char *cad) {
    for (int i=0;cad[i];i++) {
        if (cad[i]>='a' && cad[i]<='z') cad[i]=toupper(cad[i]);
    }
}

void abrirInput(ifstream &arch,const char *nameArch) {
    arch.open(nameArch,ios::in);
    if (!arch.is_open()) {
        cerr<<"EL ARCHIVO NO FUE ABIERTO CORRECTAMENTE: "<<nameArch<<endl;
        exit(1);
    }
}

void abrirOutput(ofstream &arch,const char *nameArch) {
    arch.open(nameArch,ios::out);
    if (!arch.is_open()) {
        cerr<<"EL ARCHIVO NO FUE ABIERTO CORRECTAMENTE: "<<nameArch<<endl;
        exit(1);
    }
}

void line(ofstream &rep,int anch,char c) {
    rep<<setfill(c)<<setw(anch)<<c<<setfill(' ')<<endl;
}
