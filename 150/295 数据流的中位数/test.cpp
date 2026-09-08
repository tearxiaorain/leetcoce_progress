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

// 小顶堆
class cmp1
{
    public:
    bool operator()(const int &a, const int &b)
    {
        return a > b;
    }
};

// 大顶堆
class cmp2
{
    public:
    bool operator()(const int &a, const int &b)
    {
        return a < b;
    }
};

class MedianFinder {
public:
    priority_queue<int,vector<int>,cmp1> small_pq;
    priority_queue<int,vector<int>,cmp2> big_pq;
    int cnt_small,cnt_big;

    MedianFinder() {
        cnt_small=cnt_big=0;
    }
    
    void addNum(int num) {
        if(cnt_big==0&&cnt_small==0)
        {
            big_pq.push(num);
            cnt_small++;
            return;
        }
        if(cnt_big>cnt_small)
        {
            if(num<=small_pq.top())
            {
                big_pq.push(num);
            }
            else
            {
                big_pq.push(small_pq.top());
                small_pq.pop();
                small_pq.push(num);
            }
            cnt_small++;
            return;
        }
        else if(cnt_big<cnt_small)
        {
            if(num>=big_pq.top())
            {
                small_pq.push(num);
            }
            else
            {
                small_pq.push(big_pq.top());
                big_pq.pop();
                big_pq.push(num);
            }
            cnt_big++;
            return;
        }
        else
        {
            if(num<(small_pq.top()+big_pq.top())/2)
            {
                big_pq.push(num);
                cnt_small++;
            }
            else
            {
                small_pq.push(num);
                cnt_big++;
            }
            return;
        }
    }
    
    double findMedian() {
        if(cnt_big>cnt_small)
            return small_pq.top();
        else if(cnt_big<cnt_small)
            return big_pq.top();
        else
            return (small_pq.top()+big_pq.top())/2.0;
    }
};

int main()
{
    MedianFinder* mf = new MedianFinder();
    mf->addNum(1);
    mf->addNum(2);
    cout<<mf->findMedian();
    mf->addNum(3);
    cout<<mf->findMedian();


    // cout << 1;
    return 0;
}
