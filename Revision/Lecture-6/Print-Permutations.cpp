// https://hack.codingblocks.com/app/contests/1496/307/problem
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

string s;
vector<string>ans;

void solve(int i){
    if(i==s.length()){
        ans.push_back(s);
        return;
    }
    for(int j=i; j<s.length(); j++){
        swap(s[j], s[i]);
        solve(i+1);
        swap(s[j], s[i]);
    }
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    cin>>s;
    solve(0);

    for(int i=0; i<ans.size(); i++){
		cout<<ans[i];
		if(i != ans.size()-1) cout<<" ";
	}
    return 0;
}