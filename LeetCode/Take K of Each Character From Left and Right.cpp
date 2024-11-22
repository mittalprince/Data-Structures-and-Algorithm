// https://leetcode.com/problems/take-k-of-each-character-from-left-and-right/
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

int takeCharacters(string s, int k) {
    unordered_map<char, int>m;
    int n=s.length();
    int ans = INT_MAX;
    for(char i: s) m[i]++;
    if(m['a']<k ||m['b']<k || m['c']<k)return -1;
    int i=0,j=0, window=0;
    for(; i<n; i++){
        m[s[i]]--;
        window++;

        while(m[s[i]]<k){
            m[s[j++]]++;
            window--;
        }
        ans= min(ans, n-window);
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