//https://leetcode.com/problems/maximize-distance-to-closest-person/
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

int maxDistToClosest(vector<int>& seats) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int mx=0, ct=0;
    bool flag=true;

    for(int i: seats){
        if(i==0){
            ct++;
        }
        else{
            if(flag){
                mx = max(mx, ct);
            }
            else{
                mx = max(mx, (ct+1)/2);
            }
            ct=0;
            flag=false;
        }
    }
    mx = max(mx, ct);
    return mx;
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