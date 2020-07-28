#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define mod 1000003

void facotrial(long long n, vector<long long>&fact){
    long long f=1;
    fact.push_back(1);
    for(long long i=1; i<=n; i++){
        f = (f*i)%mod;
        fact.push_back(f);
    }
    return;
}

long long moduloMultiplicateInverse(int n){
    long long int ans=1;
    long long a=n, b=mod-2;

    while(b>0){
        if(b&1){
            ans= (ans*a)%mod;
        }
        a = (a*a)%mod;
        b = b/2;
    }
    return (ans%mod);
}

int findRank(string s){
    int n = s.length();
    vector<long long> fact;
    facotrial(n, fact);
    long long rank = 1;

    int freq[256]={0};
    for(char i: s) freq[i]++;

    for(int i=0; i<n; i++){
        long long int less_than=0;
        int remaining = n - i - 1;

        for(int ch=0; ch<s[i]; ch++){
            if(freq[ch] == 0) continue;
            freq[ch]--;

            long long int numPermutation = fact[remaining];
            for(int c=0; c<128; c++){
                if(freq[c] <= 1) continue;
                numPermutation = (numPermutation * moduloMultiplicateInverse(fact[freq[c]]))%mod;
            }

            freq[ch]++;
            less_than = (less_than+numPermutation)%mod;
        }

        rank = (rank+less_than)%mod;
        freq[s[i]]--;
    }
    return rank;
}

int FindRank(string s){
    int n=s.length();
    vector<long long>fact;
    facotrial(n, fact);
    long long rank=1;


    for(int i=0; i<n; i++){
        int less_than=0;
        for(int j=i+1; j<n; j++){
            if(s[i]>s[j]) less_than++;
        }

        int freq[52] = {0};
        for(int j=i; j<n; j++){
            if(s[j]>='A' && s[j]<='Z') freq[s[j]-'A']++;
            else freq[s[j]-'a'+26]++;
        }

        long long int d_fact=1; // factorial of repeated char
        for(int i: freq){
            d_fact = (d_fact*fact[i])%mod;
        }

        rank = (rank + ((fact[n-i-1]*less_than) * moduloMultiplicateInverse(d_fact))%mod)%mod;
    }
    return rank;
}
void solve(){
    string s;
    cin>>s;
    cout<<findRank(s)<<endl;
}

int main(){
    int t;
    cin>>t;
     while(t--){
         solve();
    }
    return 0;
}