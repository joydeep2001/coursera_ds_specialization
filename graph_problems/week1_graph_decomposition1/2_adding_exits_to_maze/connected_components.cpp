#include <iostream>
#include <vector>

using std::vector;
using std::pair;

void explore(vector<vector<int> > &adj, bool* visited, int i){

    for(int j = 0;j < adj[i].size();j++)
    if(!visited[adj[i][j]]){
        visited[adj[i][j]] = true;
        explore(adj, visited, adj[i][j]);
    }

}


int number_of_components(vector<vector<int> > &adj, bool* visited, int n) {
  int res = 0;
  //write your code here

  for(int i = 0;i < n;i++){
    if(!visited[i]){
        visited[i] = true;
        explore(adj, visited, i);
        res++;
    }
  }


  return res;
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }

  bool* visited = new bool[n];

  std::cout << number_of_components(adj, visited, n);
}
