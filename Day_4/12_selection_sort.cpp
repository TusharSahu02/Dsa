#include <bits/stdc++.h>
using namespace std;

// T.C- O(N^2)
// S.C- O(1)

// iterate -> find the minimum value -> place it at starting postion -> increment

void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minElem = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minElem])
            {
                minElem = j;
            }
        }
        // swaping
        int temp = arr[minElem];
        arr[minElem] = arr[i];
        arr[i] = temp;
        // else use this
        // swap(arr[minElem],arr[i])
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

    selectionSort(arr, n);

    return 0;
}