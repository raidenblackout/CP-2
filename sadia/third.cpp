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

struct node{
    node *left;
    node *right;
    char c;
    int freq;
    node(char c,int freq){
        this->c=c;
        this->freq=freq;
        left=right=NULL;
    };
    node(char c){
        this->c=c;
        freq=0;
        left=right=NULL;
    };
};
struct CompareHeight {
    bool operator()(node *p1, node *p2)
    {
        return p1->freq > p2->freq;
    }
};

void printNode(node *t,string huffman){
    if(t==NULL)return;
    if(t->left==NULL && t->right==NULL){
        cout<<t->c<<" "<<t->freq<<" "<<huffman<<endl;
        return;
    }
    printNode(t->left,huffman+"0");
    printNode(t->right,huffman+"1");
}
void run(){
    vector<int> counter(26,0);
    string s;
    cin>>s;
    int n=0;
    for(int i = 0; i < s.size(); i++){
        counter[s[i]-'a']++;
    }
    priority_queue<node*,vector<node*>,CompareHeight> pq;
    for(int i = 0; i < 26; i++){
        if(counter[i]>0){
            pq.push(new node(i+'a',counter[i]));
        }
    }
    while(pq.size()>1){
        node *a=pq.top();
        pq.pop();
        node *b=pq.top();
        pq.pop();
        node *c=new node('*');
        c->left=a;
        c->right=b;
        c->freq=a->freq+b->freq;
        pq.push(c);
    }
    node *root=pq.top();
    pq.pop();
    printNode(root,"");
}

int main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    run();
}
