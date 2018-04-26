#pragma once
#include <iostream>
#include <math.h>

using namespace std;

class dni {
  
  private:
  
    string numero;
    bool estado;
    
    static int cont;
    
  public:
  
    dni();
    void crear_dni(void);
    void limpiar();
    void mostrar_dni(ostream& os);
    bool get_estado(void);
    string get_dni(void);

    bool operator<(dni &dni_);
    friend ostream& operator<<(ostream& os, dni& A);

    operator unsigned long();
    bool operator ==(const dni &dni_) const;
    int get_cont(void){return cont;}
    void cont_reset(void){cont=0;}
    void set_cont(void){cont++;};

};

