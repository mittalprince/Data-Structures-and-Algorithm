#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;

int main(){
    ll n,r,avg;
    cin>>n>>r>>avg;
    ll sum=0;
    vector<pair<ll, ll> >arr(n);
    for(int i=0; i<n; i++){
        ll a,b;
        cin>>a>>b;
        sum += a;
        arr[i] = make_pair(b,a);
    }
    sort(arr.begin(), arr.end());
    ll ans=0, i=0, temp;
    ll max_marks = n*avg;
    while(sum<max_marks && i<n){
        temp = min(max_marks-sum, r-arr[i].second);
        ans += temp*arr[i].first;
        sum += temp;
        i++;
    }
    cout<<ans<<endl;
}