#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<cassert>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

class Pair{
    public:
    ll start, end, idx;

    Pair(ll s, ll e, ll i):start(s),end(e),idx(i){}
};

int main(){
    ll n;
    cin>>n;
    
    vector<Pair>arr;
    vector<ll>ans(n);

    for(int i=0; i<n; i++){
        ll start, end;
        cin>>start>>end;
        Pair t(start, end, i);
        arr.push_back(t);
    }

    sort(arr.begin(), arr.end(), [](const Pair &a, const Pair &b){
        return (a.end==b.end)? (a.start<b.start) : (a.end<b.end);

    });

    set<ll>taken_days;
    for(int i=0; i<n; i++){
        ll start = arr[i].start;
        while(taken_days.count(start)){
            start++;
        }

        assert(start <= arr[i].end);
        // cout << "enter\n";
        ans[arr[i].idx] = start;
        taken_days.insert(start);
    }

    for(int i: ans){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}