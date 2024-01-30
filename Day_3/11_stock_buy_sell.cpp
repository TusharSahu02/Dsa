#include <bits/stdc++.h>
using namespace std;

// 1st approach
// T.C. - O(N^2)
// S.C. - O(1)
int bruteforce(vector<int> arr)
{
    // size of array
    int n = arr.size();
    // variable to store maximum profit
    int maxVal = 0;

    // iterating in array
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            // and check if the current element's right part contain any values that is greater than the current value
            if (arr[j] > arr[i])
            {
                // this will store the maximum profit
                maxVal = max(arr[j] - arr[i], maxVal);
            }
        }
    }
    // return the maximum profit
    return maxVal;
}
// 2nd approach
// T.C. - O(N)
// S.C. - O(1)
int optimal(vector<int> arr)
{
    // size of array
    int n = arr.size();
    // storing the maxprofit
    int maxProfit = 0;
    // to store the smallest in the array while calculating profit.
    int minPrice = INT_MAX;

    for (int i = 0; i < n; i++)
    {
        // iterating and updating the smallest values possible
        minPrice = min(minPrice, arr[i]);
        // and updating the max profit/ differene we get.
        maxProfit = max(maxProfit, arr[i] - minPrice);
    }
    // return maxProfit
    return maxProfit;
}
int main()
{

    vector<int> arr = {7, 1, 5, 3, 6, 4};

    // 1st approach
    cout << "Profit: " << bruteforce(arr) << endl;

    // 2nd approach
    cout << "Profit: " << optimal(arr) << endl;

    return 0;
}