/*
   Roteadores (1774)
   @author: Chiucchi
*/

// Complexidade: O (c logn), c = numero de cabos conectando os roteadores. c x log(n) - tempo necessario para achar o par menos custoso de cada vertice (roteador)

#include <iostream>
#include <bits/stdc++.h> 

template <typename T>

class Graph {
	private:
	int lines;
	int columns;
	T** data;

	public:
	Graph(int lines, int columns) {
		this->lines = lines;
    this->columns = columns;
		data = new T* [lines];
    for (int x = 0; x < lines; x++){
      data [x] = new T [columns];
    }
	} // constructor

	void set (int line, int column, T value){
      if ( line < 0 || line >= lines ||
      column < 0 || column >= columns )
      {
        std::cout << "\nERROR: Invalid position.\n";
      }
      else{
         data [line][column] = value;
      }
   } // set

	T get (int line, int column){
      T value = 0; 
      if ( line < 0 || line >= lines ||
       column < 0 || column >= columns ){
        std::cout << "\nERROR: Invalid position.\n";
      }
      else{
         value = data [line][column];
      }
      return (value);
   }

	void prim(Graph g) {
		int num_edge = 0;
		int V = g.lines;
		int selected[g.lines];
		int sum = 0;

		memset(selected, false, sizeof(selected));
		selected[0] = true;
		
		int x, y;

		while (num_edge < V - 1) {
			int min = 999999;
    	x = 0;
    	y = 0;

			for (int i = 0; i < V; i++) {
				if (selected[i]) {
					for (int j = 0; j < V; j++) {
						if (!selected[j] && g.get(i, j)) {
							if (min > g.get(i, j)) {
								min = g.get(i, j);
								x = i;
								y = j;
							}
						}
					}
				}
			}
			sum += g.get(x,y);
			selected[y] = true;
    	num_edge++;
		}
		std::cout << sum << std::endl;
	}
	
};

int main() {
	int r, c = 0; // routers and cables quantity (nodes and edges)
	int v, w, p = 0; // v and w nodes (routers) that are connecteds by an edge w a 'p' value, representing the cable price

	std::cin >> r; // routers - nodes
	std::cin >> c; // cables - edges

	Graph<int> graph(r,r);

	

	for (int i = 0; i < c; i++) {
		std::cin >> v; // router - node
		std::cin >> w; // router - node
		std::cin >> p; // cable price - edge value
		// putting the values in the adjency matrix
		graph.set(v-1, w-1, p);
		graph.set(w-1, v-1, p);
	}
	graph.prim(graph); // summing all the prices as the challenge wants
}