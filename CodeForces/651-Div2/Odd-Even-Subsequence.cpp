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

/*
Logic: Used Binary Search
we apply BS on cost and check if we can make a subseqence with this min cost (mid), if 
this is possible we save it and check for min cost, so dec range and move left
otehrwise move right

In inPossible we check for both means if all value at odd pos in subseq are less then this mid or not
as in final we have to take min(odd_indices_val, even) so we check first for odd places then for even places.
If we can make subseq of length atleast k with max val as mid then this mid can be ans.
*/

bool isPossible(vector<int>arr, int n, int k, int max_cost){
    bool flag=0;
    int len=0;
    // first we try to place element and odd indexes which has val <=k, if yes we can add it into
    // subseq and change the flag and incrment the len
    // for even we need not to check for val<=k condition as in final we have to take min of 
    // max_of_odd_indices_val or max_of_even_indices_val, so we just add no into even place and incremennt len
    for(int i=0; i<n; i++){
        if(!flag){ // if flag=0, means even indices val
            len++;
            flag = !flag;
        }
        else{
            if(arr[i]<=max_cost){ // if less then max_cost then add into subseq
                len++;
                flag = !flag; // flip the flag
            }
        }
    }
    if(len>=k)return true; // if we can subseq of len atleast k with min cost mid then return true
    flag=1; // otherwise repeat the same process by consider even indices
    len=0;
    for(int i=0; i<n; i++){
        if(!flag){
            len++;
            flag = !flag;
        }
        else{
            if(arr[i]<=max_cost){
                len++;
                flag = !flag;
            }
        }
    }
    return (len>=k);
}

void solve(){
    int n,k;
    cin>>n>>k;
    vector<int>arr(n);
    ip(arr, n);

    int s=0, e=inf;
    int ans;
    while(s<=e){
        int mid = s+(e-s)/2;
        if(isPossible(arr, n, k, mid)){
            ans=mid;
            e=mid-1;
        }
        else s=mid+1;
    }
    cout<<ans<<endl;
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}