#include <bits/stdc++.h>

using namespace std;


void primsAlgo(vector<vector<pair<int,int>>> &adj)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    int s = 0;
    vector<int> distance(adj.size(), 1e9);
    vector<int> parent(adj.size(), -1);
    vector<bool> visited(adj.size(), 0);
    pq.push(make_pair(0, s));
    distance[s] = 0;
    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
        if (visited[u])
        {
            continue;
        }
        visited[u] = 1;
        for (auto x : adj[u])
        {
            int v = x.first;
            int w = x.second;
            if (!visited[v] && distance[v] > w)
            {
                distance[v] = w;
                pq.push(make_pair(distance[v], v));
                parent[v] = u;
            }
        }
    }
    for (int i = 1; i < adj.size(); i++){
        cout << parent[i] << " - " << i << endl;
    }
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<pair<int,int>>> graph(n);
    for(int i=0;i<m;i++){
        int u, v, w;
        cin>>u>>v>>w;
        graph[u].push_back(make_pair(v,w));
        graph[v].push_back(make_pair(u,w));
    }
    primsAlgo(graph);
    return 0;
}