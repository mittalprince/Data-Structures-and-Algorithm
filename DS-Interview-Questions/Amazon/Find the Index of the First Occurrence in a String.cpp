// https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/
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

vector<int> kmpProcess(string needle) {
    int n = needle.length();
    vector<int> table(n, 0);

    int i=1, j=0;
    while(i<n){
        while(j>0 && needle[i] != needle[j]) j = table[j-1];
        if (needle[i] == needle[j]){
            table[i] = j+1;
            i++;
            j++;
        }
        else if ( j== 0){
            table[i] = 0;
            i++;
        }
    }
    return table;
}

int strStr(string haystack, string needle) {
    /*
    Naive approach
    int m=haystack.size(), n = needle.size();
    if (!n) return 0;

    for(int i=0; i<m-n+1; i++){
        int j=0;
        for(; j<n; j++){
            if (haystack[i+j] != needle[j])break;
        }
        if (j == n)return i;
    }
    return -1;
    */
    int m = haystack.size(), n = needle.size();
    if (!n) {
        return 0;
    }
    vector<int> lps = kmpProcess(needle);
    int i=0, j=0;

    while(i<m){
        while(j>0 && needle[j] != haystack[i]){
            j = lps[j-1];
        }
        if (needle[j] == haystack[i]){
            i++;
            j++;
        } else i++;

        if (j == n){
            return i-n;
        }
    }
    return -1;
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