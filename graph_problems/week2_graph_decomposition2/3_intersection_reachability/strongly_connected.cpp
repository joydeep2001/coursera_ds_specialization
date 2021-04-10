#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;
using std::pair;



void explore(vector<vector<int> >& adj, int s,bool* visited)
{
    for(int j = 0;j < adj[s].size();j++)
    {
        if(!visited[adj[s][j]])
        {
            visited[adj[s][j]] = true;
            explore(adj, adj[s][j], visited);
        }
    }
}
int number_of_strongly_connected_components(vector<vector<int> >& adj) {
  int result = 0;
  //write your code here
  bool* visited = new bool[adj.size()];



  for(int i = 0;i < adj.size();i++)
  {
      for(int i = 0;i < adj.size();i++)
        visited[i] = false;

      explore(adj, i, visited);
      result++;

  }

  return result;
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
  }
  std::cout << number_of_strongly_connected_components(adj);
}
