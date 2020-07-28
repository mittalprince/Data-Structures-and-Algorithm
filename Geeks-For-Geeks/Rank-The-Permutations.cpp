#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define mod 1000003

int FindRank(string A){
    int ans = 0;
    int n = A.size();
    int m = n;
    int Mod = 1e6 + 3;
    for (int i = 0; i < A.size(); i++)
    {
        int count = 0;
        for (int j = i + 1; j < A.size(); j++)
        {
            if (A[i] > A[j])
                count++;
        }
        ans = ((ans * 1ll * m) % Mod + count) % Mod;
        m--;
    }
    ans++;
    return ans;
}

long long factorial(int n, vector<long long>&arr){
    if(n==0) {
        arr[0]=1;
        return 1;
    }
    long long t = n*(factorial(n-1, arr)%1000003)%1000003;
    arr[n]=t;
    return arr[n];
}

void populateAndIncreaseCount(int arr[], string s, bool &repeat){
    for(char i: s){
        arr[i]++;
        if(arr[i]>1) repeat=true;
    }
    for(int i=1; i<256; i++){
        arr[i] += arr[i-1];
    }
}

void updatecount(int arr[], char c){
    for(int i=c; i<256; i++){
        arr[i]--;
    }
}

int findRank(string s){
    int n=s.length();
    vector<long long> Arr(n+1, 0);
    long long fact = factorial(n, Arr);
    long long rank=1;

    int arr[256]={0};
    bool repeat=false;
    populateAndIncreaseCount(arr, s, repeat);

    if(repeat){
        return 0;
    }
    for(int i=0; i<n; i++){
        fact = Arr[n-i-1];
        rank += (arr[s[i]-1]*fact);
        updatecount(arr, s[i]);
    }
    return rank;
}
void solve(){
    string s;
    cin>>s;
    cout<<(findRank(s)%mod)<<endl;
}

int main(){
    int t;
    cin>>t;
     while(t--){
         solve();
    }
    return 0;
}