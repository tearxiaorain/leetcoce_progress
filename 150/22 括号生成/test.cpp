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

void fun(vector<string> &res, int &left, int &right, string &path)
{
    if (left == 0)
    {
        if (right == 0)
        {
            res.push_back(path);
            return;
        }
        else
        {
            right--;
            string t = path;
            path += ")";
            fun(res, left, right, path);
            path = t;
            right++;
        }
    }
    else
    {
        left--;
        right++;
        string t = path;
        path += "(";
        fun(res, left, right, path);
        path = t;
        right--;
        left++;

        if (right != 0)
        {
            right--;
            string t = path;
            path += ")";
            fun(res, left, right, path);
            path = t;
            right++;
        }
    }
}

vector<string> generateParenthesis(int n)
{
    vector<string> res;
    string s = "";
    int a = 0;
    fun(res, n, a, s);
    return res;
}

int main()
{
    int arr[7] = {5, 7, 7, 8, 8, 10};
    vector<int> a;
    for (int i = 0; i < 6; i++)
    {
        a.push_back(arr[i]);
    }

    vector<string> res = generateParenthesis(3);

    cout << 1;
    return 0;
}
