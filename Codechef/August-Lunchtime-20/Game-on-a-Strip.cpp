// https://www.codechef.com/LTIME87A/problems/ARRGAME
#include<iostream>
#include<vector>
#include<unordered_map>
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
    cin >> n;
    vector<int> arr(n);
    ip(arr, n);
    unordered_map<int, int> m;

    int ct = 0, p=0;
    
    for (int i = 0; i < n; i++){
        if (arr[i] == 0){
            ct++;
        }
        else{
            m[ct]++;
            ct = 0;
        }
    }
    if(ct)m[ct]++;

    int mx = 0;
    for (auto i : m){
        mx = max(mx, i.first);
    }

    if((mx == 1 && m[mx] >= 2) or (mx == 0) or m[mx] >= 2){
        cout << "No" << endl;
        return;
    }

    if(mx == 1){
        cout << "Yes" << endl;
        return;
    }

    int mx2 = (mx) / 2;
    bool flag = false;
    for (auto i : m){
        if (i.first > mx2 && mx != i.first){
            flag = 1;
            break;
        }
    }

    if (!flag && mx & 1){
        cout << "Yes\n";
        return;
    }

    cout << "No\n";
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