#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <string>
#include <algorithm>
using namespace std;

int mySqrt1(int x) {
    int q=0;
    int arr[5]={0,1,1,1,2};
    if(x<=4)
        return arr[x];
    for(long long i=2;i<x;i++)
    {
        if(i*i>x)
        {
            q=i-1;
            break;
        }
    }
    return q;
}

int mySqrt(int x) {
    int arr[5]={0,1,1,1,2};
    if(x<=4)
        return arr[x];
    int le=0;
    int ri=x;
    int mid=x/2;
    while(le<=ri)
    {
        mid=(le+ri)/2;
        if(mid*mid<x)
        {
            le=mid+1;
        }
        else if(mid*mid>x)
        {
            ri=mid-1;
        }
        else
            break;
    }
    if(mid*mid>x)
        return mid-1;
    return mid;
}

int main()
{
    int arr[9] = {1, 3, 6, 7, 9, 4, 10, 5, 6};
    vector<int> n(0);
    for (int i = 0; i < 9; i++)
    {
        n.push_back(arr[i]);
    }
    cout << mySqrt(30);
    return 0;
}
