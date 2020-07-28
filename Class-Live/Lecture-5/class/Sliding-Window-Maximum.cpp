#include<iostream>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

vector<int> maxSlidingWindow(vector<int>&arr, int k){
    int n=arr.size();
    if(k==1) return arr;
    vector<int>ans;
    // in dequeue we store index of arr elemnt
    deque<int> q;

    for(int i=0; i<k; i++){
        // for first k size window we store all decreasing order element index
        // i.e at queue back we have max element index of first k size window
        // when incomging elemnet greater than prev store elemtn idx we remoe all these as 
        // now we have greater element to them, so this will become max, hence we pop_back queue
        // and then we push_back new idx
        while(!q.empty() && arr[i]>=arr[q.back()]){
            q.pop_back();
        }
        q.push_back(i);
    }

    for(int i=k; i<n; i++){
        // now queue ke front mein index prev window ke max ka index hoga
        // so for every window we push queue front into ans;
        ans.push_back(arr[q.front()]);

        // now we check whether q ke front ki val (i.e index) given k size ki window mein exist karta hai ki nahi
        // agr nahi karta toh hum tab usse window se chota idx ko pop front kar denege
        // i-k give current window starting index
        while(!q.empty() && q.front() <= (i-k)){
            q.pop_front();
        }
        // now we repeat the same porcess for insertion of each new elemt
        while(!q.empty() && arr[i]>=arr[q.back()]){
            q.pop_back();
        }
        q.push_back(i);
    }
    // for last window
    ans.push_back(arr[q.front()]);
    return ans;
}
int main(){
    int n,k;
    cin>>n>>k;
    vector<int> arr(n);
    ip(arr, n);
    vector<int> res = maxSlidingWindow(arr, k);
    op(res, res.size());
    return 0;
}