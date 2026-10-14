#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <math.h>

using namespace std;

bool find(vector<vector<char>> &board, vector<vector<int>> &flag, int x, int y, int m, int n, int op)
{
    if (x >= m || x < 0 || y >= n || y < 0)
        return true;
    if (board[x][y] == 'O')
    {
        if (flag[x][y] == 1 && op == 0)
            return false;
        if (flag[x][y] == 0 && op == 0)
        {
            flag[x][y] = 1;
            bool b1 = find(board, flag, x + 1, y, m, n, op);
            bool b2 = find(board, flag, x - 1, y, m, n, op);
            bool b3 = find(board, flag, x, y + 1, m, n, op);
            bool b4 = find(board, flag, x, y - 1, m, n, op);
            return b1 || b2 || b3 || b4;
        }
        else if (flag[x][y] == 1 && op == 1)
        {
            flag[x][y] = 2;
            board[x][y] = 'X';
            bool b1 = find(board, flag, x + 1, y, m, n, op);
            bool b2 = find(board, flag, x - 1, y, m, n, op);
            bool b3 = find(board, flag, x, y + 1, m, n, op);
            bool b4 = find(board, flag, x, y - 1, m, n, op);
            return b1 || b2 || b3 || b4;
        }
        else
            return false;
    }
    else
        return false;
}

void solve(vector<vector<char>> &board)
{
    int m = board.size();
    int n = board[0].size();
    vector<vector<int>> flag;
    for (int i = 0; i < m; i++)
    {
        vector<int> t(n, 0);
        flag.push_back(t);
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (board[i][j] == 'O')
            {
                if (!flag[i][j])
                {
                    if (!find(board, flag, i, j, m, n, 0))
                        find(board, flag, i, j, m, n, 1);
                }
            }
        }
    }
    return;
}

int main()
{
    vector<vector<char>> board;
    char arr[4][4] = {'O', 'O', 'X', 'X',
                      'O', 'O', 'O', 'X',
                      'X', 'X', 'O', 'X',
                      'X', 'O', 'X', 'X'};
    for (int i = 0; i < 2; i++)
    {
        vector<char> t;
        for (int j = 0; j < 2; j++)
        {
            t.push_back(arr[i][j]);
        }
        board.push_back(t);
    }

    solve(board);
    cout << 1;
    return 0;
}