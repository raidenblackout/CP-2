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
//modular inverse
ll mod_inverse(ll a, ll m)
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


//fft
void fft(vector<ll> &a, bool invert)
{
    int n = a.size();
    for (int i = 1, j = 0; i < n; i++)
    {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1)
            j ^= bit;
        j ^= bit;
        if (i < j)
            swap(a[i], a[j]);
    }
    for (int len = 2; len <= n; len <<= 1)
    {
        int wlen = invert ? len >> 1 : len;
        ll w = 1;
        for (int i = 0; i < wlen; i++)
        {
            ll u = a[i];
            ll t = w * a[i + wlen] % MOD;
            a[i] = (u + t) % MOD;
            a[i + wlen] = (u - t) % MOD;
            w = w * wn % MOD;
        }
    }
    if (invert)
    {
        ll inv = mod_inverse(n, MOD);
        for (int i = 0; i < n; i++)
            a[i] = a[i] * inv % MOD;
    }
}

ll mod_exp(ll x, ll e)
{
    ll ans = 1;
    while (e)
    {
        if (e & 1)
            ans = (ans * x) % MOD;
        x = (x * x) % MOD;
        e >>= 1;
    }
    return ans;
}

ll binpow(ll a, ll b)
{
    ll ans = 1;
    while (b)
    {
        if (b & 1)
            ans = (ans * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return ans;
}

ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(

void run(){
    int t;
    cin>>t;
    while(t--){
        int a,b,x;
        cin>>a>>b>>x;
        int mm=min(a,b);
        int mx=max(a,b);
        //cout<<p<<endl;
        while((mm!=x || mx!=x)&& mm!=0){
            cout<<mm<<" "<<mx<<endl;
            if(x<=mx && x>=mm){
                mx-=mm;
            }else{
                int p=mm;
                mm=__gcd(mm,mx);
                mx=p;
            }
        }
        if(mm==0){
            cout<<"NO"<<endl;
        }else{
            cout<<"YES"<<endl;
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
