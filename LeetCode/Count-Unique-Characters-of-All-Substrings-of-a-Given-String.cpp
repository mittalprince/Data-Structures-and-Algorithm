// https://leetcode.com/problems/count-unique-characters-of-all-substrings-of-a-given-string/
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

int uniqueLetterString(string s) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n=s.length();
    if(n==0)return 0;
    int prev[n], next[n];

    for(int i=0; i<n; i++){
        prev[i]=-1;
        next[i]=n;
    }

    unordered_map<char, int>m;
    for(int i=0; i<n; i++){
        if(m.count(s[i])){
            prev[i] = m[s[i]];
            next[m[s[i]]] = i;
        }
        m[s[i]]=i;
    }

    long long ans=0;
    for(int i=0; i<n; i++){
        ans += (((i-prev[i]) * (next[i]-i))%(1000000007));
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