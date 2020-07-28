#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MAX 100005

ll dp[MAX];
/*
Logic: if every ith element i, I have total (n-1) choices to place it, as I can't place it on its correct possition so all (n-1) pos are incorrect
now there are now two possibilities, assume I place ith item to jth item
1. jth item also place at ith, so now total rem dearangement exist is (n-2), so call on f(n-2)
2. jth item place some ohte index, but dont know on which index, so now total rem dearrangement exsist is (n-1), 
   as now I am sure only for ith item, which I placed on jth, but dont know aboyt jth item, so call on f(n-1)  
*/

ll solve(int n){
    if(n<0) return 0;

    if(dp[n] != -1) return dp[n];

    dp[n] = (n-1)*(solve(n-1)+solve(n-2));
    return dp[n];
}

int main(){
    int t;
    cin>>t;
    memset(dp, -1, sizeof(dp));
    dp[0]=1, dp[1]=0;
    solve(100000);
     while(t--){
        int n;
        cin>>n;
        cout<<dp[n]<<endl;
    }
    return 0;
}