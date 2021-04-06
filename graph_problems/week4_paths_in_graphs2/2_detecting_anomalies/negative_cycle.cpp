#include <iostream>
#include <vector>

//#define INT_MAX 2147483647



using std::vector;

int negative_cycle(vector<vector<int> > &adj, vector<vector<int> > &cost) {
  //write your code here
  int size_ = adj.size();
  int* min_cost = new int[size_];
  bool change_flag;
  for(register int i = 0;i < size_;i++)
    min_cost[i] = INT_MAX;

  min_cost[0] = 0;

  for(register int i = 0;i < size_;i++)
  {
     // change_flag = false;
      for(register int j = 0;j < adj[i].size();j++)
      {
          int cur_visit = adj[i][j];
          //relaxation
          if(min_cost[i] != INT_MAX && min_cost[cur_visit] > cost[i][j] + min_cost[i])
          {
              change_flag = true;
              min_cost[cur_visit] = cost[i][j] + min_cost[i];
          }

      }

  }


  return 1;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  vector<vector<int> > cost(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y, w;
    std::cin >> x >> y >> w;
    adj[x - 1].push_back(y - 1);
    cost[x - 1].push_back(w);
  }
  std::cout << negative_cycle(adj, cost);
}
