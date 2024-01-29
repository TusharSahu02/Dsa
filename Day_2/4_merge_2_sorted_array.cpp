#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(n+m) + O(n+m)
// Space Complexity: O(n+m) as we use an extra array of size n+m.
void bruteforce(int arr1[], int arr2[], int n, int m)
{
    int arr3[n + m];
    int left = 0, right = 0, index = 0;

    // checking that the left and right pointer should not exceed the size of array
    while (left < n && right < m)
    {
        // and if the arr1 element is lesser than the arr2 element
        if (arr1[left] <= arr2[right])
        {
            // push the smaller element in arr3 and increment the index and pointer
            arr3[index] = arr1[left];
            left++;
            index++;
        }
        else
        {
            arr3[index] = arr2[right];
            right++;
            index++;
        }
    }

    // if the right pointer reaches the end insert all the remaining elem to the array
    while (left < n)
    {
        arr3[index++] = arr1[left++];
    }

    // if the left pointer reaches the end
    while (right < n)
    {
        arr3[index++] = arr2[right++];
    }

    for (int i = 0; i < n + m; i++)
    {
        if (i < n)
        {
            arr1[i] = arr3[i];
        }
        else
        {
            arr2[i - n] = arr3[i];
        }
    }
}

// T.C - O(min(n, m)) + O(n*logn) + O(m*logm)
// Reason: O(min(n, m)) is for swapping the array elements. And O(n*logn) and O(m*logm) are for sorting the two arrays.
// S.C - O(1)
void optimal1(int arr1[], int arr2[], int n, int m)
{
    // using 2 pointe approach
    //  the left pointer is for arr1 @last index
    // the right pointer is for arr2 @first index
    int left = n - 1, right = 0;

    // jab tak left 0 se bada aur right arr2 ke size se chota hai tab tk loop chalao
    while (left >= 0 && right < m)
    {
        // aur agar koi bhi element arr1 me chota nikla to usko arr2 se swap krdo
        if (arr1[left] > arr2[right])
        {
            swap(arr1[left], arr2[right]);
            left--;
            right++;
        }
        else
        {
            // agar wo conditon trigger ni hua to kuch mat kro
            break;
        }
    }

    // now simply sort the arrays
    // coz we have collected all the desired elements in their desired arr
    sort(arr1, arr1 + n);
    sort(arr2, arr2 + m);
}

int main()
{

    int arr1[] = {1, 4, 8, 10};
    int arr2[] = {2, 3, 9};

    int n = sizeof(arr1) / sizeof(arr1[0]);
    int m = sizeof(arr2) / sizeof(arr2[0]);

    // 1st approach
    bruteforce(arr1, arr2, n, m);

    // 2nd approach
    optimal1(arr1, arr2, n, m);

    // printing array1 and array2
    for (int i = 0; i < n; i++)
    {
        cout << arr1[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < m; i++)
    {
        cout << arr2[i] << " ";
    }
    cout << endl;

    return 0;
}