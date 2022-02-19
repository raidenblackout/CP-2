#include <bits/stdc++.h>

using namespace std;

struct customer{
    char name;
    double pphour;
    int hours;
    int e_time;
};
int main(){
    int n;
    cin >> n;
    vector<customer> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i].name  >> v[i].e_time>> v[i].hours >> v[i].pphour;
        v[i].e_time=v[i].e_time%12;
        v[i].pphour/=(double)v[i].hours;
    }
    sort(v.begin(), v.end(), [](customer a, customer b){
        return a.pphour > b.pphour;
    });
    vector<int> slots(10,0);
    vector<customer> selected;
    for(auto &x: v){
        int left=0;
        for(int i=x.e_time;i>=0;i--){
            if(!slots[i]){
                left++;
            }
        }
        if(left>x.hours){
            selected.push_back(x);
            int l=x.hours;
            for(int i=x.e_time;i>=0;i--){
                if(!slots[i]){
                    slots[i]=1;
                    l--;
                    if(l==0){
                        break;
                    }
                }
            }
        }
    }
    for(auto &x: selected){
        cout << x.name << " ";
    }
    cout<<endl;
    double total=0;
    for(auto &x: selected){
        total+=x.pphour*x.hours;
    }
    cout << total << endl;
}
