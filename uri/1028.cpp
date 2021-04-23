/*
   Figurinhas (1028)
   @author: Chiucchi
*/

// Complexidade: O(3n^3)

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

int mdc(int, int);

int main() {
	int n = 0;
  int a = 0;
	int b = 0;

	std :: cin >> n;
	
	for (int i = 0; i < n; i++) {
		std :: cin >> a;
		std :: cin >> b;
	  std :: cout << mdc(a,b) << "\n";
	}
}

int mdc (int a, int b) {
	int x; 

	do {
		x = a % b; // tenta dividir um numero pelo outro, obtendo o resto da divisao
    a = b; // atribui o divisor 'possivel' entre os numeros
    b = x; // b vira o resto da divisao e e' o possivel divisor em comum
	} while (x != 0);
	return a;
}