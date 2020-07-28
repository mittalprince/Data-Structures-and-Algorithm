#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        if (n <= 3)
        {
            cout << "1"
                 << "\n";
            cout << n << " ";
            for (int i = 1; i <= n; i++)
                cout << i << " ";
            cout << "\n";
        }
        else
        {
            int ans = n / 2;
            cout << ans << "\n";
            for (int i = 1; i <= n; i += 2)
            {
                if ((i + 2) == n)
                {
                    cout << "3 " << i << " " << i + 1 << " " << i + 2 << "\n";
                    break;
                }
                else
                {
                    cout << "2 " << i << " " << i + 1 << "\n";
                }
            }
        }
    }
}