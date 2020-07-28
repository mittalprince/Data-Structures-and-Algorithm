// https://www.interviewbit.com/problems/repeat-and-missing-number-array/
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

vector<int> repeatedNumber(const vector<int> &A) {
    int n=A.size();
    long long sum=0,sq_sum=0, temp_sum=0, temp_sq_sum=0;
    
    for(long long i=0; i<n; i++){
        temp_sum +=A[i];
        temp_sq_sum += (long long)A[i]*A[i];
        sum += (i+1);
        sq_sum += (i+1)*(i+1);
    }
    long long x = sum-temp_sum, y=sq_sum-temp_sq_sum;
    int a = (y-(x*x))/(2*x);
    int b = x+a;
    vector<int>ans;
    ans.push_back(a);
    ans.push_back(b);
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