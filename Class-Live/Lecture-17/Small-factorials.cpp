// Small factorials
#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

void multiply(int a[], int no, ll &digits){
    int carry=0;
    for(ll i=0; i<digits; i++){
        ll val = a[i]*no + carry;
        a[i] = val%10;
        carry = val/10;
    }

    while(carry){
        a[digits] = carry%10;
        carry /= 10;
        digits++;
    }
}

void solve(int n){
    int a[100001]={0};
    ll digits=1;
    a[0]=1;

    for(int i=2; i<=n; i++){
        multiply(a, i, digits);
    }

    for(int i=digits-1; i>=0; i--){
        cout<<a[i];
    }
    cout<<endl;

}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        solve(n);
    }
    return 0;
}