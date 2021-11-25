#include <iostream>

void sort(int *x, int *y);
int partition(int arr[], int low, int high);
void QUICKSORT(int arr[], int low, int high);
void printarray(int arr[], int n);
using namespace std;

int main()
{
    int arr[] = {7, 6, 10, 5, 9, 2, 1, 15, 7};
    int length = sizeof(arr) / sizeof(arr[0]);
    QUICKSORT(arr, 0, length - 1);
    printarray(arr, length);
    return 0;
}
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
int partition(int arr[], int low, int high)
{
    int pivot = arr[low];
    int start = low;
    int end = high;
    while (start < end)
    {
        while (arr[start] <= pivot)
            start++;
        while (arr[end] > pivot)
            end--;
        if (start < end)
            swap(&arr[start], &arr[end]);
    }
    swap(&arr[low], &arr[end]);
    return end;
}
void QUICKSORT(int arr[], int low, int high)
{
    if (low < high)
    {
        int pivot = partition(arr, low, high);
        QUICKSORT(arr, low, pivot - 1);
        QUICKSORT(arr, pivot + 1, high);
    }
}
void printarray(int arr[], int n)
{
    cout << "The Sorted Array is: ";
    for (int i = 0; i < n; i++)
    {
        cout << " " << arr[i];
    }
    cout << endl;
}