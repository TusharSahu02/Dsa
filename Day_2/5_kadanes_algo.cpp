#include <bits/stdc++.h>
using namespace std;

// T.C - O(N^3)
// S.C.- O(1)
void bruteforce(int arr[], int n)
{
    // create a maxi variable to store the smallest number
    int maxi = INT_MIN;

    // and then find all possible subarrays
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            // and try find all the sum of subarrays
            int sum = 0;

            for (int k = i; k <= j; k++)
            {
                sum += arr[k];
            }

            // if the subarray sum is greater than the the maxi variable then we simply update the maxi
            maxi = max(maxi, sum);
        }
    }
    // and printint the maxi value.
    cout << "max value = " << maxi << endl;
}

// T.C - O(N^2)
// S.C - O(1)
void better(int arr[], int n)
{
    // same as the previous brute force we just need to remove the extra loop for the better TC
    int maxi = INT_MIN;

    // and then find all possible subarrays
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += arr[j];
            maxi = max(maxi, sum);
        }
    }
    // and printint the maxi value.
    cout << "max value = " << maxi << endl;
}
// T.C - O(N)
// S.C - O(1)
void optimal1(int arr[], int n)
{
    // using kadanes algo
    int maxi = INT_MIN;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];

        if (sum > maxi)
        {
            maxi = sum;
        }
        if (sum < 0)
        {
            sum = 0;
        }
    }

    cout << "max value = " << maxi << endl;
}
// It's just an follow up question which ask to print the subarrays

// we will store the stating and ending index of the subarrays sum
//  T.C - O(N)
//  S.C - O(1)
void optimal2(int arr[], int n)
{
    int maxi = INT_MIN;
    int sum = 0;

    int start = 0;
    int ansStart = -1, ansEnd = -1;

    for (int i = 0; i < n; i++)
    {
        if (sum == 0)
        {
            start = i;
        }
        sum += arr[i];

        if (sum > maxi)
        {
            maxi = sum;
            ansStart = start;
            ansEnd = i;
        }
        if (sum < 0)
        {
            sum = 0;
        }
    }
    // printing the subarray
    cout << "Subarray : [ ";
    for (int i = ansStart; i <= ansEnd; i++)
    {
        cout << arr[i] << " ";
    }

    cout << "]" << endl;

    cout << "max value = " << maxi << endl;
}

int main()
{
    int arr[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int n = sizeof(arr) / sizeof(arr[0]);

    // 1st approach
    bruteforce(arr, n);

    // 2nd approach
    better(arr, n);

    // 3rd approach
    optimal1(arr, n);

    // 4th approach
    optimal2(arr, n);

    return 0;
}