// https://leetcode.com/problems/check-if-it-is-a-straight-line/
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

double slope(vector<int>&x,vector<int>&y){
    int f=y[1]-x[1];
    if(f==0) return 111;
    return ((double)(y[0]-x[0])/(double)f);
}

bool checkStraightLine(vector<vector<int> >&coordinates){
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    double res=slope(coordinates[0],coordinates[1]);
    for(int j=1;j<coordinates.size()-1;j++)
    {
        double ch=slope(coordinates[j],coordinates[j+1]);
        if(ch!=res)
            return false;
    }
    return true;
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