#include <bits/stdc++.h>
#if 0
#define HOME
#endif
#ifndef ONLINE_JUDGE
#define dbgA2(A, n, m)  {cout<<"-->"<<#A<<"=\n";for(int i = 0; i < n; i++){for(int j = 0; j < m; j++){cout<<A[i][j]<<" ";}cout<<"\n";}cout<<"\n";}
#define dbgA(A, n)      {cout<<"-->"<<#A<<"=(";for(int i = 0; i < n; i++)cout<<A[i]<<" ";cout<<")\n";}
#define dbg(args...)    {string sss(#args);sss+=',';cout<<"-->";debugger::call(sss.begin(), sss.end(), args);cout<<"\n";}
#else
#define dbgA2(A, n, m)
#define dbgA(A, n)
#define dbg(args...)
#endif
#define fora(I,n) for(int I=0; I<n;I++)
#define forb(I,n) for(int I=1; I<=n;I++)
#define mXI (int)1e8
#define umXI UINT_MAX
#define llmXI LLONG_MAX
#define pb push_back
#define ll long long
using namespace std;
/*struct debugger {
    typedef string::iterator si;
    static void call(si it, si ed) {}
    template<typename T, typename ... aT>
    static void call(si it, si ed, T a, aT... rest) {
        string b;
        for(; *it!=','; ++it)
            if(*it!=' ')
                b+=*it;
        cout << b << "=" << a << " ";
        call(++it, ed, rest...);
    }
};
ll siev_arr[mXI];
void siev(ll n)
{
    siev_arr[0] = siev_arr[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        if (!siev_arr[i])
        {
            cout<<i<<endl;
            for (int j = i + i; j <= n; j += i)
            {
                siev_arr[j] = 1;
            }
        }
    }
}

int dfs(int v, int *arr, int *visited){
    if(visited[arr[v]]){
        return arr[v]=arr[arr[v]];
    }
    visited[v]=1;
    return arr[v]=dfs(arr[v],arr,visited);
}*/

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
            ans.pb({u,v});
            join(arr, depth,u, v);
        }
    }
    return ans;
}


void run(){
    int n;
    cin>>n;
    vector<pair<int,pair<int,int>>> graph;
    for(int i=0; i<n; i++){
        int u,v,w;
        cin>>u>>v>>w;
        graph.pb(make_pair(w, make_pair(u,v)));
    }
    vector< pair<int,int> > ans=kruskal(graph);
    for(auto x: ans){
        cout<<x.first<<" "<< x.second <<endl;
    }
}

int main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    run();
}
