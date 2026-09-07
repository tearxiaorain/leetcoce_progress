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

class RandomizedSet
{
public:
    unordered_map<int, int> m;
    vector<int> arr;
    int cnt;
    RandomizedSet()
    {
        cnt = 0;
    }

    bool insert(int val)
    {
        auto it = m.find(val);
        if (it != m.end())
            return false;
        m[val] = cnt;
        if (arr.size() == cnt)
            arr.push_back(val);
        else
            arr[cnt] = val;
        cnt++;
        return true;
    }

    bool remove(int val)
    {
        auto it = m.find(val);
        if (it == m.end())
            return false;
        arr[it->second] = arr[cnt - 1];
        m[arr[cnt - 1]] = it->second;
        m.erase(val);
        cnt--;
        return true;
    }

    int getRandom()
    {
        int k = rand() % cnt;
        int i = 0;
        return arr[k];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

int main()
{
    RandomizedSet *arr = new RandomizedSet();
    cout << arr->insert(0) << endl;
    cout << arr->insert(1) << endl;
    cout << arr->remove(0) << endl;
    cout << arr->insert(2) << endl;
    cout << arr->remove(1) << endl;
    cout << arr->getRandom() << endl;
    // cout<<arr->getRandom()<<endl;

    // cout << 1;
    return 0;
}
