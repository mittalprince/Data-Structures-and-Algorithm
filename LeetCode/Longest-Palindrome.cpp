// https://leetcode.com/problems/longest-palindrome/
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

int longestPalindrome(string s){
    int n=s.length();
    vector<int> vec(128, 0);
    for(int i=0; i<n; i++){
        vec[s[i]]++;
    }

   int ct=0, flag=1;
    for(int i=0; i<128; i++){
        if(vec[i]&1){
            ct += vec[i] - 1;
            if(flag==1){
                ct += 1;
            }
            flag=0;
        }
        else if((vec[i]&1)==0){
            ct += vec[i];
        }
    }
    return ct;
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