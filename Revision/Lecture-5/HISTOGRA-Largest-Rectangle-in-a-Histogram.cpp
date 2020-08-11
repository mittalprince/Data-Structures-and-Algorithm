// https://www.spoj.com/problems/HISTOGRA/
#include<iostream>
#include<vector>
#include<stack>
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

int n;
int *arr;

void solve(){
    stack<ll>s;
    ll area=0;
    int i;
    for(i=0; i<n;){
        if(!s.empty() and arr[i]<=arr[s.top()]){
            ll ht = arr[s.top()];
            s.pop();
            if(s.empty()){
                area = max(area, ht*i);
            }
            else{
                area = max(area, ht*(i-s.top()-1));
            }
        }
        else s.push(i++);
    }

    while(!s.empty()){
        ll ht = arr[s.top()];
        s.pop();
        if(s.empty()){
            area = max(area, ht*i);
        }
        else{
            area = max(area, ht*(i-s.top()-1));
        }
    }
    cout<<area<<endl;
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    cin>>n;
    while(n){
        arr = new int[n];
        ip(arr, n);
        solve();
        cin>>n;
    }
    return 0;
}