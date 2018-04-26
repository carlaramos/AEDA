#include <iostream>
#include "dni.hpp"

using namespace std;

template <class T>
void seleccion(T array[],int n){
T aux;
int x=0;
    for(int i = 0; i < n-1; i++){
        x = selecciona(array,i,n);
        aux = array[i];
        array[i] = array[x];
        array[x] = aux;
    }
}

template <class T>
int selecciona(T array[], int i, int n){
  int pos = i;
  for(int j = i+1; j < n; j++){ 
    if(array[j]<array[pos])
        pos = j;
  }
  return pos;
}

template <class T>
void insercion(T array[], int n){
    int i, pos;
    T aux;
    
    for(int i=0;i<n;i++){
        pos = i;
        aux = array[i];  
        
        while((pos>0) && (aux<array[pos-1])){
            array[pos]=array[pos-1];
            pos--;
        }
        array[pos]=aux;
    }
    
}

template <class T>
void sacudida(T array[], int n){
    int ini = 1 ;
    int fin = n-1 ;
    int cam = n ;
    while (ini < fin){ 
        for (int j = fin; j >= ini; j--){
            if (array[j] < array[j-1]){ 
                T x = array[j-1] ;
                array[j-1] = array[j] ;
                array[j] = x;
                cam = j;
            }
        }
        ini = cam + 1;
        for (int j = ini; j <= fin; j++){
            if (array[j] < array[j-1]){ 
                T x = array[j-1] ;
                array[j-1] = array[j];
                array[j] = x;
                cam = j;
            }
        }
        fin = cam - 1;
    } 
}

template <class T>
void burbuja(T array[], int n){
    T x;
    for (int i = 1; i < n; i++){ 
        for (int j = n-1; j >= i; j--){
            if (array[j]<array[j-1]){ 
                x = array[j-1];
                array[j-1] = array[j];
                array[j] = x ;
            }
        }
    }
}

template <class T>
void Qsort(T array[], int ini, int fin){
    int i = ini; 
    int f = fin;
    T p = array[(i+f)/2];
    
    while (i <= f){ 
            while (array[i] < p){ i++; }
            while (p < array[f]){ f--; }
                if (i <= f){ 
                    T x = array[i];
                    array[i] = array[f];
                    array[f] = x;
                    i++ ; 
                    f-- ;
                } 
    } 
    if (ini < f) Qsort(array, ini, f);
    if (i < fin) Qsort(array, i, fin);
} 

template <class T>
void Msort(T array[], int ini, int fin){
    if (ini < fin) { 
     
        int cen = (ini+fin)/2;
        Msort (array, ini, cen);
        Msort (array, cen+1, fin);
           
        mezcla (array, ini, cen, fin);
    } 

}

template <class T>
void mezcla(T array[],int ini, int cen, int fin){
    int i = ini;
    int j = cen + 1;
    int k = ini;
    T aux[fin];
    cout << "entra" << endl;
    while ((i <= cen) && (j <= fin)){ 
        if (array[i] < array[j]){ 
            aux[k] = array[i] ;
            i++ ;
        }
        else{ 
            aux[k] = array[j];
            j++;
        }
        k++;
    }
    if (i > cen)
    while (j <= fin){ 
        aux[k] = array[j] ;
        j++; 
        k++;
    }
    else
    while (i <= cen){ 
        aux[k] = array[i] ;
        i++;
        k++;
    } 
    for(int k = ini; k <= fin; k++){
        array[k] = aux[k];
    }
}

template <class T>
void ShellSort(T array[], int n, double alfa){
bool aux = false;

    int salto = n;
    while(salto>1){
        salto = salto * alfa;
        for(int i=salto+1;i<n;i++){
            int j=i;
            T x = array[i];
         
            while(j>=salto && x < array[j-salto]){
                array[j]=array[j-salto];
                j=j-salto;
            }
            array[j]=x;
        }
    }

}