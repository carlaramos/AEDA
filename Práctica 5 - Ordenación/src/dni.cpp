#include "dni.hpp"

#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>


using namespace std;

int dni::cont=0;

dni::dni(void): 
    estado(false) 
{}

void dni::crear_dni(void){
    estado=true;
    
    string s(8, ' ');
    for(int i=0;i<8;i++){
       int x=48+rand()%10;
       s[i]=x;
   }
   numero = s;
}

void dni::mostrar_dni(ostream& os){
    for(int i=0;i<numero.length();i++){
        os << numero[i];
    }
    os << " ";
}

bool dni::get_estado(void){
    return estado;
}

string dni::get_dni(void){
    return numero;
}

bool dni::operator<(dni &dni_){
    unsigned long a = dni::operator unsigned long();
    unsigned long b = dni_;
    cont++;
    
    if(a<b){
        return 1;
    }
    else {
        return 0;
    }
}

ostream& operator<<(ostream& os, dni& A){
    A.mostrar_dni(os);
    return os;
}

dni::operator unsigned long(){
    string copy = numero;
    reverse(copy.begin(), copy.end());
    unsigned long acum=0;
   
    for(int i=0;i<numero.length();i++){
        acum += (copy[i] - 48) * pow(10,i);
    }
    return acum;
}

bool dni::operator==(const dni &dni_) const{
    cont++;
    for(int i=0;i<numero.length();i++){
        if(numero[i]!=dni_.numero[i]){
            return false;
        }
    }
    return true;
}


void dni::limpiar(void){
    numero = "";
}