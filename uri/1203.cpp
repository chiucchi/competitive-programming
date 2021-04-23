/*
   Pontes de São Petesburgo (1203)
   @author: Chiucchi
*/

#include <bits/stdc++.h>

bool calc(int vet[], int k, int r) {
   for (int i = 0; i < r; i++) { 
      int soma = vet[i];
      for (int j = i+1; j < r; j++) {
         soma += vet[j];
         if(vet[i] + vet[j] == k) return true;
         if(vet[i] + vet[i] == k) return true;
         if(vet[i] == k || vet[j] == k) return true;
         for (int z = j+1; z < r; z++){
            soma += vet[z];
           // std::cout << "k: " << k << " soma: " << soma << std::endl;
            if (vet[i] + vet[j] + vet[z] == k) return true;
            if(vet[z] == k) return true;
            if (soma == k) return true;
            if (soma > k) {
               soma = soma - vet[z];
              // std::cout << "soma - z: " << soma << " - " << vet[z] << std::endl;
            }
         } 
      }
   }
   return false;
}

int main () {
   int r, k;
   int vet[100];

   while(std::cin >> r >> k) {
      if (r <= 100 && k <= (r*(r-1)/2))
         for (int i = 0; i < k; i++) {
            vet[i] = 0;
         }
         for (int i = 0; i < k; i++) {
            int regiao;
            std::cin >> regiao;
            vet[regiao-1]++;
            std::cin >> regiao;
            vet[regiao-1]++;
         }
       if (calc(vet, k, r) == true) std::cout << "S" << std::endl;
       else std::cout << "N" << std::endl;
   }
}