#include <bits/stdc++.h>
using namespace std;

// T.C - O(n^2)
// S.C - O(1)

// it is opposite of selection sort
// it pushes the maximum to the last

void bubbleSort(int arr[], int n)
{
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 0; j <= i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j + 1], arr[j]);
            }
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

    bubbleSort(arr, n);
    return 0;
}