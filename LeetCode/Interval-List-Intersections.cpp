//https://leetcode.com/problems/interval-list-intersections/
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

vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<vector<int>> v;
    int i=0,j=0;
    while(i<A.size() && j<B.size()){
        int l=max(A[i][0], B[j][0]);
        int u=min(A[i][1], B[j][1]);
        if(l<=u) v.push_back({l,u});
        if(A[i][1] < B[j][1])   i++;
        else j++;
    }
    return v;
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