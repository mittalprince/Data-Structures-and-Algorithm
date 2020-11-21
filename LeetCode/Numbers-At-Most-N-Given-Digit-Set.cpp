//https://leetcode.com/problems/numbers-at-most-n-given-digit-set/
#include<iostream>
#include<vector>
#include<cmath>
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

int atMostNGivenDigitSet(vector<string>& D, int N){
    string NS = to_string(N);
    int digit = NS.length(), dsize=D.size();

    int ans=0;

    // if N = 2563, D = {1,2,6}
    // x, xx, xxx for each digit: 3^1 + 3^2 + 3^3;
    for(int i=1; i<digit; i++){
        // count total numbers which has 1 to (NS-1) length.
        // so total possible number of 1 length is dsize^1 (as we have total dsize option available);
        // similarly possible number of 2 lenght is dsize^2 (as we have total dszie option available at each place) and so on.
        ans += pow(dsize, i); 
    }

    // now we have to find total number whose length is NS and are less than equal to N
    for (int i = 0 ; i < digit ; ++i) {
        bool hasSameNum = false;
        for (string &d : D) {
            if (d[0] < NS[i]) 
                ans += pow(dsize, digit - i - 1);
            else if (d[0] == NS[i]) 
                hasSameNum = true;
        }
        if (!hasSameNum) return ans;
    }    
    return ans+1;
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