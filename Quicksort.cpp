#include <iostream> 
using namespace std; 

void Quicksort(int* arr, int izq, int der) 
{ 
     int i = izq, j = der, tmp; 
     int p = arr[(izq + der) / 2]; 

     while (i <= j) 
     { 
          while (arr[i] < p) i++; 
          while (arr[j] > p) j--; 
          if (i <= j) 
           { 
               tmp = arr[i]; 
               arr[i] = arr[j]; 
               arr[j] = tmp; 
               i++; j--; 
          } 
     } 

     if (izq < j) 
          Quicksort(arr, izq, j); 
     if (i < der) 
          Quicksort(arr, i, der); 
} 

int main() 
{ 

    cout<< "Este es el Metodo QuickSort\n\n";
    cout<< "Esta es la lista a ordenar\n";
    cout<< "88, 6, 69, -33, 98, 7, 23, 5, 0, 100\n\n";
    cout<< "La lista de abajo ya se ha ordenado:\n\n";
     int arreglo[10] = { 88, 6, 69, -33, 98, 7, 23, 5, 0, 100}; 

     Quicksort(arreglo, 0, 9); 

     for(int i = 0; i < 10; i++) 
          cout << arreglo[i] << " "; 

     system("pause"); 
     return 0; 
}
