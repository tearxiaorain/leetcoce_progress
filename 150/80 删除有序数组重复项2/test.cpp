#include <iostream>
#include <vector>
using namespace std;
int main() {
    vector<int> nums;   
    int val = 1;
    int arr[3] = {1,2,2};
    for(int i=0;i<3;i++){
        nums.push_back(arr[i]);
    }
    //cin>>val;

    int n = nums.size();
    int count = -1;
    int k = 0;

    for (int i = 0; i < n; i++) {
        if (i) {
            if(nums[i] != nums[i-1])
            {
                k = i;
                count++;
                nums[count] = nums[i];
            }
            else
            {
                if(i - k < 2)
                {
                    count++;
                    nums[count] = nums[i];
                }
            }
        }
        else
        count++;
    }
    return count + 1;

    for(int i=0;i<n;i++){
        cout<<nums[i]<<" ";
    }
    cout<<endl<<count;
    return count + 1;
}