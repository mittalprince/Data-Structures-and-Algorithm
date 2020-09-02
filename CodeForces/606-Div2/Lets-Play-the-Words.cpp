//https://codeforces.com/contest/1277/problem/D
#include<iostream>
#include<vector>
#include<map>
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
    int type[4]={0};
    map<string, bool>present;
    vector<int> ind[2];
    vector<string>arr(n);

    for(int i=0; i<n; i++){
        cin>>arr[i];
        present[arr[i]]=true;
        if(arr[i][0]=='0' and arr[i].back()=='0')type[0]++;
        else if(arr[i][0]=='0' and arr[i].back()=='1'){
            type[1]++;
            ind[0].push_back(i);
        }
        else if(arr[i][0]=='1' and arr[i].back()=='0'){
            type[2]++;
            ind[1].push_back(i);
        }
        else type[3]++;
    }

    if(type[1]==0 and type[2]==0){
        if(type[0]>0 and type[3]>0){
            cout<<"-1\n";
        }
        else cout<<"0\n";
        return;
    }

    int ans = max(abs(type[1]-type[2])/2, 0);
    cout<<ans<<endl;
    if(type[1]>=type[2]){
        int i=0, cnt=0;
        while(cnt<ans){
            reverse(arr[ind[0][i]].begin(), arr[ind[0][i]].end());
            if(present.count(arr[ind[0][i]]) == 0){
                cout<<ind[0][i]+1<<" ";
                cnt++;
            }
            i++;
        }
    }
    else{
        int i=0, cnt=0;
        while(cnt<ans){
            reverse(arr[ind[1][i]].begin(), arr[ind[1][i]].end());
            if(present.count(arr[ind[1][i]]) == 0){
                cout<<ind[1][i]+1<<" ";
                cnt++;
            }
            i++;
        }
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