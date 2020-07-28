#include <iostream>
#include <vector>
using namespace std;

int mySqrt(int x)
{
    int s = 1, e = x / 2;
    if (x <= 1)
        return x;

    while (s <= e)
    {
        int mid = (s + e) / 2;
        if (mid == x / mid)
            return mid;
        else if (mid < x / mid)
        {
            if (mid + 1 == x / (mid + 1))
                return mid + 1;
            else if (mid + 1 > x / (mid + 1))
                return mid;
            else
                s = mid + 1;
        }
        else
            e = mid - 1;
    }
    return s;
}

int main()
{
    int n;
    cin >> n;
    cout << mySqrt(n) << endl;
    return 0;
}