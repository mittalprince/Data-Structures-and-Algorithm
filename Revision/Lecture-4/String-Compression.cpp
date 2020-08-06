// https://leetcode.com/problems/string-compression/
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

int compress(vector<char>& chars) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int k=0;
    int i=1, ct=0;
    int n=chars.size();

    while(i<=n){
        ct=1;
        while(i<n and chars[i] == chars[i-1])i++, ct++;
        chars[k++]=chars[i-1];
        if(ct>1){
            string val = to_string(ct);
            for(char j: val)chars[k++]=j;
        }
        i++;
    }

    return k;
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