#include<iostream>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

ll n,k;

void solve(){
    if(n<k){
        cout<<"NO\n";
        return;
    }

    priority_queue<ll>pq;
    ll pos=0;
    while(n){
        if(n&1){
            pq.push((1<<pos));
        }
        pos++;
        n >>= 1;
    }

    while(!pq.empty() && pq.size()<k){
        if(pq.top() == 1){
            break;
        }
        ll top = pq.top();
        pq.pop();
        pq.push(top/2);
        pq.push(top/2);
    }

    if(pq.size()>k){
        cout<<"NO\n";
        return;
    }

    cout<<"YES\n";
    while(!pq.empty()){
        cout<<pq.top()<<" ";
        pq.pop();
    }
    cout<<endl;
}

int main(){
    cin>>n>>k;
    solve();
    return 0;
}