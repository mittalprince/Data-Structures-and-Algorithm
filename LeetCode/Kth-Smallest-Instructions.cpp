//https://leetcode.com/problems/kth-smallest-instructions/
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

int comb(int n, int r){
    long res = 1;
    for(int i = r+1; i <= n; ++i){
        res *= i;
        res /= (i-r);
    }
    return res;
}

string kthSmallestPath(vector<int>& destination, int k) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int r=destination[0], c=destination[1];
    int n=r+c;

    string ans="";
    for(int i=0; i<n; i++){
        if(c>0){
            int t = comb(c-1+r, r);
            if(k<=t){
                ans += "H";
                c -=1;
            }
            else{
                ans += "V";
                k -=t;
                r -=1;
            }
        }
        else{
            ans += "V";
            r-=1;
        }
    }
    return ans;
}

// -------------------------

vector<vector<long long int>> ncr;

string solve(int r, int c, int k){
    if(c==0){
        return string(r, 'V');
    }
    if(r==0){
        return string(c, 'H');
    }

    if(k<=ncr[r+c-1][c-1]){
        return "H" + solve(r, c-1, k);
    }
    return "V"+ solve(r-1, c, k-ncr[r+c-1][c-1]);
}

string kthSmallestPath(vector<int>& dest, int k) {
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    ncr = vector<vector<long long int>>(40, vector<long long int>(40, 0));
    for(int i=0; i<=35; i++){
        ncr[i][0] = ncr[i][i]=1;
    }

    for(int i=2; i<=35; i++){
        for(int j=1; j<=i; j++){
            ncr[i][j] = ncr[i-1][j-1] + ncr[i-1][j];
            // ncr[i][i-j] = ncr[i][j];
        }
    }

    return solve(dest[0], dest[1], k);
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