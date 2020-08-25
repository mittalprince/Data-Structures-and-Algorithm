// https://leetcode.com/problems/kth-smallest-number-in-multiplication-table/
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

bool check(int mid, int m, int n, int k){
    int ct=0;
    int ht=1, number=n;

    while(ht<=m and number>=1){
        if(ht*number<=mid){
            ct += number;
            ht++;
        }
        else number--;
    }

    return ct>=k;
}

int findKthNumber(int m, int n, int k) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int l=1, r=m*n;
    while(l<r){
        int mid = (l+r)/2;
        if(check(mid, m, n, k)){
            r=mid;
        }
        else l=mid+1;
    }
    return l;
}

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