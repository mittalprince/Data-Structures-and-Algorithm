// https://leetcode.com/discuss/interview-question/794840/Google-or-Software-Engineer-Internship-2021-or-Online-test-questions-(OA)
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

void solve(){
    int n;
    cin>>n;
    vector<int>arr, brr;

    int q;
    cin>>q;
    while(q--){
        int type,x;
        cin>>type>>x;
        if(type==0){
            arr.push_back(x);
        }
        else{
            brr.push_back(x);
            arr.push_back(-1);
        }
    }

    for(int i=brr.size()-2; i>=0; i--){
        brr[i] ^= brr[i+1];
    }

    int idx=0;
    for(int i=0; i<n and idx<brr.size(); i++){
        if(arr[i]!=-1){
            arr[i] ^= brr[idx];
        }
        else{
            i++;
            idx++;
        }
    }

    sort(arr.begin(), arr.end());
    for(int i: arr){
        cout<<i<<" ";
    }
    cout<<endl;
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}