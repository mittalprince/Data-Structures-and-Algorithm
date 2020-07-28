#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#include<climits>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

/*
We maintain a stack and a variable third, where third is the third number, which is also 2 in pattern 132, 
initialized to the integer minimum,

Put all numbers greater than third in order in the stack, which is also 3 in pattern 132

Then when we traverse, if the current number is less than third, that is, the 1 in pattern 132 is found, we can directly return true, 
because it has been found

we should traverse the array from back to front. If the current number is greater than the top element of the stack, 
then we take the top number of the stack, assign it to third, and then push the number onto the stack

For example, for example, [2, 4, 2, 3, 5], because it is traversed from back to front, 
so the last three numbers will not enter the while loop

Then the number in the stack is 5, 3, 2 (where 2 is the top element of the stack), 
at this time third is still the smallest integer, then when iterating to 4

Finally, 4 is greater than the top element 2 of the stack, then the third value is 2, 
and 2 is out of the stack. At this time continue the while loop, because 4 is still greater than the top element 3 of the new stack

At this time, the value of third is 3, and 3 is out of the stack. 
Now that the top element of the stack is 5, then the while loop ends, 
pushing 4 onto the stack. The next number 2, less than third

hen find the sequence that meets the requirements [2, 4, 3]
*/
bool find132pattern(vector<int>& nums) {
    stack<int> s;
    int third=INT_MIN;   

    for(int i=nums.size()-1; i>=0; i--){
        if(nums[i] < third) return true; // if we find any no less than 2 it will be 1 (132) as we already have 32 so we return true
        while(!s.empty() && s.top() < nums[i]){// this loop is to find 3 (132) in pattern as it is largest
            third = s.top(); // third will used to keep track of 2 (132) in patter
            s.pop();
        }
        s.push(nums[i]); //psuh all elements in decreasing order
        // the stack store all element in dec order, when we have increasing element we pop the until this maximum elmenmt reach
        // to its correct pos (i.e one left to its higher) and maintain the highes possible value of 2 (132)
        // after if we have any value larger than third we found pattern
    }
    return false;
}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    ip(arr, n);
    if(find132pattern(arr)) cout<<"true\n";
    else cout<<"false\n";
    return 0;
}