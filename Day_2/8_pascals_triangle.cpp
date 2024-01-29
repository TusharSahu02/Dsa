#include <bits/stdc++.h>
using namespace std;

// 1st question
// T.C- O(r) -> column number
// S.C- O(1)

// using simple math calculation
// nCr = n!/(r! * (n-r)!) -> this will give the ans
int nCr(int n, int r)
{
    // this function will help to find the nCr value.
    long long res = 1;

    for (int i = 0; i < r; i++)
    {
        res = res * (n - i);
        res = res / (i + 1);
    }

    return res;
}

void question1(int r, int c)
{
    int res = nCr(r - 1, c - 1);
    cout << res << endl;
}

// 2nd question
// T.C - O(n*r)
// S.C - O(1)
void question2(int n)
{
    // printing the entire row
    for (int i = 1; i <= n; i++)
    {
        cout << nCr(n - 1, i - 1) << " ";
    }
    cout << endl;
}

// this is the optimal solution of the above question only.
// T.C - O(N)
// S.C - O(1)
void question2Optimal(int n)
{
    long long ans = 1;
    // print the 1st element i.e. 1
    cout << ans << " ";

    for (int i = 1; i < n; i++)
    {
        ans = ans * (n - i);
        ans = ans / i;
        cout << ans << " ";
    }
    cout << endl;
}

// 3rd question
// T.C - O(N^3)
// S.C - O(1)
vector<vector<int>> question3(int n)
{
    vector<vector<int>> ans;

    for (int row = 1; row <= n; row++)
    {
        vector<int> tempList;
        for (int col = 1; col <= row; col++)
        {
            tempList.push_back(nCr(row - 1, col - 1));
        }
        ans.push_back(tempList);
    }
    return ans;
}
// 3rd question optimal solution
vector<int> generateRow(int row)
{

    long long ans = 1;
    // temp list to store all the row values
    vector<int> tempList;
    // insert the 1st element
    tempList.push_back(1);

    // calculate the rest of the element
    for (int col = 1; col < row; col++)
    {
        ans = ans * (row - col);
        ans = ans / col;
        tempList.push_back(ans);
    }
    return tempList;
}

vector<vector<int>> question3Optimal(int n)
{
    vector<vector<int>> ans;

    for (int row = 1; row <= n; row++)
    {
        ans.push_back(generateRow(row));
    }
    return ans;
}

int main()
{

    // This are the possible question interviwer might ask related to this problem

    // 1) Give row and col, tell me the element at that place  i.e. row =5, col =3 that will be 6 (ans)
    // 2)Print any Nth row of pascal trianlge i.e  if n =5, print -> 1,4,6,4,1
    // 3) Given N, print the entire triangle

    int r = 5, c = 3;

    // (1st Question)
    question1(r, c);
    cout << "\n";

    int n = 5;
    //  (2nd question)
    question2(n);
    cout << "\n";
    question2Optimal(n);
    cout << "\n";

    //  (3rd question)
    vector<vector<int>> ans = question3(n);
    for (auto it : ans)
    {
        for (auto ele : it)
        {
            cout << ele << " ";
        }
        cout << "\n";
    }
    vector<vector<int>> ans2 = question3Optimal(n);
    for (auto it : ans2)
    {
        for (auto ele : it)
        {
            cout << ele << " ";
        }
        cout << "\n";
    }

    return 0;
}