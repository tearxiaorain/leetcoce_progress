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

string addBinary(string a, string b)
{
    int n1 = a.length() - 1;
    int n2 = b.length() - 1;
    int flag = 0;
    string res = "";
    while (n1 >= 0 && n2 >= 0)
    {
        int sum = (a[n1] - '0') + (b[n2] - '0') + flag;
        flag = sum / 2;
        string t = "";
        t += sum % 2 + '0';
        res = t + res;
        n1--;
        n2--;
    }
    while (n1 >= 0)
    {
        int sum = (a[n1] - '0') + flag;
        flag = sum / 2;
        string t = "";
        t += sum % 2 + '0';
        res = t + res;
        n1--;
    }
    while (n2 >= 0)
    {
        int sum = (b[n2] - '0') + flag;
        flag = sum / 2;
        string t = "";
        t += sum % 2 + '0';
        res = t + res;
        n2--;
    }
    if (flag)
        res = "1" + res;

    return res;
}

int main()
{
    int arr[5] = {4, 1, 2, 1, 2};
    vector<int> a;
    for (int i = 0; i < 5; i++)
    {
        a.push_back(arr[i]);
    }
    cout << addBinary("1010", "1011");

    // cout << 1;
    return 0;
}
