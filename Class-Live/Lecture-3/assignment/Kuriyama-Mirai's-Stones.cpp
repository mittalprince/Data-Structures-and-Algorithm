#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=1; i<=n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MAX 100005

void solve(){
    int n,m,type,l,r;
    cin >> n;
    ll arr[MAX] = {0}, a[MAX] = {0}, b[MAX] = {0};
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        a[i] += a[i-1]+arr[i];
    }
    sort(arr + 1, arr + n + 1);
    for (int i = 1; i <= n; i++)
    {
        b[i] += arr[i]+b[i-1];
    }
    cin >> m;
    while (m--)
    {
        cin >> type >> l >> r;
        if (type == 1)
        {
            cout << a[r] - a[l - 1] << endl;
        }
        else
        {
            cout << b[r] - b[l - 1] << endl;
        }
    }
}
int main(){
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
}