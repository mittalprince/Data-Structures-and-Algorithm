#include<iostream>
using namespace std;
typedef long long ll;
#define MAX 100005

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        ll arr[n+1], freq[MAX]={0};
        freq[0]=1;
        for(int i=0; i<n; i++){
            cin>>arr[i];
            if(i>0) arr[i] = arr[i-1]+arr[i];
            arr[i] %= n;
            arr[i] = (arr[i]+n)%n;
            freq[arr[i]]++;
        }

        ll ans=0;
        for(int i=0; i<n; i++){
            ans += (freq[i]*(freq[i]-1))/2;
        }
        cout<<ans<<endl;
    }
}