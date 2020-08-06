// https://leetcode.com/problems/magical-string/
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

int magicalString(int n) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string ans="";
    ans += "1";
    ans += "2";
    ans += "2";

    int curr = 1;
    int i=2;
    while(i<n){
        if(ans[i] == '2'){
            ans += curr+'0';
            ans += curr+'0';
        }
        else{
            ans += curr+'0';
        }

        (curr==1)?curr=2:curr=1;
        i++;
    }

    int ct=0;
    for(int i=0; i<n; i++){
        if(ans[i]=='1')ct++;
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