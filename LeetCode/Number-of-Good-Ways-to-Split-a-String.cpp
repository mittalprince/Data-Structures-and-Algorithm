// https://leetcode.com/problems/number-of-good-ways-to-split-a-string/
#include<iostream>
#include<vector>
#include<set>
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

int numSplits(string s) {
    set<char>S;
    int n = s.length();
    vector<int>left(n,0), right(n, 0);

    for(int i=0; i<n; i++){
        S.insert(s[i]);
        left[i] = S.size();
    }
    S = set<char>();
    for(int i=n-1; i>=0; i--){
        S.insert(s[i]);
        right[i] = S.size();
    }

    int ans=0;
    for(int i=0; i<n-1; i++){
        if(left[i] == right[i+1])ans++;
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