#include<iostream>
#include<vector>
#include<set>
#include<climits>
#include<map>
#include<algorithm>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MIN INT_MIN

template<class T>
auto lower_bound_first(const set<pair<T, T> >&s, T first){
    static constexpr T min = std::numeric_limits<T>::min();
    return s.lower_bound({first, min});
}

template<class T>
auto upper_bound_first(const set<pair<T, T> >&s, T first){
    static constexpr T min = std::numeric_limits<T>::min();
    return s.upper_bound({first, min});
}

void solve(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }    

    set<pair<int, int> > len_of_seg;
    set<pair<int, int> > segments;

    int idx=0, len=1;
    for(int i=1; i<n; i++){
        if(arr[i] != arr[i-1]){
            len_of_seg.insert({-len, idx});
            segments.insert({idx, -len});
            idx=i;
            len=1;
        }
        else len++;
    }

    len_of_seg.insert({-len, idx});
    segments.insert({idx, -len});

    ll ans=0;
    while(!len_of_seg.empty()){
        ans++;
        pair<int, int> top = *len_of_seg.begin();
        len_of_seg.erase(len_of_seg.begin());
        int idx = top.second;
        int len = top.first;

        auto lower_seg = lower_bound_first(segments, idx); // this gives the itertator to ({idx, -len})
        auto upper_seg = upper_bound_first(segments, idx); // this gives the itertator to ({idx, -len})
        // cout<<(*lower_seg).first<<" "<<(*lower_seg).second<<endl;
        // cout<<(*upper_seg).first<<" "<<(*upper_seg).second<<endl;

        // now we check if lower_seg is segment.begin() or not (as lower seg point to ({idx, -len})),if its is begin(), means we dont have lowerr segment to this
        // we incrment upper_seg (as now it points to seg ({idx, -len})), and we want just upper seg of this so we first incremnt

        upper_seg++;
        if(lower_seg == segments.begin() || upper_seg == segments.end()){
            // means after del of prev segment there is no merging so we del the prev seg from segments set and continue
            segments.erase({idx, len});
        }
        else{
            lower_seg--;
            if(arr[(*lower_seg).first] == arr[(*upper_seg).first]){ // check whehter left and right segment of del semgmnted merged or not
                int new_len = (*lower_seg).second + (*upper_seg).second;
                int new_idx = (*lower_seg).first;

                // insert new segment formed after merging
                len_of_seg.insert({new_len, new_idx});
                segments.insert({new_idx, new_len});

                // del left and right segment of del segment as now they merged and form a new segment
                auto it = len_of_seg.find({lower_seg->second, lower_seg->first});
                if(it != len_of_seg.end()) len_of_seg.erase(it);

                it = len_of_seg.find({upper_seg->second, upper_seg->first});
                if(it != len_of_seg.end()) len_of_seg.erase(it);

                segments.erase(lower_seg);
                segments.erase(upper_seg);
            }

            segments.erase({idx, len}); // del prev segment from segments et
        }
    }
    cout<<ans<<endl;
    return;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}

// Link : https://stackoverflow.com/questions/55392781/how-to-use-lower-bound-on-set-of-pairs
/*
The core issue is that your std::set instance is already sorted, 
but with the default std::pair operator<. You cannot intuitively use the member function std::set::lower_bound, 
as this uses the comparison function of its class type. You can't use std::lower_bound with a custom predicate neither, 
as this assumes a sorted range - but sorted with respect to the given predicate, which is not the case.

But there is a workaround for this specific scenario. 
Note that for each value of x in the set, the minimal associated value of y is the minimal value of type int. 
As the comparison operator for std::pair instances does a member-wise comparison, you can combine this to:
*/