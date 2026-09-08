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

int hammingWeight(int n) {
    int sum=0;
    while(n)
    {
        if(n%2)
            sum++;
        n=n>>1;
    }
    return sum;
}

int main()
{
    cout<<hammingWeight(11);

    // cout << 1;
    return 0;
}
