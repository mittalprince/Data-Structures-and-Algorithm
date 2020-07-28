// Proble Link : https://practice.geeksforgeeks.org/problems/shortest-path-from-1-to-n/0
#include <iostream>
using namespace std;

int main() {
    int test,ver,count=0;
    cin >> test;
    while(test--){
        cin >> ver;
        int dp[ver];
        for(int i=0;i<ver;i++){
            dp[i]=0;
        }
        dp[1]=1;
        dp[2]=1;
        dp[3]=1;
        for(int i=4;i<=ver;i++){
            if(i%3 == 0){
                dp[i]=min(dp[i/3]+1,dp[i-1]+1);
            }else{
                dp[i]=dp[i-1]+1;
            }
        }
        /*for(int i=1;i<=ver;i++){
         cout << dp[i]<<" ";
        }
        cout <<"\n";*/
        cout << dp[ver]<<"\n";
    }
	return 0;
}