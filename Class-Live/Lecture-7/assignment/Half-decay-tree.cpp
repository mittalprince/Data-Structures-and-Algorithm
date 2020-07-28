#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>
#include<climits>
#include<map>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
map<ll, ll>m;
ll H;

double halfDecay(ll root, ll h, ll potential){
    if(h == H){
        return max(m[root], potential);
    }
    if(potential >= m[root]) return potential;

    int left = 2*root;
    int right = left+1;

    return 0.5*(halfDecay(left, h+1, max(m[root]-m[left], potential))+halfDecay(right, h+1, max(m[root]-m[right], potential)));
}
void solve(){
    cin>>H;
    ll q;
    cin>>q;

    while(q--){
        string type;
        cin>>type;
        if(type == "add"){
            ll node, charge;
            cin>>node>>charge;
            while(node>0){
                m[node] += charge;
                node /= 2;
            }
        }
        else{
            cout<<fixed<<setprecision(10)<<halfDecay(1, 0, 0)<<endl;
        }

    }
}

int main(){
    solve();
}