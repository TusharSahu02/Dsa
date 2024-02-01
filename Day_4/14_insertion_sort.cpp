#include <bits/stdc++.h>
using namespace std;

// T.C -O(N^2)
// S.C -O(1)
void insertionSort(int arr[], int n)
{
    for (int i = 0; i <= n - 1; i++)
    {
        int j = i;

        while (j > 0 && arr[j - 1] > arr[j])
        {
            swap(arr[j - 1], arr[j]);
            j--;
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[] = {12, 46, 24, 52, 20, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    insertionSort(arr, n);
    return 0;
}