#include <iostream>
#include <vector>

#define INT_MAX 2147483647



using namespace std;
//helper
template <typename T>
    void print(T* min_cost, int size_)
    {
        for(int i = 0;i < size_;i++)
            cout << min_cost[i] << " ";
        cout << endl;
    }

//real code
void dfs(vector<vector<int> > &adj, vector<vector<int> > &cost,int source, int* min_cost, bool* update, bool* visited)
{

    visited[source] = true;

    //cout << source << " ->";

    for(int i = 0;i < adj[source].size();i++)
    {
        int temp = adj[source][i];


        if(min_cost[temp] > min_cost[source] + cost[source][i])
        {

            min_cost[temp] = min_cost[source] + cost[source][i];
            *update = true;

            if(visited[temp])
                return;

            dfs(adj, cost, temp, min_cost, update, visited);

        }

    }

}

bool bellman_ford(vector<vector<int> > &adj, vector<vector<int> > &cost,int source)
{
    bool* visited = new bool[adj.size()];
    int* min_cost = new int[adj.size()];
    bool update;
    for(int i = 0;i < adj.size();i++)
    {

        min_cost[i] = INT_MAX;
    }

    min_cost[source] = 0;


    for(int i = 0;i < (adj.size() - 1);i++)
    {

        update = false;

        for(int k = 0;k < adj.size();k++)
            visited[k] = false;
        //cout << "min_cost: ";
        //print<int>(min_cost, adj.size());

        dfs(adj, cost, source, min_cost, &update, visited);
        //cout << endl;
        if(!update)
            break;
    }
    if(update)
        dfs(adj, cost, source, min_cost, &update, visited);

    return update;
}

bool negative_cycle(vector<vector<int> > &adj, vector<vector<int> > &cost) {
  //write your code here

  bool negetive_cycle_exists = false;
  for(int i = 0;i < adj.size();i++)
  {
      for(int j = 0;j < adj[i].size();j++)
      {

        if(cost[i][j] < 0)
            negetive_cycle_exists = bellman_ford(adj, cost, i);

            if(negetive_cycle_exists)
                return true;
      }
  }


  return false;
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
