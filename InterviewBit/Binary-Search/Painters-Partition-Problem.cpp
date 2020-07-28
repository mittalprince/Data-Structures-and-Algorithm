// https://www.interviewbit.com/problems/painters-partition-problem/
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

const int mod = 10000003;

bool isPossible(vector<int>&board, int total_painter, int max_days){
    int n=board.size();
    int days_used=0;
    int painter_req=1;
    for(int i=0; i<n; i++){
        if(days_used+board[i]>max_days){
            painter_req++;
            days_used = board[i];
            
            if(painter_req>total_painter)return false;
        }
        else days_used += board[i];
    }
    return true;
    // return (painter_req<=total_painter);
}

int paint(int A, int B, vector<int> &C) {
    int n=C.size();
    int s = 0, e=0;
    for(int i: C){
        s = max(i, s);
        e += i;
    }
    
    int ans=0;
    
    while(s<=e){
        int mid = s+(e-s)/2;
        if(isPossible(C, A, mid)){
            ans=mid;
            e=mid-1;
        }
        else s=mid+1;
    }
    return (int)((ans * (long)B) % 10000003);
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