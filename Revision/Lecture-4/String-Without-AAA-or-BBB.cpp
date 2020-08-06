// https://leetcode.com/problems/string-without-aaa-or-bbb/
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

string strWithout3a3b(int a, int b) {
    string ans="";

    while(a>0 or b>0){
        if(a<b){
            if(0<b--)ans+='b';
            if(0<b--)ans+='b';
            if(0<a--)ans+='a';
        }
        else if(a>b){
            if(0<a--)ans+='a';
            if(0<a--)ans+='a';
            if(0<b--)ans+='b';
        }
        else{
            if(0<b--)ans+='b';
            if(0<a--)ans+='a';
        }
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