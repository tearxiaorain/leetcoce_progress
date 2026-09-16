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

bool fun1(vector<vector<char>> &board, vector<vector<int>> &flag,
          int x, int y, int k, string &path, string w) // 向下x正方向  向右y正方向
{
    if (k == w.length() - 1)
    {
        if (path == w)
            return true;
    }
    int m = board.size();
    int n = board[0].size();
    if (x > 0)
    {
        if (!flag[x - 1][y] && board[x - 1][y] == w[k])
        {
            string t = path;
            x--;
            flag[x - 1][y] = 1;
            k++;
            path += board[x - 1][y];
            bool b = fun1(board, flag, x, y, k, path, w);
            if (b)
                return b;
            x++;
            flag[x - 1][y] = 0;
            k--;
            path = t;
        }
    }
    if (x < m - 1)
    {
        if (!flag[x + 1][y] && board[x + 1][y] == w[k])
        {
            string t = path;
            x++;
            flag[x + 1][y] = 1;
            k++;
            path += board[x + 1][y];
            bool b = fun1(board, flag, x, y, k, path, w);
            if (b)
                return b;
            x--;
            flag[x + 1][y] = 0;
            k--;
            path = t;
        }
    }
    if (y > 0)
    {
        if (!flag[x][y - 1] && board[x][y - 1] == w[k])
        {
            string t = path;
            y--;
            flag[x][y - 1] = 1;
            k++;
            path += board[x][y - 1];
            bool b = fun1(board, flag, x, y, k, path, w);
            if (b)
                return b;
            y++;
            flag[x][y - 1] = 0;
            k--;
            path = t;
        }
    }
    if (y < n - 1)
    {
        if (!flag[x][y + 1] && board[x][y + 1] == w[k])
        {
            string t = path;
            y++;
            flag[x][y + 1] = 1;
            k++;
            path += board[x][y + 1];
            bool b = fun1(board, flag, x, y, k, path, w);
            if (b)
                return b;
            y--;
            flag[x][y + 1] = 0;
            k--;
            path = t;
        }
    }
    return false;
}

bool fun(vector<vector<char>> &board, vector<vector<int>> &flag,
         int x, int y, int k, string w) // 向下x正方向  向右y正方向
{
    int m = board.size();
    int n = board[0].size();
    if (flag[x][y])
        return false;
    if (board[x][y] != w[k])
        return false;
    flag[x][y] = 1;
    k++;
    if (k == w.length())
    {
        flag[x][y] = 0;
        return true;
    }

    int x1 = x - 1;
    int x2 = x + 1;
    int y1 = y - 1;
    int y2 = y + 1;

    int b1, b2, b3, b4;
    b1 = b2 = b3 = b4 = false;
    if (x > 0)
    {
        b1 = fun(board, flag, x1, y, k, w);
        //flag[x1][y]=0;
    }
    if (x < m - 1)
    {
        b2 = fun(board, flag, x2, y, k, w);
        //flag[x2][y]=0;
    }
    if (y > 0)
    {
        b3 = fun(board, flag, x, y1, k, w);
        //flag[x][y1]=0;
    }
    if (y < n - 1)
    {
        b4 = fun(board, flag, x, y2, k, w);
        //flag[x][y2]=0;
    }
    flag[x][y]=0;
    return (b1 || b2 || b3 || b4);
}

bool exist(vector<vector<char>> &board, string word)
{
    bool res = false;
    vector<vector<int>> flag;
    int m = board.size();
    int n = board[0].size();
    for (int i = 0; i < m; i++)
    {
        vector<int> t(n, 0);
        flag.push_back(t);
    }
    vector<vector<int>> temp=flag;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int x = i;
            int y = j;
            int k = 0;
            int b = fun(board, flag, x, y, k, word);
            if (b)
                return b;
            flag = temp;
        }
    }
    return false;
}

int main()
{
    char board[3][4]={  'A','B','C','E',
                        'S','F','E','S',
                        'A','D','E','E'};
    vector<vector<char>> b;
    for(int i=0;i<3;i++)
    {
        vector<char> t;
        for(int j=0;j<4;j++)
        {
            t.push_back(board[i][j]);
        }
        b.push_back(t);
    }

    cout << exist(b,"ABCESEEEFS");

    cout << 1;
    return 0;
}
