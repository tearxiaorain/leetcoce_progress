#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <string>
#include <algorithm>
using namespace std;

void gameOfLife(vector<vector<int>> &board)
{
    int n = board.size();
    int m = board[0].size();
    vector<vector<int>> flag(0);
    int y[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int x[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
    for (int i = 0; i < n; i++)
    {
        vector<int> temp(m, 0);
        flag.push_back(temp);
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int count = 0;
            for (int k = 0; k < 8; k++)
            {
                if (0 <= i + y[k] && i + y[k] < n && 0 <= j + x[k] && j + x[k] < m)
                    count += board[i + y[k]][j + x[k]];
            }
            if (board[i][j])
            {
                if (count >= 2 && count <= 3)
                    flag[i][j]++;
            }
            else
            {
                if (count == 3)
                {
                    flag[i][j]++;
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            board[i][j] = flag[i][j];
        }
    }
}

int main()
{
    vector<vector<int>> m;
    int arr[4][3] = {0, 1, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0};
    for (int i = 0; i < 4; i++)
    {
        vector<int> t(0);
        for (int j = 0; j < 3; j++)
        {
            t.push_back(arr[i][j]);
        }
        m.push_back(t);
    }

    gameOfLife(m);
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << m[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}
