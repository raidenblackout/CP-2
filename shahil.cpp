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
*/
struct obj{
    int end_time;
    int index;
};

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
    fora(i,e){
        int u,v;
        cin>>u>>v;
        arr[u].pb(v);
    }
    vector<int> visited(n,0);
    vector<pair<int,int>> end_time(n);
    fora(i,n){
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
