// https://www.interviewbit.com/problems/balance-array/
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

// int solve(vector<int> &A) {
//     int n=A.size();
//     vector<int>prefix(n, 0);
    
//     prefix[0]=A[0];
//     prefix[1]=A[1];
    
//     for(int i=2; i<n; i++){
//         prefix[i] = prefix[i-2]+A[i];
//     }
    
//     int oddTotalSum=0, evenTotalSum=0;
//     if(n&1){
//         oddTotalSum = prefix[n-2];
//         evenTotalSum = prefix[n-1];
//     }
//     else{
//         oddTotalSum = prefix[n-1];
//         evenTotalSum = prefix[n-2];
//     }
    
//     int ans=0;
//     int prev, evenSum=0, oddSum=0;
//     for(int i=0; i<n; i++){
//         if(i==0)prev=0;
//         else prev = prefix[i-1];
        
//         if(i&1){
//             evenSum = prev+(oddTotalSum-prefix[i]);
//             oddSum = prefix[i] + (evenTotalSum-prev) - A[i];   
//         }
//         else{
//             oddSum = prev+(evenTotalSum-prefix[i]);
//             evenSum = prefix[i] + (oddTotalSum-prev) - A[i];
//         }
        
//         if(evenSum == oddSum)ans++;
//     }
    
//     return ans;
// }

int solve(vector<int> &A){
    int n = A.size();
    int odd = 0, even = 0;
    int leftOdd[n], rightOdd[n];
    int leftEven[n], rightEven[n];
    for(int i = 0;i < n; i++){
        leftOdd[i] = odd;
        leftEven[i] = even;
        if(i%2 == 0)
            even += A[i];
        else
            odd += A[i];
    }
    odd = 0;
    even = 0;
    for(int i = n-1; i >= 0; i--){
        rightOdd[i] = odd;
        rightEven[i] = even;
        if(i%2 == 0)
            even += A[i];
        else
            odd += A[i];
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(leftOdd[i] + rightEven[i] == leftEven[i] + rightOdd[i]){
            ans++;
        }
    }
    return ans;
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int n;
    cin>>n;
    vector<int> arr(n);
    ip(arr, n);
    cout<<solve(arr)<<endl;
    return 0;
}