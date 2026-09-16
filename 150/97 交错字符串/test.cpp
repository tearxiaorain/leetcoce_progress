#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

bool isInterleave(string s1, string s2, string s3)
{
    int m = s1.length();
    int n = s2.length();
    int k = s3.length();
    if (m + n < k)
        return false;
    vector<vector<bool>> dp;
    for (int i = 0; i < m + 1; i++)
    {
        vector<bool> t(n + 1, false);
        dp.push_back(t);
    }
    dp[0][0] = true;
    for (int i = 1; i < m + 1; i++)
    {
        dp[i][0] = dp[i - 1][0] && s1[i - 1] == s3[i - 1];
    }
    for (int i = 1; i < n + 1; i++)
    {
        dp[0][i] = dp[0][i - 1] && s2[i - 1] == s3[i - 1];
    }
    for (int i = 1; i < m + 1; i++)
    {
        for (int j = 1; j < n + 1; j++)
        {
            bool b1, b2;
            b1 = b2 = false;
            b1 = dp[i - 1][j] && (s1[i - 1] == s3[i + j - 1]);
            b2 = dp[i][j - 1] && (s2[j - 1] == s3[i + j - 1]);
            dp[i][j] = b1 || b2;
        }
    }
    for (int i = 0; i < m + 1; i++)
    {
        for (int j = 0; j < n + 1; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    return dp[m][n];
}

int main()
{
    cout << isInterleave("", "b", "b");
    cout << 1;
    return 0;
}
