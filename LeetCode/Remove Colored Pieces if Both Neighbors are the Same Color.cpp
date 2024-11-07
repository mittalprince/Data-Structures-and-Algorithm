// https://leetcode.com/problems/remove-colored-pieces-if-both-neighbors-are-the-same-color/
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

bool winnerOfGame(string colors) {
    int n = colors.size();
    int a=0, b=0;
    for(int i=0; i<n; ){
        int j=i;
        while(j<n && colors[i]==colors[j])j++;
        if(colors[i]=='A') a += max(0, j-i-2);
        else b += max(0, j-i-2);
        i = j;
    }
    return a>b;
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