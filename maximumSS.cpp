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

//maximum subarray sum with divide and conquer
int maxSubArraySum(vector<int>& a, int low, int high)
{
    if (low == high)
        return a[low];
    int mid = (low + high) / 2;
    int left_sum = maxSubArraySum(a, low, mid);
    int right_sum = maxSubArraySum(a, mid + 1, high);
    int leftCrossing_sum = 0;
    int leftMaxSum=0;
    int rightCrossing_sum = 0;
    int rightMaxSum=0;
    for (int i = mid; i >= low; i--)
    {
        leftCrossing_sum += a[i];
        if (leftCrossing_sum > leftMaxSum)
            leftMaxSum = leftCrossing_sum;
    }
    for (int i = mid + 1; i <= high; i++)
    {
        rightCrossing_sum += a[i];
        if (rightCrossing_sum > rightMaxSum)
            rightMaxSum = rightCrossing_sum;
    }
    return max(max(left_sum, right_sum), leftMaxSum + rightMaxSum);
}

void run(){
    vector<int> arr={20,-7,12,-5,-2,15,-5,7,-10};
    cout<<maxSubArraySum(arr,0,arr.size()-1)<<endl;
}

int main() {
    run();
}
