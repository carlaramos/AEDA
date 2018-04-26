#include <iostream>
#include "../src/arbol/ABB.hpp"
#include "../src/arbol/ABB_nodo.hpp"
#include "../src/dni/dni.hpp"
#include <time.h>
#include <stdlib.h>
#include <climits>
#include <string>

using namespace std;

int main(void){
		
	srand(time(NULL));
	
	ABB<dni> arbol;
    
    int opcion;
    bool estadistica = false;

	cout << "¿Modo estadística?[0/1]" << endl;;
    cin >> opcion;
    if (opcion==1){
        estadistica=true;
    }

    if (!estadistica){ 
    	int op;
    	bool aux=true;
    	while(aux){
	    	cout << "[0] Salir" << endl << "[1] Insertar clave" << endl << "[2] Eliminar clave" << endl;
	    	cin >> op;
	    	switch(op){
	    		case 0: aux=false;
	    			break;
	    		case 1: {
	    				
	    				cout << "Introduzca la clave a insertar: ";
	    				/***matricula***/
	    				string x; 
	    				cin >> x;
	    				dni A;
	    				bool correcto = A.set_dni(x);
	    				if(correcto){
	    					arbol.insertar(A);	
	    				}
	    				/********/
	    				
	    				/**int**/   /* Para insertar enteros */
	    				/*int x;
	    				cin >> x;
	    				arbol.insertar(x);*/
	    				/*******/
	    				arbol.imprimir();
	    			break;
	    		}
    			case 2: {
    					cout << "Introduzca la clave a eliminar: ";
    					/***matricula***/
    					string y;
    					cin >> y;
    					dni B;
    					B.set_dni(y);
    					arbol.eliminar(B);
    					/***************/
    					/***int***/     /* Para insertar enteros */
    					/*int y;
    					cin >> y;
    					arbol.eliminar(y);*/
    					/*********/
    					arbol.imprimir();
    				break;
    			}
	    	}
    	}
    }
    if(estadistica){
    	int nPruebas, N;
    	cout << "Introduzca el tamaño del árbol: ";
    	cin >> N;
    	while(N<=0){
    		cout << "El tamaño del árbol debe ser mayor que 0. Prueba con otro: ";
    		cin >> N;
    	}
    	cout << endl << "Introduzca el número de pruebas: " << endl;
    	cin >> nPruebas;
    	
    	// BANCO DE PRUEBAS 
    	
    	dni banco_pruebas[2*N];

    	for(int i=0;i<2*N;i++){
    		banco_pruebas[i].crear_dni();
    	}
    	
    	for(int i=0;i<2*N;i++){
    		cout << banco_pruebas[i] << " ";
    	}
    	cout << endl;
    	
     	for(int i=0; i<N;i++){
    		arbol.insertar(banco_pruebas[i]);
    	}
    	
    	arbol.imprimir(); 
    	
    	double acum=0;
    	int min=INT_MAX, max=0;
    	banco_pruebas[0].cont_reset();
    	cout << endl << "Número de comparaciones:" << endl << endl << "Tamaño del árbol: " << N << " Número de pruebas: " << nPruebas <<  endl << endl;
    	
    	//BUSQUEDA
    	for(int i=0;i<nPruebas;i++){
    		int aux = rand()%N;
    		arbol.buscar(banco_pruebas[aux], arbol.get_raiz());
    		if(banco_pruebas[aux].get_cont()>max){
    			max=banco_pruebas[aux].get_cont();
    		}
    		if(banco_pruebas[aux].get_cont()<min){
    			min=banco_pruebas[aux].get_cont();
    		}
    		acum+=banco_pruebas[aux].get_cont();
    		banco_pruebas[aux].cont_reset();
    	}
			double media = acum/nPruebas;
    		
    		
    		cout << "Búsqueda: mínimo=" << min << " media=" << media << " máximo=" << max << endl;

    	//INSERCION
    	max=0; 
    	min=INT_MAX;
    	acum=0,media=0;
    	
    	for(int i=0;i<nPruebas;i++){
    		int aux = N + rand()%N;
    		arbol.buscar(banco_pruebas[aux], arbol.get_raiz());
    		if(banco_pruebas[aux].get_cont()>max){
    			max=banco_pruebas[aux].get_cont();
    		}
    		if(banco_pruebas[aux].get_cont()<min){
    			min=banco_pruebas[aux].get_cont();
    		}
    		acum+=banco_pruebas[aux].get_cont();
    		banco_pruebas[aux].cont_reset();
    	}
			media = acum/nPruebas;

    		cout << "Inserción: mínimo=" << min << " media=" << media << " máximo=" << max << endl;

    	
    }
}
	

	
