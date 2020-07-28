#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MAX 10000005

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    ll freq[MAX] = {0}, total_divisible_no[MAX] = {0}, ans[MAX] = {0};
    // ll maxE=0;
    bool isPrime[MAX];
    for (ll i = 0; i < n; i++)
    {
        ll temp;
        cin >> temp;
        // maxE = max(maxE, temp);
        freq[temp]++;
    }

    memset(isPrime, true, sizeof(isPrime));
    for (ll i = 2; i < MAX; i++)
    {
        if (isPrime[i])
        {
            for (ll j = i; j < MAX; j += i)
            {
                isPrime[j] = false;
                total_divisible_no[i] += freq[j];
            }
        }
        ans[i] = ans[i] + ans[i - 1] + total_divisible_no[i];
    }

    ll m;
    cin >> m;
    while (m--)
    {
        ll l, r;
        cin >> l >> r;
        if (l > MAX - 1)
            l = MAX - 1;
        if (r > MAX - 1)
            r = MAX - 1;

        cout << ans[r] - ans[l - 1] << endl;
    }
}