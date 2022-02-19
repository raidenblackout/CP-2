#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int>> result;
vector<pair<int,int>> dir={{-1,0},{1,0},{0,-1},{0,1}};
bool found=false;
void dfs(vector<vector<int>> &graph,int u,int v,vector<pair<int,int>> &path,vector<vector<int>> &visited){
    cout<<u<<" "<<v<<endl;
    if(found) return;
    if(u>=graph.size() || v>=graph[0].size() || u<0 || v<0 || graph[u][v]==2){
        return;
    }
    if(graph[u][v]==0){
        path.push_back({u,v});
        result=path;
        found=true;
        return;
    }
    if(visited[u][v]==1){
        return;
    }
    visited[u][v]=1;
    //path.push_back({u,v});
    for(auto x: dir){
        dfs(graph,u+x.first,v+x.second,path,visited);
    }
    visited[u][v]=0;
    path.pop_back();
}


int main(){
    freopen("output.txt","r",stdin);
    freopen("input.txt","w",stdout);
    int n,m;
    cin>>n>>m;
    vector<vector<int>> graph(n,vector<int>(m));
    int startu=0,startv=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>graph[i][j];
            if(graph[i][j]==1){
                startu=i;
                startv=j;
            }
        }
    }
    cout<<startu<<" "<<startv<<endl;
    vector<vector<int>> visited(n,vector<int>(m,0));
    vector<pair<int,int>> path;
    cout<<"dfs"<<endl;
    dfs(graph,startu,startv,path,visited);
    if(found){
        for(auto x:result){
            cout<<x.first<<" "<<x.second<<endl;
        }
    }else{
        cout<<-1 <<endl;
    }


}