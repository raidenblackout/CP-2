#include <bits/stdc++.h>
using namespace std;

int tt=0;
void dfs(vector<vector<int>> &graph, vector<int> &visited, vector<pair<int,int>> &end_time, int u){
    if(visited[u]){
        return;
    }
    visited[u]=1;
    tt++;
    for(int v:graph[u]){
        dfs(graph, visited, end_time, v);
    }
    tt++;
    end_time[u].first=tt;
}

void run(){
    int n,e;
    cin>>n>>e;
    vector<vector<int>> arr(n);
    for(int i=0;i<e;i++){
        int u,v;
        cin>>u>>v;
        arr[u].push_back(v);
    }
    vector<int> visited(n,0);
    vector<pair<int,int>> end_time(n);
    for(int i=0;i<n;i++){
        end_time[i].second=i;
    }
    for(int i=0;i<n;i++){
        dfs(arr, visited, end_time, i);
    }
    sort(end_time.begin(), end_time.end(),greater<pair<int,int>>());
    for(auto x:end_time){
        cout<<x.second<<" ";
    }
    cout<<endl;
}

int main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    run();
}