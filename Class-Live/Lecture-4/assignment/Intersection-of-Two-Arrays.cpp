#include<iostream>
#include<vector>
#include<map>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    map<int, bool> m;
    for(auto i: nums1){
        m[i]=true;
    }
    vector<int>ans;
    for(auto i: nums2){
        if(m[i]) {
            ans.push_back(i);
            m[i]=false;
        }
    }
    return ans;
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<int> arr1(n), arr2(m);
    ip(arr1, n);
    ip(arr2, m);

    vector<int> res = intersection(arr1, arr2);
    op(res, res.size());
    return 0;
}