#include <iostream>
#include <algorithm>
#include <vector>
#include<stack>

using std::vector;
using std::pair;
using std::stack;
using std::cout;

void explore(vector<vector<int> > &adj, stack<int>* order, bool* visited, int i){
    for(int k = 0;k < adj[i].size();k++)
    {

        if(!visited[adj[i][k]])
        {
            visited[adj[i][k]] = true;
            explore(adj, order, visited, adj[i][k]);
            order->push(adj[i][k]);
        }

    }
}

stack<int> toposort(vector<vector<int> > &adj, int n) {

  stack<int> order;
  //write your code here
  bool* visited = new bool[n];
  for(int i = 0;i < n;i++)
  {
    visited[i] = false;
  }

  for(int i = 0;i < n;i++)
  {
      if(!visited[i])
      {
        visited[i] = true;
        explore(adj, &order, visited, i);
        order.push(i);
      }
  }


  return order;
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
  stack<int> order = toposort(adj, n);

  while(!order.empty())
  {
      cout << order.top() + 1<< " ";
      order.pop();
  }
}
