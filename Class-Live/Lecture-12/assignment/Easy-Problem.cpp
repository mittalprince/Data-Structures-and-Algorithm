#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

/*
Logic:
we have two option when we get any char that is from (h,a,r,d) then we have two options
1. either stay the same char
2. or delete it

so when we occur (h,a,r,d) we store cost of all these into variables
so to break seq, if we have h,a we can either del all h or all a, we prform the operation that has min cost
simillary when we have h,a,r,d, we use the same concept
*/

int main(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    ll arr[n];
    ip(arr, n);
    ll cost[4]={0};

    for(int i=0; i<n; i++){
        if(s[i] == 'h') cost[0] += arr[i]; // total cost to remove h
        if(s[i] == 'a') cost[1] = min(cost[0], cost[1]+arr[i]); 
        // total cost to remove a, we either remove all preceding h(that cost store in cost[0]) or remove all r(that occur upto idndex i), so to break hard seq
        if(s[i] == 'r') cost[2] = min(cost[1], cost[2]+arr[i]);
        if(s[i] == 'd') cost[3] = min(cost[2], cost[3]+arr[i]);
    }
    // for(int i=0; i<4; i++){
    //     cout<<cost[i]<<" ";
    // }
    cout<<cost[3]<<endl;
    return 0;
}