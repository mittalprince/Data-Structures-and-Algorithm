//https://leetcode.com/problems/happy-number/
#include<iostream>
#include<vector>
#include<unordered_map>
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

bool isHappy(int n) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if(n==0) return false;
    if(n==1) return 1;

    unordered_map<int, int>m;
    while(n){
        int temp=0;
        while(n){
            temp += (n%10)*(n%10);
            n = n/10;
        }
        if(temp==1) return true;
        if(m[temp]) return false;
        m[temp]=true;
        n=temp;
    }
    return false;
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