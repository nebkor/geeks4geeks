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

#include <climits>
#include <queue>

typedef std::pair<int, int> Node;

/* The function prints V space separated integers where
   the ith integer denote the shortest distance of ith vertex
   from source vertex */
void dijkstra(int graph[MAX][MAX], int s,int V)
{
  std::vector<int> costs(V, INT_MAX);
  costs[s] = 0;

  std::priority_queue<Node, std::vector<Node>, std::greater<Node>> todo;
  todo.push(Node(0, s));

  while (!todo.empty()) {
    Node node = todo.top();
    todo.pop();
    int min = node.first;
    int u = node.second;

    for (int v = 0 ; v < V ; ++v) {
      int local_cost = graph[u][v]; //weight of edge u-v, 0 if no edge
      bool has_edge = local_cost != 0;
      int old_cost = costs[v];
      int new_cost = min + local_cost;
      if (new_cost < old_cost && has_edge)
        {
          costs[v] = new_cost;
          todo.push(Node(new_cost, v));
        }
    }
  }

  for (int i = 0; i < V ; ++i) {
    std::cout << costs[i] << " ";
  }


}
