#include <bits/stdc++.h>
using namespace std;

// 1st approach (Brute force)
// T.C - O(NlogN + N)
// S.C - O(1)
void bruteforce(int arr[], int n)
{
    // Sort the array
    sort(arr, arr + n);

    // And traverse in sorted array and apply a condition
    // if the arr[i] is equal to the arr[i+1] means we found the duplicate element
    // simply print that element or return
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == arr[i + 1])
        {
            cout << arr[i] << " ";
        }
    }
    cout << endl;
}
// 2nd approach (Better)
// T.C- O(N)
// S.C- O(N)
void better(int arr[], int n)
{
    // using frequancy array and init by 0.
    int freq[n + 1] = {0};
    // then traverse in array and check
    // agar freq array me arr ke element wala positon 0 hai to increment krdo else print krdo us number ko
    for (int i = 0; i < n; i++)
    {
        if (freq[arr[i]] == 0)
        {
            freq[arr[i]]++;
        }
        else
        {
            cout << arr[i] << endl;
        }
    }
}
// 3rd approach
// T.C - O()
// S.C - O()
void optimise(int arr[], int n)
{
    // using cyclic linkedlist

    // create a slow and a fast pointer,
    // slow pointer moves 1 step and faster pointer moves 2 steps at a time
    int slow = arr[0];
    int fast = arr[0];

    for (int i = 0; i < n; i++)
    {
        slow = arr[slow];
        fast = arr[arr[fast]];

        if (arr[slow] == arr[fast])
        {
            slow = arr[slow];
            fast = arr[fast];
            cout << arr[slow] << endl;
            return;
        }
    }
}

int main()
{

    int arr[] = {1, 3, 4, 2, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    // 1st approcah
    bruteforce(arr, n);

    // 2nd approcah
    better(arr, n);

    // 3rd approcah
    optimise(arr, n);

    return 0;
}