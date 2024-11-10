#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define ip1(arr, n) for(int i=1; i<=n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define debug(x) cout<<x<<"\n";
#define inf 1e9
#define INF 1e16
#define MOD 1000000007

long maxCharge(vector<int>& charge) {
    int n = charge.size();
    if(n==1)return charge[0];
    long long odd=0, even=0;
    bool allNeg = true;
    for(int i=0; i<n; i++){
        long long t = charge[i];
        if(t>0) allNeg = false;
        if(i&1){
            if(t>0) odd+=t;
        } else{
            if(t>0) even+=t;
        }
    }
    if(allNeg)return *max_element(charge.begin(), charge.end());
    return max(odd, even);
}
int main(){

/*
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
*/

    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}

/*
The engineers have a specialized tool that allows them to perform the following operation: Select a system and remove it, causing the neighboring systems to automatically merge and combine their charge values. If the removed system has neighboring systems with charges x and y directly to its left and right, they will combine to form a new system with charge x + y. No combination will take place if the system is the leftmost or rightmost in the array.
Since this process is computationally expensive, the engineers will simulate the operation using Amazon's advanced tools.
For example, if the system charges are [-3, 1, 4, -1, 5, -9], using the tool on the 4th system (index 3) will result in the new sequence [-3, 1, 9, -9], as the charges from the 3rd and 5th systems combine to
4 + 5 = 9. If they then use tha tool on the 1 st
system in this new sequence, it will become [1, 9,-9].
The engineers will continue performing these operations until only one system remains.
Given an array charge of size n, find the maximum possible charge of the remaining system after performing these operations.

[-2,4,9,1,-1] -> 9
*/