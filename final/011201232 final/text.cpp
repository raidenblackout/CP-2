#include <bits/stdc++.h>

using namespace std;

int main(){
    int t=36000000;
    vector<int> v(6+6+1);
    srand(time(NULL));
    for(int i=0;i<t;i++){
        int x=rand()%6+1;
        int y=rand()%6+1;
        v[x+y]++;
    }
    for(int i=1;i<=12;i++){
        cout<<i<<" "<<(double)v[i]/(double)t*100.0<<endl;
    }
    return 0;

}