/*
   Problema dos Pares Mais Próximos (1295)
   @author: Chiucchi
*/


// Complexidade do algoritmo: O(N^2)

#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

template < typename T >

class Matrix {
 private: 
   int lines ;
   int columns;
   T** data ;
 
 public:
 
   Matrix ( int lines, int columns ) {
      this->lines = lines;
      this->columns = columns;
      data = new T* [ lines ];
      for ( int x = 0; x < lines; x=x+1 )
      {
         data [x] = new T [ columns ];
      }
   } 
   
 
   void setValue (int line, int column, T value){
      if ( line < 0 || line >= lines ||
      column < 0 || column >= columns ){
         cout << "\nERROR: Invalid position.\n";
      }
      else{
         data [ line ][ column ] = value;
      } 
   } 
   
   T get (int line, int column) {
      T value = 0; // value has type dependency
      if ( line < 0 || line >= lines ||
       column < 0 || column >= columns ){
         cout << "\nERROR: Invalid position.\n";
      }else{
         value = data [ line ][ column ];
      }
      return ( value );
   } 
   
   void calcDist(Matrix coordenadas, int n) {
      double menor_dist = 10000.0;
      double dist_atual = 0.0;
      double xa, ya, xb, yb;

      for (int i = 0; i < n; i++) {
         xa = coordenadas.get(i,0); // 'fixo'
         ya = coordenadas.get(i,1); // 'fixo'
         for (int j  =  i+1;  j < n;  j++) {
            xb = coordenadas.get(j,0);
            yb = coordenadas.get(j,1);
            dist_atual = sqrt(pow(abs(xb - xa), 2) + pow(abs(yb - ya), 2));
            if (dist_atual < menor_dist){
               menor_dist  = dist_atual;
            } 
         }
      }

      if (menor_dist >= 10000) std::cout << "INFINITY" << std::endl;
      else std::cout << std::fixed << std::setprecision(4) << menor_dist << std::endl;
   }
};


int main () {
   int n;

   while (std::cin >> n && n != 0) {
      Matrix <double> coordenadas (n,2); // x  =  [i][0]  y = [i][1]
      double x, y;
      for (int i = 0; i < n; i++) {
         std::cin >> x >>  y;
         coordenadas.setValue(i,0,x);
         coordenadas.setValue(i,1,y);
      }
      coordenadas.calcDist(coordenadas, n);
   }
}