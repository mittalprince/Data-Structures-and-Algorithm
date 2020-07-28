// https://codeforces.com/contest/732/problem/D
#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=1; i<=n; i++) cin>>arr[i];
#define op(arr, n) for(int i=1; i<=n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MOD 1000000007
#define MAX 100005

ll n,m;
ll arr[MAX], t[MAX];

bool canPossible(ll days){
    int exams=m;
    bool flag[MAX]={0};
    ll total_req_time=0;

    for(int i=days; i>0; i--){
        if(arr[i] && !flag[arr[i]]){// if ith din koi exam hota hai and voh phela kabhi nahi hua ho toh
            exams--; // ek exam kam ho jaega
            total_req_time += t[arr[i]]; // total_req_time mein iss exam ka time add karo
            flag[arr[i]]=true; // yeh exam de diya toh isko true karo
        }
        else{
            if(total_req_time>0) total_req_time--;// agr exam phela se diya hua ho toh ajj ka din tota_re_time se kam kar doo
        }
    }
    if(exams>0 || total_req_time>0) return false; // is koi exam dena reh gaya hoo ya total_req bacha hoo toh false
    return true;
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    cin>>n>>m;
    ip(arr, n); // kis kis din konsa exam hai 
    ip(t, m); // ith exam ko pass karne ke liye kitna din padna padta hai 
    
    ll ans=0, s=0, e=n;
    while(s<=e){
        ll mid = (s+e)/2;
        if(canPossible(mid)){
            ans=mid;
            e=mid-1;
        }
        else s=mid+1;
    }
    if(!ans)cout<<"-1\n";
    else cout<<ans<<endl;
    return 0;
}