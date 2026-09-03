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

vector<int> plusOne(vector<int>& digits) {
    int n=digits.size();
    int flag=1;
    for(int i=n-1;i>=0;i--)
    {
        if(flag)
            digits[i]+=1;
        if(digits[i]==10)
        {
            digits[i]=0;
            flag=1;
        }
        else
            flag=0;
    }
        
    if(flag)
    {
        digits.push_back(0);
        for(int i=n-1;i>=0;i--)
        {
            digits[i+1]=digits[i];
        }
        digits[0]=1;
    }
    return digits;
}

int main()
{
    int nrr[6] = {9};
    vector<int> nums;
    for (int i = 0; i < 1; i++)
    {
        nums.push_back(nrr[i]);
    }
    nums = plusOne(nums);
    cout << 1;
    return 0;
}
