#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

int minCostClimbingStairs(vector<int>& cost) {
    int n=cost.size();

    for(int i=0; i<n; i++){
        if(i>1){
            cost[i] += min(cost[i-1], cost[i-2]);   
        }
    }
    return min(cost[n-1], cost[n-2]);
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}