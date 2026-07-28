#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <string>
#include <algorithm>
using namespace std;

void rotate(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int y[4] = {1, 0, -1, 0};
    int x[4] = {0, 1, 0, -1};
    for (int i = 0; i < n / 2; i++)
    {
        for (int k = 1; k < n - i * 2; k++)
        {   
            int pos = 0;
            int k1 = i;
            int k2 = i;
            int temp = matrix[k1][k2];
            for (int j = 1; j < 4 * (n - i * 2 - 1); j++)
            {
                matrix[k1][k2] = matrix[k1 + y[pos % 4]][k2 + x[pos % 4]];
                k1 += y[pos % 4];
                k2 += x[pos % 4];
                if (k1 + y[pos % 4] < i || k1 + y[pos % 4] >= i + n - i * 2 ||
                    k2 + x[pos % 4] < i || k2 + x[pos % 4] >= i + n - i * 2)
                    pos++;
            }
            matrix[i][i + 1] = temp;
        }
        cout<<endl;
    }
}

int main()
{
    vector<vector<int>> m;
    int arr[5][5] = {1,2,3,4,5,
                    6,7,8,9,10,
                    11,12,13,14,15,
                    16,17,18,19,20,
                    21,22,23,24,25};
    for(int i=0;i<5;i++)
    {
        vector<int> t(0);
        for(int j=0;j<5;j++)
        {
            t.push_back(arr[i][j]);
        }
        m.push_back(t);
    }

    rotate(m);
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            cout<<m[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    return 0;
}
