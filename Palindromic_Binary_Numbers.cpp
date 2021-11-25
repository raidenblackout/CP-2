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

string decimalToBinary(int n)
{
    string s = bitset<64> (n).to_string();
    const auto loc1 = s.find('1');
     
    if(loc1 != string::npos)
        return s.substr(loc1);
    return "0";
}
vector<int> palindromes;
vector<int> temp;
vector<int> res;
//modular inverse
ll modInverse(ll a, ll m)
{
    ll m0 = m;
    ll y = 0, x = 1;
    if (m == 1)
        return 0;
    while (a > 1)
    {
        ll q = a / m;
        ll t = m;
        m = a % m, a = t;
        t = y;
        y = x - q * y;
        x = t;
    }
    if (x < 0)
        x += m0;
    return x;
}


bool sumTrue(int n, int k){
    if(k>12) return false;
    if(n==0){
        res=temp;
        return true;
    }
    for(int i=0;i<palindromes.size() && palindromes[i]<=n;i++){
        temp.pb(palindromes[i]);
        if(sumTrue(n-palindromes[i],k+1)) return true;
        temp.pop_back();
    }
    return false;
}

void run(){
    for(int i=1;i<=1000;i++){
        string s=decimalToBinary(i);
        string k=s;
        reverse(k.begin(),k.end());
        if(s==k){
            palindromes.pb(i);
        }
    }
    //sort(palindromes.begin(),palindromes.end(),greater<int>());
    int t;
    cin>>t;
    while(t--){
        temp=res=vector<int>();
        int n;
        cin>>n;
        sumTrue(n,0);
        cout<<res.size()<<endl;
        for(int i=0;i<res.size();i++){
            cout<<res[i]<<" ";
        }
        cout<<endl;
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
