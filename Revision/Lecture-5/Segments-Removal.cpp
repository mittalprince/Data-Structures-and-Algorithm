// https://codeforces.com/contest/899/problem/E
#include<iostream>
#include<vector>
#include<set>
#include<iterator>
#include<climits>
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
    int n;
    cin>>n;
    int arr[n];
    ip(arr, n);

    set<pair<int, int> >len_of_seg, segments;
    int len=1, idx=0;
    for(int i=1; i<n; i++){
        if(arr[i]!=arr[i-1]){
            len_of_seg.insert({-len, idx});
            segments.insert({idx, -len});
            len=1;
            idx=i;
        }
        else len++;
    }
    len_of_seg.insert({-len, idx});
    segments.insert({idx, -len});

    int ans=0;

    while(!len_of_seg.empty()){
        ans++;

        pair<int, int>begin = *len_of_seg.begin();
        len_of_seg.erase(len_of_seg.begin());
        int idx=begin.second;
        int len=begin.first;

        set<pair<int, int> >::iterator ls = segments.find({idx, len});
        set<pair<int, int> >::iterator us = segments.find({idx, len});
        us++;
        if(ls==segments.begin() or us == segments.end()){
            segments.erase(ls);
        }
        else{
            ls--;
            if(arr[(*ls).first]==arr[(*us).first]){
                int new_len = (*ls).second + (*us).second;
                int new_idx = (*ls).first;

                len_of_seg.insert({new_len, new_idx});
                segments.insert({new_idx, new_len});

                set<pair<int, int>>::iterator it1 = len_of_seg.find({ls->second, ls->first});
                if(it1!=len_of_seg.end())len_of_seg.erase(it1);

                set<pair<int, int>>::iterator it2 = len_of_seg.find({us->second, us->first});
                if(it2!=len_of_seg.end())len_of_seg.erase(it2);

                segments.erase(ls);
                segments.erase(us);

            }
            
            segments.erase({idx, len});
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