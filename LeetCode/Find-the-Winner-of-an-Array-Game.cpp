// https://leetcode.com/problems/find-the-winner-of-an-array-game/
#include<iostream>
#include<vector>
#include<queue>
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

int getWinner(vector<int>& arr, int k) {
    int n=arr.size();
    k = min(k, n);
    /*
    int A=arr[0];
    int ct=0;
    for(int i=1; ; i++){
        int B = arr[i%n];
        if(A>=B)ct++;
        else{
            A=B;
            ct=1;
        }
        if(ct == k)return A;
    }
    */

    deque<int>q;
    for(int i: arr){
        q.push_back(i);
    }
    int ct=0;
    while(1){
        int a = q.front(); q.pop_front();
        int b = q.front(); q.pop_front();

        if(a>=b){
            ct++;
            if(ct>=k)return a;
            q.push_front(a);
            q.push_back(b);
        }
        else{
            ct=1;
            if(ct>=k)return b;
            q.push_front(b);
            q.push_back(a);
        }
    }
    return -1;
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