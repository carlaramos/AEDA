#include "persona.hpp"

#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>


using namespace std;

int persona::cont=0;

persona::persona(){}

void persona::crear_dni(string dni_){
    dni = dni_;
}

void persona::crear_nombre_apellido(string nombre_, string apellido_){
    nombre = nombre_;
    apellido = apellido_;
}

void persona::mostrar_dni(void){
    for(int i=0;i<dni.length();i++){
        cout << dni[i];
    }
}

void persona::mostrar_nombre_apellido(void){
    cout << "\t";
    for(int i=0;i<nombre.length();i++){
        cout << nombre[i];
    }
    cout << "\t";
    for(int i=0;i<apellido.length();i++){
        cout << apellido[i];
    }
}


string persona::get_dni(void){
    return dni;
}

persona::operator unsigned long(){
    string copy = dni;
    reverse(copy.begin(), copy.end());
    unsigned long acum=0;
   
    for(int i=0;i<dni.length();i++){
        acum += (copy[i] - 48) * pow(10,i);
    }
    return acum;
}

bool persona::operator==(const persona &persona_) const{
    cont++;
    for(int i=0;i<dni.length();i++){
        if(dni[i]!=persona_.dni[i]){
            return false;
        }
    }
    return true;
}

bool persona::operator<(persona &persona_){
    unsigned long a = persona::operator unsigned long();
    unsigned long b = persona_;
    cont++;
    
    
    if(a<b){
        return 1;
    }
    else {
        return 0;
    }
}


void persona::limpiar(void){
    dni = "";
    nombre = "";
    apellido = "";
}