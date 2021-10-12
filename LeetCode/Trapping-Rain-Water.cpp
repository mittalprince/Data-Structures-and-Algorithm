#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

// Brute force
int trap(vector<int>& height) {
    int n=height.size();
    if(n==0) return 0;
    int left[n], right[n];
    left[0]=height[0];
    for(int i=1; i<n; i++){
        left[i] = max(left[i-1], height[i]);
    }
    right[n-1]=height[n-1];
    for(int i=n-2; i>=0; i--){
        right[i] = max(right[i+1], height[i]);
    }
    int ans=0;
    for(int i=0; i<n; i++){
        ans += min(left[i], right[i])-height[i];
    }
    return ans;
}

int trap(vector<int>& height) {
    int n=height.size();
    if(n==0) return 0;
    int ans=0;

    int l=0, r=n-1, left_max=0, right_max=0;

    while(l<=r){
        if(height[l]<=height[r]){
            if(height[l]>=left_max){
                left_max=height[l];
            }
            else{
                ans += left_max-height[l];
            }
            l++;
        }
        else{
            if(height[r]>=right_max){
                right_max=height[r];
            }
            else{
                ans += right_max-height[r];
            }
            r--;    
        }
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}