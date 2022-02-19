#include <bits/stdc++.h>
using namespace std;

int main(){
    int t=10;
    vector<int> taken(51);
    vector<int> v;
    for(int i=0;i<t;i++){
        int x;
        cin>>x;
        if(!taken[x]){
            taken[x]=1;
            v.push_back(x);
        }
    }
    for(auto &x:taken){
        cout<<x<<" ";
    }
}