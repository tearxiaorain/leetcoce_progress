#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <string>
#include <algorithm>
using namespace std;

int climbStairs(int n) {
    if(n==0)
        return 0;
    else if(n==1)
        return 1;
    else if(n==2)
        return 2;
    else
    {
        int *arr=new int[n+1];
        for(int i=0;i<3;i++)
        {
            arr[i]=i;
        }
        for(int i=3;i<=n;i++)
        {
            arr[i]=arr[i-1]+arr[i-2];
        }
        return arr[n];
    } 
}

int main()
{
    cout << climbStairs(3);
    return 0;
}
