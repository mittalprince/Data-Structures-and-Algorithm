//https://www.codechef.com/LTIME91B/problems/SWAP10HG
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

void solve2(){
    ll n;
    cin>>n;

    string s,t;
    cin>>s>>t;

    int ans=0;
	for(int i=0; i<n; i++){
		ans += (s[i]-'0')-(t[i]-'0');
		if(ans<0){
			cout<<"No\n";
			return;
		}
	}
	if(ans==0){
		cout<<"Yes\n";
	}
	else cout<<"No\n";
}


void solve(){
    ll n;
    cin>>n;

    string s,t;
    cin>>s>>t;

    vector<int>one, zero;
	int s1=0, t1=0;
    for(int i=0; i<n; i++){
        if(s[i]!=t[i]){
            if(s[i]=='0')zero.push_back(i);
            else one.push_back(i);
        }
		if(s[i]=='1')s1++;
		if(t[i]=='1')t1++;
    }

	if(t1!=s1){
		cout<<"No\n";
		return;
	}

    sort(one.begin(), one.end());
    sort(zero.begin(), zero.end());

    int i=0, j=0;
    bool flag=true;
    while(i<one.size() and j<zero.size()){
        while(j<zero.size() and one[i]>zero[j])j++;
        if(j==zero.size()){
            flag=false;
            break;
        }
        i++;j++;
    }

    if(i!=one.size() or j!=zero.size()){
        flag=false;
    }
    
    if(flag){
        cout<<"Yes\n";
    }
    else cout<<"No\n";
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