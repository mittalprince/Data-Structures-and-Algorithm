// https://leetcode.com/problems/find-median-from-data-stream/
#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define ip1(arr, n) for(int i=1; i<=n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define debug(x) cout<<x<<"\n";
#define inf 1e9
#define INF 1e16
#define MOD 1000000007

class MedianFinder {
public:
    // idea -> median -> middle element
    // sort arr and find mid
    priority_queue<int, vector<int> >max_pq; // max heap store left half arr max element
    priority_queue<int, vector<int>, greater<int> >min_pq; // min heap store right half arr min element
    double median=0.0;
    
    /** initialize your data structure here. */
    MedianFinder() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        priority_queue<int, vector<int> >();
        priority_queue<int, vector<int>, greater<int> >();
        median=0.0;
    }
    
    void addNum(int num) {
        if (max_pq.empty() || max_pq.top()>num) max_pq.push(num);
        else min_pq.push(num);
        
        int size1=max_pq.size();
        int size2=min_pq.size();
        
        if(size1-size2>1){
            int temp = max_pq.top();
            max_pq.pop();
            min_pq.push(temp);
        }
        if(size2-size1>1){
            int temp = min_pq.top();
            min_pq.pop();
            max_pq.push(temp);
        }
    }
    
    double findMedian() {
        if(max_pq.empty() && min_pq.empty()){
            return median;
        }
        
        int size1=max_pq.size();
        int size2=min_pq.size();
        
        if(size1 == size2){
            median = (max_pq.top()+min_pq.top());
            median = (double)median/2;
        }
        else{
            if(size1>size2){
                median = max_pq.top();
            }
            else{
                median = min_pq.top();
            }
        }
        
        return median;
    }
};

int main(){

/*
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
*/

    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}