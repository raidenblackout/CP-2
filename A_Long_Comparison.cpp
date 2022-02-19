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

int compare(string s1, string s2){
    if(s1.length()<s2.length())return -1;
    if(s1.length()>s2.length())return 1;
    int i=0;
    while(i<s1.length() && i<s2.length()){
        if(s1[i]<s2[i]){
            return -1;
        }
        else if(s1[i]>s2[i]){
            return 1;
        }
        i++;
    }
    if(s1.length()<s2.length()){
        return -1;
    }
    else if(s1.length()>s2.length()){
        return 1;
    }
    return 0;
}

void run(){
    int t;
    cin>>t;
    while(t--){
        string a;int b;
        cin>>a>>b;
        string c;int d;
        cin>>c>>d;
        int n1=a.length();
        int n2=c.length();
        if(n1+b<n2+d){
            cout<<"<"<<endl;
        }else if(n1+b>n2+d){
            cout<<">"<<endl;
        }else{
            if(n1<n2){
                a+=string(n2-n1,'0');
                int cmp=compare(a,c);
                if(cmp==0){
                    cout<<"="<<endl;
                }else if(cmp==1){
                    cout<<">"<<endl;
                }else{
                    cout<<"<"<<endl;
                }
            }else if(n2<n1){
                c+=string(n1-n2,'0');
                int cmp=compare(a,c);
                if(cmp==0){
                    cout<<"="<<endl;
                }else if(cmp==1){
                    cout<<">"<<endl;
                }else{
                    cout<<"<"<<endl;
                }
            }else{
                int cmp=compare(a,c);
                if(cmp==0){
                    cout<<"="<<endl;
                }else if(cmp==1){
                    cout<<">"<<endl;
                }else{
                    cout<<"<"<<endl;
                }
            }
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