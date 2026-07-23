#include <iostream>
#include <vector>
using namespace std;
int main() {
    vector<int> nums;
    int k;    
    int val = 1;
    int arr[10] = {0,0,1,1,1,2,2,3,3,4};
    for(int i=0;i<10;i++){
        nums.push_back(arr[i]);
    }
    //cin>>val;

    int n = nums.size();
    int count = 0;

    for (int i = 0; i < n; i++) {
        if (i) {
            if(nums[i] != nums[i-1])
            {
                count++;
                nums[count] = nums[i];
            }
        }
    }
    return count + 1;

    for(int i=0;i<n-count;i++){
        cout<<nums[i]<<" ";
    }
    cout<<endl<<count;
    return count + 1;
}