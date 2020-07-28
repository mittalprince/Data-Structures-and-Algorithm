#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

/*
subproblem1:
get the largest k numbers when keeping the relative order

subproblem2:
merge two arrays which are from subproblem1.

subproblem3:
compare two arrays.
*/

bool compareTwoArrays(vector<int>&nums1, vector<int>&nums2, int startIdx1, int startIdx2){
    int len1 = nums1.size() - startIdx1;
    if(len1 <= 0) return false;

    int len2 = nums2.size() - startIdx2;
    if(len2 <= 0) return true;

    int len = max(len1, len2);
    for(int i = 0; i< len; i++) {
        int digit1 = startIdx1 + i < nums1.size() ? nums1[startIdx1 + i] : 0;
        int digit2 = startIdx2 + i < nums2.size() ? nums2[startIdx2 + i] : 0;
        if(digit1 != digit2){
            return digit1 > digit2;
        }
    }
    return true;
}

vector<int> mergeTwoArrays(vector<int>&nums1, vector<int>&nums2, int k){
    int i=0,j=0, idx=0;
    vector<int>res(k);

    while(idx<k){
        if(compareTwoArrays(nums1, nums2, i, j)){
            res[idx]=nums1[i++];
        }
        else res[idx]=nums2[j++];
        idx++;
    }
    return res;
}

vector<int> maxNumberOfSingleArray(vector<int>&num, int k){
    vector<int>ans;
    int n=num.size();
    for(int i=0, j=0; i<n; i++){
        while(j>0 && n-i+j>k && ans[j-1] < num[i]){
            ans.pop_back();
            j--;
        }
        if(j<k){
            ans.push_back(num[i]);
            j++;
        }
    }
    return ans;
}

vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
    int len1 = nums1.size();
    int len2 = nums2.size();

    vector<int>ans(k);
    if(len1+len2<k) return ans;
    
    for(int i=0; i<=k; i++){
        if(i<=len1 && (k-i)<=len2){
            vector<int> maxNumbers1 = maxNumberOfSingleArray(nums1, i);
            vector<int> maxNumbers2 = maxNumberOfSingleArray(nums2, k - i);
            vector<int> maxNumbers = mergeTwoArrays(maxNumbers1, maxNumbers2, k);
            if(compareTwoArrays(maxNumbers, ans, 0, 0)) ans=maxNumbers;
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