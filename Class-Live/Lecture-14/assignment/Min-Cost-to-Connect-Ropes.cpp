#include<iostream>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

int minCost(vector<int> cost){
    int n=cost.size();
    if(n<=1) return 0;

    priority_queue<int, vector<int>, greater<int> >pq;
    for(int i=0; i<n; i++){
        pq.push(cost[i]);
    }
    int total_min_cost=0;

    while(pq.size()>1){
        int top1 = pq.top(); pq.pop();
        int top2 = pq.top(); pq.pop();

        total_min_cost += (top1+top2);
        pq.push(top1+top2);
    }

    return total_min_cost;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}