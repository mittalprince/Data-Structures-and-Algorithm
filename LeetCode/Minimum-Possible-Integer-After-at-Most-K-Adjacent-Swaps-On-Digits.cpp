// https://leetcode.com/problems/minimum-possible-integer-after-at-most-k-adjacent-swaps-on-digits/
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

// TLE dega optimized ka code clear nahi hua

string minInteger(string num, int k) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string a = num;
    int n = num.length();

    string t=num;
    sort(t.begin(), t.end());

    for(int i=0; i<n-1 and k>0; i++){
        int pos=i,j;
        for(int j=i+1; j<n; j++){
            if(j-i>k)break;
            if(a[j]<a[pos])pos=j;
        }
        for(j=pos; j>i; j--){
            swap(a[j], a[j-1]);
        }

        k -= pos-i;
        if(t==a){
            return a;
        }
    }

    return a;
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