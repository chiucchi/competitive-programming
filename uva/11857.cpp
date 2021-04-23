/*
   Driving Rage (11857)
   @author: Chiucchi
*/

// Complexidade: O(n)

#include <iostream>
#include <vector>
#include <list>
#include <bits/stdc++.h>

using namespace std;

struct Graph {
   int v, e;
   vector< pair<int, pair<int, int>> > edges;

   Graph(int v, int edge) {
      this->v = v;
      this->e = edge;
   }

   void addEdge(int u, int v, int w){
      edges.push_back({w, {u, v}});
   }

   int kruskalAGM();
}; 

struct Disjuntos {
   int *pai, *rnk;
   int n;
  
   Disjuntos(int n)
   {
      this->n = n;
      pai = new int[n+1];
      rnk = new int[n+1];
  
      for (int i = 0; i <= n; i++){
         rnk[i] = 0;
         pai[i] = i;
      }
   }

   int find(int u) { // achar o pai
      if (u != pai[u])
            pai[u] = find(pai[u]);
   return pai[u];
   }
  
   void merge(int x, int y){
      x = find(x), y = find(y);
      if (rnk[x] > rnk[y])
         pai[y] = x;
      else 
         pai[x] = y;
      if (rnk[x] == rnk[y])
         rnk[y]++;
    }
};

int Graph::kruskalAGM(){
   int wt = 0;
  
   sort(edges.begin(), edges.end());
  
   Disjuntos ds(v);
  
   vector<pair<int, pair<int, int>> >::iterator it;
   for (it = edges.begin(); it != edges.end(); it++) {
      int u = it->second.first;
      int v = it->second.second;
  
      int set_u = ds.find(u);
      int set_v = ds.find(v);
  
      
      if (set_u != set_v) { // checar se aresta gera ciclo  
         if (it->first > wt)  wt = it->first;
         ds.merge(set_u, set_v);
      }
   }
   return wt;
}

int main ()  {
   int n, m;

   while (std::cin >> n >> m && n != 0 && m != 0)  {
      Graph g(n, m);
      for (int i = 0; i < m; i++) {
         int c1, c2, l;
         std::cin >> c1 >> c2 >> l;
         g.addEdge(c1, c2, l);
      }
      int x = g.kruskalAGM();
  
      std::cout << x << std::endl;
   }  
   if (n == 0 || m == 0) {
      std::cout << "IMPOSSIBLE" << std::endl;
   }
}