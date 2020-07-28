#include<iostream>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

class KthLargest
{
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int size;

    KthLargest(int k, vector<int> &nums)
    {
        pq = priority_queue<int, vector<int>, greater<int>>();
        size = k;
        for (auto iter : nums)
        {
            add(iter);
        }
    }

    int add(int x)
    {
        if (size > pq.size())
        {
            pq.push(x);
            return pq.top();
        }
        else
        {
            if (pq.top() <= x)
            {
                pq.pop();
                pq.push(x);
            }
            return pq.top();
        }
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
int main(){
    
    return 0;
}