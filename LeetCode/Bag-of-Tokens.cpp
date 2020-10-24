//https://leetcode.com/problems/bag-of-tokens/
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

int bagOfTokensScore(vector<int>& tokens, int P) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n=tokens.size();
    if(n==0)return 0;

    sort(tokens.begin(), tokens.end());
    int ans=0;
    int score=0;
    int i=0, j=n-1;

    while(i<=j){
        if(P>=tokens[i]){
            P-= tokens[i++];
            score++;
        }
        else{
            if(score>0){
                P += tokens[j--];
                score--;
            }
            else break;
        }
        ans = max(ans, score);
    }
    return ans;
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