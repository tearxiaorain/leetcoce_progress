#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    vector<int> nums;
    int arr[3] = {3, 2, 3};
    for (int i = 0; i < 3; i++)
    {
        nums.push_back(arr[i]);
    }

    int count = 0;
    int ind = 0;
    int n = nums.size();
    sort(nums.begin(), nums.end());
    for (int i = 0; i < n; i++)
    {
        if (i)
        {
            if (nums[i] == nums[i - 1])
            {
                count++;
                if (count >= n / 2)
                {
                    ind = i;
                    break;
                }
            }
            else
            {
                count = 0;
            }
        }
    }
    return nums[ind];
}