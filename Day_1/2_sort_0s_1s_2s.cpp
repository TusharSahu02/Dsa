#include <bits/stdc++.h>
using namespace std;

// 1st approach
// T.C. - O(NlogN)
// S.C. - O(1)
void bruteforce(int arr[], int n)
{
    // simply use any sorting algo
    sort(arr, arr + n);

    for (int i = 0; i < n; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// 2nd approach
// T.C. - O(N+N)
// S.C - O(1)
void better(int arr[], int n)
{
    // using counting sort
    // traverse in array and count the 0s, 1s and 2s
    // in this case 0-2times, 1-2times, 2-2times
    // now run a loop pf 0 to 2 and insert all the items one by one
    int count_0 = 0, count_1 = 0, count_2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            count_0++;
        }
        else if (arr[i] == 1)
        {
            count_1++;
        }
        else
        {
            count_2++;
        }
    }

    // traversing in array and filling all the elements
    for (int i = 0; i < count_0; i++)
    {
        arr[i] = 0;
    }
    for (int i = count_0; i < count_0 + count_1; i++)
    {
        arr[i] = 1;
    }
    for (int i = count_0 + count_1; i < n; i++)
    {
        arr[i] = 2;
    }

    // finally printing the sorted array
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
// 3rd approach
// T.C - O(N)
// S.C - O(1)
void optimise(int arr[], int n)
{
    // dutch national flag
    // keep track of low,mid and high
    int low = 0, mid = 0, high = n - 1;

    // traverse till mid do not exceed the high
    while (mid <= high)
    {
        // if the mid element is 0 then swap the value of arr[low] & arr[mid] and simply incremt both values
        if (arr[mid] == 0)
        {
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        } // if the mid element is 1 then no need to swap it just increment the mid
        else if (arr[mid] == 1)
        {
            mid++;
        } // and if the value if 2 then swap the high and mid value with each other and decrement high
        else
        {
            swap(arr[high], arr[mid]);
            high--;
        }
    }
    // print the sorted array
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[] = {2, 0, 2, 1, 1, 0};
    int n = sizeof(arr) / sizeof(arr[0]);

    // 1st approach
    bruteforce(arr, n);

    // 2nd approach
    better(arr, n);

    // 3rd approach
    optimise(arr, n);
    return 0;
}