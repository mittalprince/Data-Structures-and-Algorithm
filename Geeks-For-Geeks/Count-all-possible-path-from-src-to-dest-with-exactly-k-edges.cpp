// https://practice.geeksforgeeks.org/problems/possible-paths/0
#include<iostream>
#include<vector>
using namespace std;
#define MAX 25

int main(){
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int dp[MAX][MAX][MAX]={0};
	    int adj[MAX][MAX]={0};
	    
	    for(int i=0; i<n; i++){
	        for(int j=0; j<n; j++){
	            cin>>adj[i][j];
	        }
	    }
	    
	    int src, dest, k;
	    cin>>src>>dest>>k;
	    
	    for(int e=0; e<=k; e++){
	        for(int i=0; i<n; i++){
	            for(int j=0; j<n; j++){
	                if(e==0 and i==j){
	                    dp[i][j][e]=1;
	                }
	                if(e==1 and adj[i][j]){
	                    dp[i][j][e]=1;
	                }
	                if(e>1){
	                    for(int a=0; a<n; a++){
	                        if(adj[i][a]){
	                            dp[i][j][e] += dp[a][j][e-1];
	                        }
	                    }
	                }
	            }
	        }
	    }
	    cout<<dp[src][dest][k]<<endl;
	}
	return 0;
}