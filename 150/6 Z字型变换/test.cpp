#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

string convert(string s, int numRows) {
    int n = numRows;
    if(n==1)
        return s;
    int len = s.length();
    int l = 2*n-2;
    int c = len/l;
    
    string str = "";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<c+1;j++)
        {
            int ind1 = j*l+i;
            int ind2 = (j+1)*l-i;
            if(ind1!=ind2)
            {
                if(ind1<len)
                {
                    str+=s[ind1];
                    //cout<<s[ind1];
                }
                if(ind2<len&&ind2 < (j+1)*l)
                {
                    str+=s[ind2];
                    //cout<<s[ind2];

                }
            }
            else
            {
                if(ind1<len)
                {
                    str+=s[ind1];
                    //cout<<s[ind1];

                }
            }
        }
        //cout<<endl;
    }
    //cout<<endl;
    return str;
}

int main()
{
    vector<string> strs;
    string arr[7] = {"apple", "application", "apply", "approach", "april", "apricot", "apology"};
    for (int i = 0; i < 7; i++)
    {
        strs.push_back(arr[i]);
    }
    cout << convert("A", 1) << endl;
    return 0;
}
