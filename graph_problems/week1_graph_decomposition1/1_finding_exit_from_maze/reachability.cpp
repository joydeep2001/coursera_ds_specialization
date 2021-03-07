#include <iostream>
#include <vector>

using std::vector;
using std::pair;


int reach(vector<vector<int> > &adj, int x, int y, bool* visited) {
  //write your code here
   visited[x] = true;

   for(int i=0;i < adj[x].size();i++){
       if(!visited[adj[x][i]]){
           if(adj[x][i] == y){
            return 1;
           }
           if(reach(adj, adj[x][i], y,visited) == 1){
                std::cout << "1";
                exit(0);
           }
       }
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
    adj[y - 1].push_back(x - 1);
  }
  int x, y;
  std::cin >> x >> y;
  bool* visited = new bool[n];
  for(int i = 0;i < n;i++){
    visited[i] = false;
  }
  std::cout << reach(adj, x - 1, y - 1, visited);
}
