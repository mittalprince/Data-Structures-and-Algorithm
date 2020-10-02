// https://leetcode.com/problems/can-place-flowers/
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

bool canPlaceFlowers(vector<int>& fb, int N) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n=fb.size();
    if(n==0)return true;

    int placed=0;
    for(int i=0; i<n; i++){
        if(i==0){
            if(fb[i]==0){
                placed++;
                fb[i]=1;
            }
            continue;
        }
        if(fb[i]==0){
            if(fb[i-1]==0){
                placed++;
                fb[i]=1;
            }
        }
        else{
            if(fb[i-1]==1){
                placed--;
                fb[i-1]=0;
            }
        }
    }

    return placed>=N;
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