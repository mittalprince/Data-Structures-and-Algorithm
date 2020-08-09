// https://leetcode.com/problems/make-the-string-great/
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

string makeGood(string s) {
    bool flag=true;
    while(flag){
        flag=false;
        string t=s;
        for(int i=0; i<(int)s.length()-1; i++){
            if(s[i]+32 == s[i+1] or s[i+1]+32 == s[i]){
                t = s.substr(0,i)+s.substr(i+2);
                flag=true;
                break;
            }
        }
        s=t;
    }

    return s;
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