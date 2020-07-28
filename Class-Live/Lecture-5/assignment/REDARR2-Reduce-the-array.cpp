#include<iostream>
#include<vector>
#include<set>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

int main(){
    fstIO;
    int t;
    scanf("%d", &t);
    while(t--){
        int n,temp;
        scanf("%d", &n);
        multiset<ll>s;
        for(int i=0; i<n; i++){
            scanf("%d", &temp);
            s.insert(temp);
        }

        ll ans=0;
        while(s.size()>1){
            // for(auto i: s){
            //     cout<<i<<" ";
            // }
            // cout<<endl;
            ll a = *s.begin();
            s.erase(s.begin());
            ll b = *s.begin();
            s.erase(s.begin());
            ans += (a+b);
            s.insert(a+b);
        }
        printf("%lld\n", ans);
    }
    return 0;
}