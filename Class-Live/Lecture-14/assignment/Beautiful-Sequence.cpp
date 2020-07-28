#include<iostream>
#include<vector>
#include<map>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

map<ll,ll>arr, temp;

void solve(){
    
    ll sum = arr[0]+arr[1]+arr[2]+arr[3];
    vector<ll>ans;
    bool flag=false;
    for(int i=0; i<4; i++){
        if(arr[i]){
            ans.clear();
            temp = arr;
            ans.push_back(i);
            temp[i]--;
            ll prev = i;

            for(int j=0; j<sum; j++){
                if(temp[prev-1]>0){
                    temp[prev-1]--;
                    ans.push_back(prev-1);
                    prev--;
                }
                else if(temp[prev+1]>0){
                    temp[prev+1]--;
                    ans.push_back(prev+1);
                    prev++;
                }
                else break;
            }

            if(ans.size() == sum){
                flag=true;
                break;
            }
        }
    }

    if(flag){
        cout<<"YES\n";
        for(int i: ans){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    else cout<<"NO\n";
}

int main(){
    ip(arr, 4);
    solve();
    return 0;
}