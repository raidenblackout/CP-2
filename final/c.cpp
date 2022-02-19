#include <iostream>
#include <vector>
using namespace std;
struct path{
    int u,v;
    path(int a,int b){
        u=a;
        v=b;
    }
    path(){};
};
vector<path> ans;
bool dfs(vector<vector<int>> &matrix,int from,int to,int n,int m,vector<path> location, vector<vector<int>> visited){
    if(from<n && to<m && from>=0 && to>=0 && matrix[from][to]!=2){
        if(matrix[from][to]==0){
            ans=location;
            ans.push_back(path(from,to));
            return true;
        }
        if(visited[from][to]==1){
            return false;
        }
        visited[from][to]=1;
        location.push_back(path(from,to));
        if(dfs(matrix,from+1,to,n,m,location,visited)){
            return true;
        }
        if(dfs(matrix,from-1,to,n,m,location,visited)){
            return true;
        }
        if(dfs(matrix,from,to+1,n,m,location,visited)){
            return true;
        }
        if(dfs(matrix,from,to-1,n,m,location,visited)){
            return true;
        }
    }
    return false;
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> matrix(n,vector<int>(m));
    path start;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>matrix[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(matrix[i][j]==1){
                start=path(i,j);
            }
        }
    }
    vector<vector<int>> visited(n,vector<int>(m,0));
    vector<path> location;
    if(dfs(matrix,start.u,start.v,n,m,location,visited)){
        for(auto edge:ans){
            cout<<edge.u<<" "<<edge.v<<endl;
        }
    }else{
        cout<<-1<<endl;
    }
}