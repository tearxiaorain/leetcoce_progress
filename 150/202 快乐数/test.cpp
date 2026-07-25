#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <algorithm>
using namespace std;

bool isHappy(int n)
{
    map<int, int> m;
    while (1)
    {
        if (n == 1)
            return true;
        auto it = m.find(n);
        if (it != m.end())
            break;
        else
            m[n] = n;

        int a = n / 10;
        int r = n % 10;
        int c = 0;
        while (a || r)
        {
            c += r * r;
            r = a % 10;
            a /= 10;
        }
        n = c;
    }
    return false;
}

int main()
{
    vector<string> strs;
    string arr[6] = {"eat","tea","tan","ate","nat","bat"};
    for (int i = 0; i < 6; i++)
    {
        strs.push_back(arr[i]);
    }
    cout << isHappy(3);
    return 0;
}
