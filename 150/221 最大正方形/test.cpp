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

int maximalSquare(vector<vector<char>>& matrix) {
    int m=matrix.size();
    int n=matrix[0].size();
    vector<vector<int>>dp;
    int max=0;
    for(int i=0;i<m;i++)
    {
        vector<int>t(n,0);
        dp.push_back(t);
    }
    for(int i=0;i<m;i++)
    {
        if(matrix[i][0]=='1')
            dp[i][0]=1;
        if(max<dp[i][0])
            max=dp[i][0];
    }
    for(int i=0;i<n;i++)
    {
        if(matrix[0][i]=='1')
            dp[0][i]=1;
        if(max<dp[0][i])
            max=dp[0][i];
    }

    for(int i=1;i<m;i++)
    {
        for(int j=1;j<n;j++)
        {
            if(matrix[i][j]=='1')
            {
                if(dp[i-1][j-1]==dp[i-1][j]&&dp[i-1][j-1]==dp[i][j-1])
                    dp[i][j]=dp[i-1][j-1]+1;
                else
                {
                    dp[i][j]=dp[i-1][j-1];
                    if(dp[i-1][j]<dp[i-1][j-1])
                        dp[i][j]=dp[i-1][j];
                    if(dp[i][j-1]<dp[i-1][j])
                        dp[i][j]=dp[i][j-1];
                    dp[i][j]++;
                }
            }
            else    dp[i][j]=0;
            if(max<dp[i][j])
                max=dp[i][j];
        }
    }
    return max*max;
}

int main()
{
    char arr[5][5] = {  '1','1','1','1','0',
                        '1','1','1','1','0',
                        '1','1','1','1','1',
                        '1','1','1','1','1',
                        '0','0','1','1','1',};
    
    vector<vector<char>> m;
    for(int i=0;i<5;i++)
    {
        vector<char> c1;
        for(int j=0;j<5;j++)
        {
            c1.push_back(arr[i][j]);
        }
        m.push_back(c1);
    }

    cout<<maximalSquare(m);

    // cout << 1;
    return 0;
}
