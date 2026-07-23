#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int lengthOfLastWord(string s)
{
    int n = s.length();
    int count = 0;
    while (s[n - 1] == ' ' && n > 0)
    {
        n--;
        if (n <= 0)
            break;
    }
    while (s[n - 1] != ' ' && n > 0)
    {
        n--;
        count++;
        if (n <= 0)
            break;
    }
    return count;
}

int main()
{
    std::vector<int> prises;
    int arr[7] = {1, 2, 3, 4, 5, 6, 7};
    for (int i = 0; i < 7; i++)
    {
        prises.push_back(arr[i]);
    }
    cout << lengthOfLastWord("a") << endl;
    return 0;
}
