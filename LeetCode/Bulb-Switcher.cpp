#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

/*
There are n bulbs that are initially off. You first turn on all the bulbs. 
Then, you turn off every second bulb. On the third round, you toggle every third bulb 
(turning on if it's off or turning off if it's on). For the i-th round, you toggle every i bulb. 
For the n-th round, you only toggle the last bulb. Find how many bulbs are on after n rounds.
*/

/*
If we consider n bulbs that are all initially switched off, in order to have any ith bulb turned on at the end of n rounds, 
it must have been toggled an odd number of times [OFF -> ON | OFF -> ON -> OFF -> ON | and so on...]. 
The ith bulb is toggled k times, where k is the number of unique factors of i. 
Thus, 4 is toggled 3 times (one each for the 1st, 2nd, and 4th rounds) and 7 is toggled 2 times (for 1st and 7th).
So, we could find the number of numbers with an odd number of unique factors in O(n * sqrt (n)) time. 
However, this turns out to be too slow.

We can use a property of perfect squares to speed things up. 
A perfect square will have an odd number of unique factors. 
This is because generally, for a given n, if a divisor d is known, the other divisor is n / d. 
Thus, we can count them in twos. However, for a perfect square, the square root will repeat, 
and thus not be unique, so we only count it once (if n is a perfect square, sqrt(n) == n / sqrt(n)). 
Thus, we can count the number of perfect squares upto and including n, 
which will give us the number of numbers with an odd number of unique factors, 
which in turn tells us the number of bulbs that will be turned on at the end of n rounds. 
This turns out to be the floor of sqrt(n)(that is, we only consider the integral part of sqrt(n).
*/

int bulbSwitch(int n) {
    return sqrt(n);   
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}