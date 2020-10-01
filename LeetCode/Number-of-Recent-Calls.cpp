// https://leetcode.com/problems/number-of-recent-calls/
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

class RecentCounter {
public:
    vector<int> v;
    int l,r;
    
    RecentCounter() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        v.resize(10000);
        l=0, r=0;
    }
    
    int ping(int t) {
        v[r++]=t;
        while(v[l]<t-3000){
            l++;
        }
        return r-l;
    }
};

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}