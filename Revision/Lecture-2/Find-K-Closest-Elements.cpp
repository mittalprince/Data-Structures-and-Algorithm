// https://leetcode.com/problems/find-k-closest-elements/
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
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

vector<int> findClosestElements(vector<int>& arr, int k, int x) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int l,r;
    r = lower_bound(arr.begin(), arr.end(), x)-arr.begin();
    l=r-1;

    while(k--){
        if(l<0 or (r != arr.size() and arr[r]-x< x-arr[l])){
            r++;
        }
        else l--;
    }
    vector<int>ans;
    for(int i=l+1; i<r; i++){
        ans.push_back(arr[i]);
    }
    return ans;
    /*
    priority_queue<pair<int, int>>pq;

    int n=arr.size();
    for(int i=0; i<n; i++){
        if(i<k){
            pq.push({abs(x-arr[i]), arr[i]});
        }    
        else{
            if(pq.top().first>abs(x-arr[i])){
                pq.pop();
                pq.push({abs(x-arr[i]), arr[i]});
            }
            else if(pq.top().first == abs(x-arr[i]) and pq.top().second>arr[i]){
                pq.pop();
                pq.push({abs(x-arr[i]), arr[i]});
            }
        }
    }
    vector<int>ans;
    while(k--){
        ans.push_back(pq.top().second);
        pq.pop();
    }
    sort(ans.begin(), ans.end());
    return ans;
    */
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