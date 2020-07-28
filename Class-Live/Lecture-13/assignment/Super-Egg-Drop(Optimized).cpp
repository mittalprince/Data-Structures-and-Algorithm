#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

/* 
The key concept of the original O(KN^2) solution is to try all the floor to get the min-cost min(max(broke, not broke) for every floor) as the answer.
Original DP definition: I stand on nth floor and give me k eggs, the minimum times I try is dp[n][k]. This definition means the result of this problem is dp[N][K].

This solution is somehow a reverse thinking:
New DP definition: If you give me k egg, let me drop m times, I can try out maximum dp[m][k] floors. Based on this definition, the result is some m, which cases dp[m][K] equals N.

A move essentially is dropping an egg and it either breaks or doesn't break.
Case A: The egg breaks and now you have spent 1 move (M=M-1) and also lost 1 egg (K=K-1). You can still check dp[M-1][K-1] floors, with your remaining eggs and moves.
Case B: The egg remains and you only loose one move (M=M-1). You can still check dp[M-1][K] floors.
Additionally you just checked a floor by dropping the egg from it.
Therefore dp[M][K] = dp[M - 1][k - 1] + dp[M - 1][K] + 1
*/

int superEggDrop(int K, int N) {
    vector<vector<int> >dp(N+1, vector<int>(K+1, 0));
    int m=0;

    while(dp[m][K] < N){
        m++;
        for(int i=1; i<=K; i++){
            dp[m][i] = dp[m-1][i-1]+dp[m-1][i]+1;
        }
    }
    return m;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}