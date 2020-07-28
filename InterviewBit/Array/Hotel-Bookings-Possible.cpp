// https://www.interviewbit.com/problems/hotel-bookings-possible/
#include<iostream>
#include<vector>
#include<algorithm>
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

bool hotel(vector<int> &A, vector<int> &B, int K){
    int n=A.size();
    if(n==0)return true;
    if(K==0)return false;

    vector<pair<int, char> >arr;
    for(int i=0; i<n; i++){
        arr.push_back({A[i],'s'});
        arr.push_back({B[i], 'e'});
    }
    sort(arr.begin(), arr.end());
    int c=0;
    for(auto it: arr){
        if(it.second == 's'){
            c++;
        }
        else c--;

        if(c<0)c=0;
        if(c>K)return false;
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