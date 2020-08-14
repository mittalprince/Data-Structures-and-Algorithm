// https://codeforces.com/contest/493/problem/B
// https://codeforces.com/contest/493/problem/B
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

void solve(){
    int n;
    cin>>n;
    ll sum_a=0, sum_b=0;
    vector<int> seq_a, seq_b;

    int x;
    for(int i=0; i<n; i++){
        cin>>x;
        if(x>0){
            sum_a+=x;
            seq_a.push_back(x);
        }
        else{
            // x *= -1;
            sum_b+=abs(x);
            seq_b.push_back(abs(x));
        }
    }

    if(sum_a>sum_b){
        cout<<"first\n";
    }
    else if(sum_a<sum_b){
        cout<<"second\n";
    }
    else{
        int i=0, j=0;
        string ans="first";
        bool equal=true;

        while(i<seq_a.size() and j<seq_b.size()){
            if(seq_b[j] != seq_a[i])equal=false;
            if(seq_b[j]>seq_a[i]){
                ans="second";
                break;
            }
            else if(seq_a[i]>seq_b[j])break;
            i++;
            j++;

        }
        if(equal){
            if(x<0)cout<<"second\n";
            else cout<<"first\n";
            return;
        }
        cout<<ans<<endl;
    }
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}