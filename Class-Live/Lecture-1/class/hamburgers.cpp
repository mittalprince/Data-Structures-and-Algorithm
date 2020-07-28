#include <iostream>
using namespace std;
typedef long long ll;
#define MAX 1000000100000

ll maxHB(string str, ll nb, ll ns, ll nc, ll pb, ll ps, ll pc, ll amt)
{
    ll s = 0, e = MAX;
    ll ans = 0;

    int cb = 0, cs = 0, cc = 0;
    for (int i = 0; i<str.length(); i++)
    {
        if (str[i] == 'B')
            cb++;
        else if (str[i] == 'S')
            cs++;
        else
            cc++;
    }

    while (s <= e)
    {
        ll mid = (s + e)/2;
        ll reqBA = (mid * cb - nb) * pb < 0 ? 0 : ((mid * cb - nb)) * pb;
        ll reqSA = (mid * cs - ns) * ps < 0 ? 0 : ((mid * cs - ns)) * ps;
        ll reqCA = (mid * cc - nc) * pc < 0 ? 0 : ((mid * cc - nc)) * pc;

        ll reqAmt = reqBA+reqSA+reqCA;
        if(reqAmt == amt){
            return mid;
        }
        else if(reqAmt < amt){
            ans=mid;
            s=mid+1;
        }
        else e=mid-1;
    }
    return ans;
}

int main()
{
    string rec;
    cin >> rec;
    ll nb, ns, nc, pb, ps, pc;
    ll amt;
    cin >> nb >> ns >> nc >> pb >> ps >> pc;
    cin >> amt;
    cout<<maxHB(rec, nb, ns, nc, pb, ps, pc, amt)<<endl;
    return 0;
}
