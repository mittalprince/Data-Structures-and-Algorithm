// https://leetcode.com/problems/split-array-into-consecutive-subsequences/
#include<iostream>
#include<vector>
#include<map>
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

bool isPossible(vector<int>& nums) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n=nums.size();
    if(n<3) return false;

    map<int, priority_queue<int, vector<int>, greater<int>>>m;

    int less_than_3_ct=0;

    for(int i: nums){
        if(!m[i-1].empty()){
            int top = m[i-1].top();
            m[i-1].pop();
            m[i].push(top+1);

            if(top+1 == 3)less_than_3_ct--;
        }
        else{
            m[i].push(1);
            less_than_3_ct++;
        }
    }

    return less_than_3_ct==0;
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