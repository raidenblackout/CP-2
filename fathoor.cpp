#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define ALL(v) v.begin(),v.end()
#define endl "\n"
#define in(x) scanf("%d",&x)

#define MAX 2000
#define MOD 1000000007
#define PI 2*acos(0.0)

typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vll;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef vector<bool> vb;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int x4[] = {1,0,-1,0};
int y4[] = {0,-1,0,1};
int x8[] = {1,1,0,-1,-1,-1,0,1};
int y8[] = {0,-1,-1,-1,0,1,1,1};

void prntVec(vector<int> &a){
    for(int i=0;i<a.size();i++){
        cout<<a[i];
        i+1==a.size()?cout<<endl:cout<<' ';
    }
    // cout<<endl;
}

const ll mod = 1e9+7;



ll n,k,m;
ll a,b,c,d;

ll dp[50][3];
//state 1: blue
//state 2: white
//state 0: red
ll DP(int n,int state,int prev = -1){

    if(n==1 && state==1) return 0;
    if(n==1 && state!=1) return dp[n][state] =1;
    if(n<1) return 0;

    if(dp[n][state]!=-1) return dp[n][state];
    ll a;
    if(state==0){
        if(prev!=1)
            a = DP(n-1,1,state)+DP(n-1,2,state); 
        else
            a = DP(n-1,2,state);
    }
    else if(state == 1){
        if(prev == 0)
            a = DP(n-1,2,state);
        if(prev == 2)
            a = DP(n-1,0,state);
    } 
    else{
        if(prev !=1)
            a = DP(n-1,0,state)+DP(n-1,1,state);
        else
            a = DP(n-1,0,state);
    }
    return dp[n][state] = a;
}

void solve(){
    memset(dp,-1,sizeof(dp));
    cin>>n;

    a = DP(n,0);
    cout<<a+a<<endl;

    // for(int i=1;i<=n;i++){
    //     for(int j=0;j<3;j++){
    //         cout<<dp[i][j]<<' ';
    //     }
    //     cout<<endl;
    // }



}


int main(){
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);

    int t=1,cas=1;

    // cin>>t;

    while(t--){
        // cout<<"Case "<<cas++<<":\n";
        solve();
        // if(t) cout<<endl;
    }

    return 0;

}