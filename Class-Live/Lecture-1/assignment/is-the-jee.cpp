#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define pi 3.14159265359

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        double b, c;
        cin >> b >> c;
        double s = 0, e = pi / 2;
        double ans = 0;
        while (s <= e)
        {
            double mid = (e + s) / 2;
            float num1 = (2 * mid + b) * sin(mid);
            float num2 = cos(mid) * (mid * mid + b * mid + c);
            float val = num1 - num2;
            if (val == 0.000000000000000)
            {
                ans = mid;
                break;
            }
            else if (val < 0)
            {
                ans = mid;
                s = mid;
            }
            else
            {
                e = mid;
            }
        }
        ans = (ans * ans + b * ans + c) / sin(ans);
        cout << setprecision(11) << ans << endl;
    }
    return 0;
}