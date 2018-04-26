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
    
    for(int i=0;i<8;i++){
       numero[i]=48+rand()%10;
   }
  
}

bool dni::set_dni(string dni_){
    if(comprobar_dni(dni_)){
        for(int i=0;i<8;i++){
            numero[i] = dni_[i];
        }
        return true;
    }
    else {
        cout << "DNI incorrecto." << endl;
        return false;
    }
    
}

void dni::mostrar_dni(ostream& os){
    for(int i=0;i<8;i++){
        os << numero[i];
    }
    os << " ";
}

bool dni::get_estado(void){
    return estado;
}

char* dni::get_dni(void){
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
    unsigned long acum = 0;
    int aux = 7;
    for(int i=0;i<8;i++){
        acum += (numero[i] - 48) * pow(10,aux);
        aux--;
    }
    return acum;
    
}

bool dni::operator==(dni &dni_){
    cont++;
    /*for(int i=0;i<numero.length();i++){
        if(numero[i]!=dni_.numero[i]){
            return false;
        }
    }
    return true;*/
    unsigned long a = dni::operator unsigned long();
    unsigned long b = dni_;
    if(a==b){
        return 1;
    }
    else{
        return 0;
    }  
}


bool dni::comprobar_dni(string dni_){
    if(dni_.size()!=8){
        return false;
    }
    for(int i=0;i<8;i++){
        if(!(dni_[i] < 58 && dni_[i] > 47)){
            return false;
        }
    }
    // if(!(dni_[8] < 91 && dni_[8] > 64)){
    //     return false;
    // }
    return true;
}