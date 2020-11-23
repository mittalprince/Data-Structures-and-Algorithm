//https://www.codechef.com/COOK124B/problems/FLIP
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

void check(string &a,string b,int j){

	for(int i=j;i<a.size();i+=2){
		if(a[i]==b[i])return;
		else a[i]=b[i];
	}
}

void solve(){
    string a,b;
    cin>>a>>b;

    int ans=0;
    int n=a.length();
    for(int i=0;i<a.size();i++){
        if(a[i]!=b[i]){
            ans++;
            check(a,b,i);
        }
    }
    cout<<ans<<endl;
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}