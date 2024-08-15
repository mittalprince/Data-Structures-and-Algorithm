// https://leetcode.com/problems/count-days-without-meetings/
#include<iostream>
#include<vector>
#include<algorithm>
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

int countDays(int days, vector<vector<int>>& meetings) {
    int n = meetings.size();
    sort(meetings.begin(), meetings.end());
    int ans = meetings[0][0] - 1;
    for(int i=1; i<n; i++){
        if(meetings[i][0] <= meetings[i-1][1]){
            meetings[i][1] = max(meetings[i-1][1], meetings[i][1]);
        } else{
            ans += (meetings[i][0] - meetings[i-1][1]) - 1;
        }
    }
    ans += days - meetings[n-1][1];
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