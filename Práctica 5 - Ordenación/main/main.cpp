#include <iostream>
#include <time.h>   
#include <math.h>
#include <stdlib.h>
#include <climits>
#include "../src/dni.hpp"
#include "../src/ordenacion.hpp"
#include "../src/persona.hpp"

using namespace std;

int main(void){
    srand (time(NULL));
    
    int tam_v, opcion;
    bool estadistica = false;

    cout << "¿Modo estadística?[0/1]" << endl;
    cin >> opcion;
    if (opcion==1){
        estadistica=true;
    }

    if (!estadistica){  

            bool aux=false;
            while(!aux){
                cout << "Tamaño vector (< 25): ";
                cin >> tam_v;
                if(tam_v <=25){ aux=true; }
            }
           
            cout << "1. Inserción" << endl;
            cout << "2. QuickSort" << endl;
            cout << "3. MergeSort" << endl;
            cout << "4. HeapSort"  << endl;
            cout << "5. ShakeSort" << endl;
            cout << "6. Burbuja"   << endl;
            cout << "7. Selección" << endl;
            cout << "8. ShellSort" << endl;
            
            cout << "Algoritmo a ejecutar: ";
            cin >> opcion;
            
            dni banco[tam_v]; 
            for(int i=0;i<tam_v;i++){
                banco[i].crear_dni();
            }
            
            double alfa=0;
            switch(opcion){
            
            case 1: insercion(banco,tam_v); break;
            case 2: Qsort(banco,0,tam_v-1); break;
            case 3: Msort(banco,0,tam_v-1); break;
            case 4: /*Hsort(banco,tam_v); */break;
            case 5: sacudida(banco,tam_v); break;
            case 6: burbuja(banco,tam_v); break;
            case 7: seleccion(banco,tam_v); break;
            case 8: { bool aux=false;
                    while(!aux){
                        cout << "alfa: ";
                        cin >> alfa;
                        if(alfa > 0 && alfa < 1){ aux=true; }
                    }
                    ShellSort(banco,tam_v,alfa); } break;
            
        }
        for(int i=0;i<tam_v;i++){
            //unsigned long x = banco[i];
            cout << banco[i] /*<< "(" << x << ")  "*/;
        }
        cout << endl; 
    }
    else{
        int n_pruebas=0, acum=0, min=INT_MAX, max=0;
        cout << "Número de pruebas: ";
        cin >> n_pruebas;
        cout << "Tamaño del vector: ";
        cin >> tam_v;
        
        cout << "Número de comparaciones: " << endl;
       
        
        /* INSERCION */
        acum=0; min=INT_MAX; max=0;
        for(int i=0;i<n_pruebas;i++){
            dni banco[tam_v];
            for(int j=0;j<tam_v;j++){
                banco[j].crear_dni();
            }
            
            banco[0].cont_reset();
        
            insercion(banco,tam_v);
            if(banco[0].get_cont()>max){
                max=banco[0].get_cont();
            }
            if(banco[0].get_cont()<min){
                min=banco[0].get_cont();
            }
            acum+=banco[0].get_cont();
        }
        cout << "Inserción: min=" << min << " max=" << max << " media=" << acum/n_pruebas << endl;
        
        /* QUICK SORT */
        acum=0; min=INT_MAX; max=0;
        for(int i=0;i<n_pruebas;i++){
            dni banco[tam_v];
            for(int j=0;j<tam_v;j++){
                banco[j].crear_dni();
            }
            
            banco[0].cont_reset();
        
            Qsort(banco,0,tam_v-1);
            if(banco[0].get_cont()>max){
                max=banco[0].get_cont();
            }
            if(banco[0].get_cont()<min){
                min=banco[0].get_cont();
            }
            acum+=banco[0].get_cont();
        }
        cout << "QuickSort:  min=" << min << " max=" << max << " media=" << acum/n_pruebas << endl;
        
        /* MERGE SORT */
        /*acum=0; min=INT_MAX; max=0;
        for(int i=0;i<n_pruebas;i++){
            dni banco[tam_v];
            for(int j=0;j<tam_v;j++){
                banco[j].crear_dni();
                cout << banco[j] << endl;
            }
            
            banco[0].cont_reset();
        
            Msort(banco,0,tam_v-1);
            if(banco[0].get_cont()>max){
                max=banco[0].get_cont();
            }
            if(banco[0].get_cont()<min){
                min=banco[0].get_cont();
            }
            acum+=banco[0].get_cont();
        }
        cout << "MergeSort:  min=" << min << " max=" << max << " media=" << acum/n_pruebas << endl;*/
        
        /* HEAPSORT */
        
        /* SACUDIDA (SHAKESORT) */
        acum=0; min=INT_MAX; max=0;
        for(int i=0;i<n_pruebas;i++){
            dni banco[tam_v];
            for(int j=0;j<tam_v;j++){
                banco[j].crear_dni();
            }
            
            banco[0].cont_reset();
        
            sacudida(banco,tam_v);
            if(banco[0].get_cont()>max){
                max=banco[0].get_cont();
            }
            if(banco[0].get_cont()<min){
                min=banco[0].get_cont();
            }
            acum+=banco[0].get_cont();
        }
        cout << "Sacudida:  min=" << min << " max=" << max << " media=" << acum/n_pruebas << endl;
               
        /* BURBUJA */
        acum=0; min=INT_MAX; max=0;
        for(int i=0;i<n_pruebas;i++){
            dni banco[tam_v];
            for(int j=0;j<tam_v;j++){
                banco[j].crear_dni();
            }
            
            banco[0].cont_reset();
        
            burbuja(banco,tam_v);
            if(banco[0].get_cont()>max){
                max=banco[0].get_cont();
            }
            if(banco[0].get_cont()<min){
                min=banco[0].get_cont();
            }
            acum+=banco[0].get_cont();
        }
        cout << "Burbuja:  min=" << min << " max=" << max << " media=" << acum/n_pruebas << endl;
        
        
         /* SELECCION */
        acum=0; min=INT_MAX; max=0;
        for(int i=0;i<n_pruebas;i++){
            dni banco[tam_v];
            for(int j=0;j<tam_v;j++){
                banco[j].crear_dni();
            }
            
            banco[0].cont_reset();
        
            seleccion(banco,tam_v);
            if(banco[0].get_cont()>max){
                max=banco[0].get_cont();
            }
            if(banco[0].get_cont()<min){
                min=banco[0].get_cont();
            }
            acum+=banco[0].get_cont();
        }
        cout << "Seleccion: min=" << min << " max=" << max << " media=" << acum/n_pruebas << endl;
        
        /* SHELL SORT */
        acum=0; min=INT_MAX; max=0;
        double alfa=0;
        bool aux=false;
                    while(!aux){
                        cout << "alfa: ";
                        cin >> alfa;
                        if(alfa > 0 && alfa < 1){ aux=true; }
                    }
        for(int i=0;i<n_pruebas;i++){
            dni banco[tam_v];
            for(int j=0;j<tam_v;j++){
                banco[j].crear_dni();
            }
            
            banco[0].cont_reset();

            ShellSort(banco,tam_v,alfa);
            if(banco[0].get_cont()>max){
                max=banco[0].get_cont();
            }
            if(banco[0].get_cont()<min){
                min=banco[0].get_cont();
            }
            acum+=banco[0].get_cont();
        }
        cout << "ShellSort:  min=" << min << " max=" << max << " media=" << acum/n_pruebas << endl;
     }

}