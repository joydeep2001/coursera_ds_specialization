#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#define LLONG_MAX 9223372036854775807
using std::vector;
using std::queue;
using std::pair;
using std::priority_queue;
using std::greater;
using std::cout;
using std::endl;
using std::make_pair;

typedef pair<long long, int> pi;

int find_min(long long* arr, int n,bool* processed)
{

    long long min_ = LLONG_MAX;
    int min_id = -1;
    for(int i = 0;i < n;i++)
    {
        if(arr[i] < min_)
        {
            if(!processed[i])
            {
                min_  = arr[i];
                min_id = i;
            }
        }
    }

    return min_id;
}

void explore(int s, long long* min_cost, vector<vector<int> > &adj, vector<vector<int> > &cost, bool* processed)
{
    int id;
    for(int i = 0;i < adj.size();i++)
    {
        //finding the minimum cost unprocessed node
        id = find_min(min_cost, adj.size(), processed);
        if(id == -1)
            break;
        //cout << "id : " << id << endl;
        processed[id] = true;
        for(int j = 0;j < adj[id].size();j++)
        {
            long long temp = adj[id][j];
            long long cur_cost = min_cost[id] + cost[id][j];
            //relaxation
            if(min_cost[temp] > cur_cost)
            {
                min_cost[temp] = cur_cost;
            }
        }
    }


}

long long distance(vector<vector<int> > &adj, vector<vector<int> > &cost, int s, int t) {
  //write your code her
    int size_ = adj.size();
    long long* min_cost = new long long[size_];
    bool* processed = new bool[size_];

    for(int i = 0;i < size_;i++)
        processed[i] = false;

    for(int i = 0;i < size_;i++)
    {
        min_cost[i] = LLONG_MAX;

    }


    min_cost[s] = 0;

    explore(s, min_cost, adj, cost, processed);

    //cout << LLONG_MAX << " "<< min_cost[t] - 7;

  return (min_cost[t] == LLONG_MAX ? -1 : min_cost[t]);
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
  int s, t;
  std::cin >> s >> t;
  s--, t--;
  std::cout << distance(adj, cost, s, t);
}
