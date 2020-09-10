// https://leetcode.com/problems/bulls-and-cows/
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

string getHint(string secret, string guess) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int bull = 0, cow = 0, i, n = secret.length();
    int countS[10] = {0};
    int countG[10] = {0};
    for(i=0; i<n; i++){
        if(secret[i] == guess[i]) bull++;
        else{
            countS[secret[i] - '0']++;
            countG[guess[i] - '0']++;
        }
    }

    for(i=0;i<10;i++){
        cow += min(countS[i], countG[i]);
    }       
    return (to_string(bull)+"A"+to_string(cow)+"B");
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