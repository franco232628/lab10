//
// Created by aml on 24/11/2025.
//

#ifndef FUNCIONESAUXILIARES_H
#define FUNCIONESAUXILIARES_H
void cargarLista(struct Nodo *&lista,const char *nameArch);
void readStructRandom(struct DatosRandom &nuevoDatoRandom,ifstream &input);
void insertarNodoOrdenado(const struct DatosRandom &nuevoDatoRandom,struct Nodo *&lista);
int readInt(ifstream &input);
char *readStr(ifstream &input,char delim,bool mayus);
void cadToMayus(char *cad);
void abrirInput(ifstream &arch,const char *nameArch);
void abrirOutput(ofstream &arch,const char *nameArch);
void emitirLista(struct Nodo *lista,const char *nameArch);
void eliminarDatosPequeños(struct Nodo *&lista);
void line(ofstream &rep,int anch,char c);
#endif //FUNCIONESAUXILIARES_H
