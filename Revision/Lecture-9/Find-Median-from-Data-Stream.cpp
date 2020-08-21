// https://leetcode.com/problems/find-median-from-data-stream/
#include<iostream>
#include<vector>
#include<queue>
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

static int x=[](){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
return 0;
}();

class MedianFinder {
public:
    priority_queue<int, vector<int> >max_pq;
    priority_queue<int, vector<int>, greater<int> >min_pq;
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
        if(max_pq.empty() && min_pq.empty()){
            max_pq.push(num);
            return;
        }
        
        if(num<=median){
            max_pq.push(num);
        }
        else{
            min_pq.push(num);
        }
        
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

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}