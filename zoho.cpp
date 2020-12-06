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

int ceil(float n){
    if((1-n)<(n))return 1;
    return 0;
}

int pow(int a, int b){
    int ans=1;
    while(b){
        if(b&1){
            ans *= a;
        }
        a *= a;
        b >>= 1;
    }
    return ans;
}

void solve(){
    string s;
    cin>>s;
    int n=s.length();
    int ans=0;
    float t=0;
    int i=0;
    bool postive=true;
    if(s[i] == '-' or s[i]=='+'){
        if(s[i]=='-')postive=false;
        i++;
    }

    while(i<n and s[i]=='0')i++;

    if(s[i]<'1' or s[i]>'9'){ 
        cout<<"Error\n";
        return;
    }

    while(i<n and s[i]>='0' and s[i]<='9'){
        ans *= 10;
        ans += s[i]-'0';
        i++;
    }

    if(s[i]=='.'){
        i++;
        int divisor=0;
        while(i<n and s[i]>='0' and s[i]<='9'){
            t *= 10;
            t += s[i]-'0';
            i++;
            divisor++;
        }
        t /= pow(10, divisor);
    }
    t = ceil(t);
    ans += t;
    
    if(!postive){
        ans *= -1;
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

// complxity -> O(n);