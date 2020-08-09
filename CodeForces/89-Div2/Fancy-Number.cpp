// https://codeforces.com/contest/118/problem/C
#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<queue>
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
#define ppi pair<ll,ll>

void solve(){
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    int ans = (int)1e9+7;
    string ans_string="";
    string orignal_string=s;

    for(char c='0'; c<='9'; c++){
        s=orignal_string;
        priority_queue<ppi, vector<ppi>, greater<ppi> >pq;

        for(int i=0; i<n; i++){
            //agr s[i] chota hai means s[i] convert into bigger val, so perfer index which comed at end, then treat index first that is closer to end ->(74395, k=3) 74394, 72495
            // for reverse case perfer index which comes closer to 0 
            pq.push({abs(s[i]-c), s[i]>=c?i-n:n-i});
        }
        int curr=0;
        for(int i=0; i<k; i++){
            ppi top = pq.top();
            pq.pop();
            curr += top.first;
            int x=top.second;
			if(x<0){
				x=-x;
			}
			x=-x+n;
			s[x]=c;
        }

        if(curr<ans or (curr==ans and ans_string>s)){
            ans=curr;
            ans_string=s;
        }
    }

    cout<<ans<<endl<<ans_string<<endl;
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}