// https://www.hackerearth.com/practice/math/number-theory/basic-number-theory-1/tutorial/
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

/*

Find the answer of ((A^B)/C)%M.

Input:
The only line of input consists of four integers A,B,C and M. The input always has C and M such that gcd(C,M)=1.

Output:
Print the answer as asked in the problem statement.
*/
ll binaryExponentiation(ll a, ll b, ll m){
    ll ans=1;
    while(b){
        if(b&1){
            ans *= a;
            ans %= m;
        }
        a *= a;
        a %= m;

        b >>= 1;
    }
    return ans;
}

void extendedEuclid(ll a, ll b, ll &x, ll &y, ll &d){
    if(b==0){
        x=1;
        y=0;
        d=a;
        return;
    }
    ll x1, y1;
    // ll ans = 
    extendedEuclid(b, a%b, x1, y1, d);
    x = y1;
    y = x1-(a/b)*y1;

    // return ans;
}

void helper(){
    int a,b,c,m;
    cin>>a>>b>>c>>m;
    ll x,y,d;
    extendedEuclid(c, m, x, y,d);
    ll ans1 = binaryExponentiation(a, b, m)%m;
    ll ans2 = (x%m+m)%m;
    ll ans = ((ans1%m)*(ans2%m))%m;
    cout<<ans<<endl;
}

ll gcd(ll a, ll b){
    if(b==0)return a;
    return gcd(b, a%b);
}

// The time complexity of the extended Euclidean algorithm is O(log(max(A,B))).
int eea(int a, int b, int &x, int &y){
    if(b==0){
        x=1, y=0;
        return a;
    }
    int x1,y1;
    int ans = eea(b, a%b, x1, y1);
    x = y1;
    y = x1-(a/b)*y1;
    cout<<x<<" "<<y<<endl;
    return ans;
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int a,b;
    cin>>a>>b;
    cout<<gcd(a,b)<<endl;
    int x,y;
    cout<<eea(a,b,x,y)<<endl;
    return 0;
}