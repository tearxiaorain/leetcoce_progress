#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <string>
#include <algorithm>
using namespace std;

int minPathSum(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();
    int *arr = new int[n];
    int *brr = new int[n];
    arr[0] = brr[0] = grid[0][0];
    for (int i = 1; i < n; i++)
    {
        arr[i] = brr[i] = arr[i - 1] + grid[0][i];
    }
    for (int i = 1; i < m; i++)
    {
        brr[0] = arr[0] + grid[i][0];
        for (int j = 1; j < n; j++)
        {

            int l1 = INT_MAX;
            int l2 = INT_MAX;
            l1 = brr[j - 1] + grid[i][j];
            l2 = arr[j] + grid[i][j];
            brr[j] = l1;
            if (l2 < l1)
                brr[j] = l2;
        }
        swap(arr, brr);
    }
    // sort(arr,arr+n);
    return arr[n - 1];
}

int main()
{
    int arr[3][3] = {1, 2, 3,
                     4, 5, 6,
                     4, 2, 1};
    vector<vector<int>> n(0);
    for (int i = 0; i < 2; i++)
    {
        vector<int> t(0);
        for (int j = 0; j < 3; j++)
        {
            t.push_back(arr[i][j]);
        }
        n.push_back(t);
    }
    cout << minPathSum(n);
    return 0;
}
