#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MAX 100005

class Pair{
    public:
    ll freq, idx, val;

    Pair():freq(0),idx(0),val(0){}
};

bool comp(Pair a, Pair b){
    if(a.freq == b.freq){
        return a.idx<b.idx;
    }
    return a.freq>b.freq;
}

int main(){
    ll n,m,temp;
    cin>>n>>m;
    Pair arr[MAX];
    for(ll i=0; i<n; i++){
        cin>>temp;
        if(arr[temp].freq == 0){
            arr[temp].freq=1;
            arr[temp].val=temp;
            arr[temp].idx = i;
        }
        else arr[temp].freq++;
    }

    sort(arr, arr+n, comp);
    for(int i=0; i<n; i++){
        for(int j=0; j<arr[i].freq; j++){
            cout<<arr[i].val<<" ";
        }
    }
    cout<<endl;
    return 0;
}