#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

int canCompleteCircuitB(vector<int>&gas, vector<int>&cost){
    int n = gas.size();

    for(int i=0; i<n; i++){
        if(gas[i]-cost[i] >= 0){
            int ct=1;
            int initial_gas = gas[i]-cost[i];
            int j=i+1;
            while(ct<n){
                j %= n;
                initial_gas += gas[j]-cost[j];
                if(initial_gas<0){
                    break;
                }
                j++;
                ct++;
            }
            if(ct==n) return i;
        }
    }
    return -1;
}

int canCompleteCircuit(vector<int>&gas, vector<int>&cost){
    int n=gas.size();

    int net_gas=0, curr_gas=0, min_gas=0, start=0;

    for(int i=0; i<n; i++){
        net_gas += (gas[i]-cost[i]);
        curr_gas += (gas[i] - cost[i]);

        // if at current instant we have fuel less than 0 we can't move forward
        // soo start from next point
        if(curr_gas < 0){
            curr_gas = 0;
            start=i+1;
        }
    }
    // if the net_ags for whole trip is less than 0 no matter from where we start
    // then it compulsory that no path exist so return -1;

    return (net_gas>=0)?start:-1;
}
int main(){
    int n;
    cin>>n;
    vector<int> gas(n), cost(n);
    ip(gas, n);
    ip(cost, n);
    cout<<canCompleteCircuit(gas, cost)<<endl;
    return 0;
}