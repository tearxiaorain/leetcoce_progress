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

int minDistance(string word1, string word2)
{
    int m = word1.length();
    int n = word2.length();

    vector<vector<int>> dp;
    for (int i = 0; i < m + 1; i++)
    {
        vector<int> t(n + 1, false);
        dp.push_back(t);
    }
    dp[0][0] = 0;
    for (int i = 1; i < m + 1; i++)
    {
        dp[i][0] = i;
    }
    for (int i = 1; i < n + 1; i++)
    {
        dp[0][i] = i;
    }
    for (int i = 1; i < m + 1; i++)
    {
        for (int j = 1; j < n + 1; j++)
        {

            int d1 = dp[i - 1][j - 1] + (word1[i - 1] != word2[j - 1]); // 替换
            int d2 = dp[i][j - 1] + 1;                                  // 删除
            int d3 = dp[i - 1][j] + 1;                                  // 插入
            int d = d1;
            if (d2 < d)
                d = d2;
            if (d3 < d)
                d = d3;
            dp[i][j] = d;
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
    cout << minDistance("horse", "ros");
    cout << 1;
    return 0;
}
