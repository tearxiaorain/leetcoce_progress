#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <string>
#include <algorithm>
using namespace std;

int trailingZeroes1(int n) {
    int a=n;
    int count=0;
    for(int i=n-1;i>0;i--)
    {
        int r1=a%10;
        
        while(a&&!r1)
        {
            count++;
            a/=10;
            r1=a%10;
        }
        int t=i;
        int r2=t%10;
        while(t&&!r2)
        {
            count++;
            t/=10;
            r2=t%10;
        }
        int r=(r1*r2)%10;
        int m=r1*r2;
        while(m&&!r)
        {
            count++;
            m/=10;
            r=m%10;
        }
        a=m;
    }
    int rr=a%10;
    while(a&&!rr)
    {
        count++;
        a/=10;
        rr=a%10;
    }
    return count;
}

int trailingZeroes(int n) {
    int num_2,num_5,count;
    num_2=num_5=count=0;
    for(int i=1;i<=n;i++)
    {
        int t=i;
        while(t%5==0)
        {
            num_5++;
            t/=5;
        }
        while(t%2==0)
        {
            num_2++;
            t/=2;
        }
    }
    count=num_2;
    if(num_5<num_2)
        count=num_5;
    return count;
}

int main()
{
    int arr[9] = {1, 3, 6, 7, 9, 4, 10, 5, 6};
    vector<int> n(0);
    for (int i = 0; i < 9; i++)
    {
        n.push_back(arr[i]);
    }
    cout << trailingZeroes(30);
    return 0;
}
