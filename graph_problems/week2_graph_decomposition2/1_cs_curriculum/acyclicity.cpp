#include <iostream>
#include <vector>

using std::vector;
using std::pair;



bool explore(vector<vector<int> > &adj, bool* visited, int curr){


    if(visited[curr] == true){

        return true;
    }
    visited[curr] = true;
    for(int j = 0;j < adj[curr].size();j++){

        if(explore(adj, visited, adj[curr][j])){
            return true;
        }

    }

    visited[curr] = false;

    return false;
}

int acyclic(vector<vector<int> > &adj, int n) {
  //write your code here
  bool* visited = new bool[n];
  for(int i = 0;i < n;i++){
    visited[i] = false;
  }
  for(int i = 0;i < n;i++){
    visited[i] = true;
    for(int j = 0;j < adj[i].size();j++){

        if(explore(adj, visited, adj[i][j])){

            return 1;
        }


    }

    visited[i] = false;
  }

  return 0;
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

  std::cout << acyclic(adj, n);
}
