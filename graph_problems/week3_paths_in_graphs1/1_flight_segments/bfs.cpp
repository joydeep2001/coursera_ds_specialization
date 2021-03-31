#include <iostream>
#include <vector>
#include <queue>

using std::vector;
using std::queue;


void explore(vector<vector<int > > &adj, int curr, bool* visited, int* distance,queue<int>* q)
{


    for(int i = 0;i < adj[curr].size();i++)
    {
        if(!visited[adj[curr][i]])
        {
            visited[adj[curr][i]] = true;
            distance[adj[curr][i]] = distance[curr] + 1;
            q->push(adj[curr][i]);
        }

    }

}

int distance(vector<vector<int> > &adj, int source, int dest) {
  //write your code here
    queue<int> q;
    int* distance = new int[adj.size()];
    bool* visited = new bool[adj.size()];
    //initializing distance array
    for(int i = 0;i < adj.size();i++)
    {
        if(i == source)
        {
            distance[i] = 0;
        }
        else
        {
            distance[i] = -1;
        }
    }
    for(int i = 0;i < adj.size();i++)
    {
        visited[i] = false;
    }


    distance[source] = 0;

    q.push(source);
    explore(adj, source, visited, distance, &q);

    while(!q.empty())
    {
        int f = q.front();
        q.pop();
        explore(adj, f, visited, distance, &q);
        if(distance[dest] != -1)
        {

            return distance[dest];
        }

    }


    return -1;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  bool* visited;
  for (int i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  int s, t;
  std::cin >> s >> t;
  s--, t--;



  std::cout << distance(adj, s, t);
}
