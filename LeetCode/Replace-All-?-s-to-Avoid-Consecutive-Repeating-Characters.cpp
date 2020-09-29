// https://leetcode.com/problems/replace-all-s-to-avoid-consecutive-repeating-characters/
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

string modifyString(string s) {

    int n=s.length();
    for(int i=0; i<n; i++){
        if(s[i]=='?'){
            s[i]='a';
            if(i and s[i-1]==s[i])s[i]++;
            if(i+1<n and s[i+1]==s[i])s[i]++;
            if(i and s[i-1]==s[i])s[i]++;
            if(i+1<n and s[i+1]==s[i])s[i]++;
        }
    }

    return s;
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