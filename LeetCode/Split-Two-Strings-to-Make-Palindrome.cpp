// https://leetcode.com/problems/split-two-strings-to-make-palindrome/
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

bool check(string s, int l, int r){
    int i=l, j=r;
    while(i<j){
        if(s[i]!=s[j])return false;
        i++;j--;
    }
    return true;
}

bool solve(string a, string b){
    int n=a.length();
    for(int i=0, j=n-1; i<j; i++, j--){
        if(a[i]!=b[j]){
            return check(a, i, j) or check(b, i, j);
        }
    }
    return true;
}
bool checkPalindromeFormation(string a, string b) {
    return solve(a,b) or solve(b,a);
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