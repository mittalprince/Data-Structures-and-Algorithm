// https://codeforces.com/contest/600/problem/B
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MOD 1000000007

int n, m;
vector<int>arr, brr;

vector<int> solve(){
    vector<int>ans;

    for(int i=0; i<m; i++){
        int s=0, e=n-1;
        int idx=-1;
        while(s<=e){
            int mid = (s+e)/2;
            if(arr[mid]<=brr[i]){
                idx=mid;
                s=mid+1;
            }
            else e=mid-1;
        }
        ans.push_back(idx+1);
    }
    return ans;
}

vector<int> Solve(){
    vector<int>ans;
    for(int i=0; i<m; i++){
        int idx = upper_bound(arr.begin(), arr.end(), brr[i])-arr.begin();
        ans.push_back(idx);
    }
    return ans;
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    cin>>n>>m;

    arr = vector<int>(n);
    brr = vector<int>(m);

    ip(arr, n);
    ip(brr, m);
    
    sort(arr.begin(), arr.end());
    vector<int>ans = Solve();
    for(int i: ans){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}