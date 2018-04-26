#pragma once
#include <iostream>
#include <math.h>

using namespace std;

class persona {
  
  private:
  
    string dni;
    string nombre;
    string apellido;
    
    static int cont;
    
  public:
  
    persona();
    void crear_dni(string dni_);
    void crear_nombre_apellido(string nombre, string apellido);
    void limpiar();
    void mostrar_dni(void);
    void mostrar_nombre_apellido(void);
    string get_dni(void);
    
    operator unsigned long();
    bool operator ==(const persona &persona_) const;
    bool operator<(persona &persona_);
    int get_cont(void){return cont;}
    void cont_reset(void){cont=0;}

};

