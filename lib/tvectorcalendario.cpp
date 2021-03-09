#include <iostream>
using namespace std;

#include "../include/tvectorcalendario.h"

TVectorCalendario::TVectorCalendario(){
    this->tamano = 0;
    this->c = NULL;
}

TVectorCalendario::TVectorCalendario(int tam){
    if(tam <= 0){
        this->tamano = 0;
        this->c = NULL;
    }
    else{
        this->tamano = tam;
        this->c = new TCalendario [tamano];
        if(c == NULL){
            this->tamano = 0;
            return;
        }
    }
}

TVectorCalendario::TVectorCalendario(const TVectorCalendario & obj){
    this->tamano = obj.tamano;;
    this->c = new TCalendario [tamano];

    if(c == NULL){
        this->tamano = 0;
        return;
    }
    for(int i = 0; i < this->tamano; i++){
        c[i] = obj[i+1];
    }
    
}

TVectorCalendario::~TVectorCalendario(){
    this->tamano = 0;
    if(this->c != NULL){
        delete [] c;
        this->c = NULL;
    }
}

TVectorCalendario& TVectorCalendario::operator=(const TVectorCalendario &obj){
if (this ==&obj)
    {
        return *this;
        
    }else{
        (*this).~TVectorCalendario();
        this->tamano =obj.tamano;
        this->c=new TCalendario[tamano];
        for (int i = 0; i < tamano; i++){
            this->c[i]=obj[i+1];
        }
        return *this;
    }
}

bool TVectorCalendario::operator==(TVectorCalendario &obj){
    if(this->tamano != obj.tamano)
        return false;
    else{
        for(int i = 0; i < this->tamano; i++){
            if(this->c[i] != obj.c[i])
                return false;
        }
    }
    return true;
}

bool TVectorCalendario::operator!=(TVectorCalendario &obj){
    return !(*this == obj);
}

TCalendario& TVectorCalendario::operator[](int numero){
    if(numero >= 1 && numero <= this->tamano)
        return this->c[numero-1];
    return error;
}

TCalendario TVectorCalendario::operator[](int numero) const{
    if(numero >= 1 && numero <= this->tamano)
        return this->c[numero-1];
    return error;
}

int TVectorCalendario::Ocupadas(){
    int ocupadas = 0;
    for(int i = 0; i < this->tamano; i++)
        if(this->c[i] != this->error)
            ocupadas++;
    return ocupadas;
}

bool TVectorCalendario::ExisteCal(TCalendario &obj){
    for(int i = 0; i < this->tamano; i++)
        if(this->c[i] == obj)
            return true;
    return false;
}

void TVectorCalendario::MostrarMensajes(int dia, int mes, int anyo){
    
}

bool TVectorCalendario::Redimensionar(int tam){
    if(tam <= 0)
        return false;
    if(tam == this->tamano)
        return false;

    TCalendario *aux = new TCalendario[tam];
    TCalendario *vacio = new TCalendario();

    //El vector resultante sera mayor
    if(tam > this->tamano){
        for(int i = 0; i < tam; i++){
            if(i < this->tamano)
                aux[i] = this->c[i];
            else aux[i] = (*vacio);
        } 

        (*this).~TVectorCalendario();   
        this->c = aux;
        this->tamano = tam;

        return true;  
    }
    else{
        for(int i = 0; i < tam; i++)
            aux[i] = this->c[i];

        (*this).~TVectorCalendario();   
        this->c = aux;
        this->tamano = tam;

        return true;  
    }
}

ostream& operator<<(ostream &s, const TVectorCalendario &obj){
    s << "[";
    for(int i = 1; i <= obj.tamano; i++){
        s << "(" << i <<") " << obj[i];
        if(i!= obj.tamano)
            s << ", "; 
    }
    s<< "]";

    return s;
}