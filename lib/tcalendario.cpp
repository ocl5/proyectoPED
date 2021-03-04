#include <iostream>
using namespace std;

#include "../include/tcalendario.h"

TCalendario::TCalendario(){
    this->dia = 1;
    this->mes = 1;
    this->anyo = 1900;
    mensaje = NULL;
}

TCalendario::TCalendario(int dia, int mes, int anyo, char * mensaje){
    if(comprobarFecha(dia, mes, anyo)){
        this->dia = dia;
        this->mes = mes;
        this->anyo = anyo;
        this->mensaje = NULL;
    }
    else{
        this->dia = 1;
        this->mes = 1;
        this->anyo = 1900;
        this->mensaje = NULL;
    }
}

TCalendario::TCalendario(const TCalendario &obj){
    this->dia = obj.dia;
    this->mes = obj.mes;
    this->anyo = obj.anyo;
}

TCalendario::~TCalendario(){
    this->dia = 1;
    this->mes = 1;
    this->anyo = 1900;
    this->mensaje = NULL;
}

bool TCalendario::bisiesto(int anyo){
    if(anyo % 4 == 0 && (anyo % 100 != 0 || anyo % 400 == 0))
        return true;
    return false; 
}

bool TCalendario::comprobarFecha(int dia, int mes, int anyo){
    //Limites (dias negativos, +12 meses, +31 dias, <1900, mes-dias)
    if(dia > 0 && dia <= 31 && mes <= 12 && anyo >= 1900){

        //Febrero bisiesto (max 29), sino (max 28)
        if(bisiesto(anyo)){
            if(mes == 2 && dia <= 29)
                return true; 
            else return false;
        }
        else{
            if(mes == 2 && dia <= 28)
                return true;
            else return false;
        }

        //Abril. junio, septiembre y noviembre (=30)
        if(mes == 4 || mes == 6 || mes == 9 || mes == 11){
            if(dia <= 30)
                return true;
            else return false;
        }
        return true;
    }
    return false;
}


bool TCalendario::ModFecha(int dia, int mes, int anyo){
    if(comprobarFecha(dia,mes,anyo)){
        this->dia = dia;
        this->mes = mes;
        this->anyo = anyo;

        return true;
    }
    return false;
}

bool TCalendario::ModMensaje(char * mensaje){
    bool modificado = false;

    if(mensaje == NULL){
        this->mensaje = NULL;
        modificado = true;
    }
    else{
        this->mensaje = mensaje;
        modificado = true;
    }
    return modificado;
}

TCalendario& TCalendario::operator=(const TCalendario &obj){

    if(this != &obj){   //Protección contra autoasignacion
        (*this).~TCalendario();
        this->dia = obj.dia;
        this->mes = obj.mes;
        this->anyo = obj.anyo;
    }
    return *this;
}

TCalendario TCalendario::operator+(int cantDias){
    
}

TCalendario TCalendario::operator-(int cantDias){
    //Poner como condicion d eparada que sea el 1/1/1900
}

//Preincremento
TCalendario & TCalendario::operator++(){
    dia++;

    if(mes == 2 && dia ==29 && !bisiesto(this->anyo)){
        dia = 1;
        mes = 3;
    }
    else if((mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 ||
             mes == 10 || mes == 12) && dia == 32){
        dia = 1;
        mes++;

        if(mes == 13){
            mes == 1;
            anyo++;
        }
    }
    else if(dia == 31){
        dia = 1;
        mes++;
    }
    return *this;
}

//Postincremento
TCalendario TCalendario::operator++(int cantDias){
    TCalendario tcalendario(*this);
    dia++;
    if(mes == 2 && dia == 29 && !bisiesto(this->anyo)){
        dia == 1;
        mes == 3;
    }
    else if((mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 ||
             mes == 10 || mes == 12) && dia == 32){
        dia = 1;
        mes++;

        if(mes == 13){
            mes = 1;
            anyo++;
        }
    }
    else if(dia == 31){
        dia = 1;
        mes++;
    }

    return tcalendario;
}

//Preincremento
TCalendario & TCalendario::operator--(){
    dia--;
    if(dia == 0){
        mes--;
        if(mes = 0){
            mes = 12;
            anyo--;
        }
        if(mes == 2 && !bisiesto(this->anyo))
            dia = 28;
        else if(mes == 2 && bisiesto(this->anyo))
            dia = 29;
        else if(mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 ||
                mes == 10 || mes == 12)
            dia = 31;
        else dia = 30;
    }

    if(!comprobarFecha(dia, mes, anyo))
        this->~TCalendario();

    return *this;
}


//Postincremento
TCalendario TCalendario::operator--(int cantDias){
    TCalendario tcalendario(*this);
    dia--;
    if(dia == 0){
        mes--;
        if(mes = 0){
            mes = 12;
            anyo--;
        }
        if(mes == 2 && !bisiesto(this->anyo))
            dia = 28;
        else if(mes == 2 && bisiesto(this->anyo))
            dia = 29;
        else if(mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 ||
                mes == 10 || mes == 12)
            dia = 31;
        else dia = 30;
    }

    if(!comprobarFecha(dia, mes, anyo))
        this->~TCalendario();

    return tcalendario;
    
}


bool TCalendario::operator== (const TCalendario &obj){
    bool same = (dia==obj.dia && mes==obj.mes && anyo==obj.anyo && strcmp(mensaje, obj.mensaje)) ? true : false;
    return same;
}

bool TCalendario::operator!= (const TCalendario &obj){
    return !(*this==obj);
}

/*
bool TCalendario::operator> (const TCalendario &obj){
    if(this->anyo > obj.anyo)
        return true;
    else if(this->anyo == obj.anyo && this->mes > obj.mes )
        return true;
    else if(this->anyo == obj.anyo && this->mes == obj.mes && this->dia > obj.dia)
        return true;
    else if((this->anyo == obj.anyo && this->mes == obj.mes && this->dia == obj.dia)
            && this->mensaje != obj.mensaje){
        if(this->mensaje == NULL)
            return false;
        if(obj.mensaje == NULL)
            return true;
        if(strcmp(this->mensaje, obj.mensaje) > 1)
            return true
    }

    return false;
}
*/

bool TCalendario::operator< (const TCalendario &obj){

}


bool TCalendario::EsVacio(){
    if(dia == 1  && mes == 1 && anyo == 1900 && mensaje == NULL)
        return true;
    return false;
}

ostream& operator<<(ostream &s, const TCalendario &obj){
    if(obj.dia < 10)
        s << "0" << obj.dia;
    else s << obj.dia;

    s << "/";

    if(obj.mes < 10)
        s << "0" << obj.mes;
    else s << obj.mes;

    s << "/";
    s << obj.anyo << " ";
    s << " \" ";
    
    if(obj.mensaje != NULL)
        s << obj.mensaje;
    
    s << " \" ";

    return s;
}


