// https://leetcode.com/problems/orderly-queue/
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

string orderlyQueue(string& S, int k) {
    if(k==1){
        string ans=S;
        for(int i=0; i<S.length(); i++){
            string temp = S.substr(i)+ S.substr(0, i);
            if(temp.compare(ans) < 0) ans=temp;
        }
        return ans;
    }
    else{
        sort(S.begin(), S.end());
    }
    return S;
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