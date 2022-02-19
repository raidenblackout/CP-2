#include <bits/stdc++.h>

using namespace std;
int maximumresult=0;
int dp[507][507];
int dfs(vector<vector<int>> &graph,int u,int v){
    if(u==graph.size()-1 && v==graph.size()-1){
        return 0;
    }
    if(u>=graph.size() || v>=graph.size()){
        return -INT_MAX;
    }
    if(dp[u][v]!=-1){
        return dp[u][v];
    }
    return dp[u][v]=max(dfs(graph,u+1,v)+graph[u][v],dfs(graph,u,v+1)+graph[u][v]);
}


int main(){
    int n;
    cin>>n;
    memset(dp,-1,sizeof(dp));
    vector<vector<int>> graph(n,vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>graph[i][j];
        }
    }
    cout<<dfs(graph,0,0);

}