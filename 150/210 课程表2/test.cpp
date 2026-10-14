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

vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> g;
    vector<int> incount(numCourses,0);
    vector<int> flag(numCourses,0);
    vector<int> res;
    for(int i=0;i<numCourses;i++)
    {
        vector<int> t(numCourses,0);
        g.push_back(t);
    }
    for(int i=0;i<prerequisites.size();i++)
    {
        g[prerequisites[i][1]][prerequisites[i][0]]=1;
        incount[prerequisites[i][0]]++;
    }
    for(int i=0;i<numCourses;i++)
    {
        for(int j=0;j<numCourses;j++)
        {
            if(!incount[j]&&!flag[j])
            {
                res.push_back(j);
                flag[j]=1;
                for(int k=0;k<numCourses;k++)
                {
                    if(g[j][k])
                        incount[k]--;
                }
                break;
            }
        }
    }
    if(res.size()!=numCourses)
        res.clear();
    return res;
}

int main()
{
    
    cout << endl << 1;
    return 0;
}