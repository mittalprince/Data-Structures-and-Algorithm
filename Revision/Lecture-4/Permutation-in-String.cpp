// https://leetcode.com/problems/permutation-in-string/
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

bool compare(vector<int>&pat, vector<int>&txt){
    for(int i=0; i<26; i++){
        if(pat[i]^txt[i]) return false;
    }
    return true;
}

bool checkInclusion(string s1, string s2) {
    int pat_len = s1.length();
    int str_len = s2.length();

    vector<int>pat(26, 0), txt(26, 0);
    if(str_len<pat_len) return false;

    for(int i=0; i<pat_len; i++){
        pat[s1[i]-'a']++;
        txt[s2[i]-'a']++;
    }

    for(int i=0; i<str_len-pat_len; i++){
        if(compare(pat, txt)) return true;
        txt[s2[i+pat_len]-'a']++;
        txt[s2[i]-'a']--;
    }

    return compare(pat, txt);
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