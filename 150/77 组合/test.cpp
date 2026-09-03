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

void fun_a(vector<int> &flag, vector<vector<int>> &res, vector<int> &path, int n, int &cnt, int k)
{
    if (cnt == k)
    {
        res.push_back(path);
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (!flag[i])
        {
            // f_flag++;
            flag[i] = 1;
            cnt++;
            path.push_back(i);
            fun_a(flag, res, path, n, cnt, k);
            path.pop_back();
            cnt--;
            flag[i] = 0;
        }
    }
}

void fun_c(vector<vector<int>> &res, vector<int> &path, int n, int &cnt, int k, int c)
{
    if (cnt == k)
    {
        res.push_back(path);
        return;
    }
    if (n - c < k - cnt)
        return;

    for (int i = c + 1; i < n; i++)
    {
        path.push_back(i+1);
        cnt++;
        fun_c(res, path, n, cnt, k, i);
        cnt--;
        path.pop_back();
    }
}

vector<vector<int>> combine(int n, int k)
{
    vector<vector<int>> res;
    vector<int> flag(n, 0);
    vector<int> path;
    int a = 1;
    // fun_a(flag, res, path, n,a,k);
    for(int i=0;i<n;i++)
    {
        path.push_back(i+1);
        fun_c(res, path, n, a, k, i);
        path.pop_back();
    }
    
    return res;
}

int main()
{
    int arr[3] = {1, 2, 3};
    vector<int> a;
    for (int i = 0; i < 3; i++)
    {
        a.push_back(arr[i]);
    }
    vector<vector<int>> r = combine(4, 2);
    for (int i = 0; i < r.size(); i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout << r[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
