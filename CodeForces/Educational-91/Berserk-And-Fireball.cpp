// https://codeforces.com/contest/1380/problem/D
#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
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
    ll n,m;
    cin>>n>>m;
    ll x,y,k;
    cin>>x>>k>>y;

    vector<ll>arr(n), brr(m);
    ip(arr, n);
    ip(brr, m);

    if(n==m){
        if(arr==brr){
            cout<<0<<endl;
            return;
        }
        else{
            cout<<-1<<endl;
            return;
        }
    }

    vector<ll>pos;
    ll j=0;
    for(ll i=0; i<n; i++){
        if(arr[i] == brr[j]){
            pos.push_back(i);
            j++;
            if(j==m)break;
        }
    }

    if(j < m){
        cout<<-1<<endl;
        return;
    }

    ll ans=0;

    for(ll i=0; i<pos.size(); i++){
        ll l,r;
        if(i==0)l=0;
        else l=pos[i-1]+1;
        r = pos[i]-1;

        bool beforeSeg = false, afterSeg = false; // store whether there is any greater elemnt before or after the seg, as if we need we can use Berserk power
        if(l<=r){
            ll segLen = r-l+1;
            ll mxE = *max_element(arr.begin()+l, arr.begin()+r+1);
            if(l>0 and arr[l-1]>mxE)beforeSeg=true;
            if(r<n-1 and arr[r+1]>mxE)afterSeg=true;

            if(segLen<k and !beforeSeg and !afterSeg){ // since segLen <k we cant use Fireball and since the max element
                // of seg is > just before the seg elemnt and just after seg element so we can't use Berserk since it will del req element, so ans dont exist.
                cout<<"-1\n";
                return;
            }

            if(segLen%k){
                ans += (segLen%k)*y;
                segLen -= (segLen%k);
            }

            // now segLen is multiple of k
            if(y*k >= x){ // here the cost to del whole seg is less as to del element one by one
                ans += (segLen/k)*x;
            }
            else if(beforeSeg or afterSeg){// means cost to del one by one element is less as to del whole seg
                // but for to use berserk we check whether there is greter element to max of segment just before or after the seg or not, if yes we use y
                ans += (segLen*y);
            }
            else{// yha hum jitne sare bade element hai unn par phela berserk use karnege then unko k len ki seg mein lake fireball se sabko del kar denge
                ans += (segLen-k)*y+x;
            }
        }
    }

    ll l = pos[pos.size()-1]+1;
    ll r = n-1;
    bool beforeSeg = false, afterSeg = false; // store whether there is any greater elemnt before or after the seg, as if we need we can use Berserk power
    if(l<=r){
        
        ll segLen = r-l+1;
        ll mxE = *max_element(arr.begin()+l, arr.begin()+r+1);
        if(l>0 and arr[l-1]>mxE)beforeSeg=true;
        if(r<n-1 and arr[r+1]>mxE)afterSeg=true;

        if(segLen<k and !beforeSeg and !afterSeg){ // since segLen <k we cant use Fireball and since the max element
            // of seg is > just before the seg elemnt and just after seg element so we can't use Berserk since it will del req element, so ans dont exist.
            cout<<"-1\n";
            return;
        }

        if(segLen%k){
            ans += (segLen%k)*y;
            segLen -= (segLen%k);
        }

        // now segLen is multiple of k
        if(y*k >= x){ // here the cost to del whole seg is less as to del element one by one
            ans += (segLen/k)*x;
        }
        else if(beforeSeg or afterSeg){// means cost to del one by one element is less as to del whole seg
            // but for to use berserk we check whether there is greter element to max of segment just before or after the seg or not, if yes we use y
            ans += (segLen*y);
        }
        else{// yha hum jitne sare bade element hai unn par phela berserk use karnege then unko k len ki seg mein lake fireball se sabko del kar denge
            ans += (segLen-k)*y+x;
        }
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