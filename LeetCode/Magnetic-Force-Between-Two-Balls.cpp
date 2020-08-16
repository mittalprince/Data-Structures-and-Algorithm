// https://leetcode.com/problems/magnetic-force-between-two-balls/
#include<iostream>
#include<vector>
#include<algorithm>
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

bool canPlace(vector<int>&pos, int mid, int m){
    int placed=0;
    long long t=0;
    for(int i: pos){
        if(i>=t){
            placed++;
            t = i+mid;
        }
        if(placed>=m)return true;
    }
    return false;
}

int maxDistance(vector<int>& position, int m) {
    int n=position.size();
    sort(position.begin(), position.end());
    int s=0, e=(int)1e9;
    int ans;
    while(s<=e){
        int mid = (s+e)/2;
        if(canPlace(position, mid, m)){
            ans=mid;
            s=mid+1;
        }
        else e=mid-1;
    }
    return ans;
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