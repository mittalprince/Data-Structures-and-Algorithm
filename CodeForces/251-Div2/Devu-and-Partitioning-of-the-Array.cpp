// https://codeforces.com/contest/439/problem/C
#include<iostream>
#include<vector>
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

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int n,k,p;
    cin>>n>>k>>p;
    vector<int>odd, even;
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        if(x&1) odd.push_back(x);
        else even.push_back(x);
    }
    int odd_set = k-p;
    int odd_size = odd.size();
    int extra_odd_size = odd_size-odd_set;
    int even_size=even.size()+(extra_odd_size/2);
    int e=even.size(), o=odd.size();

    if((extra_odd_size%2==0) and (odd_set<=odd_size) and (even_size >= p)){
        cout<<"YES\n";
        int i=0;

        for(; i<p and i<k-1 and e>0; i++){
            cout<<"1 "<<even[--e]<<endl;
        }

        for(; i<k-1 and i<p and o>1; i++, o-=2){
            cout<<"2 "<<odd[o-1]<<" "<<odd[o-2]<<endl;
        }

        for(; i<k-1; i++){
            cout<<"1 "<<odd[--o]<<endl;
        }
        cout<<(o+e)<<" ";
        while(o){
            cout<<odd[--o]<<" ";
        }
        while(e){
            cout<<even[--e]<<" ";
        }
    }
    else{
        cout<<"NO\n";
    }
    return 0;
}