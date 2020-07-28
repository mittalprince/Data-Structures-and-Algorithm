#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MOD 1000000007

/*
There are 2N people a company is planning to interview. 
The cost of flying the i-th person to city A is costs[i][0], 
and the cost of flying the i-th person to city B is costs[i][1].

Return the minimum cost to fly every person to a city 
such that exactly N people arrive in each city.
*/

int twoCitySchedCost(vector<vector<int>>& costs) {

    int n=costs.size();

    sort(costs.begin(), costs.end(), [&](const vector<int>&a, const vector<int>&b){
       return a[1]-a[0]>b[1]-b[0]; 
    });

    int ans=0;
    for(int i=0; i<n; i++){
        if(i<(n/2)) ans += costs[i][0];
        else ans += costs[i][1];
    }

    return ans;
}

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