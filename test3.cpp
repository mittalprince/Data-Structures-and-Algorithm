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

void solve(){
    string s;
    cin>>s;

    ll n=s.length();
    if(n<3){
        cout<<"0\n";
        return;
    }
    ll three=0;
    ll one=0;
    ll two=0;
    // ll t=0;

    ll freq[26]={0};
    for(char i: s){
        freq[i-'a']++;
    }

    for(int i=0; i<26; i++){
        if(freq[i]==1)one++;
        else if(freq[i]==2)two++;
        else if(freq[i]==3)three++;
        else if(freq[i]>3){
            three += freq[i]/3;
			ll mod=freq[i]%3;
			if(mod==1)one++;
			else if(mod==2)two++;
        }
    }

    ll ans=three;
    if(two==0){
        cout<<ans<<endl;
        return;
    }

    // while(one and two){
    //     ans++;
    //     two--;
    //     one--;
    // }
    ans += min(one, two);
    if(one<two){
        two -= one;
        two *=2;
        two/=3;
        ans += two;
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