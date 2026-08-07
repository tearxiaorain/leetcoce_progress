#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int m=matrix.size();
    int n=matrix[0].size();
    int left=0;
    int right=m*n-1;
    int mid=right/2;
    while(left<=right)
    {
        mid=(left+right)/2;
        int r=mid/n;
        int c=mid%n;
        if(matrix[r][c]<target)
        {
            left=mid+1;
        }
        else if(matrix[r][c]>target)
        {
            right=mid-1;
        }
        else
            break;
    }
    int r=mid/n;
    int c=mid%n;
    if(matrix[r][c]==target)
        return true;
    return false;
}




int main()
{
    int arr[9] = {1,3,5,6, -1, -4};
    int brr[9] = {1, 2, 2, 5, 1};
    int mar[3][4]={1,3,5,7,10,11,16,20,23,30,34,60};
    
    vector<int> m(0);
    vector<vector<int>> r(0);

    for (int i = 0; i < 3; i++)
    {
        vector<int> n(0);
        for(int j=0;j<4;j++)
        {
            n.push_back(mar[i][j]);
        }
        r.push_back(n);
        // m.push_back(brr[i]);
    }
    cout<< searchMatrix(r,2);
    return 0;
}
