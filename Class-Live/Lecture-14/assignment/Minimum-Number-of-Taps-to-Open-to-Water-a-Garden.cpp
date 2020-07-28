#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

// optimized
int minTaps(int n, vector<int>& ranges) {
    vector<pair<int, int>>vec;
    for(int i=0; i<=n; i++){
        vec.push_back({i-ranges[i], i+ranges[i]}); // create ranges
    }

    sort(vec.begin(), vec.end());

    int res=0; // min interval req
    int cur=0; // curr_location or pos of garden
    int l=0; // max_dist that i can covered
    int index=0; // denote prev kis loction tak ki tap ko consider kar chuka hoo 

    while(cur<n){
        // pick all tap whose ranges starting <= curr_location, and 
        // then find the max right dist that i can cover using tap range
        for(int j=index; j<ranges.size() && vec[j].first<=cur; j++){
            if(l<vec[j].second){
                l=vec[j].second;
                index=j;
            }
        }
        // if max_dist that I cover is than the curr pos (i,e i cant reach at curr loc)
        // return -1;
        if(l <= cur) return -1;
        cur = l;
        res++;
    }

    return res;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}