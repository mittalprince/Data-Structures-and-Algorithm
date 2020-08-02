// https://leetcode.com/problems/find-all-anagrams-in-a-string/
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

bool check(int p[], int s[]){
    for(int i=0; i<26; i++){
        if(p[i] != s[i])return false;
    }
    return true;
}

vector<int> findAnagrams(string s, string p) {
    int pt[26]={0}, st[26]={0};

    int plen = p.length();
    int slen = s.length();

    if(slen < plen)return {};

    for(int i=0; i<p.length(); i++){
        pt[p[i]-'a']++;
        st[s[i]-'a']++;
    }

    vector<int>ans;
    if(check(pt, st))ans.push_back(0);

    for(int i=0; i<(s.length()-p.length()); i++){
        st[s[i+plen]-'a']++;
        st[s[i]-'a']--;
        if(check(pt, st))ans.push_back(i+1);
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