#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MAX 5000

bool isPrime[MAX];
ll total_factors[MAX]={0}, divisors[MAX]={0}, ct_factors[MAX]={0};

void CalculateAllPrime(){
    memset(isPrime, true, sizeof(isPrime));
    for(ll i=2; i*i<MAX; i++){
        if(isPrime[i]){
            for(ll j=2*i; j<MAX; j+=i){
                isPrime[j]=false;
                divisors[j]=i;
            }
        }
    }
}

void CalculateNoOfAllPrimeFactors(){
    for(ll i=2; i<MAX; i++){
        if(isPrime[i]){
            total_factors[i]=1;
        }
        else{
            ll t = i/divisors[i];
            total_factors[i] = total_factors[t]+1;
        }
        ct_factors[i] = ct_factors[i]+ct_factors[i-1]+total_factors[i];
    }
}

ll factors[MAX] = {0};

void CalculateAllPrimeFac()
{
    factors[1] = 1;
    for (ll i = 2; i < MAX; i++)
        factors[i] = i;
    for (ll i = 4; i < MAX; i += 2)
        factors[i] = 2;
    for (ll i = 3; i * i < MAX; i++)
    {
        if (factors[i] == i)
        {
            for (ll j = 2 * i; j < MAX; j += i)
            {
                if (factors[j] == j)
                    factors[j] = i;
            }
        }
    }
}

ll findtotalFactors(ll n)
{
    ll ans = 1;
    if (n == 1)
        return ans;
    ll smallest_factor = factors[n];
    ll factor_ct = 1;
    n = n / factors[n];

    while (n != 1)
    {
        if (factors[n] == smallest_factor)
            factor_ct++;
        else
        {
            ans *= (factor_ct + 1);
            smallest_factor = factors[n];
            factor_ct = 1;
        }
        n = n / factors[n];
    }
    ans *= (factor_ct + 1);
    return ans;
}

int main(){
    CalculateAllPrime();
    CalculateNoOfAllPrimeFactors();
    CalculateAllPrimeFac();
    int n;
    cin>>n;
    cout<<ct_factors[n]-ct_factors[n-1]<<endl;
    cout << findtotalFactors(n)<<endl;
    return 0;
}