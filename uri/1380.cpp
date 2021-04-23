/*
   Bacilos (1380)
   @author: Chiucchi
*/

// Complexidade: O(N), linear


#include <iostream>
#include <string> 

void calcularBacilos (int k) {
	unsigned long long a = 0, b = 1, c, i; 
  if (k == 0) 
    std::cout << 0 << std::endl;
  for (i = 2; i <= k; i++) {
		 
     c = a%1000 + b%1000; 
     a = b%1000; 
     b = c; 
	}
	if (b < 10) {
		std::string s = std::to_string(b);
		std::cout << "00" << s << std::endl;
	} else if (b > 9 && b < 100){
		std::string s = std::to_string(b);
		std::cout << "0" << s << std::endl;
	} else if (b > 10){
		std::cout << b%1000 << std::endl;
	}
	
}

int main() {
	int n = 0;
	int k = 0;
	
	std::cin >> n;
	for(int i = 0; i < n; i++) {
		std::cin >> k;
		calcularBacilos(k);
	}
}