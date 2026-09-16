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

string longestPalindrome(string s)
{
    int len = s.length();
    vector<vector<int>> dp;
    int max = 1;
    int l, r;
    l = r = 0;
    for (int i = 0; i < len; i++)
    {
        vector<int> t(len, 0);
        dp.push_back(t);
    }
    for (int i = 0; i < len; i++)
        dp[i][i] = 1;
    for (int i = 0; i < len - 1; i++)
    {
        if (s[i] == s[i + 1])
        {
            dp[i][i + 1] = 1;
            if (max < 2)
            {
                max = 2;
                l = i;
                r = i + 1;
            }
        }
    }
    for (int i = 2; i < len; i++)
    {
        for (int j = 0; j + i < len; j++)
        {
            dp[j][j + i] = dp[j + 1][j + i - 1] && (s[j] == s[j + i]);
            if (dp[j][j + i])
            {
                if (max < i + 1)
                {
                    max = i + 1;
                    l = j;
                    r = j + i;
                }
            }
        }
    }
    return s.substr(l, max);
}

int main()
{
    cout << longestPalindrome("abbcccba");
    cout << 1;
    return 0;
}
