#include <bits/stdc++.h>

using namespace std;

bool dfs(vector<vector<int>> &graph, vector<int> &visited, int u){
    if(visited[u]){
        return false;
    }
    visited[u]=1;
    for(int v:graph[u]){
        if(!dfs(graph,visited,v)){
            return false;
        }
    }
    return true;
}
int find(vector<int> &parent, int u){
    if(parent[u]==u){
        return u;
    }
    return parent[u]=find(parent, parent[u]);
}
int union_find(vector<int> &parent, int u, int v){
    int pu=find(parent, u);
    int pv=find(parent, v);
    if(pu==pv){
        return 0;
    }
    parent[pu]=pv;
    return 1;
}

void dfs(vector<vector<int>> &graph, int u, vector<int> &visited, vector<int> &parent){
    if(visited[u]){
        return;
    }
    visited[u]=1;
    for(int v:graph[u]){
        union_find(parent, u, v);
        dfs(graph, v, visited, parent);
    }

}

int main(){
    int n,e;
    cin>>n>>e;
    vector<vector<int>> arr(n);
    for(int i=0;i<e;i++){
        int u,v;
        cin>>u>>v;
        arr[u].push_back(v);
    }
    vector<int> visited(n,0);
    vector<int> parent(n);
    for(int i=0;i<n;i++){
        parent[i]=i;
    }
    for(int i=0;i<n;i++){
        dfs(arr, i, visited, parent);
    }
    map<int, set<int>> mp;
    for(int i=0;i<n;i++){
        mp[find(parent, i)].insert(i);
    }
    int i=0;
    for(auto x:mp){
        cout<<"Components "<<i++<<" : ";
        for(int i:x.second){
            cout<<i<<" ";
        }
        cout<<endl;
    }

}