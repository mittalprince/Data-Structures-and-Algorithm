// https://leetcode.com/problems/numbers-with-same-consecutive-differences/
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

vector<int> numsSameConsecDiff(int N, int k) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int>ans;

    queue<int>q;
    for(int i=1; i<10; i++){
        q.push(i);
    }

    for(int i=1; i<N; i++){
        int sz=q.size();
        for(int j=0; j<sz; j++){
            int top=q.front();
            q.pop();

            int unit = top%10;
            if(unit+k < 10){
                q.push(top*10+unit+k);
            }
            if(unit-k>=0 and k!=0){
                q.push(top*10 + unit-k);
            }
        }
    }
    if(N==1)ans.push_back(0);
    while(!q.empty()){
        ans.push_back(q.front());
        q.pop();
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