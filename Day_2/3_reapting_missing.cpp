#include <bits/stdc++.h>
using namespace std;

// 1st approach
// T.C. - O(N^2)
// S.C. - O(1)
void bruteforce(int arr[], int n)
{
    // take 2 variable for repeating and missing inti by -1
    int rep = -1, mis = -1;
    // now traverse in array
    for (int i = 1; i <= n; i++)
    {
        // taka counter variable to check the occurance of element
        int count = 0;
        for (int j = 0; j < n; j++)
        {
            // if the value of i and arr[j] gets equal then  increment the count
            if (arr[j] == i)
            {
                count++;
            }
        } // and check if the counter is equal to 2 means it is a repeating element
        if (count == 2)
            rep = i;
        else if (count == 0) // and if it equal to 0 means it is a missing element
            mis = i;
    }
    // simply print both the element
    cout << "Repeating: " << rep << ", Missing : " << mis << endl;
}
// to make it better we can use the concept of hash array or say freq array
// 2nd approach
void better(int arr[], int n)
{
    int freq[n + 1] = {0};

    for (int i = 0; i < n; i++)
    {
        freq[arr[i]]++;
    }

    int rep = -1, mis = -1;
    for (int i = 1; i <= n; i++)
    {
        if (freq[i] == 2)
        {
            rep = i;
        }
        else if (freq[i] == 0)
        {
            mis = i;
        }
    }

    cout << "Missing : " << mis << ", Repeating : " << rep << endl;
}

// 3rd approach
void optimal1(int arr[], int n)
{
    // using simple maths calculation

    // take long long to check not overflow
    // we need S - Sn = x - y
    // and S2 - S2N

    // sum of all natural number from (1 - n)
    long long SN = (n * (n + 1)) / 2;
    // sum of all square of natural number from (1 - n)
    long long S2N = (n * (n + 1) * (2 * n + 1)) / 6;
    // this is the init value to store the sum for the array
    long long S = 0, S2 = 0;

    // storing the sum values of array
    for (int i = 0; i < n; i++)
    {
        S += arr[i];
        S2 += (long long)arr[i] * (long long)arr[i];
    }
    // simple calculation to find x and y.
    
    long long val1 = S - SN; // x - y
    long long val2 = S2 - S2N;
    val2 = val2 / val1; // x + y
    long long x = (val1 + val2) / 2;
    long long y = x - val1;

    cout << "Repeating: " << (int)x << ", Missing: " << (int)y << endl;
}
int main()
{

    int arr[] = {4, 3, 6, 2, 1, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    // 1st approach
    bruteforce(arr, n);

    // 2nd approach
    better(arr, n);

    // 3rd approach
    optimal1(arr, n);

    return 0;
}