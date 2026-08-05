#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <string>
#include <algorithm>
using namespace std;

int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
{
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    int *arr = new int[n];
    int *brr = new int[n];
    arr[0] = brr[0] = 1 - obstacleGrid[0][0];
    for (int i = 1; i < n; i++)
    {
        if (obstacleGrid[0][i])
        {
            arr[i] = brr[i] = 0;
        }
        else
        {
            arr[i] = brr[i] = arr[i - 1];
        }
    }
    for (int i = 1; i < m; i++)
    {
        brr[0] = arr[0];
        if (obstacleGrid[i][0])
            brr[0] = 0;

        for (int j = 1; j < n; j++)
        {
            if (obstacleGrid[i][j])
            {
                brr[j] = 0;
                continue;
            }

            int l1 = arr[j];
            int l2 = brr[j - 1];
            brr[j] = l1 + l2;
        }
        swap(arr, brr);
    }
    // sort(arr,arr+n);
    return arr[n - 1];
}

int main()
{
    int arr[3][3] = {0, 1, 0,
                     0, 0, 0,
                     0, 0, 0};
    vector<vector<int>> n(0);
    for (int i = 0; i < 3; i++)
    {
        vector<int> t(0);
        for (int j = 0; j < 3; j++)
        {
            t.push_back(arr[i][j]);
        }
        n.push_back(t);
    }
    cout << uniquePathsWithObstacles(n);
    return 0;
}
