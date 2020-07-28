// https://www.interviewbit.com/problems/maximum-unsorted-subarray/
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

vector<int> subUnsort(vector<int> &A) {
    int n=A.size();
    if(n==0)return {-1};

    int start=-1,end=-1, curr_max=INT_MIN, curr_min=INT_MAX;
    for(int i=0; i<n; i++){
        curr_max = max(curr_max, A[i]);
        if(curr_max >A[i]){
            if(start==-1 or curr_min>A[i]){
                start=i;
                curr_min = min(curr_min, A[i]);
            }
            end = i;
        }
    }

    if(start == -1)return {-1};

    int j=0;
    while(j<n){
        if(A[j]>A[start]){
            break;
        }
        j++;
    }
    vector<int>ans;
    ans.push_back(j);
    (end==-1)?ans.push_back(n-1):ans.push_back(end);
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