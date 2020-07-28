// https://codeforces.com/contest/1372/problem/C
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

/*
Trick: the max val of reshuffling will be 2
So we first check if arr is sorted in any or not
if yes and its incresingly sorted then ans will be 0
and if decreasingly then ans will be 1

When arr is not sorted then we find the very first segment where the no are not its correct pos
from both end

like 1 2 4 6 5 3 7 so we need to check 4 6 5 3 still 5 is on correct pos

Now here we check if any no in the above selected arr is its correct pos or not if yes means 
here we have more than 1 seg where no are not sorted like 4,6 and 3 so we first chnage 5 to it pos and
then normally sort the arr in one move so total move req is 2.

otherwise if no element is it correct pos then ans will be 1 as we just need to sort in one move
*/
void solve(){
    int n;
    cin>>n;
    vector<int>arr(n);
    ip(arr, n);

    int i=0, j=n-1;
    while(i<n and arr[i] == i+1)i++;
    while(j>=0 and arr[j] == j+1)j--;

    if(i==n){
        cout<<0<<endl;
        return;
    }
    if(j==0){
        cout<<1<<endl;
        return;
    }

    while(i<=j){
        if(arr[i] == i+1){
            cout<<2<<endl;
            return;
        }
        i++;
    }
    cout<<1<<endl;
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}