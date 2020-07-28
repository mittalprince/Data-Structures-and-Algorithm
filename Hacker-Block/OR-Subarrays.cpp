#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MOD 1000000007

ll n, sum=0;
ll *arr;

void solve(){

    for(int i=0; i<n; i++){
        ll sum1=0;
        for(int j=i; j<n; j++){
            sum1 = (sum1|arr[j]);
            sum += sum1;
        }
    }
    cout<<sum<<endl;
}
int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    cin>>n;
    arr = new ll[n];

    ip(arr,n);
    solve(); 
    
    return 0;
}