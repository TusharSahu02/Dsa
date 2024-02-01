#include <bits/stdc++.h>
using namespace std;

// T.C - O(NlogN)
// S.C - O(N)

void merge(int arr[], int low, int mid, int high)
{
    int n = low + high;
    int temp[n];
    int left = low;
    int right = mid + 1;
    int i = 0;

    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
        {
            temp[i] = arr[left];
            i++;
            left++;
        }
        else
        {
            temp[i] = arr[right];
            i++;
            right++;
        }
    }

    while (left <= mid)
    {
        temp[i] = arr[left];
        i++;
        left++;
    }
    while (right <= high)
    {
        temp[i] = arr[right];
        i++;
        right++;
    }
    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[i - low];
    }
}

void mergeSort(int arr[], int low, int high)
{
    if (low >= high)
        return;
    int mid = (low + high) / 2;

    mergeSort(arr, low, mid);
    mergeSort(arr, mid + 1, high);
    merge(arr, low, mid, high);
}

int main()
{
    int arr[] = {12, 46, 24, 52, 20, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    mergeSort(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}