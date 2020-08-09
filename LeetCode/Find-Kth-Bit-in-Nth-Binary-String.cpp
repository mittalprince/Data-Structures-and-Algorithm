// https://leetcode.com/problems/find-kth-bit-in-nth-binary-string/
#include<iostream>
#include<vector>
#include<algorithm>
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

char findKthBit(int n, int k) {
    string s="0", t="";

    for(int i=1; i<n; i++){
        t = s+"1";
        for(char &i: s){
            if(i=='0')i='1';
            else i='0';
        }
        reverse(s.begin(), s.end());
        t += s;
        s=t;
    }

    return s[k-1];
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