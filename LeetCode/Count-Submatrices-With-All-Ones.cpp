// https://leetcode.com/problems/count-submatrices-with-all-ones/
#include<iostream>
#include<vector>
#include<climits>
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

/*
Logic Used:

for each cell we consider it as the starting point of rectangle and cal how many diff rectangles we can make when
rectangle start from (i,j);

so to fix each cell we run n^2 loop
then for each starting point we first check at all row that how many rectangle we can have
consider all col having consecutive one from this (i,j). no in this also e need n^2.

But since we already precomputed the consutive 1 from for each cell in its right alredy no now total complexity will be n^3.

int x = INT_MAX;
for(int k=i; k<n and x; k++){
    if(arr[k][j]==0) break;
    x = min (x, arr[k][j]);
    ans += x;
}

here we start from (i,j) and check for ith row how many rectangle we can have starting from (i,j) and consider all col from j, it's 
already store in arr[i][j] (means consecutive 1 from this point in right direction).

the same we do for all row (isliye k=i to n ka loop hai).

Since we consider how many rectangle we can when the top left corned of rectangle is fixed, 
so in donwward direction we check min(x, arr[i][j])

1 0 1
1 1 0
1 1 0

for when (0,0) is fixed for i=1 row ke liye hum sirf 2x1 ka rectangle bna sakte hai jakdi 1 row par 2 consuctive 1 hai, qki
reactangle ka top fixed hai isliye hum abhi tak jo min a rha hai ussi tak a rectnagle le sakte hai, isliye mein 0 honepar break kar diya

jab hum (1,0) ko fixed karenge tak 2 row ke liye 2x2 ka rectangle consider hoga
*/

int numSubmat(vector<vector<int>>& mat) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n=mat.size();
    int m=mat[0].size();

    int arr[n][m];
    for(int i=0; i<n; i++){
        int ct=0;
        for(int j=m-1; j>=0; j--){
            if(mat[i][j])ct++;
            else ct=0;
            arr[i][j]=ct;
        }
    }

    int ans=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            int x = INT_MAX;
            for(int k=i; k<n and x; k++){
                if(arr[k][j]==0) break;
                x = min (x, arr[k][j]);
                ans += x;
            }
        }
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