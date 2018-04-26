#pragma once
#include "ABB_nodo.hpp"
#include <queue>
#include "../dni/dni.hpp"

#include <iostream>

using namespace std;

template <class T>
class ABB{
private:
	ABB_nodo<T>* raiz;
public:
	ABB(void);
	~ABB(void);
	
	ABB_nodo<T>* insertar(T data);
	ABB_nodo<T>*& buscar(T dato, ABB_nodo<T>*& nodo);
	ABB_nodo<T>*& buscar_maximo(ABB_nodo<T>*& nodo);
	void eliminar(T dato);
	void imprimir(void);
	ABB_nodo<T>*& get_raiz(){ 
		return raiz;
	}


};

template <class T>
ABB<T>::ABB(void):
raiz(NULL){}

template <class T>
ABB<T>::~ABB(void){
	
}

template <class T>
ABB_nodo<T>* ABB<T>::insertar(T dato){
	ABB_nodo<T>*& nodo = buscar(dato, raiz);
	if(nodo==NULL){
		nodo=new ABB_nodo<T>(dato);
	}
	else{
		cout << "Error. Ya existe dicho nodo en el árbol." << endl;
	}
}

template <class T>
void ABB<T>::eliminar(T dato){
	ABB_nodo<T>*& nodo = buscar(dato, raiz);
	if(nodo==NULL){
		cout << "Error. No existe dicho nodo en el árbol." << endl;
	}
	else if(nodo->get_data()==dato){
		if(nodo->get_left()==NULL && nodo->get_right()==NULL){
			delete nodo ;
			nodo = NULL;
		}
		else if(nodo->get_left()!=NULL && nodo->get_right()==NULL){
			nodo = nodo->get_left();
		}
		else if(nodo->get_left()==NULL && nodo->get_right()!=NULL){
			nodo = nodo->get_right();
		}
		else if((nodo->get_left()!=NULL)&&(nodo->get_right()!=NULL)){
			ABB_nodo<T>*& nodo_max = buscar_maximo(nodo->get_left());
			T aux = nodo_max->get_data();
			eliminar(nodo_max->get_data());
			nodo->set_data(aux);
		}
	}
}
template <class T>
ABB_nodo<T>*& ABB<T>::buscar_maximo(ABB_nodo<T>*& nodo){
	if(nodo->get_right()==NULL){
		return nodo;
	}
	else{
		return buscar_maximo(nodo->get_right());
	}
}

template <class T>
ABB_nodo<T>*& ABB<T>::buscar(T dato, ABB_nodo<T>*& nodo){
	if(nodo==NULL){
		return nodo;
	}
	else{
		if(nodo->get_data()==dato){
			return nodo;
		}
		else{
			if(nodo->get_data()<dato){
				buscar(dato,nodo->get_right());
			}
			else{
				buscar(dato,nodo->get_left());
			}
		}
	}
}

template <class T>
void ABB<T>::imprimir(void){
   queue<ABB_nodo<T>*> Q;
   Q.push(get_raiz());
   int i=0;
   
   while(Q.size()!=0){				// maneja cada nivel distinto
		int cola = Q.size();
    	cout << "Nivel " << i << ": ";
    	i++;
    	while(cola>0){					// maneja los distintos nodos de un nivel
    		if(Q.front()==NULL){
    			cout << "[.] ";
    		}
    		else{
    			T aux = Q.front()->get_data();
	    		cout << aux << " ";
	    		Q.push(Q.front()->get_left());
	    		Q.push(Q.front()->get_right());
    		}
    		cola--;
    		Q.pop();
    	}
    	cout << endl;
	}
    
    
    
}
    