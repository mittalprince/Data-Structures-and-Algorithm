// https://www.interviewbit.com/problems/find-duplicate-in-array/
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

int repeatedNumber(const vector<int> &A) {
    int n=A.size();
    bool arr[n];
    for(int i=0; i<n; i++){
        arr[i] = false;
    }
    for(int i=0; i<n; i++){
        if(arr[A[i]] == false){
            arr[A[i]] = true;
        }
        else{
            return A[i];
        }
    }
    
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