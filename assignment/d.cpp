#include <bits/stdc++.h>

using namespace std;


void primsAlgo(vector<vector<pair<int,int>>> &adj)
{
    priority_queue<pair<int,pair<int, int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>> > pq;
    int s = 0;
    pq.push({0, {s, s}});
    vector<pair<int,int>> res;
    vector<bool> visited(adj.size(), false);
    while(!pq.empty()){
        auto x = pq.top();
        int u=x.second.first;
        int v=x.second.second;
        int w=x.first;
        pq.pop();
        if(visited[v]) continue;
        visited[v]=1;
        for(auto y:adj[v]){
            int w2=y.second;
            int v2=y.first;
            if(!visited[v2]){
                pq.push({w2, {v,v2} });
            }
        }
        res.push_back({u,v});
    }
    for(auto &y: res){
        cout<<y.first<<" "<<y.second<<endl;
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
