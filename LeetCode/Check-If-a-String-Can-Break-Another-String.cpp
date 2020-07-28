#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MOD 1000000007

/*
Given two strings: s1 and s2 with the same size, 
check if some permutation of string s1 can break some permutation of string s2 or vice-versa (in other words s2 can break s1).
A string x can break string y (both of size n) if x[i] >= y[i] (in alphabetical order) for all i between 0 and n-1.
*/

bool checkIfCanBreak(string s1, string s2) {
    int arr1[26]={0};
    int arr2[26]={0};

    for(int i=0; i<s1.length(); i++){
        arr1[s1[i]-'a']++;
        arr2[s2[i]-'a']++;
    }

    bool canbreak1 = true;
    bool canbreak2 = true;

    int ct1=0, ct2=0;

    for(int i=0; i<26; i++){
        ct1 += arr1[i];
        ct2 += arr2[i];

        if(ct1>ct2){
            canbreak1 = false;
        }
        if(ct2>ct1){
            canbreak2=false;
        }
    }
    return (canbreak1||canbreak2);
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}