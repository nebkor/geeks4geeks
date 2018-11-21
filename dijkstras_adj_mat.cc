// A C / C++ program for Dijkstra's single source shortest path algorithm.
// The program is for adjacency matrix representation of the grap
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000
int g[MAX][MAX];
void dijkstra(int graph[MAX][MAX], int ,int V);
int main()
{
   /* Let us create the example graph discussed above */
   int t;
int V;
   cin>>t;
   while(t--){
cin>>V;
  for(int i=0;i<V;i++)
  {
  	for(int j=0;j<V;j++)
  	{
  		cin>>g[i][j];
  	}
  }
  int s;
  cin>>s;
    dijkstra(g, s,V);
cout<<endl;
   }
    return 0;
}


/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

#include <map>
#include <climits>

/* The function prints V space separated integers where
    the ith integer denote the shortest distance of ith vertex
    from source vertex */
void dijkstra(int graph[MAX][MAX], int s,int V)
{
   std::map<int, int> weights;

   int *neighbors = graph[s];
   for (int i = 0 ; i < V ; ++i) {
       int weight = neighbors[i];
       if (weight == 0 && i != s) {
           weights[i] = INT_MAX;
       } else {
           weights[i] = weight;
       }
   }

   // we have visited every vertex and have a preliminary weight
   for (int v = 0 ; v < V ; ++v) {
       int *vertex = graph[v];
       for (int n = 0 ; n < V ; ++n) {
           int wn = vertex[n]; // weight from current vertex to n'th neighbor
           int old_v = weights[v]; // previous minimum weight to current vertex from start vertex
           int old_n = weights[n]; // previous minimum weight to current neighbor from start vertex
           int new_v = min(old_v, wn + old_n);
           int new_n = min(old_n, new_v + wn);
           new_v = min(new_v, new_n + wn);
           new_n = min(new_n, new_v + wn);
           bool shorter_to_neighbor = new_n < old_n;
           bool shorter_to_v = (wn + min(old_n, new_n)) < old_v;
           weights[v] = new_v;
           weights[n] = new_n;
       }
   }
   for (auto i = weights.begin() ; i != weights.end() ; ++i) {
       std::cout << i->second << " ";
   }


}
