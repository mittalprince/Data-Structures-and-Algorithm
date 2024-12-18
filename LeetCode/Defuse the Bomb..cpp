// https://leetcode.com/problems/defuse-the-bomb/
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

vector<int> decrypt(vector<int>& code, int k) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n = code.size();
    vector<int>ans(n,0);

    for(int i=0; i<n; i++){
        if(k>0){
            for(int j=1; j<=k; j++){
                ans[i] += code[(i+j)%n];
            }        
        }
        else{
            for(int j=1; j<=abs(k); j++){
                ans[i] += code[(i-j+n)%n];
            }
        }
    }
    return ans;
}

int main(){

/*
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
*/

    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}