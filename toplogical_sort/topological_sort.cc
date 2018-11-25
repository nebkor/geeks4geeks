
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
      std::cout << "Traversing graph:" << std::endl;
      for (int i = 0 ; i < N ; ++i) {
        auto v = graph[i];
        std::cout << i << ": ";
        for (auto n : v) {
          std::cout << n << " ";
        }
        std::cout << std::endl;
      }
      int *res = topoSort(graph,N);
      bool valid =true;
      std::cout << "res: ";
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
        cout<< "wrong" <<endl << endl;
      else
        cout<< "right" <<endl << endl;
    }
}



/*Please note that it's Function problem i.e.
  you need to write your solution in the form of Function(s) only.
  Driver Code to call/invoke your function is mentioned above.*/


#include <queue>

/* You need to complete this function */
int * topoSort(vector<int> graph[], int N)
{
  int *res = new int[N];
  std::vector<int> nodes(N, 0);
  std::queue<int> todo;

  for (size_t v = 0 ; v < size_t(N) ; ++v) {
    auto vertex = graph[v];
    for (auto n : vertex) {
      nodes[n] += 1;
    }
  }

  // the ith node in nodes contains number of node i's incoming edges.
  for (int i = 0 ; i < N ; ++i) {
    if (nodes[i] == 0) {
      todo.push(i);
    }
  }

  int count = 0;
  while (!todo.empty()) {
    int cur = todo.front();
    todo.pop();
    res[count] = cur;
    count++;

    for (auto n : graph[cur]) {
      if (--nodes[n] == 0) {
        todo.push(n);
      }
    }
  }

  return res;
}
