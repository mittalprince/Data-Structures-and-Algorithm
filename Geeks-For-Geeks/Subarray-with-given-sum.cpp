// https://practice.geeksforgeeks.org/problems/subarray-with-given-sum/0/
#include<iostream>
#include<vector>
using namespace std;

vector<int> solve(int arr[], int target, int n){
    int curr_sum=arr[0], start=0;
    vector<int>ans;
    
    for(int i=1; i<=n; i++){
        while(curr_sum>target and start<i-1){
            curr_sum -= arr[start++];
        }
        if(curr_sum == target){
            ans.push_back(start);
            ans.push_back(i-1);
            return ans;
        }
        if(i<n){
            curr_sum += arr[i];
        }
    }
    return ans;
}

int main(){
	int t;
	cin>>t;
	while(t--){
	    int n, target;
	    cin>>n>>target;
	    int arr[n];
	    for(int i=0; i<n; i++){
	        cin>>arr[i];
	    }
	    
	    vector<int>ans = solve(arr, target, n);
	    if(ans.empty()){
	        cout<<"-1\n";
	    }
	    else{
	        for(int i: ans){
	            cout<<i+1<<" ";
	        }
	        cout<<endl;
	    }
	}
	return 0;
}