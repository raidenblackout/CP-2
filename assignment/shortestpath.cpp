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
#define ipair pair<int,int>
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
void printPath(vector<int> &parents, int u){
    if(parents[u]==u || parents[u]==-1){
        cout<<u<<" ";
        return;
    }
    printPath(parents,parents[u]);
    cout<<u<<" ";
}
void dijkstra(vector<vector<pair<int,int>>> &adj_list, int source){
    vector<int> distance(adj_list.size(),mXI);
    distance[source]=0;
    vector<int> parents(adj_list.size(),-1);
    priority_queue<ipair, vector<ipair>, greater<ipair>> pq;
    pq.push({0,source});
    parents[source]=source;
    while(!pq.empty()){
        auto u=pq.top();
        pq.pop();
        for(auto &c: adj_list[u.second]){
            int v=c.first;
            int w=c.second;
            if(distance[v]>distance[u.second]+w){
                distance[v]=distance[u.second]+w;
                parents[v]=u.second;
                pq.push({distance[v],v});
            }
        }
    }
    for(int i=0;i<adj_list.size();i++){
        cout<<"0 - "<<i<<" "<<distance[i]<<endl;
    }
    cout<<"Path"<<endl;
    for(int i=0;i<adj_list.size();i++){
        cout<<i<<": ";
        printPath(parents,i);
        cout<<endl;
    }
}


void run(){
    int n,e;
    cin>>n>>e;
    vector<vector<pair<int,int>>> adj_list(n);
    fora(i,e){
        int u,v,w;
        cin>>u>>v>>w;
        adj_list[u].push_back({v,w});
    }
    dijkstra(adj_list,1);
}

int main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    run();
}
