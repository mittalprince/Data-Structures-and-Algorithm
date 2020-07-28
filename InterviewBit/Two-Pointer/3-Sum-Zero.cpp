// https://www.interviewbit.com/problems/3-sum-zero/
#include<iostream>
#include<vector>
#include<algorithm>
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

vector<vector<int> > threeSum(vector<int> &A) {
    int n=A.size();
    vector<vector<int> >res;
    
    if(n<3)return {};
    
    sort(A.begin(), A.end());
    
    for(int i=0; i<n; i++){
        if(i>0 and A[i] == A[i-1])continue;
        int s=i+1;
        int e=n-1;
        
        while(s<e){
            long long val = A[i]+A[s]+A[e];
            if(val == 0){
                res.push_back({A[i], A[s], A[e]});
                while(s<e and A[s] == A[s+1])s++;
                while(e>s and A[e] == A[e-1])e--;
                s++;
                e--;
            }
            else if(val<0)s++;
            else e--;
        }
    }
    
    return res;
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