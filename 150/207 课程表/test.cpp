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

// 超内存

// 连接图 访问标记 路径标记查环 当前节点 环标记
void dfs(vector<vector<int>> graph, vector<int> &flag, vector<int> &pathf, int c, int &f)
{
    if (f)
        return;
    if (pathf[c])
    {
        f = 1;
        return;
    }
    else
    {
        pathf[c] = 1;
    }

    int n = flag.size();
    for (int i = 0; i < n; i++)
    {
        if (graph[c][i] && !flag[i])
        {
            dfs(graph, flag, pathf, i, f);
        }
    }
    flag[c] = 1;
}

bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
{
    int np = prerequisites.size();
    vector<vector<int>> graph;
    vector<int> flag(numCourses, 0);
    vector<int> pathf(numCourses, 0);

    for (int i = 0; i < numCourses; i++)
    {
        vector<int> g(numCourses, 0);
        graph.push_back(g);
    }
    for (int i = 0; i < np; i++)
    {
        vector<int> t = prerequisites[i];
        graph[t[0]][t[1]] = 1;
    }
    int f = 0;
    for (int i = 0; i < numCourses; i++)
    {
        if(!flag[i])
            dfs(graph, flag, pathf, i, f);
        if (f)
            return false;
        // for(int j=0;j<numCourses;j++)
        // {
        //     pathf[i]=0;
        // }
    }
    if (!f)
        return true;
    return false;
}

int main()
{
    int numCourses = 2;
    vector<vector<int>> prerequisites;
    int arr[2][2] = {0, 1, 1, 0};
    for (int i = 0; i < 1; i++)
    {
        vector<int> a;
        for (int j = 0; j < 2; j++)
        {
            a.push_back(arr[i][j]);
        }
        prerequisites.push_back(a);
    }
    cout << canFinish(numCourses, prerequisites);

    return 0;
}
