#include <bits/stdc++.h>

using namespace std;

bool dfs(vector<vector<int>> &graph, vector<int> &visited,int u,set<int> &parents){
    if(visited[u]){
        return parents.find(u)!=parents.end();
    }
    visited[u]=1;
    parents.insert(u);
    for(int i=0;i<graph[u].size();i++){
        if(!dfs(graph,visited,graph[u][i],parents)){
            return false;
        }
    }
    parents.erase(u);
    return true;
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>> graph(n);
    for(int i=0;i<n;i++){
        int u, v;
        cin>>u>>v;
        graph[u].push_back(v);
    }
    vector<int> visited(n,0);
    for(int i=0;i<n;i++){
        if(!visited[i]){
            set<int> parents;
            if(!dfs(graph,visited,i,parents)){
                cout<<"NO"<<endl;
                return 0;
            }
        }
    }
    cout<<"YES"<<endl;
}