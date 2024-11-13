/*
There are n gas stations along a circular route, where the amount of gas at the ith station is gas[i].
You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from the ith station to its next (i + 1)th station. You begin the journey with an empty tank at one of the gas stations.
Given two integer arrays gas and cost, return the starting gas station's index if you can travel around the circuit once in the clockwise direction, otherwise return -1. If there exists a solution, it is guaranteed to be unique.

https://leetcode.com/problems/gas-station/
*/

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

int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int net_gas=0, curr_gas=0, start=0;
    int n=gas.size();

    for(int i=0; i<n; i++){
        net_gas += (gas[i]-cost[i]);
        curr_gas += (gas[i]-cost[i]);

        if(curr_gas<0){
            start=i+1;
            curr_gas=0;
        }
    }

    if(net_gas<0)return -1;
    return start;
}

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