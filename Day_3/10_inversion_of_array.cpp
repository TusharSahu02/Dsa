#include <bits/stdc++.h>
using namespace std;

// 1st approach
// T.C.- O(N^2)
// S.C.- O(1)
int bruteforce(vector<int> &arr, int n)
{
    // take a counter variable
    int count = 0;

    // and iterate in the loop
    for (int i = 0; i < n - 1; i++)
    {
        // and check for the remaining right part of the element
        for (int j = i + 1; j < n; j++)
        {
            // if any of the element value is greater than previous
            if (arr[i] > arr[j])
                // simply increment the count
                count++;
        }
    }

    // and return the total count
    return count;
}

//  2nd approach
//  T.C.- O(NlogN )
//  S.C.- O(N)

// using merge sort
int merge(vector<int> &arr, int low, int mid, int high)
{
    vector<int> temp;    // temporary array
    int left = low;      // starting index of left half of arr
    int right = mid + 1; // starting index of right half of arr

    // cnt variable to count the pairs:
    int cnt = 0;

    // storing elements in the temporary array in a sorted manner//

    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else
        {
            temp.push_back(arr[right]);
            cnt += (mid - left + 1);
            right++;
        }
    }

    // if elements on the left half are still left //

    while (left <= mid)
    {
        temp.push_back(arr[left]);
        left++;
    }

    //  if elements on the right half are still left //
    while (right <= high)
    {
        temp.push_back(arr[right]);
        right++;
    }

    // transfering all elements from temporary to arr //
    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[i - low];
    }

    return cnt;
}

int mergeSort(vector<int> &arr, int low, int high)
{
    int cnt = 0;
    if (low >= high)
        return cnt;
    int mid = (low + high) / 2;
    cnt += mergeSort(arr, low, mid);      // left half
    cnt += mergeSort(arr, mid + 1, high); // right half
    cnt += merge(arr, low, mid, high);    // merging sorted halves
    return cnt;
}

int optimal(vector<int> &a, int n)
{
    // Count the number of pairs:
    return mergeSort(a, 0, n - 1);
}

int main()
{
    vector<int> a = {5, 4, 3, 2, 1};
    int n = 5;

    // 1st approach
    cout << bruteforce(a, n) << endl;

    // 2nd approach
    cout << optimal(a, n) << endl;

    return 0;
}