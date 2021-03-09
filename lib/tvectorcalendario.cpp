#include <iostream>
using namespace std;

#include "../include/tvectorcalendario.h"

TVectorCalendario::TVectorCalendario(){
    this->tamano = 0;
    this->c = NULL;
}

TVectorCalendario::TVectorCalendario(int tam){
    if(tam < 0){
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

TVectorCalendario::TVectorCalendario( TVectorCalendario & obj){
    this->tamano = obj.tamano;;
    this->c = new TCalendario [tamano];

    if(c == NULL){
        this->tamano = 0;
        return;
    }
    for(int i = 0; i < this->tamano; i++){
        c[i] = obj.c[i];
    }
    
}

TVectorCalendario::~TVectorCalendario(){
    this->tamano = 0;
    if(this->c != NULL){
        delete [] c;
        this->c = NULL;
    }
}

TVectorCalendario& TVectorCalendario::operator=(TVectorCalendario &obj){
    if(this != &obj){
        if(this->tamano = obj.tamano){
            this->tamano = obj.tamano;
            if(this->c != NULL)
                delete this->c;
            this->c = new TCalendario[this->tamano];
            //Comprobamos que se ha asignado correctamente la memoria
            if(this->c == NULL){
                this->tamano = 0;
                return *this;
            }
        }
        for(int i = 0; i < this->tamano; i++){
            c[i] = obj.c[i];
        }
    }
    return *this;
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

int TVectorCalendario::Tamano(){
    return this->tamano;
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

bool TVectorCalendario::Redimensionar(int tam){
    
}