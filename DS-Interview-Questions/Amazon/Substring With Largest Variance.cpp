// https://leetcode.com/problems/substring-with-largest-variance/
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

int largestVariance(string s) {
    int arr[26]={0};
    for(char i: s)arr[i-'a']++;
    int ans=0;
    for(char i='a'; i<='z'; i++){
        for(char j='a'; j<='z'; j++){
            if(i==j || !arr[i-'a'] || !arr[j-'a'])continue;

            for(int k=1; k<=2; k++){
                int a1=0, a2=0;
                for(char p: s){
                    if(p==i)a1++;
                    if(p==j)a2++;
                    if(a1<a2){
                        a1=0;
                        a2=0;
                    }
                    if(a1 && a2)
                        ans = max(ans, a1-a2);
                }
                reverse(s.begin(), s.end());
            }
        }
    }
    return ans;
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