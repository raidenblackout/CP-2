#include <bits/stdc++.h>

using namespace std;

int count_inversion(vector<int> &arr, int start, int end){
    if(start >= end) return 0;
    int mid = start+(end-start) / 2;
    int left_count = count_inversion(arr, start, mid);
    int right_count = count_inversion(arr, mid + 1, end);
    int split_inv = 0;
    int i = start, j = mid + 1;
    vector<int> temp;
    while(i <= mid && j <= end){
        if(arr[i] <= arr[j]){
            temp.push_back(arr[i]);
            i++;
        }
        else{
            temp.push_back(arr[j]);
            j++;
            split_inv += mid - i + 1;
        }
    }
    while(i <= mid){
        temp.push_back(arr[i]);
        i++;
    }
    while(j <= end){
        temp.push_back(arr[j]);
        j++;
    }
    for(int i = start; i <= end; i++){
        arr[i] = temp[i - start];
    }
    return left_count + right_count + split_inv;
}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    cout << count_inversion(arr, 0, n - 1) << endl;
    return 0;
}