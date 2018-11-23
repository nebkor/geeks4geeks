
#include<bits/stdc++.h>
using namespace std;
vector<int> graph[10001];
int * topoSort(vector<int> graph[],int N);
int main()
{
  int T;
  cin>>T;
  while(T--)
    {
      memset(graph,0,sizeof graph);
      int N,E;
      cin>>E>>N;
      for(int i=0;i<E;i++)
        {
          int u,v;
          cin>>u>>v;
          graph[u].push_back(v);
        }
      int *res = topoSort(graph,N);
      bool valid =true;
      for(int i=0;i<N;i++)
        {
          std::cout << res[i] << " ";
          int n=graph[res[i]].size();
          for(int j=0;j<graph[res[i]].size();j++)
            {
              for(int k=i+1;k<N;k++)
                {
                  if(res[k]==graph[res[i] ] [j] )
                    n--;
                }
            }
          if(n!=0)
            {
              valid =false;
              break;
            }
        }
      std::cout << std::endl;
      if(valid==false)
        cout<< "wrong" <<endl;
      else
        cout<< "right" <<endl;
    }
}



/*Please note that it's Function problem i.e.
  you need to write your solution in the form of Function(s) only.
  Driver Code to call/invoke your function is mentioned above.*/

#include <queue>

typedef std::pair<int, int> Node; // pair<num_incoming_edges, node_id>
typedef std::priority_queue<int, std::vector<Node>, std::greater<Node>> minheap;

/* You need to complete this function */
int * topoSort(vector<int> graph[], int N)
{
  int *res = new int[N];
  std::vector<int> nodes(N, 0);
  minheap order;

  for (size_t v = 0 ; v < size_t(N) ; ++v) {
    auto vertex = graph[v];
    for (size_t n = 0 ; n < vertex.size() ; ++n) {
      nodes[vertex[n]] += 1;
    }
  }

  for (int i = 0 ; i < N ; ++i) {
    Node node(nodes[i], i);
    order.push(node);
  }

  for (int i = 0 ; i < N ; ++i) {
    res[i] = order.top().second;
    order.pop();
  }

  return res;
}
