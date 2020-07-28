#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

/*
Question: 
You are given a sorted array consisting of only integers where every element appears exactly twice, 
except for one element which appears exactly once. 
Find this single element that appears only once.

EXPLANATION:-
Suppose array is [1, 1, 2, 2, 3, 3, 4, 5, 5]
we can observe that for each pair, 
first element takes even position and second element takes odd position
for example, 1 is appeared as a pair,
so it takes 0 and 1 positions. similarly for all the pairs also.

this pattern will be missed when single element is appeared in the array.

From these points, we can implement algorithm.
1. Take left and right pointers . 
    left points to start of list. right points to end of the list.
2. find mid.
    if mid is even, then it's pair should be after that position.
	or if mid is odd, then it's pair should be before that position.
	check these two conditions, 
	if any of the conditions is satisfied,
	then pattern is not missed, 
	so check in next half of the array. i.e, left = mid + 1
	if condition is not satisfied, then the pattern is missed.
	so, single number must be before mid.
	so, update end to mid.
3. At last return the nums[left]

*/

int singleNonDuplicate(vector<int>& nums) {
    int e=nums.size()-1, s=0;

    while(s<e){
        int mid = (s+e)/2;
        if((mid%2 == 0 && nums[mid]==nums[mid+1]) || (mid%2 == 1 && nums[mid] == nums[mid-1])){
            s=mid+1;
        }
        else e=mid;
    }
    return nums[s];
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}