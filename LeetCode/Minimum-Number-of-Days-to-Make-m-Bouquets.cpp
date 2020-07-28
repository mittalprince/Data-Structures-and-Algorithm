#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define debug(x) cout<<x<<"\n";
#define inf 1e9
#define INF 1e16
#define MOD 1000000007

bool isValid(vector<int>&arr, int m, int k, int days){
    int currCount=0;
    for(int i: arr){
        if(i<=days){
            currCount++;
        }
        else{
            currCount=0;
        }
        if(currCount==k){
            m--;
            currCount=0;
            if(m<=0)return true;
        }
    }
    return false;
}

int minDays(vector<int>& bloomDay, int m, int k){
    int n=bloomDay.size();

    if(n==0 || m==0 || k==0)return 0;
    if(m*k > n)return -1;

    int l=inf, r=-inf;
    for(int i: bloomDay){
        l = min(l, i);
        r = max(r, i);
    }

    while(l<=r){
        int mid = (l+r)/2;
        if(isValid(bloomDay, m, k, mid)){
            r=mid-1;
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