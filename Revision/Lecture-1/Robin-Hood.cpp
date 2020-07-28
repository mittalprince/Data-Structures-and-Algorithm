#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MOD 1000000007
#define MAX 5000005

ll n,k;
ll arr[MAX];

bool canMakeMax(ll mid){
    ll greater_diff=0, lesser_diff=0;
    for(int i=0; i<n; i++){
        if(arr[i]>mid){
            greater_diff += arr[i]-mid;
        }
        else lesser_diff += mid-arr[i];
    }

    return (greater_diff<=k && lesser_diff>=greater_diff);
}

bool canMakeMin(ll mid){
    ll greater_diff=0, lesser_diff=0;
    for(int i=0; i<n; i++){
        if(arr[i]<mid){
            lesser_diff += mid-arr[i];
        }
        else greater_diff += arr[i]-mid;
    }

    return (lesser_diff<=k && lesser_diff<=greater_diff);
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    cin>>n>>k;
    ip(arr, n);
    
    sort(arr, arr+n);
    ll MX = arr[n-1], MI = arr[0];

    ll s=arr[0], e=arr[n-1];
    while(s<=e){
        ll mid =(s+e)/2;
        if(canMakeMax(mid)){
            MX=mid;
            e=mid-1;
        }
        else s=mid+1;
    }

    s=arr[0], e=arr[n-1];
    while(s<=e){
        ll mid = (s+e)/2;
        if(canMakeMin(mid)){
            MI=mid;
            s=mid+1;
        }
        else e=mid-1;
    }
    cout<<MX-MI<<endl;
    return 0;
}