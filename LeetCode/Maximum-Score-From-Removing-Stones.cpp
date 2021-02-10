//https://leetcode.com/problems/maximum-score-from-removing-stones/
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

int maximumScore(int a, int b, int c) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int arr[3] = {a,b,c};
    sort(arr, arr+3);

    int sum1 = arr[0]+arr[1];
    int sum2 = arr[2];

    if(sum2 <= sum1){
        return (sum1+sum2)/2;
    }
    return sum1;
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