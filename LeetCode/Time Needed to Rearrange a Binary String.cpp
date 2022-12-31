// https://leetcode.com/problems/time-needed-to-rearrange-a-binary-string/
#include<iostream>
#include<vector>
#include<algorithm>
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

//Brute Force
int secondsToRemoveOccurrences(string s) {
    int ans=0;
    bool isChanged=true;

    while(isChanged){
        isChanged=false;
        for(int i=0; i<s.length()-1; i++){
            if (s[i] == '0' && s[i+1] == '1'){
                s[i]='1';
                s[i+1]='0';
                isChanged = true;
                i++;
            }
        }
        ans += isChanged;
    }
    return ans;
}

//  Optimised O(N) TC

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