#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <string>
#include <algorithm>
using namespace std;

bool isPalindrome(int x)
{
    if (x < 0)
        return false;
    vector<int> arr;
    int a = x;
    while (a)
    {
        arr.push_back(a % 10);
        a /= 10;
    }
    int n = arr.size();
    int flag = 0;
    for (int i = 0; i < n / 2; i++)
    {
        if (arr[i] != arr[n - 1 - i])
        {
            flag++;
            break;
        }
    }
    if (!flag)
        return true;
    return false;
}

int main()
{
    int arr[9] = {1, 3, 6, 7, 9, 4, 10, 5, 6};
    vector<int> n(0);
    for (int i = 0; i < 9; i++)
    {
        n.push_back(arr[i]);
    }
    cout << isPalindrome(121);
    return 0;
}
