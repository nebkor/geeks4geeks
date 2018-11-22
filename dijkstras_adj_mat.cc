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
  std::vector<int> costs;
  costs.resize(ulong(V), INT_MAX);
  for (int i = 0 ; i < V ; ++i) {
    costs[i] = INT_MAX;
  }

  costs[s] = 0;

  std::set<int> done;

  while (done.size() < ulong(V)) {
    int min = INT_MAX;
    int u = -1;
    for (int n = 0 ; n < V ; ++n) {
      if ( (done.find(n) == done.end()) && costs[n] <= min) {
        u = n;
        min = costs[n];
      }
    }
    auto _nada = done.insert(u);

    for (int n = 0 ; n < V ; ++n) {
      int cost = graph[u][n]; //weight of edge u-n
      int new_cost = min + cost;
      if (new_cost < costs[n])
        {
          costs[n] = new_cost;
        }
    }

  } // end while



  for (int i = 0; i < V ; ++i) {
    std::cout << costs[i] << " ";
  }


}
