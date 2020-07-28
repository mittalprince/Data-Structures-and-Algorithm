#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

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
    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}