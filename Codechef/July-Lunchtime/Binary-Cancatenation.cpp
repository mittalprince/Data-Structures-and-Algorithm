// https://www.codechef.com/LTIME86B/problems/BINFUN
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
const int BIG = (int)(2e9 + 239);

const int M = (int)(2e5 + 239);
const int N = (int)(2e3 + 239);
const int L = 31;
const int T = (1 << 20) + 239;
const int B = 500;
const int X = 1e4 + 239;

int len(int x)
{
    int ans = 0;
    while (x)
    {
        x /= 2;
        ans++;
    }
    return ans;
}

int mn[L], mx[L], n;

void solve()
{
    cin >> n;
    for (int i = 0; i < L; i++)
    {
        mn[i] = BIG;
        mx[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        int l = len(a);
        mn[l] = min(mn[l], a);
        mx[l] = max(mx[l], a);
    }
    ll ans = 0;
    for (int i = 0; i < L; i++)
        for (int j = 0; j < L; j++)
            if (mx[i] != 0 && mx[j] != 0)
            {
                ll pi = (1 << i) - 1;
                ll pj = (1 << j) - 1;
                ans = max(ans, pj * (ll)mx[i] - pi * (ll)mn[j]);
            }
    cout << ans << "\n";
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