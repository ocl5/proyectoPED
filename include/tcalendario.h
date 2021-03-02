#ifndef _tcalendario_ 
#define _tcalendario_

#include <iostream>
#include <cstring>
using namespace std;

class TCalendario {
    friend ostream & operator<< (ostream &, TCalendario &);

    private:
        bool bisiesto (int);
        bool comprobarFecha (int, int, int);

        int dia, mes, anyo;
        char * mensaje;

    public:
        TCalendario();
        TCalendario(int, int, int, char *);
        TCalendario(TCalendario &);
        ~TCalendario();

        TCalendario & operator= (TCalendario &);
        
        TCalendario operator+ (int);
        TCalendario operator- (int);

        TCalendario operator++ (int);
        TCalendario operator++ ();

        TCalendario operator-- (int);
        TCalendario operator-- ();

        bool ModFecha(int, int, int);
        bool ModMensaje(char *);

        bool operator== (TCalendario &);
        bool operator!= (TCalendario &);
        bool operator> (TCalendario &);
        bool operator< (TCalendario &);

        bool EsVacio();

        int Dia(){return this->dia;}
        int Mes(){return this->mes;}
        int Anyo(){return this->anyo;}
        char * Mensaje(){return this->mensaje;}
};
#endif
        