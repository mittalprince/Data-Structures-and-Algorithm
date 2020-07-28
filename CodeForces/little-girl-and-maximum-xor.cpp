#include <iostream>
using namespace std;
typedef long long ll;

// logic
/*
The maximum possible XOR of any two integers from an interval [l, r] can be determined from l ⊕ r, 
assuming l, r to be integers. This value is equal to pow(2, p) − 1, 
where p is the smallest value such that pow(2, p) is larger than l ⊕ r.
*/
int main()
{
    /*
    All you have to do is take xor of l and r.
    Then find the leftmost set bit.
    Then for maximum xor of 2 numbers, all you have to do is upto that leftmost bit, 
    add the (1<<i) to answer.
    */
    ll l, r, i;
    cin >> l >> r;
    for (i = 63; i >= 0; i--)
    {
        if ((l & (1ll << i)) ^ (r & (1ll << i)))
        {
            break;
        }
    }
    ++i;
    // cout<<++i<<endl;
    ll ans = (1ll << i) - 1;
    cout << ans << endl;
}