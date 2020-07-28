#include<iostream>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

int lastStoneWeight(vector<int>& stones) {
    priority_queue<int>pq;

    if(stones.empty()) return 0;

    for(int i: stones){
        pq.push(i);
    }

    while(pq.size()>1){
        int a=pq.top(); pq.pop();
        int b=pq.top(); pq.pop();

        pq.push(abs(a-b));
    }
    return pq.top();
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}