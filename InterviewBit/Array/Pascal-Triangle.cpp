// https://www.interviewbit.com/problems/pascal-triangle/
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

vector<vector<int> > solve(int A) {
    vector<vector<int> >ans;
    if(A<1) return ans; 
    vector<int>temp;
    
    temp.push_back(1);
    ans.push_back(temp);

    for(int i=0; i<A-1; i++){
        vector<int>t;
        t.push_back(1);
        for(int j=0; j<ans[i].size()-1; j++){
            t.push_back(ans[i][j]+ans[i][j+1]);
        }
        t.push_back(1);
        ans.push_back(t);
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