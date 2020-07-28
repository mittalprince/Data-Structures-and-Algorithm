#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
#define ip(arr, n)              \
    for (int i = 0; i < n; i++) \
        cin >> arr[i];
#define op(arr, n)              \
    for (int i = 0; i < n; i++) \
        cout << arr[i] << " ";
#define fstIO                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string a, b;
        cin >> a >> b;
        int I = 0;
        for (int i = 0; i < a.length(); i++)
        {
            if (a[i] >= 'A' && a[i] <= 'Z')
                a[i] += 32;
            if (b[i] >= 'A' && b[i] <= 'Z')
                b[i] += 32;
            if (a[i] < b[i])
            {
                I = -1;
                break;
            }
            else if (a[i] > b[i])
            {
                I = 1;
                break;
            }
        }
        cout << I << endl;
    }
    return 0;
}