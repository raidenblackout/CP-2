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

bool test(vector<int> &arr, vector<int> &v){
    stack<int> left;
    queue<int> right;
    int i=0,j=arr.size()-1;
    int index=0;
    while(i<=j){
        if(i==j){
            index=i;
        }
        if(arr[i]<arr[j]){
            left.push(arr[i]);
            i++;
        }else{
            right.push(arr[j]);
            j--;
        }
    }

    vector<int> res,res2;
    res2.push_back(arr[index]);
    while(!left.empty()){
        res.pb(left.top());
        res2.push_back(left.top());
        left.pop();
    }
    while(!right.empty()){
        res.pb(right.front());
        if(arr[index]!=right.front()){
            res2.push_back(right.front());
        }
        right.pop();
    }
    return res==v || res2==v;
}

vector<int> rev(vector<int> v1){
    vector<int> v=v1;
    reverse(v.begin(),v.end());
    if(test(v,v1)){
        return v;
    }
    return {};
}

void run(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> v(n);
        fora(i,n)cin>>v[i];
        vector<int> res=rev(v);
        if(res.empty()){
            cout<<-1<<endl;
        }else{
            fora(i,res.size()){
                cout<<res[i]<<" ";
            }
            cout<<endl;
        }
        
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