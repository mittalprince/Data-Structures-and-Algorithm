// https://leetcode.com/problems/closest-prime-numbers-in-range/
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

vector<int>p;
bool sieve[1000006] = {};

vector<int> closestPrimes(int left, int right) {
    if(p.empty()){
        for(long long i=2; i<1000005; i++){
            if(!sieve[i]){
                p.push_back(i);
                for(long long j=i*i;j<1000006; j+=i){
                    sieve[j]=true;
                }
            }
        }
    }

    int n1=-1,n2=-1, i =lower_bound(p.begin(), p.end(), left) - p.begin();
    for(; i+1<p.size() && p[i+1]<=right; i++){
        if(n1 == -1 || p[i+1]-p[i] < n2-n1){
            n1 = p[i];
            n2 = p[i+1];
            if(n2-n1 < 3)break; 
        }
    }
    return {n1, n2};
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