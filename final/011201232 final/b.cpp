#include <bits/stdc++.h>

using namespace std;
int find(vector<int> &arr, int u){
    if(arr[u]==u)
        return u;
    return arr[u]=find(arr,arr[u]);
}

void join(vector<int> &arr,vector<int> &depth, int u, int v){
    int x=find(arr, u);
    int y=find(arr, v);
    if(depth[x]>depth[y]){
        arr[y]=x;
        depth[x]+=depth[y];
    }
    else{
        arr[x]=y;
        depth[y]+=depth[x];
    }
}
int maximum=0;
vector<pair<int,int>> kruskal(vector<pair<int,pair<int,int>>> graph){
    sort(graph.begin(), graph.end());
    vector<int> arr(graph.size()+1, 0);
    vector<int> depth(graph.size()+1, 1);
    for(int i=1; i<=graph.size(); i++){
        arr[i]=i;
        depth[i]=1;
    }
    vector<pair<int,int>> ans;
    for(int i=0; i<graph.size(); i++){
        int u=graph[i].second.first;
        int v=graph[i].second.second;
        int w=graph[i].first;
        int x=find(arr, u);
        int y=find(arr, v);
        if(x!=y){
            ans.push_back({u,v});
            maximum+=w;
            join(arr, depth,u, v);
        }
    }
    return ans;
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<pair<int,pair<int,int>>> graph(m);
    int anss=0;
    for(int i=0; i<m; i++){
        int u,v,w;
        cin>>u>>v>>w;
        graph[i]={w,{u,v}};
        anss+=w;
    }
    vector<pair<int,int>> ans=kruskal(graph);
    cout<<anss-maximum<<endl;
    for(auto x: ans){
        cout<<x.first<<" "<< x.second <<endl;
    }
}