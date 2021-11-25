#include <stdio.h>

int min(int a, int b) {
    return a < b ? a : b;
}
int abs(int a) {
    return a < 0 ? -a : a;
}

int main(){
    int n;
    scanf("%d", &n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d", &arr[i]);
    }
    int mindiff=1e9;
    int first,second;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int temp = mindiff;
            mindiff=min(mindiff,abs(arr[i]-arr[j]));
            if(temp!=mindiff){
                first=i;
                second=j;
            }
        }
    }
    printf("%d %d\n",arr[first],arr[second]);
}