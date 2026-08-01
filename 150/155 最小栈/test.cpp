#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <string>
#include <algorithm>
using namespace std;

class MinStack {
public:
    vector<int> st;
    int count = 0;
    int size = st.size();
    int min = INT_MAX;
    int ind = -1;
    MinStack() {
        count = 0;
        size = st.size();
    }
    
    void push(int value) {
        if(count==size)
        {
            st.push_back(value);
            size++;
            count++;
        }
        else
        {
            st[count]=value;
            count++;
        }
        if(min>value&&ind!=-1)
        {
            min=value;
            ind=count-1;
        }
    }
    
    void pop() {
        count--;
        if(ind>=count)
        {
            min=INT_MAX;
            ind=-1;
        }  
    }
    
    int top() {
        return st[count-1];
    }
    
    int getMin() {
        if(ind!=-1)
            return min;
        if(count>0)
        {
            for(int i=0;i<count;i++)
            {
                if(min>st[i])
                {
                    min=st[i];
                    ind = i;
                }
            }
        }
        return min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

int main()
{
    MinStack* ms = new MinStack();
    ms->push(-10);
    ms->push(14);
    cout<<ms->getMin();
    cout<<endl;
    cout<<ms->getMin();
    cout<<endl;
    ms->push(-20);
    cout<<ms->getMin();
    cout<<endl;
    cout<<ms->getMin();
    cout<<endl;
    cout<<ms->top();
    cout<<endl;
    cout<<ms->getMin();
    cout<<endl;
    ms->pop();
    ms->push(10);
    ms->push(-7);
    cout<<ms->getMin();
    cout<<endl;
    ms->push(-7);
    ms->pop();
    ms->top();
    cout<<ms->getMin();
    cout<<endl;
    ms->pop();

    return 0;
}
