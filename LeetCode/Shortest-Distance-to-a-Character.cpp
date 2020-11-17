//http://leetcode.com/problems/shortest-distance-to-a-character/
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

vector<int> shortestToChar(string S, char C) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n=S.length();
    vector<int>ans(n);

    int prev=-n;
    for(int i=0; i<n; i++){
        if(S[i]==C)prev=i;
        ans[i] = i-prev;
    }
    for(int i=prev-1; i>=0; i--){
        if(S[i]==C)prev=i;
        ans[i] = min(ans[i], prev-i);
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