#include <bits/stdc++.h>
#define mXI 1e6
using namespace std;

void path(vector<vector<int>> &next, int i, int j){
    if(i==j || next[i][j]==-1){
        cout<<i<<" ";
        return;
    }
    cout<<i<<" ";
    path(next,next[i][j],j);
}

void floydWarshall(vector<vector<int>> &graph, int n)
{
    vector<vector<int>> distance(n,vector<int>(n,mXI));
    vector<vector<int>> next(n,vector<int>(n,-1));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            distance[i][j]=graph[i][j];
            if(graph[i][j]!=mXI){
                next[i][j]=j;
            }
        }
    }
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(distance[i][j]>distance[i][k]+distance[k][j]){
                    distance[i][j]=distance[i][k]+distance[k][j];
                    next[i][j]=next[i][k];
                }
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<distance[i][j]<<" ";
        }
        cout<<endl;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<i<<":"<<j<<"->";
            path(next,i,j);
            cout<<endl;
        }
        cout<<endl;
    }
}

int main(){
    int n;
    cin >> n;
    vector<vector<int>> graph(n, vector<int>(n, mXI));
    for(int i=0;i<n;i++)
    {
        for(int j=0; j<n;j++)
        {
            int x;
            cin >> x;
            if (x == 999999)
            {
                graph[i][j] = mXI;
            }
            else
            {
                graph[i][j] = x;
            }
        }
    }
    floydWarshall(graph, n);
}