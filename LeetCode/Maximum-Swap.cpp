#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

/*
Given a non-negative integer, you could swap two digits at most once to get the maximum valued number. Return the maximum valued number you could get.

Example 1:
Input: 2736
Output: 7236
Explanation: Swap the number 2 and the number 7.

Example 2:
Input: 9973
Output: 9973
Explanation: No swap.
*/

// Brute Force try all possible swap, as num is only 8 in length(1-10^8), so 8C2 -> 28
// so change every i with its next places and comp the number if its greater store this
int maximumSwap(int num) {
    string s = to_string(num);
    string temp = s;

    for(int i=0; i<s.length(); i++){
        for(int j=i+1; j<s.length(); j++){
            swap(s[i], s[j]);
            if(temp<s){
                temp=s;
            }
            swap(s[i], s[j]);
        }
    }
    int ans = stoi(temp);
    return ans;
}

int maximumSwap(int num) {
    /*
    1. At each digit of the input number in order, if there is a larger digit that occurs later, 
    we know that the best swap must occur with the digit we are currently considering.
    
    2. We will compute \text{last[d] = i}last[d] = i, the index \text{i}i of the last occurrence of digit d (if it exists).
    3. Afterwards, when scanning the number from left to right, if there is a larger digit in the future, 
       we will swap it with the largest such digit; if there are multiple such digits, we will swap it with the one that occurs the latest
    */
    
    string s = to_string(num);
    
    int last_Pos[10]={0};
    for(int i=0; i<s.length(); i++){
        last_Pos[s[i]-'0'] = i;
    }
    
    for(int i=0; i<s.length(); i++){
        for(int d=9; d>s[i]-'0'; d--){
            if(last_Pos[d] > i){
                swap(s[i], s[last_Pos[d]]);
                return stoi(s);
            }
        }
    }
    return num;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}