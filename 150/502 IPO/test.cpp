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

class val_cost
{
public:
    int val;
    int cost;
    val_cost() : val(0), cost(0) {};
    val_cost(int v, int c) : val(v), cost(c) {};
};

// 优先成本小的
class cmp1
{
    public:
    bool operator()(const val_cost &a, const val_cost &b)
    {
        return a.cost > b.cost;
    }
};

// 优先利润大的
class cmp2
{
    public:
    bool operator()(const val_cost &a, const val_cost &b)
    {
        return a.val < b.val;
    }
};

int findMaximizedCapital(int k, int w, vector<int> &profits, vector<int> &capital)
{
    priority_queue<val_cost, vector<val_cost>, cmp1> pqc;
    priority_queue<val_cost, vector<val_cost>, cmp2> pqp;
    int n = profits.size();
    for (int i = 0; i < n; i++)
    {
        val_cost t(profits[i], capital[i]);
        pqc.push(t);
    }
    for (int i = 0; i < k; i++)
    {
        while(!pqc.empty())
        {
            if(pqc.top().cost <= w)
            {
                val_cost t = pqc.top();
                pqc.pop();
                pqp.push(t);
            }
            else break;
        }
        if(pqp.empty())
            break;
        w += pqp.top().val;
        pqp.pop();
    }
    return w;
}

int main()
{
    int arr[6] = {1, 2, 3, 5, 6, 4};
    int brr[6] = {1, 1, 2, 5, 6, 4};

    vector<int> n1;
    vector<int> n2;

    for (int i = 0; i < 3; i++)
    {
        n1.push_back(arr[i]);
        n2.push_back(brr[i]);
    }
    cout << findMaximizedCapital(2, 2, n1, n2);
    // cout << 1;
    return 0;
}
