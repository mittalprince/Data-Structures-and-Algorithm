// https://www.interviewbit.com/problems/flip/
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

vector<int> flip(string A){
    int n=A.size();
    int start=-1, end=0, temp=0;
    int curr=0, ms=0;

    bool flag=true;
    for(int i=0; i<n; i++){
        if(A[i] == '0'){
            curr++;
            flag=false;
        }
        else curr--;
        if(ms<curr){
            ms=curr;
            start=temp;
            end=i;
        }
        if(curr<0){
            curr=0;
            temp=i+1;
        }
    }

    if(flag)return {};

    vector<int>ans;
    ans.push_back(start+1);
    ans.push_back(end+1);
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