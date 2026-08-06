#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <string>
#include <algorithm>
using namespace std;

double myPow(double x, int n) {
    if(x==0)
        return 0;
    if(x==1)
        return 1;
    if(x==-1)
    {
        if(n%2)
            return -1;
        return 1;
    }
    if(n==0)
        return 1;
    if(n==1)
        return x;
    if(n==-1)
        return 1/x;
    if(n==2)
        return x*x;
    if(n==-2)
        return 1/(x*x);
    double res=x;
    int flag=0;
    long long nn=n;
    if(n<0)
    {
        flag=1;
        nn=0-nn;
    }
    // for(int i=0;i<nn;i++)
    // {
    //     res*=x;
    // }
    long long count=0;
    for(long long i=2;i<nn;i*=2)
    {
        count=i;
        res*=res;
    }
    for(long long i=count;i<nn;i++)
    {
        res*=x;
    }
    if(flag)
        return 1/res;
    return res;
}

int main()
{
    int arr[9] = {1, 3, 6, 7, 9, 4, 10, 5, 6};
    vector<int> n(0);
    for (int i = 0; i < 9; i++)
    {
        n.push_back(arr[i]);
    }
    cout << myPow(-1, 2147483647);
    return 0;
}
