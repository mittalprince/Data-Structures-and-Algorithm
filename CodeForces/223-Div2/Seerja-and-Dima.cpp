// https://codeforces.com/contest/381/problem/A
#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MOD 1000000007

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    #endif

    int n;
    cin>>n;
    int arr[n];
    ip(arr, n);
    
    int s=0, e=n-1;
    ll sum1=0, sum2=0;
    bool flag=true;

    while(s<=e){
        if(flag){
            if(arr[s]>=arr[e]){
                sum1 += arr[s];
                s++;
            }
            else{
                sum1 += arr[e];
                e--;
            }
        }
        else{
            if(arr[s]>=arr[e]){
                sum2 += arr[s];
                s++;
            }
            else{
                sum2 += arr[e];
                e--;
            }
        }
        flag = !flag;
    }

    cout<<sum1<<" "<<sum2<<endl;
    return 0;
}