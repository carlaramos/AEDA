#pragma once
#include <iostream>
#include <math.h>

using namespace std;

class dni {
  
  private:
  
    char numero[8];
    bool estado;
    
    static int cont;
    
  public:
  
    dni();
    void crear_dni(void);
    void mostrar_dni(ostream& os);
    bool get_estado(void);
    char* get_dni(void);
    bool comprobar_dni(string dni_);
    bool set_dni(string dni_);

    bool operator<(dni &dni_);
    friend ostream& operator<<(ostream& os, dni& A);

    operator unsigned long();
    bool operator==(dni &dni_);
    int get_cont(void){return cont;}
    void cont_reset(void){cont=0;}
    void set_cont(void){cont++;};

};

