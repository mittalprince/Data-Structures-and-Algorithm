// https://codeforces.com/contest/1038/problem/C
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
#define MAX 100005

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int n;
    cin>>n;
    vector<int> a(MAX, 0), b(MAX, 0);
    ip(a, n);
    ip(b, n);

    sort(a.begin(), a.end(), [&](int i, int j)->bool{
        return i>j;
    });
    sort(b.begin(), b.end(), [&](int i, int j)->bool{
        return i>j;
    });

    int total_moves = 2*n;
    int ct=0;
    ll sum_a=0, sum_b=0;
    bool flag=true;
    int i=0, j=0;
    while(ct<total_moves){
        if(flag){
            if(a[i]>=b[j]){
                sum_a += a[i++];
            }
            else j++;
        }
        else{
            if(b[j]>=a[i]){
                sum_b += b[j++];
            }
            else i++;
        }
        ct++;
        flag = !flag;
    }
    
    cout<<sum_a-sum_b<<endl;
    return 0;
}