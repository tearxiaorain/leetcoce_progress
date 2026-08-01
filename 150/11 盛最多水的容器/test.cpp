#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <string>
#include <algorithm>
using namespace std;

int maxArea(vector<int>& height) {
    int be,en;
    be=0;
    en=height.size()-1;
    int n1=be;
    int n2=en;
    int p=0;
    int hmin=height[0];
    if(height[en]<height[be])
        hmin=height[en];
    int max=hmin*(en-be);
    int flag1,flag2;
    flag1=flag2=0;
    while(n1<n2)
    {
        if(flag1+flag2>2)
            break;
        if(!p)
        {
            while(n1<n2)
            {
                if(height[n1]>height[be])
                {
                    hmin=height[en];
                    if(height[n1]<hmin)
                        hmin=height[n1];
                    int s=hmin*(en-n1);
                    if(s>max)
                    {
                        max=s;
                        be=n1;
                        p=1;
                        flag2=0;
                        break;
                    }
                }
                n1++;
            }
            p=1;
            flag1++;
            n1=be;
        }
        else
        {
            while(n1<n2)
            {
                if(height[n2]>height[en])
                {
                    hmin=height[be];
                    if(height[n2]<hmin)
                        hmin=height[n2];
                    int s=hmin*(n2-be);
                    if(s>max)
                    {
                        max=s;
                        en=n2;
                        p=0;
                        flag1=0;
                        break;
                    }
                }
                n2--;
            }
            p=0;
            flag2++;
            n2=en;
        }
    }
    return max;
}

int main()
{
    int arr[9]={2,3,4,5,18,17,6,3,7};
    vector <int>n;
    for(int i=0;i<7;i++)
    {
        n.push_back(arr[i]);
    }
    cout<<maxArea(n);
    return 0;
}
