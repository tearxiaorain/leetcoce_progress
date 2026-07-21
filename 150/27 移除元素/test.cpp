#include <iostream>
#include <vector>
using namespace std;
int main() {
    vector<int> nums;
    int k;    
    int val = 1;
    int arr[1] = {1};
    for(int i=0;i<1;i++){
        nums.push_back(arr[i]);
    }
    //cin>>val;

    int n = nums.size();
    int count = 0;

    for (int i = 0; i + count < n; i++) {
        if (nums[i] == val) {
            while (nums[i] == val) {
                if(i + count >= n) {
                    break;
                }
                swap(nums[i], nums[n - 1 - count]);
                count++;
            }
        }
    }
    for(int i=0;i<n-count;i++){
        cout<<nums[i]<<" ";
    }
    cout<<endl<<count;
    return count;
}