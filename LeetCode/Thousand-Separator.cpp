// https://leetcode.com/problems/thousand-separator/
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

string thousandSeparator(int n) {

    string s = to_string(n);

    std::reverse(s.begin(), s.end());
    int ct=0;
    string ans="";
    for(int i=0; i<s.length(); i++){
        if(ct==3){
            ans +=".";
            ct=0;
        }
        ans += s[i];
        ct++;
    }
    std::reverse(ans.begin(), ans.end());
    // cout<<ans<<endl;
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