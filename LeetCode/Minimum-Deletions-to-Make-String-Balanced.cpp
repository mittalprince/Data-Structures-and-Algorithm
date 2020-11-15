//https://leetcode.com/problems/minimum-deletions-to-make-string-balanced/
#include<iostream>
#include<vector>
#include<climits>
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

int minimumDeletions(string s) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int pre[100005];
    pre[0]=0;
    int n=s.length();

    for(int i=0; i<n; i++){
        pre[i+1] = pre[i];
        if(s[i]=='b')pre[i+1]++;
    }

    int suf[100005];
    suf[n]=0;
    for(int i=n-1; i>=0; i--){
        suf[i] = suf[i+1];
        if(s[i]=='a')suf[i]++;
    }

    int ans=INT_MAX;
    for(int i=0; i<=n; i++){
        ans = min(ans, pre[i]+suf[i]);
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