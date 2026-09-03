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

void color(vector<vector<char>> &grid, int x, int y, vector<vector<int>> &flag, int c) // x向下正方向 y向右正方向
{
    if (grid[x][y] == '1' && flag[x][y] == 0)
    {
        flag[x][y] = c;
    }
    if (x - 1 >= 0)
        if (grid[x - 1][y] == '1' && flag[x - 1][y] == 0)
            color(grid, x - 1, y, flag, c);
    if (x + 1 < grid.size())
        if (grid[x + 1][y] == '1' && flag[x + 1][y] == 0)
            color(grid, x + 1, y, flag, c);
    if (y - 1 >= 0)
        if (grid[x][y - 1] == '1' && flag[x][y - 1] == 0)
            color(grid, x, y - 1, flag, c);
    if (y + 1 < grid[0].size())
        if (grid[x][y + 1] == '1' && flag[x][y + 1] == 0)
            color(grid, x, y + 1, flag, c);
}

int numIslands(vector<vector<char>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> flag;
    for (int i = 0; i < m; i++)
    {
        vector<int> f(n, 0);
        flag.push_back(f);
    }
    int sum = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == '1' && flag[i][j] == 0) // 没访问过
            {
                sum++;
                color(grid, i, j, flag, sum);
            }
        }
    }
    return sum;
}

int main()
{
    vector<vector<char>> grid;
    char arr[4][5] = {'1', '1', '0', '0', '0',
                      '1', '1', '0', '0', '0',
                      '0', '0', '1', '0', '0',
                      '0', '0', '0', '1', '1'};
    for (int i = 0; i < 4; i++)
    {
        vector<char> g;
        for (int j = 0; j < 5; j++)
        {
            g.push_back(arr[i][j]);
        }
        grid.push_back(g);
    }
    cout << numIslands(grid);

    return 0;
}
