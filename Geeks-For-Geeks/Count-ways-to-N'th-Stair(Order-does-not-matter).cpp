#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

/*
Link: https://practice.geeksforgeeks.org/problems/count-ways-to-nth-stairorder-does-not-matter/0/

There are N stairs, and a person standing at the bottom wants to reach the top. The person can climb either 1 stair or 2 stairs at a time. Count the number of ways, the person can reach the top (order does not matter).
Note: Order does not matter means for n=4 {1 2 1},{2 1 1},{1 1 2} are considered same.

Explanation:-
1.(n divide two):- it gives total number of 2s...and this total number is same as number of ways(not total ways) to reach n..
e.g:- for n=4,(n divide two)=(4/2)=2;
so picking one 2 out of total 2s and rest 1s form one way i.e.{2,1,1}..
picking two 2s out of total 2s and rest 1s form one way i.e.{2,2}..
that's all...so number of ways=2.
2. add( one):-now not picking 2s at all so number of way=1.

Hence Total no. of ways :(n divide two) add( one)=2+1=3.i.e.,{1,1,1,1}.{2,1, 1},{2,2}..

we find how many 2 step jump he can take atmost, let say x
then 1 comb is all 2s, second is (x-1) 2s and one 1, third is (x-2) 2s and 2 ones, so on .....
at last all ones

so (n/2) -> gives total 2 arrangement with is, and +1 is because when we consider all i

*/
void solve(){
    int n;
    cin>>n;
    int res= (n>>1)+1;
    cout<<res<<endl;
}

int main(){
    int t;
    cin>>t;
     while(t--){
         solve();
    }
    return 0;
}