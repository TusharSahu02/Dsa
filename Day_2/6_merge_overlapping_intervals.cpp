#include <bits/stdc++.h>
using namespace std;
// 1st approach
// T.C - O(NlogN) + O(2*N)
// S.C - O(N)
vector<vector<int>> bruteforce(vector<vector<int>> &arr)
{
    // finding the size of array
    int n = arr.size();
    // sorting the array
    sort(arr.begin(), arr.end());
    // after sort we got {{1,3},{2,4},{2,6},{8,9},{8,10},{9,11},{15,18},{16,17}}

    // this is to store the ans
    vector<vector<int>> ans;

    for (int i = 0; i < n; i++)
    {
        // select an interval
        // i=0 means = [1,3]
        int start = arr[i][0]; // here start = 1
        int end = arr[i][1];   // here end = 3

        // skip all merged interval if that already exist
        if (!ans.empty() && end <= ans.back()[1])
        {
            // we do not do anything we just skip
            continue;
        }

        // iterating for the rest of the elements
        for (int j = i + 1; j < n; j++)
        {
            // this is for the 2nd element in array i.e [2,4]
            if (arr[j][0] <= end) // if 2(1st index of 2nd element of array) <= 3(end)
            {
                // if true
                // update the end to the max of (3,4)
                end = max(end, arr[j][1]); // i.e 4
            }
            else
            {
                break;
            }
        }
        // inserting all the merged interval into ans vector
        ans.push_back({start, end});
    }

    // and returing
    return ans;
}

// 2nd approach
// T.C - O(NlogN) + O(N)
// S.C - O(N)
vector<vector<int>> optimal(vector<vector<int>> &arr)
{
    // finding the size of array
    int n = arr.size();
    // sorting the array
    sort(arr.begin(), arr.end());
    // after sort we got {{1,3},{2,4},{2,6},{8,9},{8,10},{9,11},{15,18},{16,17}}

    // this is to store the ans
    vector<vector<int>> ans;

    for (int i = 0; i < n; i++)
    {
        if (ans.empty() || arr[i][0] > ans.back()[1])
        {
            ans.push_back(arr[i]);
        }
        else
        {
            // ans.back().second = max(ans.back().second, arr[i][1]);
            ans.back()[1] = max(ans.back()[1], arr[i][1]);
        }
    }

    // and returing
    return ans;
}

int main()
{
    vector<vector<int>> arr = {{1, 3}, {8, 10}, {2, 6}, {15, 18}};

    // 1st approach
    vector<vector<int>> ans = bruteforce(arr);
    // 2nd approach
    vector<vector<int>> ans2 = optimal(arr);

    for (auto i : ans)
    {
        cout << "[" << i[0] << ", " << i[1] << "]";
    }
    cout << endl;

    for (auto i : ans2)
    {
        cout << "[" << i[0] << ", " << i[1] << "]";
    }
    cout << endl;

    return 0;
}