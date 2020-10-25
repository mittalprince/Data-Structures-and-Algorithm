// https://leetcode.com/problems/largest-substring-between-two-equal-characters/
#include<iostream>
#include<vector>
#include<unordered_map>
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

int maxLengthBetweenEqualCharacters(string s) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    unordered_map<char, int>freq;

    int ans=-1;
    for(int i=0; i<s.length(); i++){
        if(freq.count(s[i])){
            ans = max(ans, i-freq[s[i]]-1);
        }
        else freq[s[i]]=i;
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