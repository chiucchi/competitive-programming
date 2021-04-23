/*
   Guloso (1594)
   @author: Chiucchi
*/

// Complexidade: O(n+1-k)*k -> n+1-k pois é a forma que o codigo percorre o vetor e isto sempre vai acontecer, *k pois se o maior numero nao estiver dentro do novo subarray, ele ira percorrer o subarray em sua procura


#include <iostream>

long long somar (int vetor[], int k, int n) {
	long long resultado = 0;
	int pos, maior = 0;

	for (int i = 0; i <= n + 1 - k; i++) {
		std::cout << "I ---> " << i << std::endl;
			if (pos < i) { // se o maior nao estiver dentro do novo subarray ele sai procurando
			//	maior = 0;
				for (int j = i; j <= i + k; j += 1) {
					if (vetor[j] > maior) {
						maior = vetor[j];
						pos = j;
					}
				}
				std::cout << "1 O maior atualmente e: " << maior << std::endl;
				resultado += maior; // soma o resultado
				std::cout << "1 POS ----> " << pos << std::endl;
				std::cout << "1 A soma e: " << resultado << std::endl;
			} else if (maior < vetor[i+k-1] && pos >= i) { // testa se o maior atual é menor que o ultimo valor a entrar no subarray
				maior = vetor[i+k-1];
				pos = i+k-1;
				resultado += maior; // soma o resultado
				std::cout << "2 O maior atualmente e: " << maior << std::endl;
				std::cout << "2 A soma e: " << resultado << std::endl;
			} 
	}
	return resultado;
}

int main() {
  int t = 0;
	int n, k, s = 0;
	std::cin >> t;

	for (int i = 0; i < t; i++) {
	std::cin >> n; // tam array
	std::cin >> k; // tam subarray
	std::cin >> s;
	int array[n];
	
	array[0] = s;
	for (int i = 1; i < n; ++i) {
    array[i] = (1LL*array[i-1]*1103515245 + 12345) % (2147483648LL);
	//	std::cout << array[i] << std::endl;
	}
	
	std::cout << somar(array, k, n) << std::endl;
	}
}