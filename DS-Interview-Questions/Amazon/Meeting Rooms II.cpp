// https://leetcode.com/problems/meeting-rooms-ii/
#include<iostream>
#include<vector>
#include<map>
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

int minMeetingRooms(vector<vector<int>>& intervals) {
    map<int, int>m;
    for(auto it: intervals){
        m[it[0]]++;
        m[it[1]]--;
    }
    int ans=0, ct=0;
    /*
        start par increment
        end par decrement
        at a time we have to check total sum of + and -
        tell ki kitne rooms chahiye
    */
    for(auto it: m){
        ct += it.second;
        ans = max(ans, ct);
    }
    return ans;
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