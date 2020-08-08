// https://leetcode.com/problems/can-convert-string-in-k-moves/
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

bool canConvertString(string s, string t, int k) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int freq[26]={0};
    int ans=0;
    if(s.length() != t.length())return false;

    for(int i=0; i<s.length(); i++){
        if(s[i] != t[i]){
            int val = ((t[i]-s[i])+26)%26;
            ans = max(ans, freq[val]*26+val);
            freq[val]++;
        }
    }
    return ans<=k;
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