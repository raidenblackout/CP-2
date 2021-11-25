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
int nextDiff(vector<int> arr, int a, bool direction){
    int temp=arr[a];
    if(direction){
        while(a>=0 && arr[a]==temp){
            a--;
        }
        return a;
    }else{
        while(a<arr.size() && arr[a]==temp){
            a++;
        }
        return a;
    }
}
 
bool finder(vector<int> &arr, int n, bool direction){
    if(direction){
        int last=-1;
    bool flag=true;
    int i=0,j=n-1;
    while(true){
        if(arr[i]!=arr[j]){
            if(last==-1){
                int a=nextDiff(arr,i,false);
                int b=nextDiff(arr,j,true);
                if(arr[b]==arr[i]){
                    last=arr[j];
                    j=b;
                }
                else if(arr[a]==arr[j]){
                    last=arr[i];
                    i=a;
                }else{
                    flag=false;
                    break;
                }
            }else{
                //cout<<last<<endl;
                if(arr[i]!=last && arr[j]!=last){
                    flag=false;
                    break;
                }
                int a=nextDiff(arr,i,false);
                int b=nextDiff(arr,j,true);
                if(arr[a]==arr[j]){
                    last=arr[i];
                    i=a;
                }else if(arr[b]==arr[i]){
                    last=arr[j];
                    j=b;
                }else{
                    flag=false;
                    break;
                }
            }
        }else{
            i++;
            j--;
        }
        if(i>=j){
            break;
        }
    }
    return flag;
    }else{
        int last=-1;
    bool flag=true;
    int i=0,j=n-1;
    while(true){
        if(arr[i]!=arr[j]){
            if(last==-1){
                int a=nextDiff(arr,i,false);
                int b=nextDiff(arr,j,true);
                if(arr[a]==arr[j]){
                    last=arr[i];
                    i=a;
                }else if(arr[b]==arr[i]){
                    last=arr[j];
                    j=b;
                }else {
                    flag=false;
                    break;
                }
            }else{
                //cout<<last<<endl;
                if(arr[i]!=last && arr[j]!=last){
                    flag=false;
                    break;
                }
                int a=nextDiff(arr,i,false);
                int b=nextDiff(arr,j,true);
                if(arr[a]==arr[j]){
                    last=arr[i];
                    i=a;
                }else if(arr[b]==arr[i]){
                    last=arr[j];
                    j=b;
                }else{
                    flag=false;
                    break;
                }
            }
        }else{
            i++;
            j--;
        }
        if(i>=j){
            break;
        }
    }
    return flag;
    }
    
}

void run(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        bool flag = true;
        int last=-1;
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        flag=max(finder(arr,n,true),finder(arr,n,false));
    
        // int i=0,j=n-1;
        // while(true){
        //     if(arr[i]!=arr[j]){
        //         if(last==-1){
        //             int a=nextDiff(arr,i,false);
        //             int b=nextDiff(arr,j,true);
        //             if(arr[a]==arr[j]){
        //                 last=arr[i];
        //                 i=a;
        //             }else if(arr[b]==arr[i]){
        //                 last=arr[j];
        //                 j=b;
        //             }else{
        //                 flag=false;
        //                 break;
        //             }
        //         }else{
        //             cout<<last<<endl;
        //             if(arr[i]!=last && arr[j]!=last){
        //                 flag=false;
        //                 break;
        //             }
        //             int a=nextDiff(arr,i,false);
        //             int b=nextDiff(arr,j,true);
        //             if(arr[a]==arr[j]){
        //                 last=arr[i];
        //                 i=a;
        //             }else if(arr[b]==arr[i]){
        //                 last=arr[j];
        //                 j=b;
        //             }else{
        //                 flag=false;
        //                 break;
        //             }
        //         }
        //     }else{
        //         i++;
        //         j--;
        //     }
        //     if(i>=j){
        //         break;
        //     }
        // }
        cout<<(flag?"YES\n":"NO\n");
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