// https://www.geeksforgeeks.org/pair-with-largest-sum-which-is-less-than-k-in-the-array/
#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
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

int Max_Sum(int a[], int n, int k) {
    
    sort(a, a+n);
    
    int l=0, r=n-1, sm = a[l]+a[r], x, y, sm_max = -1 ;
    while(l<r) {
        
        sm = a[l]+a[r];
        if(sm<k) {
            if(sm>sm_max) {
                sm_max = sm;
                x=l;
                y=r;  
            }
            l++;
        }
        else {
            r--;
        }
    }
    cout<<sm_max<<" "<<x<<" "<<y;
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int arr[] = {5, 20, 110, 100, 10}, k = 85; 

    int n = sizeof(arr) / sizeof(arr[0]); 
      
    // Function call 
    Max_Sum(arr, n, k); 
    
    return 0;
}